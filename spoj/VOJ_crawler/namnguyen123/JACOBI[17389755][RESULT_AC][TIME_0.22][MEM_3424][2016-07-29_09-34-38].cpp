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
inline ll pow(ll b, ll p, ll m)
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
inline ll legendre(ll n, ll p)
{
    if(n % p == 0) return 1;
    else
    {
        ll r = pow(n, (p-1)/2, p);
        if (r == 1 ) return 1 ;
        else return 0 ;
    }
}
inline ll SqMod(ll n, ll p)
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
        while(q > 0)
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
long long int read_int(long long &a){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		a = ret;
	else
		a = -ret;
}
int main()
{
     //freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ll a,n ;
    ll K ;
    read_int(K);
    while(K--)
    {
        read_int(a);
        read_int(n);
        a%=n;
        ll r = SqMod(a,n);
        if (n == 2)
        {
            printf("%lld\n",a);
        }
        else if (r * r % n == a )
        {
            if (n - r > r )
            {
               // cout << r << " " << n - r << endl;
                printf("%lld %lld\n", r , n - r  );
            }
            else
            {
                //cout << n - r << " " << r  << endl;
                printf("%lld %lld\n",n - r , r );
            }
        }
        else
        {
            cout << "Khong co " << endl;
        }
    }

    return 0;
}
