#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph
{
    unordered_map<string, vector<string>> adj_list; // Adjacency list to represent graph
    unordered_map<string, int> page_id; // Maps each page title to a unique page ID

public:
    Graph(); // Generates the page_id map from wikilinks.txt, where each ID is the page's line number

    bool page_exists(string page_title); // Returns true if the page appears in the page_id map
    void insert(string from, string to); // Adds an edge to the graph (from-to)
    vector<string> find_adjacent(string page_title); // Returns the pages adjacent to the given page from wikilinks.txt
    vector<vector<string>> find_paths(string from, string to); // Finds all paths of the shortest possible length and returns them
}; 
