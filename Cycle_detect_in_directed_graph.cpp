#include <bits/stdc++.h>
using namespace std ;
#define N 1000
vector <int> G[N];
int n,m;
bool visited[N],inStack[N];
bool isCycle = false ;
void dfs(int i)
{
    visited[i] = true ;
    inStack[i] = true ;

    for( int j=0 ; j < G[i].size() ; j++ )
    {
        if( ( visited[ G[i][j] ] == true ) and ( inStack[ G[i][j] ] == true ) )
            isCycle = true ;

        if( visited[ G[i][j] ] == false )
        {
            dfs( G[i][j] ) ;
        }
    }

    inStack[i] = false ;
}


int main()
{
    cout << "Enter number of nodes and edges" << endl ;
    cin >> n >> m ;
    while(m--)
    {
        int u,v;
        cin >> u >> v ;
        G[u].push_back(v);
    }
    isCycle = false ;

    for(int i=1;i<=n;i++)
        if( visited[i] == false )
            dfs(i) ;

    if(isCycle) cout << "YES" << endl ;
    else cout << "NO" << endl ;


    return 0 ;
}
