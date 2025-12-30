#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long f[21] = {1};
bool c[21];

int main() {
  for(int i=1; i<=20; i++) {
    f[i] = f[i-1] * i;
  }

  int n;
  cin >> n;

  int what;
  cin >> what;

  if(what == 2) {
    vector<int> a(n);
    for(int i=0; i<n; i++)
      cin >> a[i];

    long long ans = 0;

    for(int i=0; i<n; i++) {
      for(int j=1; j<a[i]; j++) {
        if(c[j] == false)
          ans += f[n-i-1];
      }
      c[a[i]] = true;
    }
    cout << ans+1 << '\n';
  }
  else if(what == 1) {
    long long k;
    cin >> k;
    vector<int> a(n);

    for(int i=0; i<n; i++) {
      for(int j=1; j<=n; j++) {
        if(c[j] == true) continue;
        if(f[n-i-1] < k)
          k -= f[n-i-1];
        else {
          a[i] = j;
          c[j] = true;
          break;
        }
      }
    }
    for(int i=0; i<n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
