#include<bits/stdc++.h>
using namespace std;
int n, a, b;
typedef long long ll;
void solve(int x) {
    if (x == 0) return ;
    int s = x/5;
    if (s > 0)a = a *(s%2 ? 4 : 6) % 10;
    for (int y = x; y % 5 > 0; y--)
        a = a * (y % 10) % 10;
    solve(x/5);
}

void calA() {
    a = n > 9 ? 6 : 1;
   for(int i=1;i<=n%10;++i)if (i != 5) a = a * i % 10;
    solve(n/5);
}

void calB() {
    int k = 0, t = 0, F[20] = {0};
    for (int i = 5; i <= n; i *= 5) F[++t] = n / i;
    for(int i=1;i<=t;++i) k += i * (F[i] - F[i+1]);
    b = 1;
    k = (k-1+4)%4 + 1;
    for(int i=1;i<=k;++i)b = b * 2 % 10;
}

int main() {
    cin>>n;
   // if (n == 0) {puts("1"); return 0;}
    calA();
    calB();
    for (int i = 2; i <= 8; i += 2)
        if (b * i % 10 == a) n = i;
    cout<<n<<endl;

    return 0;
}
