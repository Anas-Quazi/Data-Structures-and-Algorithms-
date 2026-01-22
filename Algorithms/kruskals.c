#include <stdio.h>
#define MAX 30

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskal(int n, int cost[MAX][MAX]) {
    int i, j, a, b, u, v, min, ne = 1, mincost = 0;

    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min && cost[i][j] != 0) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum cost = %d\n", mincost);
}

int main() {
    int n = 4;
    int cost[MAX][MAX] = {
        {0, 0, 0, 0, 0},
        {0, 0, 10, 6, 5},
        {0, 10, 0, 0, 15},
        {0, 6, 0, 0, 4},
        {0, 5, 15, 4, 0}
    };

    kruskal(n, cost);

    return 0;
}
