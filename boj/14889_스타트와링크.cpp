#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using ll  = long long;
using ull = unsigned long long;
using namespace std;

constexpr int LM = 20;
int S[LM][LM]    = {0};

int main( )
{
  int N;
  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      scanf("%d", &S[i][j]);
    }
  }

  // for(int i = 0; i < N; i++) {
  //   for(int j = 0; j < N; j++) {
  //     printf("%d ", S[i][j]);
  //   }
  //   printf("\n");
  // }

  vector<int> tmp(N, 1);
  for(int i = 0; i < N / 2; i++) {
    tmp[i] = 0;
  }

  int ans = (int) 2e9;
  do {
    vector<int> start, link;
    int sumA = 0;
    int sumB = 0;

    for(int i = 0; i < N; i++) {
      if(tmp[i] == 0)
        start.push_back(i);
      else
        link.push_back(i);
    }

    for(int i = 0; i < N / 2; i++) {
      for(int j = 0; j < N / 2; j++) {
        if(i == j) continue;
        // printf("i: %d, j: %d, tmp[i]: %d, tmp[j]: %d, S[tmp[i]][tmp[j]]: %d, sumA: %d\n", i, j, tmp[i], tmp[j], S[tmp[i]][tmp[j]], sumA);
        sumA += S[start[i]][start[j]];
        sumB += S[link[i]][link[j]];
      }
    }

    // printf("N : %d, sumA: %d, sumB: %d\n", N, sumA, sumB);
    ans = min(ans, abs(sumA - sumB));

  } while(next_permutation(tmp.begin( ), tmp.end( )));

  printf("%d", ans);
}
