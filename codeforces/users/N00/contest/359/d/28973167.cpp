using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 3e5 + 10 ;
typedef pair <int, int> data ;
int n ;
int a[MAXN] ;
data Tree[4 * MAXN] ;
const int oo = 1e9 + 10 ;
data combine (data left, data right)
{
    data res ;
    res.st = __gcd(left.st, right.st) ;
    res.nd = min(left.nd, right.nd) ;
    return res ;
}
void build (int k, int l, int r)
{
    if (l == r)
    {
        Tree[k].st = a[l] ;
        Tree[k].nd = a[l] ;
        return ;
    }
    int mid = (l + r) / 2 ;
    build(2 * k, l, mid) ;
    build(2 * k + 1, mid + 1, r) ;
    Tree[k] = combine(Tree[2 * k], Tree[2 * k + 1]) ;
}
data query (int k, int l, int r, int u, int v)
{
    if (l > v || r < u) return data (0, oo) ;
    if (u <= l && r <= v) return Tree[k] ;
    int mid = (l + r) / 2 ;
    return combine(query(2 * k, l, mid, u, v), query(2 * k + 1, mid + 1, r, u, v)) ;
}
bool check (int len)
{
    for(int id = 1 ; id <= n - len + 1 ; ++id )
    {
        data ans = query(1 , 1 , n , id , id + len - 1) ;
        if(ans.st == ans.nd) return true ;
    }
    return false ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d", &n) ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%d", &a[i]) ;
    for(int i = 0 ; i < 4 * MAXN ; ++i ) Tree[i] = data(0 , oo) ;
    build(1, 1, n) ;
    int low = 1 , high = n , len = 1 ;
    while(low <= high)
    {
        int mid = (low + high) / 2 ;
        if (check(mid)) low = mid + 1 , len = mid ;
        else high = mid - 1 ;
    }
    vector <data> res ;
    for(int i = 1 ; i <= n - len + 1 ; ++i ) {
        data ans = query(1 , 1 , n , i , i + len - 1) ;
        if(ans.st == ans.nd) res.push_back(make_pair(i , i + len - 1)) ;
    }
    cout << res.size() << " " << len - 1 << endl ;
    TR(res , it) cout << it -> st << " ";
    return 0;
}
