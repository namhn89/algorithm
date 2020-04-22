using namespace std;
#include<bits/stdc++.h>
#define X first
#define Y second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define pi 3.14159265359
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const double eps = 1e-6;
int d , n , r ;
typedef pair <int , int > point ;
point a[MAXN] ;
double dist (point A, point B)
{
    return sqrt ( (A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y) );
}
bool cmp (point a , point b)   // So sánh theo tọa độ X, trong trường hợp bằng nhau so sánh theo Y
{
    return a.X < b.X || a.X == b.X && a.Y < b.Y;
}

bool cw (point a, point b, point c)   // a -> b -> c đi theo thứ tự xuôi chiều kim đồng hồ
{
    return a.X*(b.Y-c.Y) + b.X*(c.Y-a.Y) + c.X*(a.Y-b.Y) < 0;
}

bool ccw (point a, point b, point c)   // a -> b -> c đi theo thứ tự ngược chiều kim đồng hồ
{
    return a.X*(b.Y-c.Y) + b.X*(c.Y-a.Y) + c.X*(a.Y-b.Y) > 0;
}

void convex_hull (vector <point> &a)
{
    if (a.size() == 1)   return ; // chỉ có 1 điểm


    // Sắp xếp các điểm theo tọa độ X , nếu bằng nhau sắp xếp theo Y
    sort (a.begin(), a.end(), &cmp);

    point p1 = a[0] ,  p2 = a.back();

    vector<point> up , down; // chuỗi trên và chuỗi dưới
    up.push_back (p1) ;
    down.push_back (p1) ;

    for (int i = 1 ; i < a.size() ; ++i)   // xét lần lượt các điểm
    {
        // Thêm vào chuỗi trên
        if (i==a.size()-1 || cw (p1, a[i], p2))
        {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }

        // Thêm vào chuỗi dưới
        if (i == a.size() - 1 || ccw (p1 , a[i] , p2))
        {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }

    // Gộp 2 chuỗi trên và dưới để lấy bao lồi
    a.clear();
    for (int i = 0 ; i < up.size() ; ++i)
        a.push_back (up[i]);
    for (int i = down.size() - 2 ; i > 0 ; --i)
        a.push_back (down[i]);
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> d >> n >> r ;
    for(int i = 0 ; i < n ; ++i ) cin >> a[i].X >> a[i].Y ;
    int ans = 0 ;
    vector <point> b ;
    for(int mask = 1 ; mask < (1 << n) ; ++mask)
    {
        b.clear() ;
        for(int i = 0 ; i < n ; ++i ) if ( (mask >> i ) & 1 ) b.push_back(make_pair(a[i].X , a[i].Y)) ;
        convex_hull(b) ;
        //for(int i = 0 ; i < b.size() ; ++i ) cout << b[i].X << " " << b[i].Y << endl;
        b.push_back(b[0]) ;
        double rote = 1.0 * pi * 2 * r ;
        for(int i = 0 ; i < b.size() - 1 ; ++i) rote += dist(b[i] , b[i + 1]) ;
        if (d - rote > eps) {
            ans = max(ans , __builtin_popcount(mask)) ;
        }
    }
    cout << ans << endl ;
    return 0;
}
