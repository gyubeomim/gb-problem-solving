#include <bits/stdc++.h>
using namespace std;

int N;

// 마법의약 레시피와 이미 넣은 재료의 양이 주어질 때 더 넣을 재료의 양을 구한다
vector<int> solve( vector<int> recipe, vector<int> put ) {
  vector<int> ret( N );

  // 각 재료를 최소한 recipe에 적힌 만큼은 넣어야 한다
  for ( int i = 0; i < N; i++ ) {
    ret[i] = max( recipe[i] - put[i], 0 );
    put[i] += ret[i];
  }

  // 비율이 전부 맞을 때까지 재료를 계속 추가하자
  int iter = 0;
  while ( 1 ) {
    ++iter;
    // 냄비에 재료를 더 넣지 않아도 될 때까지 반복한다
    bool ok = true;
    for ( int i = 0; i < N; i++ ) {
      for ( int j = 0; j < N; j++ ) {
				// i번째 재료에 의하면 모든 재료는 put[i]/recipe[i] = X배 이상은 넣어야 한다
				// 따라서 put[j]는 recipe[j]*X 이상의 정수가 되어야 한다
        int required = ( put[i] * recipe[j] + recipe[i] - 1 ) / recipe[i];

				// 더 넣어야 하는가?
        if ( required > put[j] ) {
          ret[j] += required - put[j];
          put[j] = required;
          ok = false;
        }
      }
    }
    if ( ok ) break;
  }
  return ret;
}

int main( int argc, char **argv ) {
  int C;
  scanf( "%d", &C );

  while ( C-- ) {
    scanf( "%d", &N );

    vector<int> recipe, put;

    for ( int i = 0; i < N; i++ ) {
      int a;
      scanf( "%d", &a );
      recipe.push_back( a );
    }

    for ( int i = 0; i < N; i++ ) {
      int a;
      scanf( "%d", &a );
      put.push_back( a );
    }

    vector<int> ret = solve( recipe, put );

    for ( auto &e : ret ) {
      printf( "%d ", e );
    }
    puts( "" );
  }
}
