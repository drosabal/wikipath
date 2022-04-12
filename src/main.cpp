#include <iostream>
#include "Graph.h"

int main()
{
    Graph graph;

    std::string from, to;
    std::cout << "Start: ";
    std::cin >> from;
    std::cout << "End: ";
    std::cin >> to;
    std::cout << std::endl;

    bool valid_search = true;
    if (!graph.page_exists(from)) {
        std::cout << "Invalid start page title." << std::endl;
        valid_search = false;
    }
    if (!graph.page_exists(to)) {
        std::cout << "Invalid end page title." << std::endl;
        valid_search = false;
    }
    if (valid_search) {
        std::vector<std::vector<std::string>> paths = graph.find_paths(from, to);
        // TODO: Output found paths
    }

    return 0;
}
