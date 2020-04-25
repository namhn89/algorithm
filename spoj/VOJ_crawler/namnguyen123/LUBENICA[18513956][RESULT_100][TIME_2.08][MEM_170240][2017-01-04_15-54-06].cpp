#include<bits/stdc++.h>
using namespace std;
int dad[1000001][33];
vector< pair<int , int> >g[100001];
int ma[100001][33];
int mi[100001][33];
int h[1000001];
int v = 0;
int logn;
const int INF = 1e9 + 9 ;
void dfs(int u ){
    for(int i = 0 ; i< g[u].size() ; ++i){
         v = g[u][i].first;
        if( v != dad[u][0] ){
            dad[v][0] = u;
            h[v] = h[u] + 1;
            mi[v][0] = g[u][i].second;
            ma[v][0] = g[u][i].second;
            dfs(v);
        }
    }
}
int lca(int u , int v){
    if( h[u] < h[v] )swap(u , v);
    int delta = h[u] - h[v];
    for(int i = 0 ; i<logn ; ++i){
        if( ( delta >> i )&1 )u = dad[u][i];
    }
    if( u == v )return u;
    for(int i = logn- 1 ; i>=0 ; --i ){
        if( dad[u][i] != dad[v][i] )u = dad[u][i] , v = dad[v][i];
    }
    return dad[u][0];
}
int mindis( int u , int v){
    if( h[u] < h[v] )swap( u , v);
    int delta = h[u] - h[v];
    int ans = INF;
    for(int i = 0 ; i< logn ; ++i){
        if( ( delta >> i)&1 )ans = min( ans , mi[u][i]) , u = dad[u][i];
    }
    return ans;
}

int maxdis( int u , int v){
    if( h[u] < h[v] )swap( u , v);
    int delta = h[u] - h[v];
    int ans = 0;
    for(int i = 0 ; i< logn ; ++i){
        if( ( delta >> i)&1 )ans = max( ans , ma[u][i]) , u = dad[u][i];
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i<=n-1 ; ++i){
        int x,y,l;
        scanf("%d%d%d",&x,&y,&l);
        g[x].push_back(make_pair(y, l ));
        g[y].push_back(make_pair(x, l));
    }
    logn = 0;
    for( ; (1 << logn) <=n ; ++logn)
    dad[1][0] = 1;
    dfs(1);
    for(int j = 1 ; j <logn ; ++j ){
        for(int i = 1 ; i <= n ; ++i){
            dad[i][j] = dad[dad[i][j-1]][j-1];
            mi[i][j] = min( mi[i][j-1] , mi[dad[i][j-1]][j-1]  );
            ma[i][j] = max( ma[i][j-1] , ma[dad[i][j-1]][j-1]  );
        }
    }
    int q;
    cin >> q;
    while(q--)
       {
        int u ,  v;
        cin >> u >> v;
        int d = lca(u , v);
        //cout<<u<<" "<<v<<" "<<d<<endl;
        cout<<min(mindis(u , d) , mindis(v , d))<<" "<<max(maxdis(u , d) , maxdis(v , d))<<endl;
    }


}
