#include <bits/stdc++.h>
using namespace std;
vector <int> G[100];
vector <int> dfs ;
bool visited[100] ;
int n,m ;
void DFS(int i)
{
    visited[i] = true ;
    dfs.push_back(i);
    for(int j=0;j<G[i].size();j++)
    {
        if( visited[ G[i][j]  ] == false )
            DFS( G[i][j] );
    }
}

void DFS_UNTILL()
{
    memset( visited , false , sizeof visited ) ;
    for(int i=0;i<n;i++)
        if( visited[i] == false )
            DFS(i);
    for(int i=0;i<n;i++) cout << dfs[i] << " " ;
}

int main()
{
   // int n ,m ;
    cin >> n >> m ;
    while(m--)
    {
        int u,v;
        cin >> u >> v ;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS_UNTILL();
    return 0 ;
}
/*
9 12
0 1
0 2
1 2
1 3
2 4
2 5
2 6
3 6
4 8
5 8
6 8
8 7


*/



