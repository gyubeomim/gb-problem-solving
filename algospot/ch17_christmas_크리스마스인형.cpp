#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int LM = 100005;
const int MOD = 20091101;

int N, K;
int D[LM];
vector<int> psum;

// 몇가지 방법으로 살 수 있는지 반환하는 함수 (psum[H-1] == psum[T] 이용)
int waysToBuy() {
  int ret = 0;

  // psum의 값을 몇번이나 본 적 있는지 기록한다
  vector<ll> count( K, 0 );
  for ( int i = 0; i < psum.size(); i++ )
    count[psum[i]]++;

  // 두 번 이상 본 적 있다면 이 값 중 두 개를 선택하는 방법의 수를 더한다
  for ( int i = 0; i < K; i++ )
    if ( count[i] >= 2 ) {
      ret = ( ret + ( ( count[i] * ( count[i] - 1 ) ) / 2 ) ) % MOD;
		}

  return ret;
}

// 겹치지 않게 몇 번이나 살 수 있는지 반환하는 함수
int maxBuys() {
  // ret[i] : 첫번째 상자부터 i번째 상자까지 고려했을 때 살 수 있는 최대 횟수
  vector<int> ret( psum.size(), 0 );

  // prev[i] : prev이 i였던 마지막 위치
  vector<int> prev( K, -1 );

  for ( int i = 0; i < psum.size(); i++ ) {
    // i번째 상자를 아예 고려하지 않은 경우
    if ( i > 0 )
      ret[i] = ret[i - 1];
    else
      ret[i] = 0;

    // psum[i]를 전에도 본 적이 있으면 prev[psum[i]]+1부터 여기까지 쭉 사 본다
    int loc = prev[psum[i]];
    if ( loc != -1 ) ret[i] = max( ret[i], ret[loc] + 1 );

    // prev에 현재 위치를 기록한다
    prev[psum[i]] = i;
  }
  return ret.back();
}

int main( int argc, char** argv ) {
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d%d", &N, &K );

    psum.resize( N + 1 );

		// psum의 첫번째 원소 전에 0을 삽입했다고 가정한다 (psum[-1] = 0과 같은 효과)
    psum[0] = 0;  

    for ( int i = 1; i <= N; i++ ) {
      scanf( "%d", &D[i] );
      if ( i == 1 )
        psum[1] = D[i] % K;
      else
        psum[i] = ( psum[i - 1] + D[i] % K ) % K;
    }

    int ans1 = waysToBuy();
    int ans2 = maxBuys();
    printf( "%d %d\n", ans1, ans2 );
  }
}
