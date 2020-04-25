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
const int MAXN=3e5+5;
vector <int> g[10];
char c[MAXN];
bool f[MAXN];
int a[MAXN],b[MAXN];
int dao (int n)
{
    int k[10];
    int x =0;
    int sum = 0;
    while(n)
    {
        x++;
        k[x] = n%10;
        n/=10;

    }
    FORE(i, 1, x) sum = sum *10 + k[i];
    return sum ;
}
void sang()
{
    int k=0;
    for (int i=2; i<MAXN; i++)
    {
        if (a[i])
        {
            k++;
            b[k]=i;
            for (int j=2; j*i<=MAXN; j++)
                a[i*j]=0;
        }
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    memset(a,1,sizeof a);
    int n,k;
    scanf("%d%d",&n,&k);
    sang();
    int z = 0;
    FORE(i, 1, n)
    {
        b[i] = dao(b[i]);
        while(b[i])
        {
            z++;
            c[z] = b[i]%10;
            b[i]/=10;
        }
    }
    FORE(i, 1, z)
    {
        g[0].push_back(c[i]);
    }
   // FOR(i , 0 , g[0].size()) cout << g[0][i] ;
  //  cout << endl;
    FORE(i, 1, 10)
    {
        memset(f,true,sizeof (f));
        FOR(j , 0 , g[i-1].size())
        {
            if (k==0)break;
            if(g[i-1][j]==(i-1))
            {
                k--;
                f[j] = false;

            }

        }
        FOR(j , 0 , g[i-1].size())
        {
            if(f[j])
            {
                g[i].push_back(g[i-1][j]);

            }
        }
    }
    FOR(i , 0 , g[10].size() )cout << g[10][i];
    //cout << endl;
    return 0;
}
