// 종교 jungol.co.kr/problem/1863
#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 50005;
int N, M, ret;
vector<int> p(LM, -1);

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);   // 최적화1 : 경로 압축 적용
}

void swap(int& a, int& b) { int c=a; a=b; b=c;}

void Union( int a, int b ) {
  a = find( a ), b = find( b );
  if ( a == b ) return;
  ret--;

  // 최적화2 : 랭크 기반 합치기, rank, parent를 하나의 변수에서 처리하는 버전
  if ( p[a] < p[b] ) swap( a, b );
  if ( p[a] == p[b] ) p[a]--;
  p[b] = a;
}

int main() {
  scanf( "%d %d", &N, &M );
  ret = N;

  for ( int i = 0; i < M; i++ ) {
    int a, b;
    scanf( "%d %d", &a, &b );
    Union( a, b );
  }
  printf( "%d", ret );
}

