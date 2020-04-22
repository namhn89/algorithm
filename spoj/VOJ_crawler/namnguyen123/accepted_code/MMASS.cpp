#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int main() {
    string s; stack<int> st;

    cin >> s;
    FOR(i,0,s.size()-1) {
        if (s[i] == '(') st.push(-1);
        else if (s[i] == 'C') st.push(12);
        else if (s[i] == 'H') st.push(1);
        else if (s[i] == 'O') st.push(16);
        else if ('2' <= s[i] && s[i] <= '9') {
            int x = st.top() * (s[i] - '0');
            st.pop(); st.push(x);
        }
        else {
            int x = 0;
            for (;;) {
                int y = st.top(); st.pop();
                if (y == -1) break;
                x += y;
            }
            st.push(x);
        }
    }

    int ans = 0;
    while (! st.empty()) ans += st.top(), st.pop();

    printf("%d\n", ans);

    return 0;
}
