//! graph data structure in c++

#include <iostream>
#include <vector>
#include <list>

//& implement Graph using c++ stl list
class Graph {

    //^ no. of vertices & neighbours
    int V;
    std :: list<int> *l; //~ create a dynammic array (int* arr syntax)

public:
    //^ constructor
    Graph(int V) {
        //todo initialize v and list array
        this -> V = V;
        l = new std :: list<int> [V]; //~ arr = new int[V] syntax
    }

    //? add edge (establish link between two nodes)
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    //? check for connection
    bool isEdge(int u, int v) {
        
        for(int neigh : l[u]) {
            if(neigh == v) {
                return true;
            }
        }
        return false;
    }

    // //? remove edge
    // void remove edge 

    //? print adjacency list
    void printAdjList() {

        for(int i=0; i<V; i++) {
            std :: cout << i << " : ";
            for(int neigh : l[i]) {
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

    std :: cout << "\n" << g.isEdge(1, 4);

    return 0;
}