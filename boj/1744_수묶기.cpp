#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> plus;
  vector<int> minus;

  int one=0;
  int zero=0;

  for(int i=0; i<n; i++) {
    int x;
    cin >> x;

    if(x==1)
      one += 1;
    else if(x>0)
      plus.push_back(x);
    else if(x<0)
      minus.push_back(x);
    else
      zero += 1;
  }

  sort(plus.begin(), plus.end());
  reverse(plus.begin(), plus.end());
  sort(minus.begin(), minus.end());

  if(plus.size()%2 == 1)
    plus.push_back(1);
  if(minus.size()%2 == 1)
    minus.push_back(zero>0 ? 0:1);

  int ans = one;
  for(int i=0; i<plus.size(); i+=2) {
    ans += plus[i]*plus[i+1];
  }
  for(int i=0; i<minus.size(); i+=2) {
    ans += minus[i]*minus[i+1];
  }
  cout << ans << '\n';

  return 0;
}
