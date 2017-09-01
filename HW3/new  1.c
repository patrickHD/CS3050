#include<stdio.h>
#include<stdbool.h>

#define gsize 6
#define white 0
#define gray 1
#define black 2

int graph[gsize][gsize];

bool DFSDetectCycle (int graph[gsize][gsize], int u);
int colorOfNode[gsize];
int parent[gsize];
bool checkBackEdge (int u, int v);

bool DFSAll (int graph[gsize][gsize])
{
    int i = 0;
    for (i = 0; i < gsize; i++)
    {
        colorOfNode[i] = white;
        parent[i] = -1;
    }
    for (i = 0; i < gsize; i++)
    {
        if (colorOfNode[i] == white)
            if (DFSDetectCycle (G, i))
            {
                return true;
            }
    }
    printf ("\n");
    return false;
}

bool DFSDetectCycle (int graph[gsize][gsize], int u)
{
    // color veterx u gray
    colorOfNode[u] = gray;

    // explore adjacent vertices of u
    int v = 0;
    for (v = 0; v < gsize; v++)
    {
        // if vertex v is not visited
        if (graph[u][v] && (colorOfNode[v] == white))
        {
            parent[v] = u;
            // then visit vertex v
            if (DFSDetectCycle (G, v))
            {
                return true;
            }
        }
        // cycle found
        else if (graph[u][v] && colorOfNode[v] == gray)
        {
            if (checkBackEdge (u, v))
                return true;
        }
    }
    colorOfNode[u] = black;	// finished node
    return false;
}

bool checkBackEdge (int u, int v)
{
    if (parent[u] != v)
        return true;
    else
        return false;
}