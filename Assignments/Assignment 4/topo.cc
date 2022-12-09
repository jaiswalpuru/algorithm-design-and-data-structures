#include "graph.h"
#include "topo_dfs.h"
#include "topo_bfs.h"

int main() {
    vcc edges_one{{'m', 'q'},{'m', 'r'},{'m', 'x'},{'n', 'o'},{'n', 'q'},{'n', 'u'},{'o', 'r'},{'o', 's'},{'o', 'v'},
        {'p', 'o'},{'p', 's'},{'p', 'z'},{'q', 't'},{'r', 'u'},{'r', 'y'},{'s', 'r'},{'v', 'x'},{'v', 'w'},{'w', 'z'},{'y', 'v'}};
    vii edges_two{{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 5}, {2, 7}, {3, 4}, {4, 5}, {5,7}, {5,8}, {6,5}, {6,8}, {7, 4}};

    Graph<char> g_one(edges_one, 14);
    Graph<int> g_two(edges_two, 8);
    
    std::cout<<"\n\nGraph 1\n\n";
    g_one.print();
    std::cout<<"\n\nTopological sort dfs\n";
    g_one.topo_dfs();
    std::cout<<"\n\nTopological sort bfs\n";
    g_one.topo_bfs();
    
    std::cout<<"\n\nGraph 2\n\n";
    g_two.print();
    std::cout<<"\n\nTopological sort dfs\n";
    g_two.topo_dfs();
    std::cout<<"\n\nTopological sort bfs\n";
    g_two.topo_bfs();
}
