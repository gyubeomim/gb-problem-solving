#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int, int>;
using ll = long long;
using namespace std;

const int LM = 100000;
int n;
vector<int> child[LM];

struct RMQ {
  int n;                 // 배열의 길이
  vector<int> rangeMin;  // 각 구간의 최소치

  RMQ( const vector<int>& array ) {
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

int no2serial[LM];  // 트리 번호에 대응하는 일련번호
int serial2no[LM];  // 일련번호에 대응하는 트리 번호
int locInTrip[LM];  // 각 노드가 trip에 처음 등장하는 위치
int depth[LM];
int nextSerial;  // 다음 일련번호

// 깊이가 d인 노드 here 이하를 전위 탐색한다
void traverse( int here, int d, vector<int>& trip ) {
  no2serial[here] = nextSerial;
  serial2no[nextSerial] = here;
  ++nextSerial;
  depth[here] = d;

  locInTrip[here] = trip.size();
  trip.push_back( no2serial[here] );

  for ( int i = 0; i < child[here].size(); i++ ) {
    traverse( child[here][i], d + 1, trip );
    trip.push_back( no2serial[here] );
  }
}

RMQ* prepareRMQ() {
  nextSerial = 0;
  vector<int> trip;
  traverse( 0, 0, trip );
  return new RMQ( trip );
}

int distance( RMQ* rmq, int u, int v ) {
  int lu = locInTrip[u], lv = locInTrip[v];
  if ( lu > lv ) swap( lu, lv );

  int lca = serial2no[rmq->query( lu, lv )];
  return depth[u] + depth[v] - 2 * depth[lca];
}

int N, Q;

int main( int argc, char** argv ) {
  // freopen("t.txt", "r",stdin);
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d%d", &N, &Q );

    for ( int i = 0; i < LM; i++ )
      child[i].clear();

    for ( int i = 1; i < N; i++ ) {
      int p;
      scanf( "%d", &p );
      child[p].push_back( i );
    }

    RMQ* segtree = prepareRMQ();
    for ( int i = 0; i < Q; i++ ) {
      int a, b;
      scanf( "%d%d", &a, &b );

      int ans = distance( segtree, a, b );
      printf( "%d\n", ans );
    }
  }
}
