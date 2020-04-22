using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;

vector <int> g[MAXN] , idd[MAXN] ;
map < pair <int , int> , int > id ;
int n , m , k , dist[MAXN] ;
vector <string> ans ;
string res ;
void dfs (int u) {
    if (ans.size() == k) return ;
    if (u == n + 1) {
        ans.push_back(res) ;
        return ;
    }
    TR(idd[u] , it) {
        int v = *it ;
        res[v] = '1' ;
        dfs(u + 1) ;
        res[v] = '0' ;
    }
}
int main()
{
#define TASK "1005F"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    scanf("%d %d %d", &n , &m , &k) ;
    for(int i = 0 ; i < m ; ++i ) {
        int u , v ;
        scanf("%d %d", &u , &v) ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
        id[make_pair(u , v)] = i ;
        id[make_pair(v , u)] = i ;
    }
    memset(dist , -1 , sizeof(dist)) ;
    dist[1] = 0 ;
    queue <int> q ;
    q.push(1) ;
    while(!q.empty()) {
        int u = q.front() ;
        q.pop() ;
        TR(g[u] , it) {
           int v = *it ;
           if (dist[v] == -1) {
                dist[v] = dist[u] + 1 ;
                q.push(v) ;
           }
           if (dist[v] == dist[u] + 1) {
                idd[v].push_back(id[make_pair(u , v)]) ;
           }
        }
    }
   /*for(int i = 1 ; i <= n ; ++i ) {
        cout << i << " " << dist[i] << " " << idd[i].size() << endl;
    }*/
    for(int i = 0 ; i < m ; ++i ) res = res + '0' ;
    dfs(2) ;
    printf("%d\n" , ans.size()) ;
    for(int i = 0 ; i < ans.size() ; ++i ) {
       printf("%s\n" , ans[i].c_str()) ;
    }


    return 0;
}
