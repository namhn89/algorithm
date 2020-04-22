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
const int MAXN = 55;
int n, k;
string s[MAXN];
string a[MAXN];
int answer[MAXN];
int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    int nString = 0;
    for (char c = 'A'; c <= 'B'; c++) {
        for (char c2 = 'a'; c2 <= 'z'; c2++) {
            s[++nString] += c;
            s[nString] += c2;
        }
    }

    cin >> n >> k;
    for (int i = 1; i <= n - k + 1; i++) {
        cin >> a[i];
    }
    if (a[1] == "YES") {
        for (int i = 1; i <= k; i++) answer[i] = i;
    }
    else {
        for (int i = 1; i <= k - 1; i++) answer[i] = i;
        answer[k] = answer[1];
    }
    for (int i = 2; i <= n - k + 1; i++) {
        if (a[i] == "NO") {
            answer[i + k - 1] = answer[i];
        }
        else {
            for (int choose = 1; choose <= nString; choose++) {
                bool ok = true;
                for (int pos = i; pos <= i + k - 2; pos++) {
                    if (answer[pos] == choose) ok = false;
                }
                if (ok) {
                    answer[i + k - 1] = choose;
                    break;
                }
            }
        }
    }

    /*for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    */
    for (int i = 1; i <= n; i++) {
        cout << s[answer[i]] << " ";
    }
    return 0;
}
