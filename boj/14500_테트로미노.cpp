#include <algorithm>
#include <iostream>

using namespace std;

struct Tetromino {
  int r1, r2, r3, r4;
  int c1, c2, c3, c4;

  void SetForm(int type, int r, int c) {
    r1 = r;
    c1 = c;

    if (type == 1) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1;
      c3 = c1 + 2;

      r4 = r1;
      c4 = c1 + 3;
    } else if (type == 2) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1 + 1;
      c3 = c1;

      r4 = r1 + 1;
      c4 = c1 + 1;
    } else if (type == 3) {
      r2 = r1 + 1;
      c2 = c1;

      r3 = r1 + 1;
      c3 = c1 + 1;

      r4 = r1 + 2;
      c4 = c1 + 1;
    } else if (type == 4) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1 - 1;
      c3 = c1 + 1;

      r4 = r1 - 1;
      c4 = c1 + 2;
    } else if (type == 5) {
      r2 = r1 + 1;
      c2 = c1;

      r3 = r1 + 2;
      c3 = c1;

      r4 = r1 + 3;
      c4 = c1;
    } else if (type == 6) {
      r2 = r1 + 1;
      c2 = c1;

      r3 = r1 + 2;
      c3 = c1;

      r4 = r1 + 2;
      c4 = c1 + 1;
    } else if (type == 7) {
      r2 = r1 + 1;
      c2 = c1;

      r3 = r1;
      c3 = c1 + 1;

      r4 = r1;
      c4 = c1 + 2;
    } else if (type == 8) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1 + 1;
      c3 = c1 + 1;

      r4 = r1 + 2;
      c4 = c1 + 1;
    } else if (type == 9) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1;
      c3 = c1 + 2;

      r4 = r1 - 1;
      c4 = c1 + 2;
    } else if (type == 10) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1 + 1;
      c3 = c1 + 1;

      r4 = r1;
      c4 = c1 + 2;
    } else if (type == 11) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1 - 1;
      c3 = c1 + 1;

      r4 = r1 + 1;
      c4 = c1 + 1;
    } else if (type == 12) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1 - 1;
      c3 = c1 + 1;

      r4 = r1;
      c4 = c1 + 2;
    } else if (type == 13) {
      r2 = r1 + 1;
      c2 = c1;

      r3 = r1 + 1;
      c3 = c1 + 1;

      r4 = r1 + 2;
      c4 = c1;
    } else if (type == 14) {
      r2 = r1 - 1;
      c2 = c1;

      r3 = r1 - 1;
      c3 = c1 + 1;

      r4 = r1 - 2;
      c4 = c1 + 1;
    } else if (type == 15) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1 + 1;
      c3 = c1 + 1;

      r4 = r1 + 1;
      c4 = c1 + 2;
    } else if (type == 16) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1 - 1;
      c3 = c1 + 1;

      r4 = r1 - 2;
      c4 = c1 + 1;
    } else if (type == 17) {
      r2 = r1 + 1;
      c2 = c1;

      r3 = r1 + 1;
      c3 = c1 + 1;

      r4 = r1 + 1;
      c4 = c1 + 2;
    } else if (type == 18) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1 + 1;
      c3 = c1;

      r4 = r1 + 2;
      c4 = c1;
    } else if (type == 19) {
      r2 = r1;
      c2 = c1 + 1;

      r3 = r1;
      c3 = c1 + 2;

      r4 = r1 + 1;
      c4 = c1 + 2;
    }
  }
};

int map[501][501] = {0};
int R, C;

bool CheckBoundary(Tetromino t) {
  // cout<< "R,C: " << R<<", "<<C<<endl;
  if (t.r1 < 0 || t.r1 >= R || t.c1 < 0 || t.c1 >= C) return false;
  if (t.r2 < 0 || t.r2 >= R || t.c2 < 0 || t.c2 >= C) return false;
  if (t.r3 < 0 || t.r3 >= R || t.c3 < 0 || t.c3 >= C) return false;
  if (t.r4 < 0 || t.r4 >= R || t.c4 < 0 || t.c4 >= C) return false;

  return true;
}

int GetScore(Tetromino t) {
  int sum = 0;
  sum = map[t.r1][t.c1] + map[t.r2][t.c2] + map[t.r3][t.c3] + map[t.r4][t.c4];
  // cout<<"sum: "<<sum<<endl;
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      int x;
      cin >> x;
      map[i][j] = x;
      // cout<<"map[i][j]: " << map[i][j] << ' ';
    }
    // cout<<endl;
  }

  Tetromino t;
  int max_score = -9999;

  for (int type = 1; type <= 19; type++) {
    for (int i = -1; i < R + 1; i++) {
      for (int j = -1; j < C + 1; j++) {
        int score = 0;
        t.SetForm(type, i, j);

        if (!CheckBoundary(t)) {
          continue;
        }
        // cout << "t.r2: " << t.r2 << ", t.c2: " << t.c2 << endl;
        // cout << "t.r3: " << t.r3 << ", t.c3: " << t.c3 << endl;
        // cout << "t.r4: " << t.r4 << ", t.c4: " << t.c4 << endl;

        score = GetScore(t);
        if (max_score < score) {
          max_score = score;
        }
      }
    }
  }

  cout << max_score << '\n';

  return 0;
}