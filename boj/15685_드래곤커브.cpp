#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100+1;
int n;
int ans = 0;
int map[MAX][MAX] = {0};

void draw_curve(int x, int y, int d, int g) {
  map[x][y] = 1;

  vector<int> seq;
  vector<int> tmp;

  seq.push_back(d);

  for (int i = 0; i < g; i++) {
    for (auto rit = seq.rbegin(); rit != seq.rend(); rit++) {
      int num = (*rit + 1) % 4;
      tmp.push_back(num);
    }
    seq.insert(seq.end(), tmp.begin(), tmp.end());
    tmp.clear();
  }

  int nx = x;
  int ny = y;
  for (int i = 0; i < seq.size(); i++) {
    if (seq[i] == 0) {
      nx += 1;
    } else if (seq[i] == 1) {
      ny -= 1;
    } else if (seq[i] == 2) {
      nx -= 1;
    } else if (seq[i] == 3) {
      ny += 1;
    }
    if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX)
      map[nx][ny] = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, d, g;
    cin >> x >> y >> d >> g;
    draw_curve(x, y, d, g);
  }

  for (int i = 0; i < MAX-1; i++) {
    for (int j = 0; j < MAX-1; j++) {
      if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
        ans += 1;
    }
  }
  cout << ans << '\n';

  return 0;
}