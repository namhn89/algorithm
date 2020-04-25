using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
long long pow_mod(long long a,long long b,long long p)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}

long long solve(long long a,long long p)
{
    long long q=p-1,s=0;
    while(q%2==0)
    {
        s++;
        q>>=1;
    }
    if(s==1)return pow_mod(a,(p+1)/4,p);
    long long z;
    while(1)
    {
        z = 1 + rand()%(p - 1);
        if(pow_mod(z, (p - 1)/2,p) != 1) break;
    }
    long long c = pow_mod(z, q, p);
    long long r = pow_mod(a, (q + 1)/2, p);
    long long t = pow_mod(a, q, p);
    long long m = s, b,i;
    while(1)
    {
        if(t%p==1)break;
        for(i=1; i<m; i++)if(pow_mod(t,1<<i,p)==1)break;
        b=pow_mod(c,1<<(m-i-1),p);
        r=(r*b)%p;
        c=(b*b)%p;
        t=(t*c)%p;
        m=i;
    }
    return r;
}

int main()
{
    long long a,p,i;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&p);
        if(p==2)
        {
            if(a%p==1)printf("1\n");
            else printf("Khong co\n");
            continue;
        }
        if(pow_mod(a, (p-1)/2,p) != 1)
        {
            puts("Khong co");
            continue;
        }
        i=solve(a,p);
        if(p-i==i)printf("%lld\n",i);
        else printf("%lld %lld\n",min(i,p-i),max(i,p-i));
    }
    return 0;
}
