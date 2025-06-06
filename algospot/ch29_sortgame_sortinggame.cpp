#include <bits/stdc++.h>
using namespace std;

int N;

#if 0
// TLE
int bfs(const vector<int>& perm){
  int n = perm.size();
  vector<int> sorted = perm;
  sort(sorted.begin(), sorted.end());

  // 방문 목록(큐)과 시작점부터 각 정점까지의 거리
  queue<vector<int>> Q;
  map<vector<int>, int> distance;

  // 시작점을 큐에 넣는다
  Q.push(perm);
  distance[perm] = 0;

  while(!Q.empty()){
    vector<int> here = Q.front(); Q.pop();

    if(here == sorted) 
      return distance[here];

    int cost = distance[here];
    
    for(int i=0; i<n;i++){
      for(int j=i+2; j<=n; j++){
        reverse(here.begin() + i, here.begin() + j);
        if(distance.count(here) == 0){
          distance[here] = cost+1;
          Q.push(here);
        }
        reverse(here.begin() + i, here.begin() + j);
      }
    }
  }
  return -1;
}
#endif

map<vector<int>, int> toSort;

void precalc( int n ) {
  vector<int> perm( n );
  for ( int i = 0; i < n; i++ ) perm[i] = i;

  queue<vector<int>> q;
  q.push( perm );

  toSort[perm] = 0;

  while ( !q.empty() ) {
    vector<int> here = q.front();
    q.pop();
    int cost = toSort[here];

    for ( int i = 0; i < n; i++ ) {
      for ( int j = i + 2; j <= n; j++ ) {
        reverse( here.begin() + i, here.begin() + j );
        if ( toSort.count( here ) == 0 ) {
          toSort[here] = cost + 1;
          q.push( here );
        }
        reverse( here.begin() + i, here.begin() + j );
      }
    }
  }
}

int solve( const vector<int>& perm ) {
  int n = perm.size();
  vector<int> fixed( n );

  for ( int i = 0; i < n; i++ ) {
    int smaller = 0;
    for ( int j = 0; j < n; j++ )
      if ( perm[j] < perm[i] )
        ++smaller;
    fixed[i] = smaller;
  }

  return toSort[fixed];
}

int main( int argc, char** argv ) {
  // freopen("s_in_1233.txt", "r", stdin);
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d", &N );

    vector<int> perm;
    for ( int i = 0; i < N; i++ ) {
      int a;
      scanf( "%d", &a );
      perm.push_back( a );
    }

    precalc( N );
    int ans = solve( perm );
    printf( "%d\n", ans );
  }
}
