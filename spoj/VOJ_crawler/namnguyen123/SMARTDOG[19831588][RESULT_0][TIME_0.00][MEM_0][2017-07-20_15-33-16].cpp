using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MaxN = (int)(1e3 + 10);
const int oo = 2e9 ;

int a[MaxN][MaxN] ;
int stMax[4 * MaxN * MaxN], stMin[4 * MaxN * MaxN];

inline void Build(int k, int a1, int b1, int a2, int b2) {
   if (a1 > a2 || b1 > b2) return;
   if (a1 == a2 && b1 == b2) {
      stMax[k] = a[a1][b1];
      return;
   }
   int midx = (a1 + a2) >> 1;
   int midy = (b1 + b2) >> 1;
   Build(4 * k - 2, a1, b1, midx, midy);
   Build(4 * k - 1, midx + 1, b1, a2, midy);
   Build(4 * k + 0, a1, midy + 1, midx, b2);
   Build(4 * k + 1, midx + 1, midy + 1, a2, b2);
   stMax[k] = max(stMax[4 * k - 2], max(stMax[4 * k - 1], max(stMax[4 * k + 0], stMax[4 * k + 1])));
}
inline void Update(int k , int a1 , int b1 , int a2 , int b2 , int x , int y , int val) {
   if (a1 > a2 || b1 > b2) return;
   if (x > a2 || y > b2 || x < a1 || y < b1) return;
   if (x == a1 && y == b1 && x == a2 && y == b2) {
      stMax[k] = val;
      return;
   }
   int midx = (a1 + a2) >> 1;
   int midy = (b1 + b2) >> 1;
   Update(4 * k - 2, a1, b1, midx, midy, x, y, val);
   Update(4 * k - 1, midx + 1, b1, a2, midy, x, y, val);
   Update(4 * k + 0, a1, midy + 1, midx, b2, x, y, val);
   Update(4 * k + 1, midx + 1, midy + 1, a2, b2, x, y, val);
   stMax[k] = max(stMax[4 * k - 2], max(stMax[4 * k - 1], max(stMax[4 * k + 0], stMax[4 * k + 1])));
}
int Query(int k , int a1 , int b1 , int a2 , int b2 , int x1 , int y1 , int x2 , int y2) {
   int ansMax = -oo ;
   if (x1 > a2 || y1 > b2 || x2 < a1 || y2 < b1 || a1 > a2 || b1 > b2) return 0 ;
   if (x1 <= a1 && y1 <= b1 && a2 <= x2 && b2 <= y2) {
      ansMax = max(ansMax , stMax[k]);
      return ansMax ;
   }
   int midx = (a1 + a2) >> 1;
   int midy = (b1 + b2) >> 1;
   ansMax = max(ansMax , Query(4 * k - 2 , a1 , b1 , midx , midy , x1, y1, x2, y2) ) ;
   ansMax = max(ansMax , Query(4 * k - 1 , midx + 1, b1, a2, midy, x1, y1, x2, y2) ) ;
   ansMax = max(ansMax , Query(4 * k + 0 , a1, midy + 1, midx, b2, x1, y1, x2, y2) ) ;
   ansMax = max(ansMax , Query(4 * k + 1 , midx + 1, midy + 1, a2, b2, x1, y1, x2, y2) ) ;
   return ansMax ;
}
int n , k ;
const int N = 1e3 ;
const int Mx = 2 * (1000 + 2)  ;
int dp[MaxN][MaxN] ;
int x[MaxN] , y[MaxN] , z[MaxN] ;
int main() {
    #define rev(x,y,k)  x+y-k , x+y+k , x-y-k+N , x-y+k+N
    scanf("%d %d" ,&n , &k) ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%d %d %d" , &x[i] , &y[i] , &z[i]) ;
    for(int i = n ; i >= 1 ; --i ) {
        int ans = Query(1 , 1 , 1 , Mx , Mx , rev(x[i] , y[i] , k) ) + z[i] ;
        Update(1 , 1 , 1 , Mx , Mx , x[i] + y[i] , x[i] - y[i] + N , ans) ;
    }
    cout << Query(1 , 1 , 1 , Mx , Mx , rev(0 , 0 , k ) ) ;

}
