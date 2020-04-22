#include <stdlib.h>
#include <stdio.h>

/*
  SuperSum(0,n)=n
  SuperSum(k,n)=Xichma(SuperSum(k-1,i),i,1,n)=n/1
  : SuperSum(1,n)=n(n+1)/2
  : SuperSum(2,n)=Xichma(i(i+1)/2,i,1,n)=n(n+1)(n+2)/6
  : SuperSum(3,n)=Xichma(i(i+1)(i+2)/6,i,1,n)=n(n+1)(n+2)/24
  ...
  SuperSum(k,n)=n(n+1)(n+2)...(n+k-1)/(k+1)!
*/


const long MOD=1000000007;//la so nguyen to

// x>=y
long exgcd(long x, long y, long& a, long& b){
	if(y==0){
		a=1;b=0;
		return x;
	}else{
		long r=exgcd(y,x%y,a,b);
		/*
		r=a*y+b*(x-y[x/y])
		 =ay+bx-by*[x/y]
		 =bx+(a-b*[x/y])y
		*/
		long t=a;a=b;b=t-x/y*b;
		return r;
	}
}

long SuperSum(int k, long n/*MAX=1 000 000 000*/){
	long long r;
	long i,a,b;
	r=1;
	for(i=0;i<=k;i++){
		//r=r*(n+k)
		r=r*(n+i)%MOD;
		//r=r/(k+1)
		if(r%(i+1)==0) r/=i+1;
		else{
			exgcd(i+1,MOD,a,b);
			//1=a*(k+1)+b*MOD
			//==> a*(k+1) % MOD = 1
			a=(((a%MOD)+MOD)%MOD);
			r=r*a%MOD;
		}
	}
	return r;
}

int main(){
	char s[22];
	int k; long n;
	while(scanf("%s",s)==1){
		if(s[0]!='[') continue;
		if(s[1]=='E') break;
		scanf("%d%ld",&k,&n);
		printf("%ld\n",SuperSum(k,n));
	}
}
