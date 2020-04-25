using namespace std;
#include<bits/stdc++.h>

const unsigned long long num[] = {2 , 3 , 31 , 7 , 5 };

unsigned long long power (unsigned long long a , unsigned long long n , unsigned long long mod) {
    unsigned long long res = 1 ;
    while(n){
        if (n & 1) res = (res * a) % mod ;
        a = (a * a) % mod ;
        n >>= 1 ;
    }
    return res ;
}

bool test(unsigned long long a , unsigned long long d , int s , unsigned long long n)
{
    unsigned long long res = power(a , d , n);
    if (res == 1 || res == n - 1) return 1;
    else
    {
        for (int r = 1 ; r < s; ++r)
        {
            res *= res;
            res %= n;
            if (res == n - 1) return 1;
        }
    }
    return 0;
}

bool Rabin_Miller(unsigned long long n)
{
    unsigned long long d = n - 1 , s = 0;
    while (d % 2 == 0)
    {
        d /= 2 ;
        s++;
    }
    bool ans = 1;
    for (int i = 0 ; i < 3 && ans && num[i] < n; ++i)
        ans = test(num[i] , d , s , n);
    return ans;
}

int main()
{
    //freopen("PAGAIN.inp", "r", stdin);
    //freopen("PAGAIN.out", "w", stdout);
    int Test ;
    scanf("%d",&Test) ;
    while (Test--)
    {
        unsigned long long n;
        scanf("%llu", &n);
        while (1)
        {
            n--;
            if (Rabin_Miller(n))
            {
                printf("%llu\n", n);
                break;
            }
        }
    }
}
