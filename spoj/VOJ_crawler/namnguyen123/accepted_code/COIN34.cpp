#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iomanip>
#include <limits>
#include <bitset>
#include <locale>
#include <cstdio>
#include <vector>
#include <cfloat>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <list>
#include <map>
#include <set>
 
using namespace std;
 
int coin [34], maxs = 59139, maxcoin [59139], x, res;
 
void backtrack1 (int t, int cnt, int s)
{
	if (t > 17)
	{
		maxcoin [s] = max (maxcoin [s], cnt);
		return;
	}
	backtrack1 (t + 1, cnt, s);
	backtrack1 (t + 1, cnt + 1, s + coin [t]);
}
 
void init ()
{
	coin [1] = 2; coin [2] = 3; coin [3] = 5;
	for (int i = 4; i <= 34; ++i) coin [i] += coin [i - 1] + coin [i - 2] + coin [i - 3];
	memset (maxcoin, -1, sizeof maxcoin);
	backtrack1 (1, 0, 0);
}
 
void backtrack2 (int t, int cnt, int s)
{
	
	if (t > 34)
	{
		if (s <= x && x - s < maxs && maxcoin [x - s] != -1)
			res = max (res, cnt + maxcoin [x - s]);
		return;
	}
	backtrack2 (t + 1, cnt, s);
	backtrack2 (t + 1, cnt + 1, s + coin [t]);
}
 
void solve ()
{
	scanf ("%d", &x);
	res = -1;
	backtrack2 (18, 0, 0);
	printf ("%d\n", res);
}
int main ()
{
	init ();
	int t; scanf ("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		printf ("Case #%d: ", i);
		solve ();
	}
	return 0;
}
 