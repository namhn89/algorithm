#include<bits/stdc++.h>
using namespace std;
int k, h;
string s;

int main() {

    scanf("%d%d", &k,&h);
    while (k > 0) {
        s = char(k%2+'0') + s;
        k /= 2;
    }
    cout << s;

    return 0;
}
