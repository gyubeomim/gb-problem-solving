#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int, int>;
using ll = long long;
using namespace std;

vector<vector<int>> adj;

// 두 구간 a,b가 서로 겹치지 않는지 확인한다
bool disjoint( const pii& a, const pii& b ) {
  return a.Y <= b.X || b.Y <= a.X;
}

// meetings[]가 각 팀이 하고 싶어하는 회의 시간의 목록일 때
// 이를 2-SAT 문제로 변환한 뒤 함의 그래프를 생성한다.
// i번 팀은 meetings[2*i] 혹은 meetings[2*i+1] 중 하나의 시간에 회의실을 써야한다
void makeGraph( const vector<pii>& meetings ) {
  int vars = meetings.size();

  // 그래프는 각 변수마다 2개의 정점을 갖는다
  adj.clear();
  adj.resize( vars * 2 );

  for ( int i = 0; i < vars; i += 2 ) {
    // 각 팀은 i번 회의나 j번 회의 둘 중 하나는 해야 한다.
    // (i || j) 절
    int j = i + 1;
    adj[i * 2 + 1].push_back( j * 2 );  // ~i --> j
    adj[j * 2 + 1].push_back( i * 2 );  // ~j --> i
  }

  // 회의를 하나 했으면 남은 회의는 반드시 안해야한다
  for ( int i = 0; i < vars; i += 2 ) {
    // (!i || !j) 절
    int j = i + 1;
    adj[i * 2].push_back( j * 2 + 1 );  // i --> ~j
    adj[j * 2].push_back( i * 2 + 1 );  // j --> ~i
  }

  for ( int i = 0; i < vars; i++ ) {
    for ( int j = 0; j < i; j++ ) {
      // i번 회의가 j번 회의가 서로 겹칠 경우
      if ( !disjoint( meetings[i], meetings[j] ) ) {
        // i번 회의가 열리지 않거나 j번 회의가 열리지 않아야 한다
        // (~j || ~i)절을 추가한다
        adj[i * 2].push_back( j * 2 + 1 );  // i --> ~j
        adj[j * 2].push_back( i * 2 + 1 );  // j --> ~i
      }
    }
  }
}

vector<int> sccId;       // 각 정점의 컴포넌트 번호, 0부터 시작
vector<int> discovered;  // 각 정점의 발견 순서
stack<int> st;           // 정점의 번호를 담는 스택

int sccCounter, vertexCounter;  // 컴포넌트 번호 카운터, 정점 발견 순서 카운터

int scc( int here ) {
  int ret = discovered[here] = vertexCounter++;

  // here를 스택에 넣는다. here의 자손들은 here 위로 들어감
  st.push( here );

  for ( int i = 0; i < adj[here].size(); i++ ) {
    int there = adj[here][i];
    // (here, there)가 트리 간선이라면
    if ( discovered[there] == -1 ) ret = min( ret, scc( there ) );
    // there가 무시해야하는 교차 간선이 아니거나 역방향 간선이라면
    else if ( sccId[there] == -1 )
      ret = min( ret, discovered[there] );
  }

  if ( ret == discovered[here] ) {
    while ( 1 ) {
      int t = st.top();
      st.pop();
      sccId[t] = sccCounter;
      if ( t == here ) break;
    }
    sccCounter++;
  }
  return ret;
}

vector<int> tarjanSCC() {
  sccId = discovered = vector<int>( adj.size(), -1 );
  sccCounter = vertexCounter = 0;

  for ( int i = 0; i < adj.size(); i++ ) {
    if ( discovered[i] == -1 )
      scc( i );
  }

  return sccId;
}

vector<int> solve2SAT() {
  int n = adj.size() / 2;
  vector<int> label = tarjanSCC();

  // 한 변수를 나타내는 두 정점이 같은 강결합요소에 속해 있을 경우 답이 없다
  for ( int i = 0; i < 2 * n; i += 2 )
    if ( label[i] == label[i + 1] )
      return vector<int>();

  // SAT 문제를 푸는 것이 가능하다! 답을 생성하자
  vector<int> value( 2 * n, -1 );

  // Tarjan 알고리즘에서 SCC 번호는 위상 정렬의 역순으로 배정된다
  // SCC 번호의 역순으로 각 정점을 정렬하면 위상 정렬 순서가 된다
  vector<pii> order;
  for ( int i = 0; i < 2 * n; i++ )
    order.push_back( make_pair( -label[i], i ) );

  sort( order.begin(), order.end() );

  for ( int i = 0; i < 2 * n; i++ ) {
    int vertex = order[i].Y;

    int var = vertex / 2;
    int is_true = ( vertex % 2 == 0 );

    if ( value[var] != -1 ) continue;

    // !A가 A보다 먼저 나왔으면 A는 참
    // A가 !A보다 먼저 나왔으면 A는 거짓
    value[var] = !is_true;
  }
  return value;
}

int main( int argc, char** argv ) {
  // freopen("s_in_1122.txt", "r", stdin);
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    int M;
    scanf( "%d", &M );
    vector<pii> meetings;

    for ( int i = 0; i < M; i++ ) {
      int s1, e1, s2, e2;
      scanf( "%d%d%d%d", &s1, &e1, &s2, &e2 );
      meetings.push_back( make_pair( s1, e1 ) );
      meetings.push_back( make_pair( s2, e2 ) );
    }

    makeGraph( meetings );
    vector<int> result = solve2SAT();

    if ( result.size() == 0 )
      printf( "IMPOSSIBLE\n" );
    else {
      printf( "POSSIBLE\n" );
      for ( int i = 0; i < result.size(); i++ ) {
        if ( result[i] == 1 )
          printf( "%d %d\n", meetings[i].X, meetings[i].Y );
      }
    }
  }
}
