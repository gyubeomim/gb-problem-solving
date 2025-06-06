#include <bits/stdc++.h>
using namespace std;

int N, M;
string digits;

int append( int here, int edge, int mod ) {
  int there = here * 10 + edge;
  if ( there >= mod ) return mod + there % mod;
  return there % mod;
}

// digis에 속한 숫자들만으로 구성되고 C mod n == m 인 최소의 C를 찾는다
string gifts() {
  // 간선의 번호를 오름차순으로 정렬해두면 사전순으로 가장 앞에 있는 경로를 찾을 수 있다
  sort( digits.begin(), digits.end() );

  // 흰색 정점 i는 0 ~ n-1, 회색 정점 j는 n ~ 2n-1로 표현한다
  // parent[i] = BFS 스패닝 트리에서 정점 i의 부모
  // choice[i] = parent[i]에서 i로 연결된 간선의 번호
  vector<int> parent( 2 * N, -1 ), choice( 2 * N, -1 );

  queue<int> q;

  // 흰색 0번을 큐에 추가
  parent[0] = 0;
  q.push( 0 );

  while ( !q.empty() ) {
    int here = q.front();
    q.pop();
    for ( int i = 0; i < digits.size(); i++ ) {
      // 간선 digits[i]-'0'을 따라가본다
      int there = append( here, digits[i] - '0', N );
      if ( parent[there] == -1 ) {
        parent[there] = here;
        choice[there] = digits[i] - '0';
        q.push( there );
      }
    }
  }

  // 회색 m번에 도달하지 못했으면 실패
  if ( parent[N + M] == -1 ) return "IMPOSSIBLE";

  // 부모로 가는 연결을 따라가면서 C를 계산한다
  string ret;
  int here = N + M;
  while ( parent[here] != here ) {
    ret += char( '0' + choice[here] );
    here = parent[here];
  }
  reverse( ret.begin(), ret.end() );
  return ret;
}

int main( int argc, char **argv ) {
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    cin >> digits >> N >> M;
    string ans = gifts();
    printf( "%s\n", ans.c_str() );
  }
}
