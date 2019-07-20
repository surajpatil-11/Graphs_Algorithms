#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define inf 1000000000
vector <pair<int,int> > G[100]; // Index of G is U ,first is V and second is weight .
int n , m ,dist[100];
bool flag; // true if negative cycle
void BMF(int src)
{
    for(int i=0;i<n;i++) dist[i] = inf ;
    dist[src] = 0 ;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            for( int k=0;k < G[j].size() ; k++ )
            {
                /*     wt
                   U ----> (V,W)
                   relax V
                */

                int u = j ;
                int v = G[j][k].first;
                int wt = G[j][k].second;
                if( dist[ u ] != inf and wt + dist[ u ] < dist[v] )
                dist[ v ] = min( dist[ v ] , wt + dist[ u ] ) ;
            }

        }
    }

    flag = false;
    // If the graph contain negative cycle then the path weight of the vertex in that cycle keep on decreasing .
    for(int i=0;i<n;i++)
    {
        for( int j=0;j<G[i].size();j++ )
        {
            int u = i ;
            int v = G[i][j].first ;
            int wt = G[i][j].second ;
            if( dist[v] > dist[u] + wt )
                flag = true ;
        }
    }


}

int main()
{
    cin >> n >> m ;
    // n -> no. of vertex
    // m -> no. of edges
    // 0 based indexing
    for( int i=0;i<m;i++ )
    {
        int u,v,wt;
        cin >> u >> v >> wt ;
        G[u].pb( { v , wt  }  );
    }
    BMF(0);
    if(flag) cout << "Contain negative cycle." << endl ;
    else
    {
        cout << "Vertex\tdistance" << endl ;
        for(int i=0;i<n;i++)
            cout << i << "\t" << dist[i] << endl ;
    }
    return 0 ;
}


/* do not have cycle

5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3

*/

/* contain cycle

4 4
0 1 5
1 2 -1
2 3 -2
3 1 -3


*/


