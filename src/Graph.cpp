#include "Graph.h"
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_set>
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

/*
bool Graph::bfs(vector<string>& st_path, string from, string to) {
    //bool found = false;
    //vector<string> st_path;
    set<string> visited;
    queue<string> q;
    visited.insert(from);
    q.push(from);
    
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        st_path.push_back(u);
        vector<string> neighbors = find_adjacent(u);
        sort(neighbors.begin(), neighbors.begin() + neighbors.size());
        for (string v : neighbors) {
            if (v == to) {
                return true;
            }
            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                q.push(v);
            }
        }
    }
    return false;
}
*/

vector<string> Graph::bfs(string from, string to)
{
    unordered_set<string> visited;
    visited.insert(from);
    queue<string> q;
    q.push(from);
    vector<string> path;
    
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        vector<string> neighbors = find_adjacent(u);
        for (string v : neighbors) {
            if (visited.count(v) == 0) {
                parent[v] = u;
                if (v == to) {
                    path = backtrace(from, to);
                    return path;
                }
                visited.insert(v);
                q.push(v);
            }
        }
    }
    return path;
}
vector<string> Graph::backtrace(string from, string to)
{
    vector<string> path;
    path.push_back(to);
    while (path[path.size() - 1] != from) {
        path.push_back(parent[path[path.size() - 1]]);
    }
    return path;
}
