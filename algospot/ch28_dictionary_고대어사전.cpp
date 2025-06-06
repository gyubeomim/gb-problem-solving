#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH( x ) cout << #x << " : " << x << '\n';
#define PRINT( x ) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int, int>;
using ll = long long;
using namespace std;

vector<vector<int>> adj;
vector<string> words;
int N;

void makeGraph() {
  adj = vector<vector<int>>( 26, vector<int>( 26, 0 ) );

  for ( int j = 1; j < words.size(); j++ ) {
    int i = j - 1;
    int len = min( words[i].size(), words[j].size() );

    for ( int k = 0; k < len; k++ ) {
      if ( words[i][k] != words[j][k] ) {
        int a = words[i][k] - 'a';
        int b = words[j][k] - 'a';
        adj[a][b] = 1;
        break;
      }
    }
  }
}

vector<int> seen, order;

void dfs( int cur ) {
  seen[cur] = 1;
  for ( int next = 0; next < adj.size(); ++next )
    if ( adj[cur][next] && !seen[next] )
      dfs( next );
  order.push_back( cur );
}

// adj에 주어진 그래프를 위상정렬한 결과를 반환한다. 그래프가 DAG가 아니라면 빈 벡터를 반환한다
vector<int> topologicalSort() {
  int m = adj.size();
  seen = vector<int>( m, 0 );
  order.clear();

  for ( int i = 0; i < m; i++ )
    if ( !seen[i] )
      dfs( i );

  reverse( order.begin(), order.end() );

  // puts("[order]");
  // for(auto e : order) printf("%d ", e);
  // puts("");

  // 만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다
  for ( int i = 0; i < m; i++ ) {
    for ( int j = i + 1; j < m; j++ ) {
      if ( adj[order[j]][order[i]] )
        return vector<int>();
    }
  }
  // 없는 경우라면 dfs에서 얻은 순서를 반환한다
  return order;
}

int main( int argc, char **argv ) {
  int C;
  scanf( "%d", &C );
  while ( C-- ) {
    scanf( "%d", &N );

    adj.clear();
    words.clear();

    for ( int i = 0; i < N; i++ ) {
      string w;
      cin >> w;
      words.push_back( w );
    }

    // puts("words");
    // for(auto s : words) cout<<s << " ";
    // puts("");

    makeGraph();

    vector<int> ans = topologicalSort();
    if ( ans.empty() )
      printf( "INVALID HYPOTHESIS\n" );
    else {
      for ( auto e : ans ) {
        printf( "%c", e + 'a' );
      }
      puts( "" );
    }
  }
}
