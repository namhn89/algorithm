using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e3 + 5 ;
long long crush[MAXN] ;
long long number[MAXN] ;
long long vis[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    FORE(i , 1 , n ) cin >> crush[i] ;
    int n_num = 0 ;
    FORE(i , 1 , n )
    if(!vis[i])
    {
        int j = i;
        vis[i] = ++n_num;
        number[n_num] ++;
        j = crush[i];
        while(!vis[j])
        {
            vis[j] = vis[i];
            number[n_num]++;
            j = crush[j];
        }
        if(j != i)
        {
            cout << - 1 << endl;
            return 0 ;
        }
    }
    FORE(i, 1, n_num)
    if(number[i] % 2 == 0 ) number[i] /= 2;
    long long ans = 1;
    FORE(i , 1 , n_num)
    {
        ans = ans* number[i]/__gcd(ans, number[i]);
    }
    cout << ans << endl;

    return 0;
}
