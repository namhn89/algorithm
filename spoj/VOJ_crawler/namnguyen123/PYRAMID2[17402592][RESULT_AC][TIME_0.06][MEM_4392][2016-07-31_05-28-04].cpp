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
const int MAXN = 1e6 + 5 ;
char s[MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int n ;
    cin >> n ;
    FORE(i , 1 , n ) cin >> s[i];
    int mo = 0 ,dong = 0, res = 0 ;
    FORD(i , n , 1 )
    {
        if (s[i] == '>')
        {
            if (mo > 0) dong++;
            if (dong > 0 ) res = max(mo + dong - 1, res);

        }
        else
        {
            mo++;
            if(dong > 0) dong--;
        }
        //cout << mo << " " << dong << endl;
    }
    cout << res << endl;

    return 0;
}
