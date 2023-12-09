#include <iostream>
#include <httplib.h>
#include<nlohmann/json.hpp>
int main() {
    httplib::Server svr;

    svr.Get("/get_image", [&](const httplib::Request& req, httplib::Response& res) {

        json reqBody = json::parse(req.body);

        std::string url = "wget "+ std::string(req.params.key["imgLink"]);
        system(url.c_str());

        std::ifstream infile("dua.png", std::ios::binary);

        if (!infile.is_open()) {
            std::cerr << "Error opening image file\n";
            res.status = 500;
            res.set_content("Internal Server Error", "text/plain");
            return;
        }

        infile.seekg(0, std::ios::end);
        size_t file_size = infile.tellg();
        infile.seekg(0, std::ios::beg);

        std::vector<char> file_content(file_size);
        infile.read(file_content.data(), file_size);
        infile.close();

        res.set_content(file_content.data(), file_size, "image/jpeg");
    });

    std::cout << "Server is running on http://localhost:8080\n";
    svr.listen("localhost", 8080);

    return 0;
}
