template <typename T>
void Graph<T>::topo_dfs() {
    std::map<T, bool> visited;
    std::map<T, int> order;

    for (auto it = this->g.begin(); it != this->g.end();it++) {
        order[it->first] = -1;
    }
    int n = this->n;
    bool cycle = false;
    for(auto it=this->g.begin(); it!= g.end(); it++) {
        T f = it->first;
        if (!visited[f]) _dfs_topo(f, visited, order, n, cycle);
    }
    if (!cycle) {
        for (auto it=order.begin(); it!=order.end(); it++) {
            std::cout<<it->first << " = " << it->second << "\n";
        }
    }else {
        std::cout<<"Cycle in the graph\n";
    }
}

template <typename T>
void Graph<T>::_dfs_topo(T src, std::map<T, bool> &visited, std::map<T, int> &order, int& num, bool& cycle) {
    visited[src] = true;
    for (int i=0;i<this->g[src].size(); i++) {
        if (visited[this->g[src][i]] && order[this->g[src][i]]==-1) {
            cycle = true;
        }
        if (!visited[this->g[src][i]] && !cycle) {
            _dfs_topo(this->g[src][i], visited, order, num, cycle);
        }
    }
    order[src]=num;
    num--;
}
