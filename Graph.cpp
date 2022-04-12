#include "Graph.h"
#include <fstream>
#include <sstream>

Graph::Graph()
{
    std::ifstream file("wikilinks.txt");
    std::string line;
    int i = 1;
     while (std::getline(file, line)) {
        std::istringstream line_stream(line);
        std::string page_title;
        std::getline(line_stream, page_title, '|');
        page_id.emplace(page_title, i);
        i++;
    }
    file.close();
}

bool Graph::page_exists(std::string page_title)
{
    return (page_id.find(page_title) != page_id.end());
}
void Graph::insert(std::string from, std::string to)
{
    adj_list[from].push_back(to);
}
std::vector<std::string> Graph::find_adjacent(std::string page_title)
{
    std::vector<std::string> adjacent;
    std::string line;
    std::ifstream file("wikilinks.txt");
    for (int i = 0; i < page_id[page_title]; i++) {
        std::getline(file, line);
    }
    file.close();
    std::istringstream line_stream(line);
    std::string token;
    std::getline(line_stream, token, '|');
    while (std::getline(line_stream, token, '|')) {
        adjacent.push_back(token);
    }
    return adjacent;
}
std::vector<std::vector<std::string>> Graph::find_paths(std::string from, std::string to)
{
    std::vector<std::vector<std::string>> paths;
    // TODO: Implement
    return paths;
}