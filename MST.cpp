#include <bits/stdc++.h>
using namespace std ;
#define int long long int
#define for(i,n) for(int (i)=0;(i)<(n) ;(i)++ )
int n,m,p[100001],r[100001] ;
struct edge
{
    int u,v,w ;
};

bool f(edge a,edge b) // comparator function
{
    return a.w < b.w ;
}

int fp(int a) // find_parent
{
    while( p[a] != a ) a = p[a] ;
    return a ;
}

void U(int a,int b) // Union
{
    int ac = a , bc = b ;
    a = fp(a) ;
    b = fp(b) ;
    if( r[a] > r[b] )
    {
        p[b] = a ;
        p[ac] = p[bc] = a ; // path compression
    }
    else if( r[a] < r[b] )
    {
        swap(a,b) ;
        p[b] = a ;
        p[ac] = p[bc] = a ;// path compression
    }
    else{
        p[b] = a ;
        p[ac] = p[bc] = a ; 
        r[a]++ ;

    }
}

bool ch(int a,int b) // are a and b in same group
{
    return fp(a) == fp(b) ;
}

signed main()
{
    cin >> n >> m ;
    int mc = m ;
    for(i,n+1) p[i]=i , r[i]=1 ;
    vector< edge  > ve ;

    while(m--)
    {
        int u,v,w ;
        cin >> u >> v >> w ;
        edge e ;
        e.u = u ;
        e.v = v ;
        e.w = w ;
        ve.push_back(e) ;
    }
    sort( ve.begin() , ve.end() , f ) ;
    int ans = 0 ;
    int c = 0 ;
    for(i,mc)
    {
        if( not ch( ve[i].u , ve[i].v ) )
        {
            ans += ve[i].w ;
            U( ve[i].u , ve[i].v ) ;
            c++ ;
            if(c == n-1) break ;
        }
    }
    cout << ans ;
    return 0 ;
}
// https://www.spoj.com/problems/MST/
