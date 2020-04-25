#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+1;
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
 int n, x;
ll ans;
stack<int> st;
map<int,int> cnt;

int main() {
    scanf("%d\n", &n);
    while (n--) {
        scanf("%d\n", &x);
        while (!st.empty() && x > st.top()) {
            cnt[st.top()]--;
            st.pop();
            ans++;
        }
        if (!st.empty())
            ans += x==st.top() ? cnt[x] + (st.size() > cnt[x]) : 1;
        st.push(x);
        cnt[x]++;
    }
    printf("%lld\n", ans);

    return 0;
}

