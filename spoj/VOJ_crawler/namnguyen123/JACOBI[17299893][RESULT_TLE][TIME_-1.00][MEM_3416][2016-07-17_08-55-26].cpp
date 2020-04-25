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
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
ll pow(ll b, ll p, ll m)
{
    if (!p)
        return 1;
    if (p == 1)
        return b % m;
    ll ret = pow(b, p >> 1, m);
    ret = (ret * ret) % m;
    if (p & 1)
        ret = (ret * b) % m;
    return ret % m;
}
ll legendre(ll n, ll p)
{
    if(n % p == 0) return 1;
    else
    {
        ll r = pow(n, (p-1)/2, p);
        if (r == 1 ) return 1 ;
        else return 0 ;
    }
}
ll SqMod(ll n, ll p)
{
    if(p == 2) return 1 ;
    ll q = (p + 1)/2;
    if(p%4 == 3)
    {
        return pow(n, q/2, p );
    }
    else
    {
        ll s = 1;
        n--;
        while(legendre(n,p) == 1)
        {
            s++;
            n = (n - 2*s + 1) % p;
            if(n == 0)
            {
                return s;
            }
        }
        q/=2;
        ll v = 1, r = s, u = 1;
        while(q>0)
        {
            ll x = ( r * r - n * u * u )% p;
            if(x < 0) x += p;
            u = (2*r*u)%p;
            r = x ;
            if(q & 1)
            {
                x = (s * r - n * v *u )% p;
                if( x < 0 ) x += p;
                v = (v * r + s * u) %p;
                s = x;
            }
            q >>= 1;
        }
        return s;
    }
}
int main()
{
     freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ll a,n ;
    int K ;
    scanf("%d",&K);
    while(K--)
    {
        scanf("%lld %lld ", &a,&n );
        a%=n;
        ll r = SqMod(a,n);
        if (n == 2)
        {
            cout << a << endl;
        }
        else if (r * r % n == a )
        {
            if (n - r > r )
            {
                cout << r << " " << n - r << endl;
            }
            else
            {
                cout << n - r << " " << r  << endl;

            }
        }
        else
        {
            cout << "Khong co " << endl;
        }
    }

    return 0;
}
