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

  int ans = (int) 2e9;

  for(int k = 1; k <= N / 2; k++) {
    vector<int> tmp(N, 1);
    for(int i = 0; i < k; i++) {
      tmp[i] = 0;
    }

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

      for(int i = 0; i < start.size(); i++) {
        for(int j = 0; j < start.size(); j++) {
          if(i == j) continue;
          // printf("i: %d, j: %d\n", i, j);
          // if(start.size( ) < i + 1 || start.size( ) < j + 1) continue;
          sumA += S[start[i]][start[j]];
          // if(link.size( ) < i + 1 || link.size( ) < j + 1) continue;
        }
      }

      for(int i = 0; i < link.size(); i++) {
        for(int j = 0; j < link.size(); j++) {
          if(i == j) continue;
          sumB += S[link[i]][link[j]];
        }
      }
      // printf("N : %d, sumA: %d, sumB: %d, ans %d\n", N, sumA, sumB, ans);
      if(sumA != 0 && sumB != 0)
        ans = min(ans, abs(sumA - sumB));

    } while(next_permutation(tmp.begin( ), tmp.end( )));
  }
  printf("%d", ans);
}
