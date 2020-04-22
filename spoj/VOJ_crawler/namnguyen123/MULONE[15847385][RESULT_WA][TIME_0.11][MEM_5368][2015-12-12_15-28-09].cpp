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
const int MAXN=2e6+3;
char a[MAXN];
int main()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    int t,n,k;
    cin>>t;
    while(t--)
    {
        k=0;
        cin>>n;
        FOR(i,1,2*n)
        {
            if (i <= n)
                k += i;
            else
                k += 2*n-i;
            a[2*n-i] = k % 10 + 48;
            k /= 10;
        }
        FOR(i,1,2*n)printf("%c",a[i]);
        printf("%\n");
    }
    return 0;
}
