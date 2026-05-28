/**
 * Author:
 * Date:
 * License:
 * Source:
 * Description: Checks whether a graph is bipartite using DFS by coloring each node
 * with two colors (1 and 2). If any conflict arises, an odd cycle exists, and the
 * graph is not bipartite.
 * Usage:
 *  Run dfs(startNode, 1) for every unvisited component. If flag becomes true,
 *  the graph is not bipartite.
 * Time: O(N + M) where N = nodes, M = edges
 * Memory: O(N + M)
 */
#pragma once

const int N = 200020;
vector<int> edge[200010];
int col[N];
bool flag = 0;
// colour korbo 1 or 2 diye....
void dfs(int u, int c)
{
    if (col[u]) // aghe jodi colour kora takhe...
    {
        if (col[u] != c) // colour ta jodi kankito colour na hoi...
        {
            flag = 1; // odd length er cycle exist kore && graph colour kora jabe na(!BIPARTITE).
            return;
        }
        return;
    }
    col[u] = c;
    for (int v : edge[u])
    {
        dfs(v, 3 - c); //(colour jodi 1 hoi amra er adjacent gula(3 - 1) == 2 diye colour korbo)...
    } //(colour jodi 2 hoi amra er adjacent gula (3 - 2) == 1 diye colour korbo)...
}
