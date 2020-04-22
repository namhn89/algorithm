#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair <int, int> p[200002];

main()
{
    ios::sync_with_stdio(false);    cin.tie();
    cin >> N;
    for (int i = 1; i <= 2 * N; i++) cin >> p[i].first;
    for (int i = 1; i <= N; i++) p[i].second = 1;
    sort(p + 1, p + 2 * N + 1);
    for (int i = 1; i < 2 * N; i++)
    {
        int j = i;
        while (p[i].second == p[j].second && i <= 2 * N) i++;
        if (i <= 2 * N) ans++;
            else break;
    }
    cout << ans;
}
    