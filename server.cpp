#include <bits/stdc++.h>
#include <httplib.h>
#include "Runner.h"
#include<nlohmann/json.hpp>
using namespace httplib;
using json = nlohmann::json;


void SolvePath(const Request &req, Response &res) {
    std::cout<<"AYA"<<std::endl;

    try{
        json reqBody = json::parse(req.body);
    }   
    catch(std::exception &e) {
        std::cout<<e.what();
    }
    system("wget https://v2.jokeapi.dev/joke/Programming,Dark?type=single -O joke.json");
    std::ifstream infile;
    infile.open("joke.json");

    if(!infile) {
        res.set_content("Error Opening WGET RES","application/json");
    }
    else{
        std::stringstream buffer;
        buffer << infile.rdbuf(); // Read the entire file into the buffer
        infile.close();

        std::string fileContent = buffer.str();
        json JOKE = json::parse(fileContent);
        std::cout<<"Joke ->"<<JOKE<<std::endl;
        res.set_content(JOKE.dump(),"application/json");
    }

 /*   
    if(reqBody.contains("List") && reqBody.contains("Edges")) {
        reqBody.emplace("SentBy","C++ Server");
        res.set_content(reqBody.dump(),"application/json");
    }

    else {
        res.status = 400;
        res.set_content("Bad Request.","text/plain");       
    }
*/
}

int main()
{

    Server server;

    server.Get("/algo",SolvePath);

    

    Dijkstra Graph;
    // int num_edges;
    // std::cin >> num_edges;

    // std::cout << "Enter the edges in the format (source destination weight):\n";
    // for (int i = 0; i < num_edges; ++i)
    // {
    //     Dijkstra::Vertex source, destination;
    //     Dijkstra::Weight weight;

    //     std::cin >> source >> destination >> weight;
    //     Graph.graph[source][destination] = weight;
    // }

    // Dijkstra::Vertex start_vertex;
    // std::cout << "Enter the starting vertex: ";
    // std::cin >> start_vertex;

    // auto result = Graph.run(start_vertex);

    // std::cout << "Shortest distances from " << start_vertex << ":\n";
    // for (const auto &pair : result)
    // {
    //     std::cout << "To " << pair.first << ": " << pair.second << "\n";
    // }

    std::cout<<"Running on local 8080"<<std::endl;
    server.listen("localhost",8080);

    return 0;   
}