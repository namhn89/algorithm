using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 1;
int par[MAXN] ;
int findSet (int p) {
  if (par[p] == p) return par[p] ;
  else return par[p] = findSet(par[p]) ;
}
void join (int u , int v) {
   int x = findSet(u) , y = findSet(v) ;
   par[y] = x ;
}
int main()
{
#define TASK "IOIBIN"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int n ;
    scanf("%d",&n) ;
    for(int i = 1 ; i < MAXN ; ++i ) par[i] = i ;
    for(int i = 1 ; i <= n ; ++i ) {
        int u , v , type ;
        cin >> u >> v >> type ;
        if (type == 1) {
            join(u , v) ;
        }
        else {
            if (findSet(u) == findSet(v)) {
                cout << "1\n" ;
            }
            else {
                cout << "0\n" ;
          }
        }

    }
    return 0;
}
