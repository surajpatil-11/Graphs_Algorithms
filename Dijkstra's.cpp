// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define f(i,n) for(int (i)=0;(i)<(n);(i)++)
#define inf 100000000
#define fi first
#define se second
int n,src;
vector < pii > G[10000];

void sd(int src)
{
    vector <int> dist(n,inf);
    dist[src]=0;
    priority_queue <  pii , vector < pii > ,greater < pii > > pq;
    pq.push({0,src});
    while(! pq.empty()  )
    {
        pii temp=pq.top();
        pq.pop();
        int u=temp.se;
        f(i, G[u].size()  )
        {
            int v=G[u][i].fi;
            int wt=G[u][i].se;
            if(dist[v]>dist[u]+wt)
            {
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
            }

        }
    }
    f(i,n)
    {
        cout<<i<<" "<<dist[i]<<endl;

    }

}

/*
0 1 1
0 2 5
1 3 8
1 4 2
2 3 7
2 4 6
3 5 9
4 5 3
*/
int main()
{
    int m;
    cout<<"Enter number of nodes and edges"<<endl;
    cin>>n>>m;
    cout<<"enter u v wt"<<endl;
    cout<<"Indexing is 0 based"<<endl;
    int u,v,w;
    f(i,m)
    {
        cin>>u>>v>>w;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }
    cout<<"Enter source node \n";
    cin>>src;
    sd(src);


}
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7



*/
