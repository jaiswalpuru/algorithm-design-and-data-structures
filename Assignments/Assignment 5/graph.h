#include "def.h"

class Graph {
private:
    um graph;
    void add_edges(vpn edges);
    void _print();
public:
    vi parent;
    Graph(vpn edges);
    ~Graph() {}
    void print_graph();
    vi dijkstra(int src);
};

Graph::Graph(vpn edges) { add_edges(edges); }

void Graph::add_edges(vpn edges) {
    for (auto it = edges.begin(); it != edges.end(); it++) {
        this->graph[it->first].PB(new Node(it->second->val, it->second->weight));
        this->graph[it->second->val].PB(new Node(it->first, it->second->weight));
    }
}

void Graph::print_graph() {
    std::cout<<"------Graph-------\n";
    _print();
    std::cout<<"------Graph-------\n";
}

void Graph::_print() {
    for (int i=0; i<SIZE; i++) {
        std::cout<<i<<" -> ";
        for (int j=0; j<this->graph[i].size(); j++) {
            std::cout<<"("<<this->graph[i][j]->val<<","<<this->graph[i][j]->weight<<") "; 
        }
        std::cout<<"\n";
    }
}

vi Graph::dijkstra(int src) {
    vi dis(SIZE, INT_MAX);
    pqn pq;
    dis[src] = 0;
    this->parent = vi(SIZE);
    pq.push(new Node(src, 0));
    while(!pq.empty()) {
        Node *curr = pq.top();
        int curr_val = curr->val;
        int curr_wt = curr->weight;
        pq.pop();
        for (int i=0; i<this->graph[curr_val].size(); i++) {
            int v = this->graph[curr_val][i]->val;
            int wt = this->graph[curr_val][i]->weight;
            if (dis[v] >= curr_wt+wt){
                this->parent[v] = curr_val; 
                dis[v] = curr_wt + wt;
                pq.push(new Node(v, dis[v]));
            }
        }
    }
    return dis;
}
