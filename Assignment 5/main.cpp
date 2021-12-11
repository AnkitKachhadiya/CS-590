#include <iostream>
#include "graph.h"

int main()
{
    Graph *g = new Graph(10);

    g->set_edge(0, 1, 1);
    g->set_edge(0, 2, 1);
    g->set_edge(0, 3, 1);
    g->set_edge(1, 2, 1);
    g->set_edge(1, 5, 1);
    g->set_edge(3, 4, 1);
    g->set_edge(3, 7, 1);
    g->set_edge(4, 6, 1);
    g->set_edge(5, 7, 1);
    g->set_edge(8, 9, 1);

    cout << "BFS output: " << endl;
    g->bfs(0);

    cout << endl;
    cout << "DFS output: " << endl;
    g->dfs();

    delete g;

    return 0;
}
