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

const int LM = 2000005;
const int HALF = 1000000;

int N;
int freq[LM];

void countingSort() {
  for ( int i = 0; i < N; i++ ) {
    int a;
    scanf( "%d", &a );
    freq[a + HALF]++;
  }

  for ( int i = 0; i < LM; i++ ) {
    while ( freq[i]-- ) {
      printf( "%d\n", i - HALF );
    }
  }
}

int main( int argc, char **argv ) {
  scanf( "%d", &N );
	countingSort();
}
