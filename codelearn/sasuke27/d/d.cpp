using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e3 + 100;
const int MOD = 1e9 + 7; 

int used[50]; 
int ans = 0; 
int a[50], a1[50], a2[50];
int f[N];

int countCase(int n)
{
    int nn = 0;
    for (int i = 1; i * i <= n; i++) a[nn++] = i * i;
    int n1 = nn/2;
    int n2 = nn - n1;
    for (int i = 0; i < n1; i++) a1[i] = a[i];
    for (int i = n1; i < nn; i++) a2[i - n1] = a[i];

    sort(a1, a1 + n1, greater <int>());
    sort(a2, a2 + n2, greater <int>());

    int res = 0;
    for (int mask = 0; mask < (1 << n2); mask++) {
        int sum = 0;
        for (int i = 0; i < n2; i++)
            if ((mask >> i) & 1) {
                sum += a2[i];
                if (sum > n) break;
            }
            if (sum > n) continue;
        f[sum]++;
    }

   for (int mask = 0; mask < (1 << n1); mask++) {
        int sum = 0;
        for (int i = 0; i < n1; i++)
            if ((mask >> i) & 1) {
                sum += a1[i];
                 if (sum > n) break;
            }
            if (sum > n) continue;
        res += f[n - sum];
    }
    return res;

}

int main() {

  cout << countCase(100) << endl; 
}