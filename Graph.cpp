//! graph data structure in c++

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

//& implement Graph using c++ stl list
class Graph {

    //^ hashmap for tarcking vertices + neighbours 
    std :: unordered_map<int, std :: list<int>> adjList;

public:
    //^ constructor
    Graph(std :: vector<int> vertices) {
        for(int v : vertices) {
            adjList[v] = std :: list<int>();
        }
    }

    //? add edge (establish link between two nodes)
    void addEdge(int u, int v) {

        //& if one of edge didn't exist
        if(adjList.find(u) == adjList.end() || adjList.find(v) == adjList.end()) {
            std :: cout << "One or both vertices don't exist\n";
            return;
        }

        //todo make connection
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //? check for connection
    bool isEdge(int u, int v) {
        
        if(adjList.find(u) == adjList.end()) return false;

        for(int neigh : adjList[u]) {
            if(neigh == v) {
                return true;
            }
        }
        return false;
    }

    //? remove edge
    void removeEdge(int u, int v) {

        //todo remove connection (if exist)
        if(isEdge(u,v)) {
            adjList[u].remove(v);
            adjList[v].remove(u);
            return;
        }
        std :: cout << "Edge didn't exist\n";
    }

    //? add vertex to graph
    void addVertex(int v) {
        
        //todo add vertex if not exists
        if(adjList.find(v) != adjList.end()) {
            std :: cout << "Vertex already exists\n";
            return;
        }
        adjList[v] = std :: list<int>();
    }

    //? remove vertex
    void removeVertex(int v) {
        
        if(adjList.find(v) == adjList.end()) {
            std::cout << "Vertex doesn't exist\n";
            return;
        }

        //todo remove v from all other adjacency lists
        for(auto& [vertex, neighbors] : adjList) {
            neighbors.remove(v);
        }

        adjList.erase(v);
    }

    //? print adjacency list
    void printAdjList() {

        for (auto& [vertex, neighbors] : adjList) {
            std::cout << vertex << " : ";
            for (int neigh : neighbors) {
                std::cout << neigh << " ";
            }
            std::cout << std::endl;     
        }
    }
};

int main() {

    Graph g({0, 1,2, 3, 8});

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.printAdjList();

    std :: cout << "\n\n";

    g.addVertex(16);
    g.addEdge(8, 16);
    g.addEdge(3, 16);
    
    g.printAdjList();

    std :: cout << "\n" << g.isEdge(1, 4);

    return 0;
}