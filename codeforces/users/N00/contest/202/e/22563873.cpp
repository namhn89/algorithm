using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
int n , a[MAXN] ;
long long Left[MAXN] , Right[MAXN] , fL[MAXN] , fR[MAXN] ;
int main()
{
#define TASK "BRIDGES"
    // freopen(TASK".inp","Right",stdin);
   //  freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    FORE(i , 1 , n - 1) cin >> a[i];
    Left[1] = fL[1] = 0;
    FORE(i , 2 , n )
    {
        if(a[i - 1] >= 2)
        {
            Left[i] = max(Left[i - 1] , fL[i - 1]) + a[i - 1] + (a[i - 1] & 1 ) - 1 ;
            fL[i] = fL[i - 1] + a[i - 1] - (a[i - 1] & 1);
        }
        else Left[i] = max(Left[i - 1] , fL[i - 1]) + 1;
    }
    Right[n] = fR[n] = 0;
    FORD(i , n - 1 , 1 )
    {
        if(a[i] >= 2)
        {
            Right[i] = max(Right[i + 1], fR[i + 1]) + a[i] + (a[i] & 1) - 1 ;
            fR[i] = fR[i + 1] + a[i] - (a[i] & 1);
        }
        else Right[i] = max(Right[i + 1], fR[i + 1]) + 1;
    }
    long long res = 0 ;
    FORE(i , 1 , n )
    {
        res = max(res , max( Left[i] + fR[i] , Right[i] + fL[i] ) );
        res = max(res , fL[i] + fR[i] );
    }
    cout << res << endl;
    return 0;
}
