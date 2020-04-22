#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define remove_duplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

typedef long long longint;

const int MAXN = 200005;
char s[MAXN], t[MAXN];
int a[MAXN];
int n;
bool mark[MAXN];

bool check (int lim) {
    for (int i = 1; i <= n; i++) mark[i] = 0;
    for (int i = 1; i <= lim; i++) mark[a[i]] = 1;
    int ptr = 1;
    for (int i = 1; i <= n; i++) {
        if (mark[i]) continue;
        if (s[i] == t[ptr]) ptr++;
    }
    return ptr == strlen(t + 1) + 1;
}



int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    scanf("%s", s + 1);
    scanf("%s", t + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int lo = 1, hi = n, res = 0;
    while (lo <= hi) {
        int mi = (lo + hi) >> 1;
        if (check(mi)) {
            res = mi;
            lo = mi + 1;
        }
        else hi = mi - 1;
    }
    cout << res;
    return 0;
}
