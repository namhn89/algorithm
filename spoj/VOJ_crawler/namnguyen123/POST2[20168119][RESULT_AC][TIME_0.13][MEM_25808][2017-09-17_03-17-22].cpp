using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const double PI = acos((double) -1.0);
const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;

typedef complex <double> cplex ;
const int N = (1 << 18) + 1 ;
const int NBIT = 18;
cplex W[N] , anext[N] ;
/*

int revBit(int nbit , int mask)
{
    for(int i = 0 , j = nbit - 1 ; i <= j ; ++i , --j)
    {
        if( (mask >> i & 1) != (mask >> j & 1) )
        {
            mask ^= 1 << i;
            mask ^= 1 << j;
        }
    }
    return mask;
}

void fft (cplex a[] , int n , bool invert ) {
    for(int i = 0; i < n ; ++i ) {
        int j = revBit(NBIT , i);
        if(i < j) swap(a[i] , a[j]);
    }
    for(int step = 1 ; step < n ; step <<= 1) {
        double ang = PI / step ;
        if (invert) ang = -ang;

        cplex w(1 , 0) , wn (cos(ang) , sin(ang)) ;
        for(int i = 0 ; i < step ; ++i ) {
            W[i] = w ;
            w *= wn ;
        }
        int start_even = 0;
        int start_odd  = start_even + step;
        while(start_even < n)
        {
            for(int i = 0; i < step; ++i)
            {
                anext[start_even + i]        = a[start_even + i] + W[i] * a[start_odd + i];
                anext[start_even + i + step] = a[start_even + i] - W[i] * a[start_odd + i];
            }
            start_even += 2 * step;
            start_odd   = start_even + step;
        }
        for(int i = 0; i < n; ++i)
            a[i] = anext[i];
       }
       if (invert) {
        for(int i = 0; i < n; ++i)
            a[i] /= n ;
    }
}
*/
cplex x[N] ;
int rev[N] ;
void fft(cplex input[], int n, bool invert) {
    int dig = 0;
    while ((1 << dig) < n) {
        ++dig;
    }
    for (int i = 0; i < n; ++i) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (dig - 1));
        if (rev[i] > i) {
            swap(input[i] , input[rev[i]]);
        }
    }
    for (int len = 2 ; len <= n ; len <<= 1) {
        double angle = 2 * PI / len;
        if (invert) {
            angle *= -1;
        }
        cplex w(cos(angle), sin(angle));
        x[0] = cplex(1);
        for (int i = 1; i < len / 2; ++i) {
            x[i] = x[i - 1] * w;
        }
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len / 2; ++j) {
                cplex a = input[i + j];
                cplex b = x[j] * input[i + j + len / 2];
                input[i + j] = a + b;
                input[i + j + len / 2] = a - b;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; ++i) {
            input[i] /= n;
        }
    }
}
const int M = 5e4 ;
int cntA[MAXN] , cntB[MAXN] ;
cplex fx[N] , px[N] ;
int n ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> n ;
    int MaxA = 0 , MaxB = 0 ;
    for(int i = 1 ; i <= n ; ++i ) {
        int u ;
        scanf("%d", &u) ;
        ++cntA[u + M] ;
        MaxA = max(MaxA , u + M) ;
    }
    for(int i = 1 ; i <= n ; ++i ) {
        int u ;
        scanf("%d", &u) ;
        ++cntB[u + M] ;
        MaxB = max(MaxB , u + M) ;
    }
    for(int i = 0 ; i <= 100000 ; ++i ) {
        fx[i] = cplex(cntA[i] , 0) ;
        px[i] = cplex(cntB[i] , 0) ;
    }
    int deg = MaxA + MaxB ;
    int sz = 1 ;
    while (sz < deg + 1) sz <<= 1;
    fft(fx , sz , false) ;
    fft(px , sz , false) ;
    for(int i = 0 ; i < sz ; ++i ) fx[i] = fx[i] * px[i] ;
    long long res = 0 ;
    fft(fx , sz , true) ;
    for(int i = 1 ; i <= n ; ++i ) {
        int v ;
        cin >> v ;
        res += (long long)(fx[v + M + M].real() + 0.5) ;
    }
    cout << res ;



    return 0;
}
