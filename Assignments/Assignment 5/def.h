/*
Contains definitions
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <map>
#include "Node.h"

#define SIZE 10
#define PB push_back

class Compare {
public:
    bool operator() (Node* a, Node* b) { return a->weight < b->weight; }
};

typedef std::vector<int> vi;
typedef std::vector<Node*> vn;
typedef std::vector<std::pair<int, Node*>> vpn;
typedef std::priority_queue<Node*, vn, Compare> pqn;
typedef std::map<int, vn> um;


