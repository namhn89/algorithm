using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e3 + 5 ;

struct Point {
   long long x , y ;
   long long operator < (const Point &v) const {return x == v.x ? y < v.y : x < v.x ;}
   long long cross (const Point &p , const Point &q) {
       return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x) ;
   }
} poly[MAXN] ;
long long area (Point poly[] , int k) {
    long long S = ( poly[k - 1].x - poly[0].x ) * ( poly[k - 1].y + poly[0].y );
    for(int i = 1 ; i < k ; ++i )
        S += (poly[i - 1].x - poly[i].x) * ( poly[i - 1].y + poly[i].y );
    return S;
}
long long areaThree (Point A , Point B , Point C) {
    return abs(((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)));
}

int n ;
Point a[MAXN] , p[MAXN] , b[MAXN] ;

int main()
{
#define TASK "NKLAND"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int T ;
    scanf("%d",&T) ;
    while(T--){
        n = 0 ;
        int MA , MB ;
        scanf("%d", &MA) ;
        for(int i = 0 ; i < MA ; ++i ) {
            scanf("%lld %lld", &a[i].x , &a[i].y ) ;
            p[n].x = a[i].x ;
            p[n].y = a[i].y ;
            n++ ;
        }
        long long S1 = area(a , MA) ;
        scanf("%d", &MB) ;
        for(int i = 0 ; i < MB ; ++i ) {
            scanf("%lld %lld", &b[i].x , &b[i].y ) ;
            p[n].x = b[i].x ;
            p[n].y = b[i].y ;
            n++ ;
        }
        long long S2 = area(b , MB) ;
        bool ok = false ; // diem nam trong da giac
        for(int i = 0 ; i < MA ; ++i ) {
             long long cnt = 0 ;
             for(int j = 0 ; j < MB - 1; ++j ) cnt += areaThree(b[j] , b[j + 1] , a[i]) ;
             cnt += areaThree(b[0] , b[MB - 1] , a[i]) ;
             if (cnt == S2) {
                 bool On = false ;
                 for(int j = 0 ; j < MB - 1 ; ++j ) if (areaThree(b[j] , b[j + 1] , a[i]) == 0) {
                       On = true ;
                 }
                 if (On) continue ;
                 ok = true ;
                 break ;
             }
        }
        /*
        sort(p , p + n) ;
        int k = 0 ;
        for(int i = 0 ; i < n ; ++i ) {
            while(k >= 2 && poly[k - 2].cross(poly[k - 1] , p[i]) <= 0) --k;
            poly[k++] = p[i];
        }
        for(int i = n - 2 , t = k + 1 ; i >= 0; --i) {
            while(k >= t && poly[k - 2].cross(poly[k - 1] , p[i]) <= 0) --k;
            poly[k++] = p[i];
        }
        long long T = area(poly , k) ;
        */
        if(ok) {
            printf("YES\n") ;
        }
        else printf("NO\n") ;
    }
    return 0;
}
