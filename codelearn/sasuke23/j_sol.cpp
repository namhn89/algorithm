#include <bits/stdc++.h>
 
int assigment(std::vector<std::vector<int>> cost) {
    // minimum cost assigment problem
    // n^2 * 2^n. If TLE, use hungarian algorithm to speed up.
    int n = (int)cost.size();
    const int INF = int(1e9);
    std::vector<std::vector<int>> dp(n, std::vector<int>(1 << n, INF));
    for (int j = 0; j < n; ++j) {
        dp[0][1 << j] = cost[0][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int mask = 0; mask < 1 << n; ++mask) {
            for (int j = 0; j < n; ++j)
                if (mask & (1 << j)) {
                    dp[i][mask] = std::min(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + cost[i][j]);
                }
        }
    }
    return dp[n - 1][(1 << n) - 1];
}
 
int get_cost(int from, int to) {
    int t = to - from;
    while (t < 5) t += 24;
    return t;
}
 
std::string to_hour(int v) {
    std::string suffix = (v >= 12 ? "PM" : "AM");
    v %= 12;
    if (v == 0) v = 12;
    return std::to_string(v) + " " + suffix;
}
 
int minimumLayover(std::vector<std::string> a, std::vector<std::string> b) {
    std::vector< std::pair<int, int> > pa, pb;
    std::map<std::string, std::pair<int, int>> to_range;
    for (int l = 0; l < 24; ++l) {
        for (int r = 0; r < 24; ++r) {
            std::string hour_range = to_hour(l) + " - " + to_hour(r);
            to_range[hour_range] = std::make_pair(l, r);
        }
    }
 
    int n = (int)a.size();
 
    for (auto s : a) {
        pa.push_back(to_range[s]);
    }
 
    for (auto s : b) {
        pb.push_back(to_range[s]);
    }
 
    int ans = int(1e9);
 
    std::vector<std::vector<int>> cost(n, std::vector<int>(n));
    // O(C(n, n / 2) * O(assignment))
    // currentlen O(C(n, n / 2) * n ^ 2 * 2 ^n)
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) != n / 2) continue;
        for (int i = 0; i < n; ++i) {
            int dir = (mask >> i) & 1;
            for (int j = 0; j < n; ++j) {
                auto fa = pa[i], fb = pb[j];
                cost[i][j] = (dir ? get_cost(fa.second, fb.first) : get_cost(fb.second, fa.first));
            }
        }
 
        int cur = assigment(cost);
        ans = std::min(ans, cur);
    }
 
    return ans;
}
 
int main() {
    int n;
    std::string tmp;
    std::getline(std::cin, tmp);
    n = std::atoi(tmp.c_str());
    std::vector<std::string> a(n), b(n);
    for (auto &s : a) std::getline(std::cin, s);
    for (auto &s : b) std::getline(std::cin, s);
    std::cout << minimumLayover(a, b) << std::endl;
}