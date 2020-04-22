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
const int MAXN=1e3+5;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int n,k;
void sang()
{
    int x = 0;
    int m = 0;
    for (int i=2; i<MAXN; i++)
    {
        if (a[i])
        {
            b[k++]=i;
            for (int j=2; j*i<=MAXN; j++)
            {
                m++;
                if (m==k)
                {
                    cout << i*j << endl;
                }
                a[i*j]=0;
            }

        }
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdou);
    while(cin>>n&&cin>>k)
    {
        FORE(i, 0,MAXN)a[i] = 1;
        sang();
    }



    return 0;
}
