using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const ll INF=1e9+7;
const int MAXN=1e5+1;
int n, k;
int a[MAXN], f[2][50];
int main(){
  //freopen(".inp","r",stdin);
  //freopen(".out","w",stdout);
  scanf("%d %d", &n, &k);
   FOR(i, 0, n) scanf("%d", a+i);

   memset(f, 0, sizeof f);
   int last = 0, next = 1;
   f[next][0] = 1;
   FOR(i, 0, n){
      swap(next, last);
      FOR(r, 0, k) f[next][r] = f[last][r];
      FOR(r, 0, k) if(f[last][r])
         f[next][(r+a[i]) % k] = f[last][r]+1;
   }

   printf("%d\n", f[next][0]-1);
   return 0;

return 0;
}
