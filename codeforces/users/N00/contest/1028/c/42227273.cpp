using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 132674 ;
const int INF = 1e9 + 100 ;
struct Rectangle {
    int bottomRight_x , bottomRight_y , topLeft_x , topLeft_y ;
    Rectangle () {} ;
    Rectangle(int topLeft_x , int topLeft_y , int bottomRight_x , int bottomRight_y) : topLeft_x(topLeft_x) , topLeft_y(topLeft_y) , bottomRight_x(bottomRight_x) , bottomRight_y(bottomRight_y) {}
};
Rectangle a[MAXN] , Tree[MAXN * 4] ;
Rectangle intersect (Rectangle a , Rectangle b) {
     int xMax = max(a.topLeft_x , b.topLeft_x) ;
     int yMax = max(a.topLeft_y , b.topLeft_y) ;
     int xMin = min(a.bottomRight_x , b.bottomRight_x) ;
     int yMin = min(a.bottomRight_y , b.bottomRight_y) ;
     if (xMax > xMin || yMax > yMin) {
         return Rectangle(INF , INF , INF , INF) ;
     }
     return Rectangle (xMax , yMax , xMin , yMin) ;

}
int n ;
void build (int k , int l , int r) {
    if (l == r) {
        Tree[k] = a[l] ;
        return ;
    }
    int mid = (l + r) / 2 ;
    build(2 * k , l , mid) ;
    build(2 * k + 1 , mid + 1 , r) ;
    Tree[k] = intersect(Tree[2 * k] , Tree[2 * k + 1]) ;
}
Rectangle query (int k , int l , int r , int u , int v) {
    if (u > r || v < l) return Rectangle(-INF , -INF , INF , INF) ;
    if (u <= l && r <= v ) return Tree[k] ;
    int mid = (l + r) / 2 ;
    return intersect(query(2 * k , l , mid , u , v) , query(2 * k + 1 , mid + 1 , r , u , v)) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d",&n) ;
    for(int i = 1 ; i <= n ; ++i ) {
        scanf("%d %d %d %d" , &a[i].topLeft_x , &a[i].topLeft_y , &a[i].bottomRight_x , &a[i].bottomRight_y) ;
    }
    build(1 , 1 , n) ;
    for(int i = 1 ; i <= n ; ++i) {
        Rectangle ans = intersect(query(1 , 1 , n , 1 , i - 1) , query(1 , 1 , n , i + 1 , n)) ;
        if (ans.topLeft_x != -INF && ans.topLeft_x != INF) {
            cout << ans.topLeft_x << " " << ans.topLeft_y << endl;
            return 0 ;
        }
    }


    return 0;
}
