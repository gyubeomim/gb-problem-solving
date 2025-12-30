#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>

using namespace std;

int d[10001][3];
int B[10001];

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  int A;
  vector<int> v;

  for(int i=1; i<=n; i++) {
    // cin >> A;
    // v.push_back(A);
    cin >> B[i];
  }

  // d[1][0] = 0;
  // d[1][1] = v.at(0);
  // d[1][2] = v.at(0);

  // d[2][0] = v.at(0);
  // d[2][1] = v.at(1);
  // d[2][2] = d[1][1] + v.at(1);

  d[1][0] = 0;
  d[1][1] = B[1];
  d[1][2] = B[1];

  d[2][0] = B[1];
  d[2][1] = B[2];
  d[2][2] = d[1][1] + B[2];

  for(int i=3; i<=n; i++) {
    d[i][0] = std::max({d[i-1][0],d[i-1][1],d[i-1][2]});
    d[i][1] = d[i-1][0] + B[i];
    d[i][2] = d[i-1][1] + B[i];
  }

  cout << std::max({d[n][0], d[n][1], d[n][2]}) << endl;

  return 0;
}
