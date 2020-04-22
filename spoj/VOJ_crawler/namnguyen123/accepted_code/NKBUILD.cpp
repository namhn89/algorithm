#include <bits/stdc++.h>
using namespace std;

const int LimitN = 2e5 + 5;
const int LimitNEdge = 2e5 + 5;
const int LimitNSpeacial = 7;
const long long oo = (long long)(1e18) + 10;
struct TEdge {
    int foo, bar, Cost;
    TEdge (int foo = 0, int bar = 0, int Cost = 0) : foo(foo), bar(bar), Cost(Cost) {}
    int GetAdj (int u) { if (u == foo) return bar; return foo; }
};

struct TState {
    long long F;
    int foo, S;
    TState (long long F = 0, int foo = 0, int S = 0) : F(F), foo(foo), S(S) {};
    bool operator < (const TState &Other) const {
        return F > Other.F;
    }
};

bool Minimize (long long &a, long long b) { if (a > b) a = b; else return false; return true; }



int N, NSpecial, NEdge;
int SpecialValue[LimitN];
TEdge E[LimitNEdge];
long long F[LimitN][(1 << LimitNSpeacial) + 1];
vector<int> G[LimitN];


void Input () {
    scanf("%d %d %d", &N , &NEdge , &NSpecial);
    for (int iSpecial = 0; iSpecial < NSpecial; ++iSpecial) {
        int foo; scanf("%d", &foo);
        SpecialValue[foo] = (1 << iSpecial);
    }
    for (int iEdge = 1; iEdge <= NEdge; ++iEdge) {
        int foo, bar, Cost;
        scanf("%d %d %d", &foo, &bar, &Cost);
        E[iEdge] = TEdge(foo, bar, Cost);
        G[foo].push_back(iEdge);
        G[bar].push_back(iEdge);
    }

}
void Solve () {
    for (int foo = 1; foo <= N; ++foo) {
        for (int S = 0; S < (1 << NSpecial); ++S) {
            F[foo][S] = oo;
        }
    }
    priority_queue<TState> Q;
    for (int foo = 1; foo <= N; ++foo) {
        Q.push(TState(F[foo][SpecialValue[foo]] = 0, foo, SpecialValue[foo]));
    }
    while (not Q.empty()) {
        long long FF = Q.top().F;
        int foo = Q.top().foo;
        int S = Q.top().S;
        Q.pop();
        if (FF != F[foo][S]) continue;
        if (S == ((1 << NSpecial) - 1)) { printf("%lld\n", FF) ; return; }

        int SRemain = (1 << NSpecial) - 1 - S;
        for (int S2 = SRemain; S2 > 0; S2 = (S2 - 1) & SRemain) {
            if (Minimize(F[foo][S + S2], F[foo][S] + F[foo][S2])) {
                Q.push(TState(F[foo][S + S2], foo, S + S2));
            }
        }
        for (int S2 = S; S2 > 0; S2 = (S2 - 1) & S) {
            if (Minimize(F[foo][S2], F[foo][S])) {
                Q.push(TState(F[foo][S2], foo, S2));
            }
        }
        for (int iEdge : G[foo]) {
            int bar = E[iEdge].GetAdj(foo);
            int SMerge = S | SpecialValue[bar];
            if (Minimize(F[bar][SMerge], F[foo][S] + E[iEdge].Cost)) {
                Q.push(TState(F[bar][SMerge], bar, SMerge));
            }
        }
    }
}




int main() {
    #define FILE "NKBUILD"
    //freopen(FILE".inp", "r", stdin); freopen(FILE".out", "w", stdout);
    Input();
    Solve();
}
