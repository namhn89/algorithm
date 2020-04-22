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
typedef vector<int> VI ;
typedef vector<II> VII;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
int f[MAXN];
char x[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string s ;
bool check(int k)
{
    map<char,int>F;
    int ans = 0 ;
    FORE(i, k, k + 25)
    {
        F[s[i]]++;
    }
    FORE(i, 0, 25 )
    {
        if (F[x[i]] == 1 ) ans ++ ;
    }
    ans += (f[k+25] - f[k-1]);
    if (ans == 26) return true;
    else return false ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s ;
    int n = s.size();
    s = " " + s ;
    FORE(i, 1, n )
    {
        f[i] = f[i-1] ;
        if(s[i] == '?') f[i] = f[i] + 1 ;
    }
    //FORE(i, 1, n ) cout << f[i] << " ";
    if ( n < 26 )
    {
        cout << -1 << endl;
        return 0 ;
    }
    FORE(i, 1, n - 26 + 1 )
    {
        if(check(i))
        {
            map<char,int>T;
            FORE(j, 0, 25 )
            {
                T[x[j]] = 1 ;
            }
            FORE(j, i, i + 25 )
            {
                if (s[j] != '?')
                    T[s[j]] = 0 ;
            }
            FORE(j, i, i + 25 )
            {
                if (s[j] == '?')
                {
                    FORE(k, 0, 25)
                    {
                        if (T[x[k]] == 1)
                        {
                            T[x[k]] = 0 ;
                            s[j] = x[k] ;
                            break ;
                        }
                    }
                }
            }
            FORE(j , 1, n ) {
            if(s[j] == '?') cout << "A";
            else cout << s[j] ;
            }
            return 0 ;

        }
    }
    cout << -1 << endl;

    return 0;
}
