#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph
{
    unordered_map<string, int> page_id; // Maps each page title to a unique page ID
    unordered_map<int, int> source; // Tracks the source of each page when searching

public:
    Graph(); // Generates the page_id map from wikilinks.txt, where each ID is the page's line number

    bool page_exists(string page_title); // Returns true if the page appears in the page_id map
    string get_page_title(int id); // Returns the page title of the given id
    vector<int> find_adjacent(int id); // Returns the pages adjacent to the given page from wikilinks.txt
    vector<string> bfs(string from, string to); // Runs a breadth-first search and returns the shortest path
    vector<string> backtrace(string from, string to); // Helper function for bfs to trace the found path
};
