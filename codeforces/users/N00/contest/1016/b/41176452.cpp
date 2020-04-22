#include <bits/stdc++.h>
using namespace std;

#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));


const int N = 1e5 + 10;

int ns, nt, nq;
char s[N], t[N];
int occ[N];


bool check (int pos) {
	for (int i = pos; i <= pos + nt - 1; i++)
		if (s[i] != t[i - pos + 1]) return false;
	return true;
}

int main()
{
    #define file "B"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    cin >> ns >> nt >> nq;
    cin >> s + 1;
    cin >> t + 1;
    for (int is = 1; is + nt - 1 <= ns; is++) {
    	occ[is] = occ[is - 1];
    	if (check(is)) {
    		occ[is]++;
    	}
    }
    for (int iq = 1; iq <= nq; iq++) {
    	int l, r;
    	cin >> l >> r;
    	cout << occ[max(l - 1, r - nt + 1)] - occ[l - 1] << endl;
    }
    return 0;
}
