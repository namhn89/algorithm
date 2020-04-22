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
long long operator * (point A , point B) {return abs(1LL * A.x * B.y - B.x * A.y ) ;}
void operator -= (point &A , point B) {A.x -= B.x ; A.y -= B.y ; }
bool ccw (point O , point A , point B ) {A -= O ; B -= O ; return 1LL * A.x * B.y > 1LL * A.y * B.x ;}
bool cmp (point A , point B ) { return ccw(origin , A , B) ; }
long long area (point A , point B , point C) {
    return abs(((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)));
}
bool check (point A , point B , point C , point P) {
  point PA = A - P ;
  point PB = B - P ;
  point PC = C - P ;
  point AB = B - A ;
  point AC = C - A ;
  if (PA * PB + PB * PC + PC * PA > AB * AC) return false ;
  else return true ;
}
vector < point > convex ;
int next (int u) {return (u + 1) % convex.size() ;}
int n ;
long long S ;
point a[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    while(cin >> n) {
    if (n == -1) return 0 ;
    convex.clear() ;
    for(int i = 1 ; i <= n ; ++i ) cin >> a[i].x >> a[i].y ;
    sort(a + 1 , a + n + 1) ;
    origin = a[1] ;
    sort(a + 2 , a + n + 1 , cmp ) ;
    a[0] = a[n] ; a[n + 1] = a[1];
    for(int i = 1 ; i <= n + 1 ; ++i ) {
        while(convex.size() >= 2 && !ccw(convex[convex.size() - 2], convex[convex.size() - 1], a[i]) )
            convex.pop_back();
        convex.push_back(a[i]);
    }
    convex.pop_back();
    point A , B , C ;
    int n = convex.size() ;
    int a , b , c , ba , bb , bc ;
	a = ba = 0;
	b = bb = 1;
	c = bc = 2;
	for (; a < n ; a++ ) {
		if (a == b) b = next(b) ;
		if (b == c) c = next(c) ;
		while (1) {
			while (area(convex[a], convex[b], convex[c]) <= area(convex[a], convex[b], convex[next(c)]))
				c = next(c) ;
			if (area(convex[a], convex[b], convex[c]) <= area(convex[a], convex[next(b)], convex[c])) {
				b = next(b) ;
				continue ;
			} else break ;
		}
		if (area(convex[a] , convex[b] , convex[c]) > area(convex[ba] , convex[bb] , convex[bc]) )
			ba = a , bb = b , bc = c;
	}
	long long SMax = area(convex[ba] , convex[bb] , convex[bc]) ;
	if (SMax & 1) cout << SMax / 2 << ".50" << endl ;
	else cout << SMax / 2 << ".00" << endl;
}

    return 0;
}
