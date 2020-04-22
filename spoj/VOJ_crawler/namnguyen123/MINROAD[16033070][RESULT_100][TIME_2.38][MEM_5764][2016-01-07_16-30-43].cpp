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
const int MOD=1e9+7;
const int INF=1e9;
const int MAXN=3e5+1;
pair<int, int> cay[MAXN];
int n, a, b;
vector<int> stung, struc;
int main()
{
    // freopen(".inp","r",stdin);
   //freopen(".out","w",stdout);
	cin>>n>>a>>b;
    int n1, n2;
    FOR(i, 1, n+1){
        cin>>n1>>n2;
        cay[i]=make_pair(n1, n2);
    }
    sort(cay+1, cay+n+1);
    stung.resize(n+2);
    struc.resize(n+2);
    FOR(i, 1, n+1){
        stung[i]=stung[i-1];
        struc[i]=struc[i-1];
        if(cay[i].second==1){
            stung[i]++;
        } else {
            struc[i]++;
        }
    }
    int res=INF;
    FOR(i, 1, n+1){
        int l=1;
        int r=i;
        int vt=-1;
        if(!(stung[i]-stung[l-1]>=a && struc[i]-struc[l-1]>=b)) continue;
        while(l<=r){
            int mid=(l+r)/2;
            if(stung[i] - stung[mid-1]>=a && struc[i]-struc[mid-1]>=b){
                vt=mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        if(vt!=-1){
            res=min(res, cay[i].st-cay[vt].st);
        }
    }
    if(res==INF){
        printf("-1");
    } else {
        printf("%d", res);
    }
	return 0;
}
