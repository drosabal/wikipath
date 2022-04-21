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
string Graph::get_page_title(int id)
{
    string line;
    ifstream file("wikilinks.txt");
    for (int i = 0; i < id; i++) {
        getline(file, line);
    }
    file.close();
    istringstream line_stream(line);
    string title;
    getline(line_stream, title, '|');
    return title;
}
vector<int> Graph::find_adjacent(int id)
{
    vector<int> adjacent;
    string line;
    ifstream file("wikilinks.txt");
    for (int i = 0; i < id; i++) {
        getline(file, line);
    }
    file.close();
    istringstream line_stream(line);
    string token;
    getline(line_stream, token, '|');
    while (getline(line_stream, token, '|')) {
        adjacent.push_back(page_id[token]);
    }
    return adjacent;
}
vector<string> Graph::bfs(string from, string to)
{
    unordered_set<int> visited;
    visited.insert(page_id[from]);
    queue<int> q;
    q.push(page_id[from]);
    vector<string> path;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vector<int> neighbors = find_adjacent(u);
        for (int v : neighbors) {
            if (visited.count(v) == 0) {
                source[v] = u;
                if (v == page_id[to]) {
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
    int id;
    path.push_back(to);
    while (path[path.size() - 1] != from) {
        id = page_id[path[path.size() - 1]];
        path.push_back(get_page_title(source[id]));
    }
    return path;
}
/*
bool Graph::bfs(vector<string>& st_path, string from, string to)
{
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
