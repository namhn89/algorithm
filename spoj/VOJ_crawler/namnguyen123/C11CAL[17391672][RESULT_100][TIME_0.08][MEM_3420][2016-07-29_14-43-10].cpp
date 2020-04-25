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
const ll MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long fastpow(long long a, int n){
	long long r = 1;
	while(n>0){
		if(n&1) r=(r*a)%MOD;
		a=(a*a)%MOD;
		n>>=1;
	}
	return r;
}

template<typename T>
T exgcd(T a,T b, T& x, T& y){
	if(!a||!b) {x=y=1; return a+b;}
	else{
		T r = exgcd(b, a%b, x, y);
		//r = b * x' + (a-(a/b)*b) * y' = a * y' + b * (x'-(a/b) * y)
		T x2 = x;
		x = y;
		y = (((x2 - (a/b)*y) % MOD)+MOD)%MOD;
		return r;
	}
}

template<typename T>
T invmod(T x){
	T a,b;
	T r = exgcd(((x%MOD)+MOD)%MOD, MOD, a, b);
	if(r!=1){
		fprintf(stderr, "Cannot calculate invmod for %lld (%lld)\n",x,((x%MOD)+MOD)%MOD);
		exit(-1);
	}
	return (a+MOD)%MOD;
}

/**
* Solve Ax = B (mod p)
**/
template<typename T>
vector<T> GaussElim(int n, vector<vector<T> > A, vector<T> B){
	//STEP 1 - triangleize A
	for(int i=0;i<n;i++){
		//ensure A[i][i]!=0
		for(int j=i;j<n;j++) if(A[i][j]) {swap(A[i],A[j]), swap(B[i],B[j]);break;}
		if(A[i][i]==0){
			fprintf(stderr, "Gauss failed\n");
			exit(-1);
		}
		//eliminate all A[j][i], j>i
		for(int j=i+1;j<n;j++){
			// row(j) = row(j) * A[i][i] / A[j][i] - row(i)
			T fact = A[i][i] * invmod(A[j][i]);
			for(int k=i;k<n;k++) A[j][k] = ((A[j][k] * fact - A[i][k]) % MOD+MOD)%MOD;
			B[j] = (B[j] * fact - B[i]) % MOD;
		}
	};
	//STEP 2 - solve for X
	vector<T> X(n);
	for(int i=n-1;i>=0;i--){
		T s = B[i];
		for(int j=n-1;j>i;j--) s=(s-A[i][j]*X[j]) % MOD;
		X[i] = ((s * invmod(A[i][i])) % MOD + MOD) % MOD;
	}
	return X;
}

int main(int argc, char *argv[]) {
	vector<vector<long long> > A(54,vector<long long>(54));
	vector<long long> B(54);
	vector<vector<long long> > Xs(51);
	for(int k=1;k<=50;k++){
		for(int x=0,xx=1;x<k+2;x++,xx++){
			//equation #x: a+b*xx^1+c*xx^2+... = (1^k+2^k+...+xx^k)
			for(int i=0;i<k+2;i++) A[x][i] = fastpow(xx, i);
			B[x] = 0;
			for(int i=1;i<=xx;i++) B[x] = (B[x] + fastpow(i, k)) % MOD;
		}
		Xs[k] = GaussElim(k+2, A, B);
	}
	long long N; int k;
	while(scanf("%lld%d",&N,&k)==2){
		long long r=0;
		for(int i=0;i<k+2;i++) r=(r+Xs[k][i]*fastpow(N, i))%MOD;
		printf("%lld\n",r);
	}
	return 0;
}
