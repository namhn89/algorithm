using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
typedef pair <long long , long long> LL ;
LL extended_gcd(long long  a, long long b)
{
    LL M , N ;
    if (b == 0 ) return LL (1, 0);
    else
    {
        M = LL (a / b, a % b);
        N = extended_gcd(b , M.nd);
        return LL(N.nd , N.st - M.st * N.nd);
    }
}
long long let_up (long long a , long long b) {
    if (b < 0) return let_up(- a , - b) ;
    if (a >= 0) return (a + b - 1) / b ;
    else return a / b ;
}
long long let_down (long long a , long long b) {
    if (b < 0) return let_down (-a , -b) ;
    if (a >= 0) return a / b ;
    else return (a - b + 1) / b ;
}
long long k_L , k_R , l_L , l_R ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    long long a1 , a2 , b1 , b2 , L , R ;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R ;
    long long A = a1  , B = -a2 , C = b2 - b1 ;
    if (C % __gcd(A , B) ){
        cout << 0 ; return 0 ;
    }
    long long G = __gcd(A , B) ;
    LL ans = extended_gcd(A , B) ;
    ans.st *= (C / G) ;
    ans.nd *= (C / G) ;
    long long a = B / G , b = A / G ; // x = x0 + at , y = y0 - bt ;
    k_L = max ( let_up(L - b1 , a1) , 0LL )  ; k_R = let_down (R - b1 , a1 ) ;
    l_L = max ( let_up(L - b2 , a2) , 0LL )  ; l_R = let_down (R - b2 , a2 ) ;
    //cout << ans.st << " " << ans.nd << endl;
   // cout << k_L << " " << k_R << endl;
    //cout << l_L << " " << l_R << endl;
    //cout << a << " " << b << endl ;
    long long ans_L , ans_R , ans1_L , ans1_R ;
    if (a > 0) {
    ans_L = let_up (k_L - ans.st , a );
    ans_R = let_down (k_R - ans.st , a ) ;
    }
    else {
      ans_L = let_up (- k_R + ans.st , -a );
      ans_R = let_down (- k_L + ans.st , -a ) ;
    }
    //cout << ans_L << " " << ans_R << endl;
    if (b > 0) {
       ans1_L = let_up (-l_R + ans.nd , b ) ;
       ans1_R = let_down (-l_L + ans.nd , b ) ;
    }
    else {
      ans1_L = let_up (l_L - ans.nd , -b ) ;
      ans1_R = let_down (l_R - ans.nd , -b ) ;
    }
   // if (b < 0) swap(ans1_L , ans1_R) ;
    //cout << ans1_L << " " << ans1_R << endl;
    ans_L = max(ans_L , ans1_L) , ans_R = min(ans_R , ans1_R) ;
    cout << max(0LL , ans_R - ans_L + 1) ;
    return 0 ;
}
