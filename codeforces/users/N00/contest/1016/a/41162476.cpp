#include <bits/stdc++.h>
using namespace std;

#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

const long long N = 2e5 + 10; 
long long n, L; 
long long a[N]; 

int main()
{
    #define file "A"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    cin >> n >> L;
    long long total = 0;  
    long long ret = 0; 
    for (long long i = 1; i <= n; i++) { 
    	long long x; 
    	cin >> x; 
    	total += x; 
    	cout << total / L << " "; 
    	total %= L; 
    }


    return 0;
}

