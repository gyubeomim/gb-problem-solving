#include <iostream>
#include <cstdio>

using namespace std;

char mat[2201][2201];

void solve(int N, int x, int y) {
  if (N == 1) {
    mat[x][y] = '*';
    return;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1) {
        continue;
      }
      solve(N / 3, x + i * N / 3, y + j * N / 3);
    }
  }
}

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      mat[i][j] = ' ';
    }
  }

  solve(N, 0, 0);

  for (int i = 0; i < N; i++)
    cout << mat[i] << endl;

  return 0;
}