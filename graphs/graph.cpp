#include <iostream>
#include "graph.h"
#include "item.h"

using namespace std;

Item* newItem(int v) {
    Item* new_item = new Item();
    new_item->v = v;
    return new_item;
}

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V); // resive the adjacency lists to the length of V
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // add w to v's list
}

// Assume s is in the graph
void Graph::BFSTransversal(int s) {
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V, false);

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {
        
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        for (auto adjecent: adj[s]) {
            if (!visited[adjecent]) {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}

// Assume both s and f are in the graph
string Graph::BFS(int si, int fi) {
    Queue q;
    int* path;
    Item* item = newItem(si, )
    q.pushQueue()

    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V, false);

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // Mark the path to meta
    string path, temp_path;

    while (!queue.empty()) {
        
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        if (!visited[s]) visited[s] = true;

        if (s == f) return path;

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        for (auto adjecent: adj[s]) {
            if (!visited[adjecent]) {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}

