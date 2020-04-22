using namespace std;
#include <bits/stdc++.h>
#define for1(i,a,b) for(int i=a,_b=(b);i<_b;i++)
#define for2(i,a,b) for(int i=a,_b=(b);i<=_b;i++)
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
const int MAXN=1e5+1;
const int INF=1e9+9;
int f[28];
char a[28];
int main()
{
//freopen(".inp","r",stdin);
//freopen(".out","w",stdout);
string s;
cin>>s;
int n=s.size();
s=" "+s;
//cout<<n;
int dem=0;
int dem1=0;
int dem2=0;
for2(i,1,n-25){
    for2(j,i,i+25){
        if(s[j]=='?'){dem++;}
     else if(f[s[j]-'A'+1]==0 && s[j]!='?')f[s[j]-'A'+1]++,dem1++;
        else if(f[s[j]-'A'+1]>1 && s[j]!='?')break;
    }
    //cout<<dem<<dem1;
    if(dem1+dem==26){
        for2(i,1,26){
            if(f[i]==0)dem2++,a[dem2]=char(i+64);
        }
        //for2(i,1,dem2)cout<<a[i]<<endl;
        for2(k,i,i+25){
            if(s[k]=='?')s[k]=a[dem2],dem2--;
        }
        for2(i,1,n){
            if(s[i]=='?')cout<<"A";
            else cout<<s[i];
        }
        return 0;
    }
    else{
        dem1=dem2=dem=0;
        for2(i,1,27){
            f[i]=0;
        }
    }
}
cout<<-1;
}
