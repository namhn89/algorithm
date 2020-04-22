#include<bits/stdc++.h>
using namespace std; 

int main () {
    int n, q;
    cin >> n >> q; 
    vector < vector<int> > a(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int &b: a[i]) cin >> b;
    }
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << a[n][k] << endl; 
    }
    return 0;
}