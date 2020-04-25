using namespace std;
#include<bits/stdc++.h>
#define op freopen("in.inp","r",stdin);freopen("in.out","w",stdout);
#define FOR(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FOD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define st first
#define nd second
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;

const int INF=1e9+7;
const int MOD=1e9+7;
const int MAXN=2e5+2;

ll max(ll a ,ll b){return(a<b)?b:a;}
ll min(ll a,ll b){return(a>b)?b:a;}

ll P10[MAXN];
int a[MAXN];
char s[MAXN];
int n;

ll pow(int a,int n){
    if(n==1)return a;
    ll k = pow(a,n/2);
    k=1ll*(k)*(k)%MOD;
    if(n%2)return (k*a)%MOD;
    return k;
}

int main(){
    scanf("%s",&s);
    int n=strlen(s);
    FOR(i,1,n)a[i] = s[i-1] - '0';
    P10[0] = 1;
    FOR(i,1,n)P10[i] = 1ll * (P10[i-1] * 10) % MOD;
    ll T = pow(9, MOD - 2);
    ll ans = 0;
    FOR(i,1,n){
        ans += (1ll * i*(P10[n-i+1] - 1) % MOD) * ((T*a[i]) % MOD) % MOD;
        ans %= MOD;
    }
    cout<<ans;
    return 0;
}
