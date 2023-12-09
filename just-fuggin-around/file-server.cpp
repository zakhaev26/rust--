#include <iostream>
#include <httplib.h>
#include<nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
void getImage(const httplib::Request &req, httplib::Response &res) {
    cout << "AYA" << endl;
    
    // Check if the request body is not empty
    if (req.body.empty()) {
        res.status = 400;  // Bad Request
        res.set_content("Bad Request: Empty JSON body", "text/plain");
        return;
    }

    // Parse the JSON body
    json reqBody;
    try {
        reqBody = json::parse(req.body);
    } catch (const json::parse_error &e) {
        res.status = 400;  // Bad Request
        res.set_content("Bad Request: Invalid JSON format", "text/plain");
        return;
    }

    // Check if the required field is present in the JSON body
    if (!reqBody.contains("imgLink")) {
        res.status = 400;  // Bad Request
        res.set_content("Bad Request: Missing 'imgLink' field", "text/plain");
        return;
    }

    std::string url = "wget " + std::string(reqBody["imgLink"]) + " -O dua.png";

    // Check if the system command executed successfully
    if (system(url.c_str()) != 0) {
        res.status = 500;  // Internal Server Error
        res.set_content("Internal Server Error: Failed to download image", "text/plain");
        return;
    }

    // Rest of your code for reading the image file and sending the response
    // ...

}

int main() {
    httplib::Server svr;

    svr.Post("/get_image", getImage);

    std::cout << "Server is running on http://localhost:8080\n";
    svr.listen("localhost", 8080);

    return 0;
}