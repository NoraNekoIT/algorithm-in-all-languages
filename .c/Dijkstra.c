#include<stdio.h>
#include <stdlib.h>
#include<limits.h>


void Dijkstra(int nodes, int graph[nodes][nodes], int start)
{
    int cost[nodes][nodes], dist[nodes], pre[nodes], visited[nodes];
    int c, minDist, next;

    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j < nodes; j++)
        {
            if(graph[i][j]  == 0)
                cost[i][j] = 999;
            else
                cost[i][j] = graph[i][j];
        }
    }

    for(int i=0; i<nodes; i++)
    {
        dist[i] = cost[start][i];
        pre[i] = start;
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;
    c = 1;

    while(c < nodes-1)
    {
        minDist = 999;

        for(int i=0; i<nodes; i++)
        {
            if(dist[i] < minDist && !visited[i])
            {
                minDist = dist[i];
                next = i;
            }
        }

        visited[next] = 1;
        for(int i=0; i<nodes; i++)
        {
            if(!visited[i])
            {
                if(minDist + cost[next][i] < dist[i])
                {
                    dist[i] = minDist + cost[next][i];
                    pre[i] = next;
                }
            }
        }
        c++;
    }

    printf("Node\tDistance\n");
    for(int i=0; i<nodes; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}


int main(void)
{
    int nodes, start;
    printf("Number of Nodes: ");
    scanf("%d", &nodes);

    int graph[nodes][nodes];

    for(int i=0; i<nodes; i++)
        for(int j=0; j<nodes; j++)
            scanf("%d", &graph[i][j]);

    printf("Starting Node: ");
    scanf("%d", &start);

    Dijkstra(nodes, graph, start);

    printf("\n");
}

// 0 4 0 0 0 0 0 8 0
// 4 0 8 0 0 0 0 11 0
// 0 8 0 7 0 4 0 0 2
// 0 0 7 0 9 14 0 0 0
// 0 0 0 9 0 10 0 0 0
// 0 0 4 14 10 0 2 0 0
// 0 0 0 0 0 2 0 1 6
// 8 11 0 0 0 0 1 0 7
// 0 0 2 0 0 0 6 7 0
