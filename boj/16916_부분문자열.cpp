#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

vector<int> failure( string& s ) {
  vector<int> f( s.size() );
  int j = 0;

  for ( int i = 1; i < s.size(); i++ ) {
    while ( j > 0 && s[i] != s[j] ) j = f[j - 1];
    if ( s[i] == s[j] ) f[i] = ++j;
  }
  return f;
}

int main( int argc, char** argv ) {
  string s, p;
  cin >> s >> p;

	// KMP 
  vector<int> f = failure( p );

  int j = 0;
  for ( int i = 0; i < s.size(); i++ ) {
    while ( j > 0 && s[i] != p[j] ) j = f[j - 1];
    if ( s[i] == p[j] ) j++;
    if ( j == p.size() ) {
      printf( "1\n" );
      return 0;
    }
  }
  printf( "0\n" );
}
