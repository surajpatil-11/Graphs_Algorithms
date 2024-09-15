//Detect cycle in directed graph

/**
Ref: https://cp-algorithms.com/graph/finding-cycle.html
Algorithm
We will run a series of DFS in the graph. Initially all vertices are colored white (0). 
From each unvisited (white) vertex, start the DFS, mark it gray (1) while entering 
and mark it black (2) on exit. If DFS moves to a gray vertex, 
then we have found a cycle (if the graph is undirected, the edge to parent is not considered). 
The cycle itself can be reconstructed using parent array.

Problem: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<int> state(100, 0);
bool hasCycle = false;
// state = 0, node not visited
// state = 1, node is visited but not exited yet from DFS
// state = 2, node is visited and also exited from DFS

void dfs(int u) {
    if (state[u] == 1) {
        hasCycle = true;
        return;
    }
    state[u] = 1 ;
    for(int v : graph[u]){
        if(state[v] != 2)
            dfs(v);
    }
    state[u] = 2 ;
}

void dfs_untill(int nodes) {
    for(int i=0;i<nodes;i++){
        if(state[i] == 0){
            dfs(i);
        }
    }
}

int main()
{
    // n = node count, m = edge count
    int nodes, edges ;
    cin >> nodes >> edges ;
    for(int i = 1 ; i <= edges ; i++ ){
        int u, v ;
        cin >> u >> v ;
        graph[u].push_back(v);
    }
    dfs_untill(nodes);
    if (hasCycle) {
        cout << "Graph has cycle" << endl ;
    }
    else {
        cout << "Graph does not have cycle" << endl ;
    }
    
    return 0;
}

/**
Input:
4 6
0 1
0 2
1 2
2 0
2 3
3 3

Output: Graph has cycle

**/
