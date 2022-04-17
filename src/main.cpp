#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Graph graph;

    string from, to;
    cout << "Start: ";
    cin >> from;
    cout << "End: ";
    cin >> to;
    cout << endl;

    bool valid_search = true;
    if (!graph.page_exists(from)) {
        cout << "Invalid start page title." << endl;
        valid_search = false;
    }
    if (!graph.page_exists(to)) {
        cout << "Invalid end page title." << endl;
        valid_search = false;
    }
    if (valid_search) {
        vector<vector<string>> paths = graph.find_paths(from, to);
        // TODO: Output found paths
    }

    return 0;
}
