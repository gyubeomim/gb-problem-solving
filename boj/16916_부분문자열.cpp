// 부분 문자열 boj.kr/16916
#include <bits/stdc++.h>
using namespace std;

// longest prefix suffix, LPS 배열(실패 함수) 구하기
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
