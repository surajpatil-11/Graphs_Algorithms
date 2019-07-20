//REF: GEEKSFORGEEKS
#include <bits/stdc++.h>
using namespace std;
#define N 100005
vector <int> G[N],T[N];
vector <bool> visited(N,false);
stack <int> st;
int n;

void dfs(int i)
{
    visited[i]=true;
  //  cout<<i<<" ";
    for(int j=0;j<G[i].size();j++)
    {
        if(visited[ G[i][j] ] == false)
        {
            dfs( G[i][j] );
        }
    }
    st.push(i);

}

void dfs2(int i)
{
    cout<<i<<" ";
    visited[i]=true;
    for(int j=0;j<T[i].size();j++ )
    {
        if(visited[T[i][j]] == false )
        {
            dfs2( T[i][j] );
        }
    }
}

void SCC()
{
    // STEP 1) DO DFS ON GRAPH TO FILL STACK // FOR MORE CLEARITY WATCH GEEKSFORGEEKS ALGO
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            dfs(i);
        }
    }

    // STEP 2 IS TO FIND TRANSPOSE WHICH WE HAVE ALREADY FOUND

    // T IS THE TRANSPOSE OF GRAPH

    // STEP 3 PULL OUT NODES FROM STACK AND DO DFS AGAIN

    // SET ALL NODES TO UNVISITED

    for(int i=0;i<n;i++) visited[i]=false;

    // NOW POP OUT ELEMENTS FROM STACK AND DO DFS ON TRANSPOSE OF GRAPH

    while(! st.empty() )
    {
        int u=st.top();
        st.pop();
        if(visited[u] == false )
        {
            dfs2(u);
            cout<<endl;
        }
    }
}


int main()
{
    int m;
    cout<<"ENTER NUMBER OF NODE AND NO. OF EDGE \n";
    cin>>n>>m;
    cout<<"ENTER U V REPRESENTING U-->V ZERO BASED INDEX \n";
    while(m--)
    {
        int u,v;
        cin>>u>>v; // ZERO BASED INDEX
        G[u].push_back(v);
        T[v].push_back(u); // TRANSPOSE OF GRAPH
    }
    cout<<"STRONGLY CONNECTED COMPONENTS ARE \n";
    SCC();

    return 0;
}

/*
12 17
0 1
1 4
1 3
3 1
1 2
2 5
5 2
3 6
5 7
6 7
7 9
9 10
10 11
11 8
8 6
6 11
7 11

*/
/*



*/


