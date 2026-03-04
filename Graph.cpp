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

    //? add edge for directed graph
    void addEdgeDirected(int u, int v) {
        
        if(adjList.find(u) == adjList.end() || adjList.find(v) == adjList.end()) {
            std :: cout << "One or both vertices don't exist\n";
            return;
        }
        adjList[u].push_back(v);  //~ only u → v
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

        //! visit all starting vertices (disconnected graph)
        for (auto& [vertex, _] : adjList) {
            if (!visited.count(vertex)) {
                q.push(vertex);
                visited.insert(vertex);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    std::cout << u << " ";

                    //^ visit all neighbours
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

        std :: unordered_set<int> visited;

        //? diffrent starting nodes (disonnected graph)
        for (auto& [vertex, _] : adjList) {
            if (!visited.count(vertex)) {
                DFS_Recursive(vertex, visited);
            }
        }
    }

    //* DFS (stack)
    void DFS_Iterative() {

        //^ stack and set for tracking nodes
        std :: stack<int> s;
        std :: unordered_set<int> visited;

        //! first vertex of each disconnected graph
        for(auto& [vertex, _] : adjList) {
            if(!visited.count(vertex)) {
                s.push(vertex);

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
        }
    }

    bool detectCycleDFS(int u, std :: unordered_set<int>& visited, int par) {

        visited.insert(u);

        for(int v : adjList[u]) {
            if(!visited.count(v)) {
                if(detectCycleDFS(v, visited, u)) {
                    return true;
                }
            }
            else if(v != par) {
                return true;
            }
        }

        return false;
    }

    //* detect cycle using BFS
    bool detectCycleBFS(int src, std :: unordered_set<int>& visited) {

        std :: queue<std :: pair<int, int>> q;
        q.push({src, -1});
        visited.insert(src);

        while(!q.empty()) {

            int u = q.front().first;
            int parU = q.front().second;
            q.pop();

            for(int v : adjList[u]) {
                if(!visited.count(v)) {
                    visited.insert(v);
                    q.push({v, u});
                }
                else if(v != parU) {
                    return true;
                }
            }
        }
        return false;
    }

    //* detect cycle in directed graph
    bool detectCycleDirect(int crt, std :: unordered_set<int>& visited, std :: unordered_set<int>& recPath) {

        //^ mark as true
        visited.insert(crt);
        recPath.insert(crt);

        for(int v : adjList[crt]) {
            if(!visited.count(v)) {
                if(detectCycleDirect(v, visited, recPath)) {
                    return true;
                }
            }
            else if(recPath.count(v)) {
                return true;
            }
        }

        //& backtrack
        recPath.erase(crt);
        return false;
    }

    //* main function for detecting cycle (BFS + DFS + Directed)
    bool detectCycle() {

        //^ set for tracking vertices
        std :: unordered_set<int> visited;
        std :: unordered_set<int> recPath;

        //todo visit each vertex
        for(auto& [vertex, _] : adjList) {
            if(!visited.count(vertex)) {
                if(detectCycleDirect(vertex, visited, recPath)) {
                    return true;
                }
            }
        }
        return false;
    }

    //& topological sort in Graph
    void topologicalSort(int u, std :: unordered_set<int>& visited, std :: stack<int>& s) {

        visited.insert(u);

        for(int v : adjList[u]) {
            if(!visited.count(v)) {
                topologicalSort(v, visited, s);
            }
        }

        //^ push neighbor in stack
        s.push(u);
    }

    std :: vector<int> topoSort() {

        std :: unordered_set<int> visited;
        std :: stack<int> s;

        for(auto& [vertex, _] : adjList) {
            if(!visited.count(vertex)) {
                topologicalSort(vertex, visited, s);
            }
        }

        //todo copy values from stack to array
        std :: vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        //~ just verification
        for(int val : ans) {
            std :: cout << val << " ";
        }

        return ans;
    }

};

//* number of islands : leetcode 200 (DFS Algo)
void totalIslands(int i, int j, std :: vector<std :: vector<bool>>& visited, std :: vector<std :: vector<char>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    //^ base case (boundry conditions + already visited + zero vals)
    if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] != '1') return;

    visited[i][j] = true;

    //todo call DFS (recursively) for all 4 neighbours
    totalIslands(i-1, j, visited, grid); //~ top
    totalIslands(i, j+1, visited, grid); //~ right
    totalIslands(i, j-1, visited, grid); //~ left
    totalIslands(i+1, j, visited, grid); //~ bottom

}

int numberOfIslands(std :: vector<std :: vector<char>>& grid) {

    //? initialize no. of islands 
    int islands = 0;

    int n = grid.size();
    int m = grid[0].size();

    std :: vector<std :: vector<bool>> visited(n, std :: vector<bool>(m, false));

    //todo traverse matrix
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == '1' && !visited[i][j]) {
                totalIslands(i, j, visited, grid);
                islands++;
            }
        }
    }

    return islands;
}

