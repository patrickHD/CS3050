#include<stdio.h>
#include<stdbool.h>

#define nodes 6
#define white 0
#define gray 1
#define black 2

int G[nodes][nodes];

bool DFSDetectCycle (int G[nodes][nodes], int u);
int colorOfNode[nodes];
int parent[nodes];
bool checkBackEdge (int u, int v);
bool
DFSAll (int G[nodes][nodes])
{
    int i = 0;
    for (i = 0; i < nodes; i++)
    {
        colorOfNode[i] = white;
        parent[i] = -1;
    }
    for (i = 0; i < nodes; i++)
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

bool
DFSDetectCycle (int G[nodes][nodes], int u)
{
    // color veterx u gray
    colorOfNode[u] = gray;

    // explore adjacent vertices of u
    int v = 0;
    for (v = 0; v < nodes; v++)
    {
        // if vertex v is not visited
        if (G[u][v] && (colorOfNode[v] == white))
        {
            parent[v] = u;
            // then visit vertex v
            if (DFSDetectCycle (G, v))
            {
                return true;
            }
        }
        // cycle found
        else if (G[u][v] && colorOfNode[v] == gray)
        {
            if (checkBackEdge (u, v))
                return true;
        }
    }
    colorOfNode[u] = black;	// finished node
    return false;
}

bool
checkBackEdge (int u, int v)
{
    if (parent[u] != v)
        return true;
    else
        return false;
}

// main
int
main ()
{
    int G1[nodes][nodes] = { {0, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };
    int G2[nodes][nodes] = { {0, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    if (DFSAll (G1))
        printf ("cycle detected in G1\n");
    else
        printf ("no cycle detected in G1\n");
    if (DFSAll (G2))
        printf ("cycle detected in G2\n");
    else
        printf ("no cycle detected in G2\n");
    return 0;
}