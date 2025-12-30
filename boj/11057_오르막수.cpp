#include <cstdio>
#include <iostream>

using namespace std;

using LL = long long;

LL d[1001][10];


int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  for(int i=0; i<=9; i++) {
    d[1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
        if (j == 0)
          d[i][j] = d[i - 1][j];
        else {
          switch(j) {
            case 9:
              d[i][j] += d[i - 1][j - 9];
            case 8:
              d[i][j] += d[i - 1][j - 8];
            case 7:
              d[i][j] += d[i - 1][j - 7];
            case 6:
              d[i][j] += d[i - 1][j - 6];
            case 5:
              d[i][j] += d[i - 1][j - 5];
            case 4:
              d[i][j] += d[i - 1][j - 4];
            case 3:
              d[i][j] += d[i - 1][j - 3];
            case 2:
              d[i][j] += d[i - 1][j - 2];
            case 1:
              d[i][j] += d[i - 1][j - 1];
              d[i][j] += d[i - 1][j];
              break;
          }
      }
      d[i][j] %= 10007;
    }
  }

  LL result = 0;
  for (int i = 0; i <= 9; i++) {
    result += d[n][i];
  }

  cout << result % 10007 << '\n';

  return 0;
}