#include <cstdio>
#include <iostream>

using namespace std;

int N, input[64][64];

void quadTree(int x, int y, int size) {
  int cur = input[y][x];
  bool flag = true;

  for (int i = x; (i < x + size) && flag; i++)
    for (int j = y; (j < y + size) && flag; j++)
      if (cur != input[j][i])
        flag = false;

  if (flag)
    cout << cur;
  else {
    cout << "(";
    quadTree(x, y, size / 2);
    quadTree(x, y + size / 2, size / 2);
    quadTree(x + size / 2, y, size / 2);
    quadTree(x + size / 2, y + size / 2, size / 2);
    cout << ")";
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%1d", &input[j][i]);

  quadTree(0, 0, N);
  return 0;
}