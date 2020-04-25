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
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long,int> LLI;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=1e6+5;
int t[MAXN],p[MAXN];
ll f[MAXN];
int main()
{
  //  freopen("hire.inp","r",stdin);
  //  freopen("hire.out","w",stdout);
    int n;
    scanf("%d",&n);
    FORE(i, 1, n )
    {
        scanf("%d%d",&t[i],&p[i]);
    }
    priority_queue < LLI, vector<LLI>, greater<LLI> >q;
    f[1] = p[1];
    q.push( make_pair ( f[1], t[1] ) );
    FORE(i, 2, n )
    {
        while(!q.empty() && q.top().nd < i - 1)q.pop();
        f[i] = q.top().st + p[i];
        q.push(make_pair(f[i],t[i]));
    }
    while(!q.empty()&&q.top().nd < n )q.pop();
    ll ans = q.top().st;
    cout << ans << endl;
    
    return 0;
}
