#include <bits/stdc++.h>
using namespace std;

int N, M, le[1010][1010], ri[1010][1010], up[1010][1010], dn[1010][1010];
int u[1010][1010], d[1010][1010], l[1010][1010], r[1010][1010];
int sum[1010][1010];
char s[1010][1010];
struct data
{
    int v, x, y, r;
} ans;

int getsum(int i, int l, int r)
{
    return sum[i][r] - sum[i][l - 1];
}

int calc(int x, int y, int k)
{
    int ret = 0;
    for (int i = x - k + 1; i <= x + k - 1; i++)
    {
        int r = k - abs(i - x);
        ret += getsum(i, y - r + 1, y + r - 1);
    }
    return ret;
}

main()
{
 //   freopen("vao.inp", "r", stdin);
  //  freopen("ra.out", "w", stdout);

    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%s", s[i] + 1);

    for (int i = 1; i <= N; i++)
    {
        le[i][1] = 1;
        for (int j = 2; j <= M; j++)
            le[i][j] = (s[i][j - 1] == '*' && s[i][j] == '*') ? j : le[i][j - 1];

        ri[i][M] = M;
        for (int j = M - 1; j; j--)
            ri[i][j] = (s[i][j] == '*' && s[i][j + 1] == '*') ? j : ri[i][j + 1];
    }
    for (int j = 1; j <= M; j++)
    {
        up[1][j] = 1;
        for (int i = 2; i <= N; i++)
            up[i][j] = (s[i - 1][j] == '*' && s[i][j] == '*') ? i : up[i - 1][j];

        dn[N][j] = N;
        for (int i = N - 1; i; i--)
            dn[i][j] = (s[i][j] == '*' && s[i + 1][j] == '*') ? i : dn[i + 1][j];
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            u[i][j] = min(j - le[i][j] + 1, ri[i][j] - j + 1);
            u[i][j] = min(u[i][j], u[i - 1][j] + 1);
        }
    for (int i = N; i; i--)
        for (int j = 1; j <= M; j++)
        {
            d[i][j] = min(j - le[i][j] + 1, ri[i][j] - j + 1);
            d[i][j] = min(d[i][j], d[i + 1][j] + 1);
        }

    for (int j = 1; j <= M; j++)
        for (int i = 1; i <= N; i++)
        {
            l[i][j] = min(i - up[i][j] + 1, dn[i][j] - i + 1);
            l[i][j] = min(l[i][j], l[i][j - 1] + 1);
        }

    for (int j = M; j; j--)
        for (int i = 1; i <= N; i++)
        {
            r[i][j] = min(i - up[i][j] + 1, dn[i][j] - i + 1);
            r[i][j] = min(r[i][j], r[i][j + 1] + 1);
        }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            sum[i][j] = sum[i][j - 1] + (s[i][j] == '*');

    ans.v = ans.x = ans.y = ans.r = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            int k = min(min(i, N - i + 1), min(j, M - j + 1));
            k = min(k, u[i][j]);
            k = min(k, d[i][j]);
            k = min(k, l[i][j]);
            k = min(k, r[i][j]);
            int cur = calc(i, j, k);
            if (cur > ans.v)
            {
                ans.v = cur;
                ans.x = i;
                ans.y = j;
                ans.r = k - 1;
            }
        }

    printf("%d %d %d %d", ans.v, ans.x, ans.y, ans.r);
}
