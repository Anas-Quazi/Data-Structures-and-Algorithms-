//! graph data structure in c++

#include <iostream>
#include <vector>
#include <list>

//& implement Graph using c++ stl list
class Graph {

    //^ no. of vertices & neighbours
    int V;
    std :: list<int> *adjList; //~ create a dynammic array (int* arr syntax)

public:
    //^ constructor
    Graph(int V) {
        //todo initialize v and list array
        this -> V = V;
        adjList = new std :: list<int> [V]; //~ arr = new int[V] syntax
    }

    //? add edge (establish link between two nodes)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //? check for connection
    bool isEdge(int u, int v) {
        
        for(int neigh : adjList[u]) {
            if(neigh == v) {
                return true;
            }
        }
        return false;
    }

    //? remove edge
    void removeEdge(int u, int v) {

        if(isEdge(u,v)) {
            adjList[u].remove(v);
            adjList[v].remove(u);
        }
    }

    //? add vertex to graph
    void addVertex(int v) {
        
        //^ create new array with one extra slot
        std ::list<int> *newAdjList = new std ::list<int>[V + 1];

        //todo copy old lists into new array
        for (int i = 0; i < V; i++) {
            newAdjList[i] = adjList[i];
        }
        newAdjList[V] = std::list<int>({v});

        //& change to actual list
        delete[] adjList;
        adjList = newAdjList;
        V++;
    }

    //? remove vertex
    void removeVertex(int v) {
        
        //^ clear this vertex's adjacency list
        adjList[v].clear();

        //todo remove v from all other vertices' lists
        for (int i = 0; i < V; i++) {
            adjList[i].remove(v);
        }
        V--;
    }

    //? print adjacency list
    void printAdjList() {

        for(int i=0; i<V; i++) {
            std :: cout << i << " : ";
            for(int neigh : adjList[i]) {
                std :: cout << neigh << " ";
            }
            std :: cout << std :: endl;
        }
    }
    
};

int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.printAdjList();

    std :: cout << "\n\n";

    g.addVertex(16);
    g.addEdge(4, 16);
    g.addEdge(0, 16);
    
    g.printAdjList();

    std :: cout << "\n" << g.isEdge(1, 4);

    return 0;
}