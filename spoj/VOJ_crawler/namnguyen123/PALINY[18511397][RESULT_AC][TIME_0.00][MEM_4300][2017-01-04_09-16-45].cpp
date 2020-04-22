using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const long long BASE = 1097 ;
const int MAXN = 5e4 + 5 ;
unsigned long long Hash[MAXN], powmod[MAXN] ;
char a[MAXN] ;
int n ;
unsigned long long getHash (int l , int r)
{
    return (Hash[r] - Hash[l - 1] * powmod[r - l + 1]) ;
}
bool checkeven(int len )
{

    FORE(i, 1, n - len + 1) if (getHash(i, i + len / 2 - 1) == getHash(i + len / 2, i + len - 1) ) return true ;
    return false ;
}
bool checkodd(int len )
{
    FORE(i, 1, n - len + 1) if (getHash(i, i + len / 2 - 1) == getHash(i + len / 2 + 1, i + len - 1) ) return true ;
    return false ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d",&n) ;
    scanf("%s", a + 1) ;
    powmod[0] = 1 ;
    FORE(i, 1, n ) powmod[i] = powmod[i - 1] * BASE ;
    FORE(i, 1, n ) Hash[i] = Hash[i - 1] * BASE + a[i] - '0' ;
    int l = 0, r = n / 2 + 1, ans_even ;
    while(l <= r)
    {
        int mid = (l + r) / 2 ;
        if ( checkeven(mid * 2) && mid * 2 <= n) l = mid + 1, ans_even = mid * 2;
        else r = mid - 1 ;
    }
    l = 0, r = n / 2 + 1;
    int ans_odd ;
    while(l <= r )
    {
        int mid = (l + r) / 2 ;
        if ( checkodd(mid * 2 + 1) && mid * 2 + 1 <= n) l = mid + 1, ans_odd = mid * 2 + 1;
        else r = mid - 1 ;
    }
    cout << max(ans_odd , ans_even) << endl;
    return 0;
}
