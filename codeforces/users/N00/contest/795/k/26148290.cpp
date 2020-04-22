using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    s = s + "#" ;
    int bg = 0 , ed = 0 ;
    char x = '#' ;
    vector <char> ans ;
    for(int i = 0 ; i < s.size() ; ++i)
    {
        if(s[i] != x)
        {
            int cnt = ed - bg + 1 ;
            if(x == 'e' || x == 'a' || x == 'i' || x == 'y' || x == 'o' || x == 'u')
            {
                if (x == 'e')
                {
                    if (cnt == 2)
                    {
                        ans.push_back('e') ;
                        ans.push_back('e') ;
                    }
                    else ans.push_back('e') ;
                }
                else if (x == 'o')
                {
                    if (cnt == 2)
                    {
                        ans.push_back('o') ;
                        ans.push_back('o') ;
                    }
                    else ans.push_back('o') ;
                }
                else
                {
                    ans.push_back(x) ;
                }
            }
            else {
                if (x != '#') for(int j = 1 ; j <= cnt ; ++j) ans.push_back(x) ;
            }
            x = s[i] ;
            bg = i ;
            ed = i ;
        }
        else ed ++;
    }
    TR(ans , it) cout << *it ;
    return 0;
}
