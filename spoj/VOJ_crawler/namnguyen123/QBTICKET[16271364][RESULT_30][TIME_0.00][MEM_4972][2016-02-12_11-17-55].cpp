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
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=1e5+100;
const int INF =1e16+1;
ll L1,L2,L3,C1,C2,C3;
ll n,s,f,a[MAXN];
ll F[MAXN];
void Init()
{
	ios_base::sync_with_stdio(false);
	cin>>L1>>L2>>L3>>C1>>C2>>C3;
	cin>>n;
	cin>>s>>f;
	a[1]=0;
	for(int i=2;i<=n;i++) cin>>a[i];
}

void Solve()
{
	for(ll i=s+1;i<=f;i++)
	{
		F[i]=INF;
		for(ll j=i-1;j>=s;j--)
		{
			if(a[i]-a[j]>L3) break;
			if(a[i]-a[j]>L2)
				F[i]=min(F[i],F[j]+C3);
			else
				if(a[i]-a[j]>L1)
					F[i]=min(F[i],F[j]+C2);
				else
					F[i]=min(F[i],F[j]+C1);
		}
	}
	cout<<F[f];
}

int main()
{
	Init();
	Solve();
}
