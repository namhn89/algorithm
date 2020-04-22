using namespace std ;
#include<bits/stdc++.h>
const int MAXN = 26 ;

long long f[MAXN][MAXN];

int main ()
{
    // f(n,k) = f(n-1,k-1) + f(n-1,k)* k ;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int Test ;
    int n, k ;
    f[0][0] = 1 ;
    for(int i = 1 ; i <= 25 ; ++i )
    {
        for(int j = 1 ; j <= 25 ; ++j )
        {
            f[i][j] = f[i-1][j-1] + f[i-1][j] * j ;
        }
    }
    cin >> Test ;
    while(Test--)
    {
        cin >> n >> k ;
        cout << f[n][k] << endl;

    }

}
