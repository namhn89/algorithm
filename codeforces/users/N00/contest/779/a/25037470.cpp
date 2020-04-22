#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define remove_duplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

typedef long long longint;

int cX[105], cY[105];
int c[105];


int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cX[x]++;
    }
    for (int i = 1; i <= n; i++) {
        int y;
        cin >> y;
        cY[y]++;
    }
    int res = 0;
    for (int value = 1; value <= 5; value++) {
        if ((cX[value] + cY[value]) % 2 == 1) return cout << -1, 0;
        c[value] = (cX[value] + cY[value]) / 2;
    }
    int thieu = 0, thua = 0;
    for (int value = 1; value <= 5; value++) {
        if (cX[value] < c[value]) thieu += c[value] - cX[value];
        else thua += cX[value] - c[value];
    }

    cout << (thieu + thua) / 2;

    return 0;
}
