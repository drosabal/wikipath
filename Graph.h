#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class Graph
{
    std::unordered_map<std::string, std::vector<std::string>> adj_list; // Adjacency list to represent graph
    std::unordered_map<std::string, int> page_id; // Maps each page title to a unique page ID

public:
    Graph(); // Generates the page_id map from wikilinks.txt, where each ID is the page's line number

    bool page_exists(std::string page_title); // Returns true if the page appears in the page_id map
    void insert(std::string from, std::string to); // Adds an edge to the graph (from-to)
    std::vector<std::string> find_adjacent(std::string page_title); // Returns the pages adjacent to the given page from wikilinks.txt
    std::vector<std::vector<std::string>> find_paths(std::string from, std::string to); // Finds all paths of the shortest possible length and returns them
}; 