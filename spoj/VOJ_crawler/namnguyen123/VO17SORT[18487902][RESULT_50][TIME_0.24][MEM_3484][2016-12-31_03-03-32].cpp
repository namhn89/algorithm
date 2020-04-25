using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 15 + 5 ;
const long long BASE = 1097 ;
map < string, int> f ;
int n ;
int a[MAXN] ;
struct data
{
    string S ;
    int deg ;
    data () {}
    data (string S, int deg) : S(S), deg(deg) {} ;
};
void sub1 ()
{
    if (n == 1) {
        int a ;
        scanf("%d",&a) ;
        if (a == 1) cout << 0 << endl;
    }
    if (n == 2) {
         int a , b ;
         scanf("%d %d",&a ,&b) ;
         if (a == 1 && b == 2) cout << 0 << endl;
         else cout << 1 << endl;
    }
    if (n == 3)
    {
        int a, b, c ;
        scanf("%d %d %d", &a, &b, &c) ;
        if (a == 1 && b == 2 && c == 3) cout << 0 << endl ;
        if (a == 1 && b == 3 && c == 2) cout << 1 << endl ;
        if (a == 2 && b == 3 && c == 1) cout << 1 << endl ;
        if (a == 2 && b == 1 && c == 3) cout << 1 << endl ;
        if (a == 3 && b == 2 && c == 1) cout << 2 << endl ;
        if (a == 3 && b == 1 && c == 2) cout << 1 << endl ;
    }
}
void sub2 ()
{
    string s = "";
    string Hash = "";
    FORE(i, 1, n ) scanf("%d", &a[i]) ;
    FORE(i, 1, n ) Hash = Hash + char(i + '0') ;
    FORE(i, 1, n ) s = s + char(a[i] + '0') ;
    queue < data > Q ;
    Q.push(data(s, 0)) ;
    int res = 5 ;
    if (s == Hash)
    {
        printf("0\n");
    }
    else
    {
        while(!Q.empty())
        {
            string T = Q.front().S ;
            int state = Q.front().deg ;
            Q.pop() ;
            if (res == 1) break;
            if (T == Hash) res = min(res, state) ;
            if (state == 4 || T == Hash ) continue ;
            FORE(L, 0, n - 1 )
            {
                FORE(R, L, n - 1 )
                {
                    string b = T ;
                    string c = b.substr(L, R - L + 1 ) ;
                    b.erase(b.begin() + L, b.begin() + R + 1) ;
                    int x = b.size() ;
                    FORE(i, 0, x )
                    {
                        string d = b ;
                        d.insert(i, c) ;
                        if (d == T) continue ;
                        if (f[d] == 1) continue ;
                        f[d] = 1 ;
                        Q.push(data(d, state + 1)) ;
                    }
                }
            }
        }
        if (res <= 4)
        {
            printf("%d\n", res) ;
        }
        else printf("5 or more\n");
    }
}
void sub3 ()
{
    printf("5 or more\n") ;
}
int main()
{
#define TASK "test"
    //freopen(TASK".inp","r",stdin);
   // freopen(TASK".out","w",stdout);
    int Test ;
    scanf("%d",&Test) ;
    while(Test--)
    {
        f.clear() ;
        scanf("%d", &n);
        if (n <= 3) sub1 () ;
        else if (n <= 7) sub2 () ;
        else sub3 () ;
    }
    return 0;
}
