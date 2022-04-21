#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;

int main()
{
    cout << "Loading..." << endl;
    Graph graph;
    cout << endl;
    cout << "Welcome to WikiPath! Enter the titles of any two Wikipedia articles (including underscores)." << endl;
    cout << "Article titles are case sensitive and can be found in the page's URL. Ex: https://en.wikipedia.org/wiki/ARTICLE_TITLE_HERE" << endl;
    cout << "Note: Titles with special characters are not supported on Windows and will not be displayed properly." << endl;

    string loop;
    while (loop != "q" && loop != "Q") {
        cout << endl;
        string from, to;
        cout << "Start: ";
        getline(cin, from);
        cout << "End: ";
        getline(cin, to);

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
            vector<string> path = graph.bfs(from, to);
            if (path.size() > 1) {
                cout << "The shortest path length is: " << path.size() << endl;
                cout << "The path: ";
                for (int i = path.size() - 1; i >= 0; i--) {
                    cout << path[i] << " ";
                }
                cout << endl;
            } else {
                cout << "There is no valid path between " << from << " and " << to << "." << endl;
            }
        }

        cout << "Press ENTER to search again or Q to quit: ";
        getline(cin, loop);
    }

    return 0;
}
