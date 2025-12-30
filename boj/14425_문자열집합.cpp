// 문자열 집합 boj.kr/14425
#include <bits/stdc++.h>
using namespace std;

const int LM = 500 * 10000 + 5;  // 최대 등장 가능한 글자의 수 (길이 500인 문자열 10000개)
const int ROOT = 1;

int N, M;
int unused = 2;
bool chk[LM];     // 해당 정점이 문자열의 끝인지 여부 저장j
int nxt[LM][26];  // 각 정점에서 자식의 정점 번호
                  // 배열에 문자열 저장 : char 1칸 (1바이트)
                  // Trie에 문자열 저장 : int 26칸 (4x26바이트)

int c2i(char c) { 	return c-'a'; }

// Trie
void insert( string& s ) {
  int cur = ROOT;
  for ( auto c : s ) {
    int i = c2i( c );
    if ( nxt[cur][i] == -1 )
      nxt[cur][i] = unused++;
    cur = nxt[cur][i];
  }
  chk[cur] = true;
}

bool find( string& s ) {
  int cur = ROOT;
  for ( auto c : s ) {
    int i = c2i( c );
    if ( nxt[cur][i] == -1 ) return false;
    cur = nxt[cur][i];
  }
  return chk[cur];
}

void erase( string& s ) {
  int cur = ROOT;
  for ( auto c : s ) {
    int i = c2i( c );
    if ( nxt[cur][i] == -1 ) return;
    cur = nxt[cur][i];
  }
  chk[cur] = false;
}

int main( int argc, char** argv ) {
  for ( int i = 0; i < LM; i++ ) {
    fill( nxt[i], nxt[i] + 26, -1 );
  }

  scanf( "%d%d", &N, &M );

  while ( N-- ) {
    string s;
    cin >> s;
    insert( s );
  }

  int ans = 0;
  while ( M-- ) {
    string s;
    cin >> s;
    ans += find( s );
  }
  printf( "%d\n", ans );
}
