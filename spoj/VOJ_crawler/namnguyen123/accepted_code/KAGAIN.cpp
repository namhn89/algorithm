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
const int MAXN=1e5+1;
int     q,n,a[35000],l[35000],r[35000],res,L,R;
int main()
{
    // freopen("test.inp","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d",&q);
    while (q--)
   {
        scanf("%d",&n);
        FORE(i,1,n) scanf("%d",&a[i]);
        FORE(i,1,n)
        {
            l[i] = i;
            while (a[l[i]-1] >= a[i]) l[i] = l[l[i]-1];
        }
        FORD(i,n,1)
        {
            r[i] = i;
            while (a[r[i]+1] >= a[i]) r[i] = r[r[i]+1];
        }
        res = 0;
        FORE(i,1,n)
        {
           // cout<<a[i]<<" "<<l[i]<<" "<<r[i]<<endl;
            if (res < a[i]*(r[i]-l[i]+1))
            {
                res = a[i]*(r[i]-l[i]+1);
                L = l[i];
                R = r[i];
            }
        }
            printf("%d %d %d\n",res,L,R);

    }
    return 0;
}
