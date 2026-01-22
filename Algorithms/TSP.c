#include <stdio.h>
#include <stdbool.h>
#define INF 9999

int n = 4;
int cost[20][20] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};
int visited[20];
int finalPath[20];
int finalCost = INF;

// TSP using Branch and Bound with Backtracking
void tsp(int currentCity, int currentCost, int level, int path[]) {
    // All cities visited
    if (level == n) {
        int totalCost = currentCost + cost[currentCity][0];
        if (totalCost < finalCost) {
            finalCost = totalCost;
            for (int i = 0; i < n; i++) {
                finalPath[i] = path[i];
            }
            printf("New best found: %d\n", totalCost);
        }
        return;
    }
    
    // Try each unvisited city
    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (!visited[nextCity]) {
            int newCost = currentCost + cost[currentCity][nextCity];
            
            // Pruning
            if (newCost >= finalCost) {
                continue;
            }
            
            // Visit city
            visited[nextCity] = true;
            path[level] = nextCity;
            
            // Recurse
            tsp(nextCity, newCost, level + 1, path);
            
            visited[nextCity] = false; // Backtrack
        }
    }
}

int main() {
    printf("Number of cities: %d\n", n);
    
    printf("\nDistance Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", cost[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    int path[20];
    path[0] = 0;
    visited[0] = true;
    
    printf("\nSolving...\n");
    tsp(0, 0, 1, path);
    
    // Print result
    printf("\nMinimum Cost: %d\n", finalCost);
    printf("Optimal Path: ");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", finalPath[i]);
    }
    printf("0\n");
    
    return 0;
}