#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4

int findMinCost(int cost[N][N], bool visited[], int vertex) {
    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && cost[vertex][i] < min && vertex != i) {
            min = cost[vertex][i];
        }
    }
    return min;
}

int calculateLowerBound(int cost[N][N], bool visited[], int currentVertex) {
    int lowerBound = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            lowerBound += findMinCost(cost, visited, i);
        }
    }
    return lowerBound;
}

void tspBranchAndBound(int cost[N][N], bool visited[], int currentVertex, int count, int currentCost, int *minCost, int path[]) {
    if (count == N && cost[currentVertex][0]) {
        if (currentCost + cost[currentVertex][0] < *minCost) {
            *minCost = currentCost + cost[currentVertex][0];
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i] && cost[currentVertex][i]) {
            visited[i] = true;
            path[count] = i;
            int newLowerBound = calculateLowerBound(cost, visited, i);
            if (currentCost + cost[currentVertex][i] + newLowerBound < *minCost) {
                tspBranchAndBound(cost, visited, i, count + 1, currentCost + cost[currentVertex][i], minCost, path);
            }
            visited[i] = false;
        }
    }
}

int main() {
    int cost[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    bool visited[N] = {false};
    visited[0] = true;
    int minCost = INT_MAX;
    int path[N];

    tspBranchAndBound(cost, visited, 0, 1, 0, &minCost, path);

    printf("The minimum cost of visiting all cities: %d\n", minCost);

    return 0;
}
