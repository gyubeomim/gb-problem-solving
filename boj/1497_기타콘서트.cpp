#include <bits/stdc++.h>
#define X first
#define Y second
using pii = std::pair<int, int>;
using ll = long long;
using namespace std;

int N, M;
ll state[10];

// long long 인자가 주어지면 거기에 있는 1의 개수를 반환해주는 함수
int bitCnt( ll x ) {
  int ret = 0;
  for ( int i = 0; i < max( N, M ); i++ ) {
    ret += ( x >> i ) & 1;
  }
  return ret;
}

int main( int argc, char **argv ) {
  scanf( "%d%d", &N, &M );

  for ( int i = 0; i < N; i++ ) {
    string name, tmp;  // name은 의미없음
    cin >> name >> tmp;
    for ( int j = M - 1; j >= 0; j-- ) {
      state[i] = ( state[i] << 1 ) | ( tmp[j] == 'Y' );
    }
  }

  pii ans = { 0, -1 };  // [ song num, guitar num ]

  for ( int tmp = 0; tmp < ( 1 << N ); tmp++ ) {
    ll comb = 0;

		// 조합한 결과
    for ( int i = 0; i < N; i++ ) {
      if ( ( tmp & ( 1LL << i ) ) == 0 ) continue;
      comb |= state[i];
    }

    int song_num = bitCnt( comb );
    int guitar_num = bitCnt( tmp );

    if ( ans.X < song_num )                              // 1. 연주할 수 있는 곡의 수가 더 많을 때
      ans = { song_num, guitar_num };
    else if ( ans.X == song_num && ans.Y > guitar_num )  // 2. 연주할 수 있는 곡의 수는 같은데 필요한 기타의 수가 더 적을 경우
      ans = { song_num, guitar_num };
  }

  printf( "%d\n", ans.Y );
}
