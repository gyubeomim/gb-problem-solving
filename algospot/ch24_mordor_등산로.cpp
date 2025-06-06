#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int, int>;
using ll = long long;
using namespace std;

struct SegTree {
  int n;                 // 배열의 길이
  vector<int> rangeMin;  // 각 구간의 최소치

  SegTree( const vector<int>& array ) {
    n = array.size();
    rangeMin.resize( n * 4 );
    init( array, 0, n - 1, 1 );
  }

  // node 노드가 array[left...right] 배열을 표현할 때 node를 루트로 하는 서브트리를 초기화하고 이 구간의 최소치를 반환한다
  int init( const vector<int>& array, int left, int right, int node ) {
    if ( left == right )
      return rangeMin[node] = array[left];

    int mid = ( left + right ) / 2;
    int leftMin = init( array, left, mid, node * 2 );
    int rightMin = init( array, mid + 1, right, node * 2 + 1 );
    return rangeMin[node] = min( leftMin, rightMin );
  }

  int query( int left, int right, int node, int nodeLeft, int nodeRight ) {
    if ( right < nodeLeft || nodeRight < left ) return INT_MAX;

    if ( left <= nodeLeft && nodeRight <= right ) return rangeMin[node];

    int mid = ( nodeLeft + nodeRight ) / 2;
    return min( query( left, right, node * 2, nodeLeft, mid ),
                query( left, right, node * 2 + 1, mid + 1, nodeRight ) );
  }

  int query( int left, int right ) {
    return query( left, right, 1, 0, n - 1 );
  }

  int update( int index, int newValue, int node, int nodeLeft, int nodeRight ) {
    // index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다
    if ( index < nodeLeft || nodeRight < index ) return rangeMin[node];

    if ( nodeLeft == nodeRight ) return rangeMin[node] = newValue;
    int mid = ( nodeLeft + nodeRight ) / 2;
    return rangeMin[node] = min(
               update( index, newValue, node * 2, nodeLeft, mid ),
               update( index, newValue, node * 2 + 1, mid + 1, nodeRight ) );
  }

  int update( int index, int newValue ) {
    return update( index, newValue, 1, 0, n - 1 );
  }
};

int N, Q;
vector<int> board;
vector<int> mboard;

int main( int argc, char** argv ) {
  // freopen("t.txt", "r", stdin);
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d%d", &N, &Q );

    board.clear();
    mboard.clear();

    for ( int i = 0; i < N; i++ ) {
      int a;
      scanf( "%d", &a );
      board.push_back( a );
      mboard.push_back( -a );
    }

    SegTree boardMin( board );
    SegTree boardMax( mboard );

    for ( int i = 0; i < Q; i++ ) {
      int a, b;
      scanf( "%d%d", &a, &b );
      int ans = -boardMax.query( a, b ) - boardMin.query( a, b );
      printf( "%d\n", ans );
    }
  }
}
