#include "Graph.h"
#include <fstream>
#include <sstream>
using namespace std;

Graph::Graph()
{
    ifstream file("wikilinks.txt");
    string line;
    int i = 1;
     while (getline(file, line)) {
        istringstream line_stream(line);
        string page_title;
        getline(line_stream, page_title, '|');
        page_id.emplace(page_title, i);
        i++;
    }
    file.close();
}

bool Graph::page_exists(string page_title)
{
    return (page_id.find(page_title) != page_id.end());
}
void Graph::insert(string from, string to)
{
    adj_list[from].push_back(to);
}
vector<string> Graph::find_adjacent(string page_title)
{
    vector<string> adjacent;
    string line;
    ifstream file("wikilinks.txt");
    for (int i = 0; i < page_id[page_title]; i++) {
        getline(file, line);
    }
    file.close();
    istringstream line_stream(line);
    string token;
    getline(line_stream, token, '|');
    while (getline(line_stream, token, '|')) {
        adjacent.push_back(token);
    }
    return adjacent;
}
vector<vector<string>> Graph::find_paths(string from, string to)
{
    vector<vector<string>> paths;
    // TODO: Implement
    return paths;
}