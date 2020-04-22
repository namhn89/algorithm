#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))

const int N = 2e5 + 1; // careful
const int MOD = 1e9 + 7;
using namespace std; 

struct Point {
    long long x, y;
    bool operator < (const Point &v) const { return x == v.x ? y < v.y : x < v.x; }
    long long cross(const Point &p, const Point &q) const { return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x); }
} p[N], poly[N];

int n;

int solve() {
    sort(p, p+n); int k = 0;
    for(int i = 0; i < n; ++i) {
        while(k >= 2 && poly[k-2].cross(poly[k-1], p[i]) <= 0) --k;
        poly[k++] = p[i];
    }
    for(int i = n-2, t = k+1; i >= 0; --i) {
        while(k >= t && poly[k-2].cross(poly[k-1], p[i]) <= 0) --k;
        poly[k++] = p[i];
    }
    return k;
}

bool convexPolygons(std::vector<std::vector<int>> a)
{
    n = a.size();
    for(int i = 0; i < n; ++i) p[i].x = a[i][0] , p[i].y = a[i][1];
    if (solve() == n + 1) return true;
    else return false;
}