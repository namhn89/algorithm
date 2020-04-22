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
bool isqrt(long long x)
{
	int t=x%16;
	if(t!=0 && t!=1 && t!=4 && t!=9) return false;
    long long b, y = 0, m = 0x4000000000000000ll,ox=x;
	//0,1,4,9,
    while (m != 0)
    {
        b = y | m;
        y = y >> 1;
        if (x >= b)
        {
            x = x - b;
            y = y | m;
        }
        m = m >> 2;
    }
    return y*y==ox;
}

long long nsqrt(long long x)
{
	int t=x%16;
	if(t!=0 && t!=1 && t!=4 && t!=9) return false;
    long long b, y = 0, m = 0x4000000000000000ll,ox=x;
	//0,1,4,9,
    while (m != 0)
    {
        b = y | m;
        y = y >> 1;
        if (x >= b)
        {
            x = x - b;
            y = y | m;
        }
        m = m >> 2;
    }
    return y;
}

set<long> rs;
/*So luong nghiem nguyen cua phuong trinh c=m^2+n^2, m>n>0*/
long getTotal(long c, long k){
	long n=0;
	for(long i=1;2*i*i<c;i++){
		long sq=nsqrt(c-i*i);
		if(sq*sq+i*i==c){
			if(rs.find(2*k*i*sq)!=rs.end()) continue;
			rs.insert(2*k*i*sq);
			rs.insert(k*(sq*sq-i*i));
			n++;
		}
	}
	return n;
}

long check(long c){
	long n=0;
	for(long i=0;i*i<=c;i++){
		long sq=nsqrt(c-i*i);
		if(sq*sq+i*i==c){
			printf("%ld=%ld^2+%ld^2\n",c,i,sq);
			n++;
		}
	}
	return n*4-4;
}

int main(){
	long long a,b,c;

	while(1==scanf("%lld",&c)){
		long n=0;
		rs.clear();
		for(long i=1;i*i<=c;i++){
			if(c%i==0){
				n+=getTotal(i,c/i);
				if(i*i!=c) n+=getTotal(c/i,i);
			}
		}
		//printf("%ld  %ld\n",n*8+4,check(c*c));
		printf("%ld\n",n*8+4);
	}
	system("PAUSE");
}
