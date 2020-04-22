#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
 
using namespace std;
 
typedef long long   ll;
typedef int64_t     ll;
 
int     n, k, t;
ll      f[100][100];
 
int main()
{
    f[0][0] = 1;
    for (int i=1;i<=25;i++)
        for (int j=1;j<=i;j++)
            f[i][j] = f[i-1][j-1] + f[i-1][j]*j;
 
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        printf("%lldn", f[n][k]);
    }
    return 0;
}