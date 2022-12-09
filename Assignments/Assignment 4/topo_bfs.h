template <typename T>
void Graph<T>::topo_bfs() {
    int order_start = 0;
    std::map<T, int> indegree;
    std::map<T, int> order;
    std::vector<T> ind_zero;
    std::queue<T> ind;
    
    indegree = get_indegree(order);
    ind_zero = get_zero_indegree_values(indegree);
    
    for (auto it=ind_zero.begin(); it!=ind_zero.end(); it++) {
        ind.push(*it);
    }
    while(!ind.empty()) {
        T curr = ind.front();
        ind.pop();
        order[curr] = ++order_start;
        for (auto it=this->g[curr].begin(); it!=this->g[curr].end(); it++) {
            indegree[*it]--;
            if (indegree[*it]==0) ind.push(*it); 
        }
    }
    bool cycle = false;
    for (auto it=indegree.begin(); it!=indegree.end(); it++) {
        if (it->second > 0) {
            cycle = true;
            break;
        }
    }
    if (cycle) {
        std::cout<<"Cycle in the graph\n\n";
    }else {
        for (auto it=order.begin(); it!= order.end(); it++) {
            std::cout<<it->first<<" = "<<it->second<<"\n";
        }
    }
}
