#include <bits/stdc++.h>
#include "queue.h"

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    int V;
    vector<list<int>> adj;

    public:
        Graph(int V); // Constructor
        void addEdge(int v, int w); // function to add an edge to graph
        void BFSTransversal(int s); // prints BFS transversal from a given source s
        string BFS(int s, int f); // prints BFS path from a source s to f
        // void DFS(int s); // returns DFS path from a given source s
};

#endif
