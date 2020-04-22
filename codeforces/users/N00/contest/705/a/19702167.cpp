#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];

main()
{ cin >> n;
  for(int i=1; i<n; ++i)
  { if(i%2==0) cout << "I love that ";
	if(i%2==1) cout << "I hate that ";
  }
  if(n%2==1) cout << "I hate it ";
  else cout << "I love it ";
}
