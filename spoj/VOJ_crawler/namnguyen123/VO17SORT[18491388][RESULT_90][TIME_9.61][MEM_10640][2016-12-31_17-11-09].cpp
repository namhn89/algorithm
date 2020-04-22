using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const long long MOD = 1e9 + 7 ;
map < string, int > f_start, f_finish ;
int n ;
struct data
{
    string S ;
    int deg ;
    data () {}
    data (string S, int deg) : S(S), deg(deg) {} ;
};
void solve ()
{
    string s  ;
    string Hash  ;
    FORE(i , 1 , n )
    {
        int x ;
        scanf("%d", &x) ;
        x--;
        s.push_back('0' + x) ;
    }
    FORE(i , 0 , n - 1) Hash.push_back('0' + i) ;
    queue < data > Q ;
    Q.push(data(s , 0)) ;
    f_start[s] = 0 ;
    while(!Q.empty())
    {
        string T  = Q.front().S ;
        int state = Q.front().deg ;
        Q.pop() ;
        if (state == 2) continue ;
        FORE(L , 0 , n - 1 )
        {
            FORE(R , L , n - 1 )
            {
                string b = T ;
                string c = b.substr(L, R - L + 1 ) ;
                b.erase(b.begin() + L, b.begin() + R + 1) ;
                int x = b.size() ;
                FORE(i, 0, x )
                {
                    string D = b ;
                    D.insert(i, c) ;
                    if (f_start.find(D) == f_start.end())
                    {
                        f_start[D] = state + 1 ;
                        Q.push(data(D, state + 1)) ;
                    }
                }
            }
        }
    }
    f_finish[Hash] = 0 ;
    Q.push(data(Hash, 0)) ;
    while(!Q.empty())
    {
        string T  = Q.front().S ;
        int state = Q.front().deg ;
        Q.pop() ;
        if (state == 2) continue ;
        FORE(L , 0 , n - 1 )
        {
            FORE(R , L , n - 1 )
            {
                string b = T ;
                string c = b.substr(L, R - L + 1 ) ;
                b.erase(b.begin() + L, b.begin() + R + 1) ;
                int x = b.size() ;
                FORE(i , 0 , x )
                {
                    string D = b ;
                    D.insert(i, c) ;
                    if (f_finish.find(D) == f_finish.end())
                    {
                        f_finish[D] = state + 1 ;
                        Q.push(data(D, state + 1) ) ;
                    }
                }
            }
        }
    }
    int res = 5 ;
    map < string , int > :: iterator it ;
    for(it = f_finish.begin() ; it != f_finish.end() ; ++it)
    {
        string D = it -> st ;
        int dist = it -> nd ;
        if (f_start.find(D) != f_start.end()) res = min(res , f_start[D] + dist) ;
    }
    if (res < 5) printf("%d\n", res) ;
    else printf("5 or more\n");
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
        f_start.clear() ;
        f_finish.clear() ;
        scanf("%d", &n);
        solve() ;
    }
    return 0;
}
/*
6
3
1 3 2
3
2 1 3
3
1 2 3
3
3 2 1
3
3 1 2
3
2 3 1
*/