//* rotting oranges : leetcode 994 (multi source BFS algorithm)
int rottingOranges(std :: vector<std :: vector<int>>& grid) {

    //? queue of pair of pair for tracking i,j and time
    std :: queue<std :: pair<std :: pair<int, int>, int>> q;
    std :: vector<std :: vector<bool>> visited(grid.size(), std :: vector<bool>(grid[0].size(), false));

    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
            
            //^ rotten orange
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
            }
        }
    }

    int ans;

    //& check for rotten oranges (neighbour 1 of 2s) : BFS 
    while(!q.empty()) {

        int i = q.front().first.first;
        int j = q.front().first.second;
        int time = q.front().second;
        q.pop();

        ans = std :: max(ans, time);

        //^ top neighbour
        if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == 1) {
            q.push({{i-1, j}, time+1});
            visited[i-1][j] = true;
        }

        //^ right neighbour
        if(j+1 < grid[0].size() && !visited[i][j+1] && grid[i][j+1] == 1) {
            q.push({{i, j+1}, time+1});
            visited[i][j+1] = true;
        }

        //^ left neighbour
        if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1] == 1) {
            q.push({{i, j-1}, time+1});
            visited[i][j-1] = true;
        }

        //^ bottom neighbour
        if(i+1 < grid.size() && !visited[i+1][j] && grid[i+1][j] == 1) {
            q.push({{i+1, j}, time+1});
            visited[i+1][j] = true;
        }
    }

    //! check if there's still fresh orange
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
            
            //^ fresh orange
            if(grid[i][j] == 1 && !visited[i][j]) {
                return -1;
            }
        }
    }

    return ans;
}

//* course schedule : leetcode 207
bool courseScheduleCycle(int src, std :: unordered_set<int>& visited, std :: unordered_set<int>& recPath, std :: vector<std :: vector<int>>& edge) {

    //^ mark vertex as visited and recursion path
    visited.insert(src);
    recPath.insert(src);

    for(int i=0; i<edge.size(); i++) {

        //& prerequistites
        int v = edge[i][0];
        int u = edge[i][1];

        //todo check for neighbours (if u is source)
        if(u == src) {
            if(!visited.count(v)) {
                if(courseScheduleCycle(v, visited, recPath, edge)) {
                    return true;
                }
            }
            else if(recPath.count(v)) {
                return true;
            }
        }
    }
    recPath.erase(src);
    return false;
}

bool courseSchedule(std :: vector<std :: vector<int>>& prerequisites, int numCourse) {

    //? visited and recursion path
    std :: unordered_set<int> visited;
    std :: unordered_set<int> recPath;
    
    for(int i=0; i<numCourse; i++) {
        if(!visited.count(i)) {
            if(courseScheduleCycle(i, visited, recPath, prerequisites)) {
                //! return false if cycle exist 
                return false;
            }
        }
    }
    return true;
}

//* course schedule II : leetcode 210
void topoOrder(int src, std :: stack<int>& s,std :: unordered_set<int>& visited, std :: vector<std :: vector<int>>& edge) {

    visited.insert(src);

    for(int i=0; i<edge.size(); i++) {
                
        int v = edge[i][0];
        int u = edge[i][1];

        //todo check for neighbours (if u is source)
        if(u == src) {
            if(!visited.count(v)) {
                topoOrder(v, s, visited, edge);
            }
        }
    }

    s.push(src);
}

std :: vector<int> courseScheduleII(std :: vector<std :: vector<int>>& preReq, int n) {
        
    //? visited and recursion path
    std :: unordered_set<int> visited;
    std :: unordered_set<int> recPath;
    std :: vector<int> ans;
    
    for(int i=0; i<n; i++) {
        if(!visited.count(i)) {
            if(courseScheduleCycle(i, visited, recPath, preReq)) {
                //^ schedule not possible
                return ans;
            }
        }
    }
    
    //todo perform topological sort
    std :: stack<int> s;
    visited.clear(); //~ clear set

    for(int i=0; i< n; i++) {
        if(!visited.count(i)) {
            topoOrder(i, s, visited, preReq);
        }
    }

    //& extract order from dtack to array
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

//* flood fills algorithm : leetcode 733
void floofFillHelper(std :: vector<std :: vector<int>>& image, int i, int j, int newColour, int origColour) {

    //^ base cases
    if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() ||
        image[i][j] != origColour || image[i][j] == newColour) {
            return;
    }

    image[i][j] = newColour;

    //& recursive calls
    floofFillHelper(image, i-1, j, newColour, origColour); //~ top
    floofFillHelper(image, i, j+1, newColour, origColour); //~ right
    floofFillHelper(image, i+1, j, newColour, origColour); //~ bottom
    floofFillHelper(image, i, j-1, newColour, origColour); //~ left

}

std :: vector<std :: vector<int>> floodFill(std :: vector<std :: vector<int>>& image, int sc, int sr, int colour) {

    floofFillHelper(image, sr, sc, colour, image[sr][sc]);

    return image;
}

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
    
    Graph directed({0, 1, 2, 3, 4, 5});
    directed.addEdgeDirected(3, 1);
    directed.addEdgeDirected(2, 3);
    directed.addEdgeDirected(4, 0);
    directed.addEdgeDirected(4, 1);
    directed.addEdgeDirected(5, 0);
    directed.addEdgeDirected(5, 3);

    directed.topoSort();

    return 0;
}