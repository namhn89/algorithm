#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    int n, k;
    cin >> s >> k;
    n = s.size();
    int cnt0 = 0;
    for (int i = 0; i < n; i++)
        if(s[i] == '0') cnt0 ++;
    if (cnt0 < k) {
        printf("%d\n", n - 1);
        return 0;
    }
    int tmp = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == '0') {
            tmp++;
            if(tmp == k) break;
        } else ans++;
    printf("%d\n", ans);
    return 0;
}
