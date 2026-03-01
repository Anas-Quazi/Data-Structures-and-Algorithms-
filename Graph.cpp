//! graph data structure in c++

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <stack>

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

        for(auto& [vertex, neighbors] : adjList) {
            std ::cout << vertex << " : ";
            for (int neigh : neighbors) {
                std ::cout << neigh << " ";
            }
            std ::cout << std ::endl;     
        }
        std :: cout << "\n\n";
    }

    //? size
    int size() {
        return adjList.size();
    }

    //* BFS traversal
    void BFS() {

        //& use queue and set for tracking neighbours
        std :: queue<int> q;
        std :: unordered_set<int> visited;

        for (auto& [vertex, _] : adjList) {
            if (!visited.count(vertex)) {
                q.push(vertex);
                visited.insert(vertex);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    std::cout << u << " ";

                    for (int v : adjList[u]) {
                        if (!visited.count(v)) {
                            visited.insert(v);
                            q.push(v);
                        }
                    }
                }
            }
        }
        std :: cout << "\n\n";
    }

    //* DFS Traversal (recursive)
    void DFS_Recursive(int u, std :: unordered_set<int>& visited) {

        //todo print u and mark as visited
        std :: cout << u << " ";
        visited.insert(u);

        //~ recursive call for neighbours
        for(int v : adjList[u]) {
            if(!visited.count(v)) {
                DFS_Recursive(v, visited);
            }
        }
    }

    void DFS() {

        //! avoid crashing
        if (adjList.empty()) return;

        int u = adjList.begin() -> first;
        std :: unordered_set<int> visited;

        DFS_Recursive(u, visited);
    }

    //* DFS (stack)
    void DFS_Iterative() {

        //^ stack and set for tracking nodes
        std :: stack<int> s;
        std :: unordered_set<int> visited;

        //& push start node
        s.push(adjList.begin() -> first);

        while(!s.empty()) {

            int u = s.top();
            s.pop();

            //? check if not visited first
            if(!visited.count(u)) {

                std :: cout << u << " ";
                visited.insert(u);

                //todo check for neighbours
                for(int v : adjList[u]) {
                    s.push(v);
                }
            }
        }
    }

    bool detectCycleDFS(int u, std :: unordered_set<int>& visited, int par) {

        visited.insert(u);

        for(int v : adjList[u]) {
            if(!visited.count(v)) {
                if(DFS_Recursive(v, visited, u)) {
                    return true;
                }
            }
            else if(v != par) {
                return true;
            }
        }

        return false;
    }

    bool detectCycle() {

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

    g.BFS();

    std :: cout << g.detectCycle()

    return 0;
}