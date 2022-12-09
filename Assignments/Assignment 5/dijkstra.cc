#include "graph.h"

int main() {
    vpn v{
        {0, new Node(1, 1)}, {0, new Node(2, 8)}, {0, new Node(9, 9)},
        {1, new Node(4, 3)}, {1, new Node(5, 2)}, {1, new Node(3, 6)},
        {2, new Node(9, 10)}, {2, new Node(3, 7)}, {2, new Node(4, 5)},
        {3, new Node(6, 12)}, {3, new Node(5, 14)}, {3, new Node(9 ,11)},
        {4, new Node(5, 4)}, {4, new Node(6, 13)},
        {5, new Node(7, 16)}, {5, new Node(8, 15)},
        {6, new Node(8, 18)}, {6, new Node(7, 20)},
        {7, new Node(8, 17)},
        {8, new Node(9, 19)}
    };
    Graph g(v);
    g.print_graph();
    std::cout<<"Running dijkstra from each node in the format (node, distance)\n";
    for (int i=0; i<SIZE; i++) {
        std::cout<<"Src = "<<i<<"-> ";
        vi dist = g.dijkstra(i);
        for (int i=0; i<dist.size(); i++) {
            std::cout<<"("<<i<<","<<dist[i]<<")"<<" ";
        }
        std::cout<<"\n";
        std::cout<<"Parent of each node in the format (node, parent)\n";
        for (int i = 0; i< g.parent.size(); i++){
            std::cout<<"("<<i<<","<<g.parent[i]<<")"<<" ";
        }
        std::cout<<"\n\n\n";
    }
}
