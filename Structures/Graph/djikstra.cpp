#include <bits/stdc++.h>
using namespace std;

#define V 9

int minDistance(vector<int> &dist, vector<bool> &present)
{
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < V; v++)
    {
        if (!present[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSol(vector<int> &dist)
{
    cout << "Vertex \t\t Distance from src" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << dist[i];
    }
    return;
}

void djikstra(int graph[][V], int source)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> present(V, false);
    dist[source] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(dist, present);
        present[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!present[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSol(dist);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    djikstra(graph, 0);
    return 0;
}