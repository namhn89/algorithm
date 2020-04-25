#include <bits/stdc++.h>
using namespace std;
int a[102][2], dp[102][2];
int main() {
    int n;
    cin >> n >> a[0][0] >> a[0][1];
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    for(int i = 1; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        dp[i][0] = a[i][0] + max(
            dp[i - 1][0] + abs(a[i][1] - a[i - 1][1]),
            dp[i - 1][1] + abs(a[i][1] - a[i - 1][0])
        );
        dp[i][1] = a[i][1] + max(
            dp[i - 1][0] + abs(a[i][0] - a[i - 1][1]),
            dp[i - 1][1] + abs(a[i][0] - a[i - 1][0])
        );
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
}
    