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
int a[MAXN] ;
int n, k ;
deque < int >  dq ;
int main()
{
    //  freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T ;
    cin >> T ;
    while(T--)
    {
        cin >> n >> k ;
        FORE(i, 1, n ) cin >> a[i] ;
        dq.clear();
        FORE(i , 1 , k )
        {
            while(!dq.empty() && a[i] < a[dq.back()] )dq.pop_back();
            dq.push_back(i);
        }
        cout << a[dq.front()] << " ";
        FORE(i , k + 1 , n)
        {
            while(!dq.empty() && dq.front() <= i - k )dq.pop_front();
            while(!dq.empty() && a[i] < a[dq.back()] )dq.pop_back();
            dq.push_back(i);
            cout << a[dq.front()] << " ";
        }
        cout << endl;
    }



    return 0;
}
