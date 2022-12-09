/*
Graph class with helper functions
*/

#include "def.h"

template <typename T>
class Graph {
private:
    typename mp<T>::mt g;
    int n;
    void add_edge(typename vec_two<T>::vtt edges); 
    void _dfs_topo(T src, std::map<T, bool> &visited, std::map<T, int> &order, int& num, bool& cycle);
    std::map<T, int> get_indegree(std::map<T, int>& order);
    std::vector<T> get_zero_indegree_values(std::map<T, int> indegree);

public:
    Graph(typename vec_two<T>::vtt e, int n);
    void print();
    void topo_dfs();
    void topo_bfs();
};

template <typename T>
Graph<T>::Graph(typename vec_two<T>::vtt e, int n) {
    this->n = n;
    add_edge(e);
}

template <typename T>
void Graph<T>::add_edge(typename vec_two<T>::vtt edges) {
    for (auto it:edges) g[it[0]].PB(it[1]);
}

template <typename T>
void Graph<T>::print() {
    for (auto it : g) {
        std::cout<<it.first<< ": ";
        typename vec_one<T>::vt edges = g[it.first];
        for (int i=0; i<edges.size(); i++){
            std::cout<<edges[i]<<" ";
        }
        std::cout<<"\n";
    }
}
    
template<typename T>
std::map<T, int> Graph<T>::get_indegree(std::map<T, int>& order) {
    std::map<T, int> indegree;
    for (auto it=this->g.begin(); it!= this->g.end(); it++) {
        if (indegree.find(it->first) == indegree.end()) indegree[it->first] = 0;
        for (auto j = it->second.begin(); j!= it->second.end(); j++) {
            order[*j] = -1;
            indegree[*j]++;
        }
    }
    return indegree;
}

template<typename T>
std::vector<T> Graph<T>::get_zero_indegree_values(std::map<T, int> indegree) {
    std::vector<T> ind;
    for (auto it = this->g.begin(); it != this->g.end(); it++) {
        if (indegree[it->first]==0) {
            ind.PB(it->first);
        }
    }
    return ind;
}
