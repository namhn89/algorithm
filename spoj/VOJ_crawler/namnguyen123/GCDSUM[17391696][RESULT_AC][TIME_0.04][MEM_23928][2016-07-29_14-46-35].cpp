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
const int MAXN = 1e6 + 5 ;
long long n,g[MAXN],gs[MAXN];
long mp[MAXN];
char ip[MAXN];

void GenP(){
	register long i,j;
	memset(mp,0,sizeof(mp));
	for(i=2;i<1003;i++){
		if(!ip[i]){
			for(j=i*2;j<MAXN;j+=i){
				ip[j]=1;
				if(!mp[j]) mp[j]=i;
			}
		}
	}
}

void GenG(){
	register long p,u,v,i;
	g[1]=gs[1]=1;
	for(i=2;i<MAXN;i++){
		if(!ip[i]) g[i]=(i<<1)-1;
		else{
			u=p=mp[i];
			v=1;
			while(!(i%u)) u*=p,v++;
			u/=p,v--;
			g[i]=g[i/u]*(u/p)*(v*(p-1)+p);
		}
		gs[i]=gs[i-1]+g[i];
	}
}

long gcd(int a,int b){
	if(!a || !b) return a+b;
	if(a>b) return gcd(b,a%b);
	return gcd(a,b%a);
}

long gcdsum(int N){
	long sum=0;
	for(int i=1;i< N;++i) for(int j=i+1;j<=N;++j) sum += gcd(i,j);
	return sum;
}

int main(){
	GenP();GenG();
	while(scanf("%lld",&n)==1){
		if(n==0) break;
		printf("%lld\n",gs[n]-(n*(n+1)>>1));
	}
	system("PAUSE");
}
