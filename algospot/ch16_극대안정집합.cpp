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

const int LM = 25;

int N;
int explodes[LM];  // explodes[i]는 i와 같이 두었을 때 폭발하는 물질 집합의 비트마스크 표현

// 주어진 집합이 안정적인지 확인한다
bool isStable( int set_ ) {
  for ( int i = 0; i < N; i++ ) {
		// 집합에 포함된 i번째 원소와 같이 두었을 때 폭발하는 물질이 set에 있다면
    if ( ( set_ & ( 1 << i ) ) && ( set_ & explodes[i] ) )
      return false;
  }
	return true;
}

// 모든 극대 안정 집합의 수를 구한다
int countStableSet() {
  int ret = 0;
	// 모든 집합을 만들어보자
  for ( int set_ = 1; set_ < ( 1 << N ); set_++ ) {
    if ( !isStable( set_ ) )   // 우선 안정적이 아니라면 셀 필요가 없다
			continue;
	
		// 극대 안정 집합인지 확인하기 위해 넣을 수 있는 다른 물질이 있나 확인한다
    bool canExtend = false;
    for ( int add = 0; add < N; add++ ) {
			// add가 집합에 포함되어 있지 않고 set에 addㄷ를 넣어도 안정적이라면
      if ( ( set_ & ( 1 << add ) ) == 0 && ( explodes[add] & set_ ) == 0 ) {
        canExtend = true;
        break;
      }
    }
    if ( !canExtend ) ++ret;
  }
  return ret;
}


int main(int argc, char **argv){
	 
}
