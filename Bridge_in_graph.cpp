#include <bits/stdc++.h>
using namespace std ;
#define N 1001
#define endl '\n'
vector <int> G[N] ;
bool vis[N] ;
int n ,m ,tin[N],low[N],timer;

vector < pair <int,int> > bridge ;

bool comp( pair <int,int> a ,pair <int,int> b )
{
    if( a.first == b.first ) return a.second < b.second   ;
    return a.first < b.first ;

}


void dfs(int i,int p = 0 )
{
    vis[i] = true ;
    tin[i] = low[i] = timer++ ;
    for( int j=0 ; j < G[i].size() ; j++ )
    {
        if( G[i][j] != p )
        {
            if( vis[ G[i][j] ] == true )
            {
                low[i] = min( low[i] , tin[ G[i][j] ] ) ;
            }
            else
            {
                dfs( G[i][j] , i ) ;
                low[i] = min( low[i] , low[ G[i][j] ] ) ;
                if( low[ G[i][j] ] > tin[i] )
                bridge.push_back( { i , G[i][j]  } ) ;
            }
        }
    }
}

int main()
{
    int tt , tc = 1;
    cin >> tt ;
    while( tt-- )
    {
        cin >> n >> m ;
        timer = 0 ;
        bridge.clear() ;
        for( int i=1 ; i <= n ; i++ )
        {
            vis[i] = false ;
            G[i].clear() ;
        }
        while( m-- )
        {
            int u,v ;
            cin >> u >> v ;
            G[u].push_back(v) ;
            G[v].push_back(u) ;
        }

        for( int i=1 ; i <= n ; i++ )
        {
            if( vis[i] == false )
                dfs(i) ;
        }

        for( int i=0 ; i < bridge.size() ; i++ )
        {
            if( bridge[i].first > bridge[i].second )
                swap( bridge[i].first , bridge[i].second );
        }

        sort( bridge.begin() , bridge.end() , comp ) ;

        cout << "Caso #" << (tc++) << endl ;
        if( bridge.size() != 0 )
            cout << bridge.size() << endl ;
        else
            cout << "Sin bloqueos" << endl ;

        for( int i=0 ; i < bridge.size() ; i++ )
        {
            cout << bridge[i].first << " " << bridge[i].second << endl ;
        }
    }

    return 0 ;
}

// https://www.spoj.com/problems/EC_P/

