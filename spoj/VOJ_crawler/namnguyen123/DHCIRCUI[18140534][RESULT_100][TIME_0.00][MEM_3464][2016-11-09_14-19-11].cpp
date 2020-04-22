using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define TASK test

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
typedef vector< VI> VVI;

inline void read (int &x)
{
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-')
    {
        neg = 1;
        c = getchar();
    }
    for(; c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}

const int MOD = 1e9 + 7 ;
const int MAXN = 20 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
vector <int> F[MAXN] ;
int cnt[MAXN] ;
int T[20] = {0,1,3,7,15,35,77,179,429,1039,2525,6235,15463,38513,96231,241519,607339,1529533,3857447};
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    cout << T[n] << endl;
    /* F[1].push_back(60);
     FORE(i, 2, 5)
     {
         int n = i ;
         set <int> S ;
         FORE(j , 1 , n )
         {
             FORE(k , 1, n )
             {
                 if (j + k == n )
                 {
                     FOR(x, 0, F[j].size())
                     {
                         FOR(y, 0, F[k].size())
                         {
                             int next = F[j][x] + F[k][y] ;
                             int para = (F[j][x] * F[k][y])/(F[j][x] + F[k][y]);
                             // cout << next << " " << para << endl;
                             S.insert(next);
                             S.insert(para);
                         }
                     }
                 }
             }
         }
          cout << n << ": ";
         for (set <int> :: iterator value = S.begin(); value != S.end(); value++)
         {
               cout << *value << " ";
             F[n].push_back(*value);
         }
          cout << endl;
     }
     //cout << F[5].size() ;
     FORE(i, 1, 18 ) cnt[i] = F[i].size() ;
     FORE(i, 1, 18 ) cnt[i] += cnt[i - 1];
    // FORE(i, 1, 18 ) cout << cnt[i] << ",";
     */
    return 0;
}
