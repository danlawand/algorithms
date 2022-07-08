
// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <bits/stdc++.h>
using namespace std;
 
// This class represents a directed graph using
// adjacency list representation

class Graph {
    int V;

    // Adjacency lists
    vector<list<int>> adj;

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFSTransversal(int s); // prints BFS transversal from a given source s
    string BFS(int s, int f); // prints BFS path from a source s to f
    // void DFS(int s); // returns DFS path from a given source s
};

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
string Graph::BFS(int s, int f) {
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

// void Graph::DFS(int s) {

//     // Mark all the vertices as not visited
//     vector<bool> visited;
//     visited.resize(V, false);
//     u.visited = true
//     for each v ∈ G.Adj[u]
//         if v.visited == false
//             DFS(G,v)
// }

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal " << "(starting from vertex 2) \n";
    g.BFS(2, 1);
 
    return 0;
}
