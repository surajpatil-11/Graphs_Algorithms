// https://www.hackerrank.com/topics/lowest-common-ancestor

#include <bits/stdc++.h>
using namespace std;

#define MAX_NODES 100005
#define MAX_LOG  40
int N;
//P[i][j] stores the 2^j th ancestor of node i
int P[MAX_NODES][MAX_LOG] , parent[MAX_NODES];
vector <int> G[MAX_NODES];
void preprocess(){
   //Every element in P[][] is -1 initially;
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; (1<<j) < N ; ++j){
            P[i][j] = -1;
        }
    }

    //The first ancestor(2^0 th ancestor)
    //for every node is parent[node]
    for(int i = 1 ; i <= N ; ++i){
        P[i][0] = parent[i] ;
    }

    for(int j = 1; (1<<j) < N ; ++j){
        for(int i = 0 ; i < N ; ++i){
            //If a node does not have a (2^(j-1))th ancestor
            //Then it does not have a (2^j)th ancestor
            //and hence P[i][j] should remain -1
            //Else the (2^j)th ancestor of node i
            //is the (2^(j-1))th ancestor of ((2^(j-1))th ancestor of node i)
            if(P[i][j-1] != -1){
                P[i][j] = P[ P[i][j-1] ][j-1] ;
            }
        }
    }
}

int log2(int i)
{
    return log(i)/log(2);
}
// Stores the Level of each node
int level[MAX_NODES];
void Level_finder(int node,int lev)
{
   // if(G[node].size()==0) return ;
    level[node]=lev;

    for(int i=0;i<G[node].size();i++)
    {
        //SINCE IT IS A TREE NO NEED TO KEEP TRACK OF VISITED NODE OR NOT
        Level_finder( G[node][i] , lev+1 );
    }

}


int LCA(int u , int v){
    if(level[u] < level[v]){
        swap(u,v) ;
    }



    //u is the node at a greater depth/lower level
    //So we have to raise u to be at the same
    //level as v.
    int dist = level[u] - level[v] ;
    while(dist > 0){
        int raise_by = log2(dist);
        u = P[u][raise_by];
        dist -= (1<<raise_by) ;
    }

    if(u == v){
        return u ;
    }

    //Now we keep raising the two nodes by equal amount
    //Untill each node has been raised uptill its (k-1)th ancestor
    //Such that the (k)th ancestor is the lca.
    //So to get the lca we just return the parent of (k-1)th ancestor
    //of each node

    for(int j = MAX_LOG -1; j >= 0 ; --j){
        //Checking P[u][j] != P[v][j] because if P[u][j] == P[v][j]
        //P[u][j] would be the Lth ancestor such that (L >= k)
        //where kth ancestor is the LCA
        //But we want the (k-1)th ancestor.
        if((P[u][j] != -1) and (P[u][j] != P[v][j])){
            u = P[u][j] ;
            v = P[v][j] ;
        }
    }
    return parent[u] ; //or parent[v]
}

int main()
{
    cout<<"Enter no.of nodes \n";

    cin>>N;

    for(int i=0;i<N;i++)
        parent[i]=0;
    // INDEX OF NODE START FROM 0 to N-1 //

    cout<<"Enter "<<N-1<<" edges \n";
    for(int i=0;i<N-1;i++)
    {
        int u,v;
        cin>>u>>v;
        parent[v]=u;
        G[u].push_back(v);

    }
    preprocess();
    for(int i=0;i<N;i++)
    {
        cout<<i<<" "<<"|"<<" ";
        for(int j=0;(1<<j)<N;j++)
        {
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
    // FINDING LEVELS OF EACH NODES
    int root=0;
    //ASSUMING ROOT TO BE 0

    Level_finder(root,0 );


    for(int i=0;i<N;i++)
    {
        cout<<i<<" "<<level[i]<<endl;
    }


    int Q;
    cout<<"Enter no. of query \n";
    cin >> Q;
    cout<<"Enter queries in form u  v\n";
    while(Q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<LCA(u,v)<<endl;
    }

    //cout<<LCA(9,12);

    return 0;
}


/*
https://www.spoj.com/problems/QTREE2/
14
0 1
0 5
1 2
1 4
5 6
5 7
2 3
6 8
6 9
7 10
3 11
8 12
8 13

*/

