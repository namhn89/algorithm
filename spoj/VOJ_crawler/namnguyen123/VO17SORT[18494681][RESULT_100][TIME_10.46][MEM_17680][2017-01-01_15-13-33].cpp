#include<bits/stdc++.h>
using namespace std;
struct data
{
    string S ;
    int deg ;
    data () {}
    data (string S, int deg ) : S(S), deg(deg) {} ;
};
long long encode (string s)
{
    long long res = 0  ;
    for(int i = 0 ; i < s.size() ; ++i ) res = (res << 4) + s[i] - '0' ;
    return res ;
}
map < long long, int > f_start, f_finish  ;
void solve ()
{
    int n ;
    scanf("%d",&n) ;
    string finish, start ;
    for(int i = 1 ; i <= n ; ++ i)
    {
        int x  ;
        scanf("%d",&x) ;
        start.push_back(x + '0') ;
    }
    for(int i = 1 ; i <= n ; ++ i) finish.push_back(i + '0') ;
    queue < data > Q ;
    f_start[encode(start)] = 0 ;
    Q.push(data (start, 0)) ;
    while(!Q.empty())
    {
        string S = Q.front(). S ;
        int deg  = Q.front().deg ;
        Q.pop() ;
        if (deg == 2) continue ;
        for(int i = 0 ; i < n ; ++i )
        {
            for(int j = i ; j < n ; ++j )
            {
                string A = S ;
                string C = A.substr(i, j - i + 1) ;
                A.erase(A.begin() + i, A.begin() + j + 1) ;
                int len = A.size() ;
                for(int k = 0 ; k <= len ; ++k )
                {
                    string D = A ;
                    D.insert(k, C) ;
                    if (f_start.find(encode(D)) == f_start.end())
                    {
                        f_start[encode(D)] = deg + 1 ;
                        Q.push( data(D, deg + 1) ) ;
                    }
                }
            }
        }
    }
    f_finish[encode(finish)] = 0 ;
    Q.push(data (finish, 0)) ;
    while(!Q.empty())
    {
        string S = Q.front(). S ;
        int deg  = Q.front().deg ;
        Q.pop() ;
        if (deg == 2) continue ;
        for(int i = 0 ; i < n ; ++i )
        {
            for(int j = i ; j < n ; ++j )
            {
                string A = S ;
                string C = A.substr(i, j - i + 1) ;
                A.erase(A.begin() + i, A.begin() + j + 1) ;
                int len = A.size() ;
                for(int k = 0 ; k <= len ; ++k )
                {
                    string D = A ;
                    D.insert(k, C) ;
                    if (f_finish.find(encode(D)) == f_finish.end())
                    {
                        f_finish[encode(D)] = deg + 1 ;
                        Q.push( data(D, deg + 1) ) ;
                    }
                }
            }
        }
    }
    int res = 5 ;
    map < long long, int > :: iterator it ;
    for(it = f_finish.begin() ; it != f_finish.end() ; ++it )
    {
        long long D = it -> first ;
        if (f_start.find(D) != f_start.end() ) res = min(res, f_finish[D] + f_start[D]) ;
    }
    if(res < 5) printf("%d\n", res) ;
    else printf("5 or more\n") ;
}
int main()
{
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int Test ;
    scanf("%d",&Test) ;
    while(Test--)
    {
        f_finish.clear() ; f_start.clear() ;
        solve() ;
    }
}
