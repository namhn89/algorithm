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
const int MAXN = 1e5 + 100 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;

struct T
{
    int X, Y, Z;
    T (int X = 0, int Y = 0, int Z = 0) : X(X), Y(Y), Z(Z) {};
} a[MAXN];
int N;
map <II, II> f;
int max (int a, int b, int c, int d)
{
    return max (max(a, b), max(c, d));
}
bool maxi (int &a, int b, int c, int d)
{
    a = max(a, b, c, d);
}
bool maxi(int &a, int b)
{
    if (a < b) a = b;
    else return false;
    return true;
}
bool maxi(II &a, II b)
{
    a = max(a, b);
}
int min (int a, int b, int c)
{
    return min(a, min(b, c));
}
int main()
{

    scanf("%d", &N);
    pair <int, int> best;
    int res = 0;
    FORE (i, 1, N)
    {
        scanf("%d %d %d", &a[i].X, &a[i].Y, &a[i].Z);
        if (maxi(res, min(a[i].X, a[i].Y, a[i].Z)))
        {
            best = {i, 0};
        }
        if (f.find( {a[i].X, a[i].Y} ) != f.end())
        {
            if (maxi(res, min(a[i].X, a[i].Y, a[i].Z + f[ {a[i].X, a[i].Y} ].first)))
            {
                best = {i, f[ {a[i].X, a[i].Y} ].second};
            }
        }
        if (f.find( {a[i].X, a[i].Z} ) != f.end())
        {
            if (maxi(res, min(a[i].X, a[i].Z, a[i].Y + f[ {a[i].X, a[i].Z} ].first)))
            {
                best = {i, f[ {a[i].X, a[i].Z} ].second};
            }
        }
        if (f.find( {a[i].Y, a[i].Z} ) != f.end())
        {
            if (maxi(res, min(a[i].Y, a[i].Z, a[i].X + f[ {a[i].Y, a[i].Z} ].first)))
            {
                best = {i, f[ {a[i].Y, a[i].Z} ].second};
            }
        }
        maxi ( f[ {a[i].X, a[i].Y} ], {a[i].Z, i} );
        maxi ( f[ {a[i].Y, a[i].X} ], {a[i].Z, i} );

        maxi ( f[ {a[i].X, a[i].Z} ], {a[i].Y, i});
        maxi ( f[ {a[i].Z, a[i].X} ], {a[i].Y, i});

        maxi ( f[ {a[i].Y, a[i].Z} ], {a[i].X, i});
        maxi ( f[ {a[i].Z, a[i].Y} ], {a[i].X, i});
    }
    if (best.second == 0) cout << 1 << endl;
    else cout << 2 << endl;
    cout << best.first;
    if (best.second) cout << " " << best.second;
    return 0;
}