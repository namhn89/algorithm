using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int oo = 1e9 + 10 ;
int n ;
int Prime_Divisor [9] ;
int Prime_Count = 0 ;
int calc (int cur, vector <long long> &a, vector <long long> &tree, int rootChildren_Num, int rootChildren_Sum )
{
    if ( cur == a.size() ) return rootChildren_Sum + (rootChildren_Num > 1) + a.size() - Prime_Count ;
    int best = oo ;
    for(int i = 0 ; i < tree.size() ; ++i )
        if (tree[i] % a[cur] == 0)
        {
            tree[i] /= a[cur] ;
            tree.push_back(a[cur]) ;
            best = min( best, calc (cur + 1 , a , tree , rootChildren_Num + (i == 0) , rootChildren_Sum + (i == 0 ? Prime_Divisor[cur] : 0 ) ) ) ;
            tree[i] *= a[cur] ;
            tree.pop_back();
        }
    return best ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n ;
    vector <long long> a(n) ;
    for(int i = 0 ; i < n ; ++i) cin >> a[i] ;
    sort(a.begin(), a.end(), greater <long long>() );
    for(int i = 0 ; i < n ; ++i)
    {
        long long x = a[i] ;
        for(long long j = 2 ; j * j <= x ; ++j )
        {
            while(x % j == 0 )
            {
                x /= j ;
                Prime_Divisor[i]++;
            }
        }
        if (x > 1 ) Prime_Divisor[i]++;
        if (Prime_Divisor[i] == 1) Prime_Count ++;
    }
    vector <long long> tree ;
    tree.push_back(0) ;
    cout << calc( 0, a, tree, 0, 0 ) << endl;
    return 0;
}
