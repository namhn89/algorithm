using namespace std;
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
const int MAXN = 10 + 1e6 ;
int N = 0 ;
int a[MAXN], n ;
int Mark[MAXN], f[MAXN] ;
vector <int> ans[MAXN] ;
int main()
{
    //freopen(".inp","w",stdin) ;
    //freopen(".out","r",stdout) ;
    scanf("%d",&n) ;
    for(int i = 1 ; i <= n ; ++i)
    {
        scanf("%d",&a[i]), f[a[i]] = 1, N = max(N, a[i]) ;
    }
    for(int i = 1 ; i <= N ; ++i)
    {
        if (f[i] == 1 && Mark[i] == 0) Mark[i] = 1 ;
        for(int j = 2 * i ; j <= N ; j += i)
        {
            if (f[j] == 1 ) Mark[j] = max(Mark[j], Mark[i] + 1) ;
            else Mark[j] = Mark[i] ;
        }
    }
    for(int i = 1 ; i <= n ; ++i ) ans[Mark[a[i]]].push_back(a[i]) ;
    for(int i = 1 ; i <= n ; ++i ) sort(ans[i].begin(), ans[i].end());
    int n_ans = 0 ;
    for(int i = 1 ; i <= n ; ++i) if (ans[i].size() == 0) {n_ans = i - 1 ; break;}
    cout << n_ans << endl;
    for(int i = 1 ; i <= n ; ++i )
    {
        if(ans[i].size() == 0) break ;
        cout << ans[i].size() << " " ;
        for(int j = 0 ; j < ans[i].size() ; ++j ) cout << ans[i][j] << " ";  cout << endl;
    }
    return 0;
}
