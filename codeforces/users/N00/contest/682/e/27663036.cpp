using namespace std;
#include<bits/stdc++.h>
#define x first
#define y second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
typedef pair < long long , long long > point ;
point origin ;
point operator - (point A , point B) {return point (A.x - B.x , A.y - B.y) ;}
point operator + (point A , point B) {return point (A.x + B.x , A.y + B.y) ;}
void operator -= (point &A , point B) {A.x -= B.x ; A.y -= B.y ; }
bool ccw (point O , point A , point B ) {A -= O ; B -= O ; return 1LL * A.x * B.y > 1LL * A.y * B.x ;}
bool cmp (point A , point B ) { return ccw(origin , A , B) ; }
long long area (point A , point B , point C) {
    return abs(((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)));
}
vector < point > hull ;
int next (int u) {return (u + 1) % hull.size() ;}
int n ;
long long S ;
point a[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> n >> S ;
    for(int i = 1 ; i <= n ; ++i ) cin >> a[i].x >> a[i].y ;
    sort(a + 1 , a + n + 1) ;
    origin = a[1] ;
    sort(a + 2 , a + n + 1 , cmp ) ;
    a[0] = a[n] ; a[n + 1] = a[1];
    for(int i = 1 ; i <= n + 1 ; ++i ) {
        while(hull.size() >= 2 && !ccw(hull[hull.size() - 2], hull[hull.size() - 1], a[i]) )
            hull.pop_back();
        hull.push_back(a[i]);
    }
    hull.pop_back();
    point A , B , C ;
    long long ans = 0 ;
    for(int L = 0 ; L < hull.size() ; ++L ) {
        int M = next(L);
        for(int R = next(next(L)); R != L; R = next(R)){
            while(next(M) != R && area(hull[L], hull[next(M)], hull[R]) > area(hull[L], hull[M], hull[R])) M = next(M);
            if (ans < area(hull[L], hull[M], hull[R])){
                ans = area(hull[L], hull[M], hull[R]);
                A = hull[L]; B = hull[M]; C = hull[R];
            }
        }
    }
    /*
    cout << A.x << " " << A.y << endl ;
    cout << B.x << " " << B.y << endl ;
    cout << C.x << " " << C.y << endl ;
    */
    point X = (A + B) - C ;
    point Y = (B + C) - A ;
    point Z = (A + C) - B ;
    cout << X.x << " " << X.y << endl;
    cout << Y.x << " " << Y.y << endl;
    cout << Z.x << " " << Z.y << endl;

    return 0;
}
