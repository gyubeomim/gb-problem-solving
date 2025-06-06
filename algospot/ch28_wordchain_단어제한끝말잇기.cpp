#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<string> graph[26][26];
vector<int> indegree, outdegree;

int N;

void makeGraph( const vector<string>& words ) {
  for ( int i = 0; i < 26; i++ ) {
    for ( int j = 0; j < 26; j++ ) {
      graph[i][j].clear();
    }
  }

  adj = vector<vector<int>>( 26, vector<int>( 26, 0 ) );
  indegree = outdegree = vector<int>( 26, 0 );

  for ( int i = 0; i < words.size(); i++ ) {
    int a = words[i][0] - 'a';
    int b = words[i][words[i].size() - 1] - 'a';
    graph[a][b].push_back( words[i] );
    adj[a][b]++;
    outdegree[a]++;
    indegree[b]++;
  }
}

// 유향 그래프의 인접행렬 adj가 주어질 때 오일러 서킷 혹은 트레일을 계산한다
void getEulerCircuit( int here, vector<int>& circuit ) {
  for ( int there = 0; there < adj.size(); there++ ) {
    while ( adj[here][there] > 0 ) {
      adj[here][there]--;
      getEulerCircuit( there, circuit );
    }
  }
  circuit.push_back( here );
}

// 현재 그래프의 오일러 트레일이나 서킷을 반환한다
vector<int> getEulerTrailOrCircuit() {
  vector<int> circuit;

  // 우선 트레일을 찾아본다: 시작점이 존재하는 경우
  for ( int i = 0; i < 26; i++ ) {
    if ( outdegree[i] == indegree[i] + 1 ) {
      getEulerCircuit( i, circuit );
      return circuit;
    }
  }

  // 아니면 서킷이니 간선에 인접한 아무 정점에서나 시작한다
  for ( int i = 0; i < 26; i++ ) {
    if ( outdegree[i] ) {
      getEulerCircuit( i, circuit );
      return circuit;
    }
  }

  // 모두 실패한 경우 빈 배열을 반환한다
  return circuit;
}

bool checkEuler() {
  int plus1 = 0, minus1 = 0;
  for ( int i = 0; i < 26; i++ ) {
    int delta = outdegree[i] - indegree[i];
    if ( delta < -1 || 1 < delta ) return false;
    if ( delta == 1 ) plus1++;
    if ( delta == -1 ) minus1++;
  }

  return ( plus1 == 1 && minus1 == 1 ) || ( plus1 == 0 && minus1 == 0 );
}

string solve( const vector<string>& words ) {
  makeGraph( words );
  if ( !checkEuler() ) return "IMPOSSIBLE";
  vector<int> circuit = getEulerTrailOrCircuit();
  if ( circuit.size() != words.size() + 1 ) return "IMPOSSIBLE";

  reverse( circuit.begin(), circuit.end() );

  string ret;
  for ( int i = 1; i < circuit.size(); i++ ) {
    int a = circuit[i - 1], b = circuit[i];
    if ( ret.size() ) ret += " ";
    ret += graph[a][b].back();
    graph[a][b].pop_back();
  }
  return ret;
}

int main( int argc, char** argv ) {
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d", &N );

    vector<string> words;
    for ( int i = 0; i < N; i++ ) {
      string w;
      cin >> w;
      words.push_back( w );
    }

    string ans = solve( words );
    printf( "%s\n", ans.c_str() );
  }
}
