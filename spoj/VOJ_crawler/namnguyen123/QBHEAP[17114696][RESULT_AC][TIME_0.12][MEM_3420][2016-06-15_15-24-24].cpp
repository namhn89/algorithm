
using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=1e5+1;
const int INF =1e9;
int f (string s)
{
    int sum = 0;
    FORE(i, 1, s.size() - 1)
    {
        sum = sum*10 + (s[i]-'0');
    }
    return sum ;
}
int main ()
{
    //freopen("IO.inp","r",stdin);
    // freopen(".out","w",stdout);
    priority_queue< int > q ;
    string s ;
    while (cin >> s)
    {
        if (s[0] == '+')
        {
            if (q.size() < 15000)
            {
                q.push(f(s));
            }
        }
        else if (s[0] == '-')
        {
            if (!q.empty())
            {
                int x = q.top();
                while(q.top() == x && !q.empty())q.pop();
            }
        }
    }
    vector < int > g;
    if (q.size())
    {
        while (!q.empty())
        {
            int a = q.top();
            while (!q.empty() && q.top() == a ) q.pop() ;
            g.push_back(a);
        }
        cout << g.size() << endl;
        FORE (i, 0, g.size()-1)
        {
            cout << g[i] << " ";
        }
    }
    else cout << 0 << endl;

    return 0;
}
     
