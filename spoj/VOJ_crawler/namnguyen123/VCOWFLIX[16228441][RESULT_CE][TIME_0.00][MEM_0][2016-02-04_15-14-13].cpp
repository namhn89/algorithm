#include <ctime>
#include <cctype>
#include <cmath>

using namespace std;

typedef long long longs;

int main()
{
    int A[16], N, C, i, x;

    cin >> C >> N;
    for (i = 0; i < N; ++i) cin >> A[i];

    int res = 0;
    for (x = 0; x < 1 << N; ++x)
    {
        int S = 0;
        for (i = 0; i < N; ++i)
        {
            if ((x >> i) & 1) S += A[i];
        }
        if (S > res && S <= C) res = S;
    }

    cout << res;

    return 0;
}  