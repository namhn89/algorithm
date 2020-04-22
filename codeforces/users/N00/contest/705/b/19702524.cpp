#include<bits/stdc++.h>
using namespace std;

int n;
int a[300010];

main()
{ cin >> n;
  for(int i=0; i<n; ++i) cin >> a[i];
  int ans=0;
  for(int i=0; i<n; ++i)
  { ans=ans^!(a[i]%2);
    if(ans) cout << "1\n";
    else cout << "2\n";
  }
}