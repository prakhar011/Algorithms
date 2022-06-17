/*
Prim's algorithm is another popular minimum spanning tree algorithm
that uses a different logic to find the MST of a graph.
Instead of starting from an edge, Prim's algorithm
starts from a vertex and keeps adding lowest-weight edges
which aren't in the tree, until all vertices have been covered.

T = ∅;
U = { 1 };
while (U ≠ V)
    let (u, v) be the lowest cost edge such that u ∈ U and v ∈ V - U;
    T = T ∪ {(u, v)}
    U = U ∪ {v}

The time complexity of Prim's algorithm is O(E log V).

*/

#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

#define V 5

int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

int main()
{
    int no_edge; // number of edges
    int selected[V]; // selected edges
    memset(selected, false, sizeof(selected)); // initialize selected edges to false

    no_edge = 0; // initialize number of edges to 0

    // the number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in
    // graph

    // choose 0th vertex and make it true
    selected[0] = true;

    int x; //  row number
    int y; //  col number

    // print for edge and weight
    cout << "Edge"
         << " : "
         << "Weight";
    cout << endl;
    while (no_edge < V - 1)
    {
        /* For every vertex in the set S, find the all adjacent vertices
         , calculate the distance from the vertex selected at step 1.
         if the vertex is already in the set S, discard it otherwise
         choose another vertex nearest to selected vertex  at step 1.
         */
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    { // not in selected and there is an edge
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }

    return 0;
}
