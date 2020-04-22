using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 5e2 + 1;
const int mod = 998244353; 

int qpow(int a, int b, int mod)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}
 
int n, l[N], r[N], li[N], cnt;
int dp[N][N];
 
int inv[N], c[N];
 
 
int countLISHard(std::vector<int> l, std::vector<int> r) {
  int n = l.size(); 
  int cnt = 0; 
  for (int i = 0; i < n; i++) {
       r[i]++, li[++cnt] = l[i], li[++cnt] = r[i];
  }
  inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  sort(li + 1, li + cnt + 1);
  cnt = unique(li + 1, li + cnt + 1) - li - 1;
  for (int i = 1; i <= n; i++)
  {
    l[i] = lower_bound(li + 1, li + cnt + 1, l[i]) - (li);
    r[i] = lower_bound(li + 1, li + cnt + 1, r[i]) - (li);
  }
  c[0] = 1;
 
  dp[0][cnt] = 1;
  for (int j = cnt - 1; j >= 1; j--) {
    int len = li[j + 1] - li[j];
 
    for (int i = 1; i <= n; i++)
      c[i] = 1ll * c[i - 1] * (len + i - 1) % mod * inv[i] % mod;
      for (int i = 1; i <= n; i++)
      {
        if (l[i] <= j && j < r[i])
          for (int p = 1, k = i - 1; k >= 0; k--)
            {
              dp[i][j] = (dp[i][j] + 1ll * dp[k][j + 1] * c[p]) % mod;
              p++;
              if (!(l[k] <= j && j < r[k]))
              break;
            }
      }
      for (int i = 0; i <= n; i++)
        dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
    }
    int ans = dp[n][1];
  return ans; 
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}