#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int max_value = 0;

  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> plus(n);
  vector<int> minus(n);

  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  for(int i=0; i<n; i++) {
    plus[i] = 1;
    for(int j=0; j<i; j++) {
      if(a[j] < a[i] && plus[i] < plus[j] + 1) {
        plus[i] = plus[j] + 1;
      }
    }
  }

  for(int i=n-1; i>=0; i--) {
    minus[i] = 1;
    for(int j=n-1; j>i; j--){
      if(a[j]  < a[i] && minus[i] < minus[j]+1) {
        minus[i] = minus[j] + 1;
      }
    }
  }

  for(int i=0; i<n; i++) {
    max_value = std::max(max_value, plus[i] + minus[i] - 1);
  }

  cout << max_value << '\n';



  return 0;
}
