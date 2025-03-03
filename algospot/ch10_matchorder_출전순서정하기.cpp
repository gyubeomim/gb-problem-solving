#include <bits/stdc++.h>
using namespace std;

int order( vector<int>& russian, vector<int>& korean ) {
  int wins = 0;

	// 아직 남아 있는 선수들의 레이팅
  multiset<int> ratings( korean.begin(), korean.end() );

  for ( int rus = 0; rus < russian.size(); rus++ ) {
		// 가장 레이팅이 높은 한국 선수가 이길 수 없는 경우
		// 가장 레이팅이 낮은 선수와 연결시킨다
    if ( *ratings.rbegin() < russian[rus] ) {
      ratings.erase( ratings.begin() );
		}
		// 이외의 경우 이길 수 있는 선수 중 가장 레이팅이 낮은 선수와 연결시킨다
    else {
      ratings.erase( ratings.lower_bound( russian[rus] ) );
      wins++;
    }
  }
  return wins;
}

int main( int argc, char** argv ) {
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    int N;
    scanf( "%d", &N );

    vector<int> russian, korean;
    for ( int i = 0; i < N; i++ ) {
      int man;
      scanf( "%d", &man );
      russian.push_back( man );
    }
    for ( int i = 0; i < N; i++ ) {
      int man;
      scanf( "%d", &man );
      korean.push_back( man );
    }

    int ans = order( russian, korean );
    printf( "%d\n", ans );
  }
}
