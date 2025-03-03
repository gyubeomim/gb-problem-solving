#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> len;

// 시간복잡도: O(nlogn)
// while문 : O(n)
// pq push(), top() : O(logn)
int concat() {
  priority_queue<int, vector<int>, greater<int>> pq;
  for ( int i = 0; i < len.size(); i++ ) {
    pq.push( len[i] );
  }

  int ret = 0;
  while ( pq.size() > 1 ) {
    int min1 = pq.top(); pq.pop();
    int min2 = pq.top(); pq.pop();
    pq.push( min1 + min2 );
    ret += min1 + min2;
  }
  return ret;
}

int main( int argc, char **argv ) {
  int C;
  scanf( "%d", &C );

  while ( C-- ) {
    scanf( "%d", &N );

		len.clear();

    for ( int i = 0; i < N; i++ ) {
      int l;
      scanf( "%d", &l );
      len.push_back( l );
    }
    printf( "%d\n", concat() );
  }
}
