#include<bits/stdc++.h>
using namespace std;


int     t,n,f[31][31][31],Max,res,ans,a,b,c;
int minint = -int(1e9 + 9);

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        for (int x=1; x<=n; x++)
            for (int y=1; y<=n; y++)
                for (int z=1; z<=n; z++)
                {
                    scanf("%d",&f[x][y][z]);
                    f[x][y][z] += f[x-1][y][z] + f[x][y-1][z]
                                  + f[x][y][z-1]
                                  - f[x-1][y-1][z] - f[x-1][y][z-1]
                                  - f[x][y-1][z-1]
                                  + f[x-1][y-1][z-1];
                }
        res = minint;
        for (int x=1; x<=n; x++)
            for (int y=1; y<=n; y++)
                for (int z=1; z<=n; z++)
                {
                    Max = min(min(x,y),z);
                    for (int t=1; t<=Max; t++)
                    {
                        a = x-t;
                        b = y-t;
                        c = z-t;
                        ans = f[x][y][z]
                              - f[a][y][z] - f[x][b][z] - f[x][y][c]
                              + f[x][b][c] + f[a][y][c] + f[a][b][z]
                              - f[a][b][c];
                        res = max(res,ans);
                    }
                }
        printf("%d\n",res);
    }
    return 0;
}
