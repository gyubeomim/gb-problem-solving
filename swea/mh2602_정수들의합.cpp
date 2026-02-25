#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	// freopen("data/mh2602.txt", "r", stdin);
#endif
	int N,K; scanf("%d%d", &N, &K);

	for ( int a = 1; a <= N; a++ ) {
		for ( int b = 1; b <= N; b++ ) {
			for ( int c = 1; c <= N; c++ ) {
				for ( int d = 1; d <= N; d++ ) {
					if(a+b-c-d == K){
						printf("%d %d %d %d\n", a,b,c,d);
					}
				}
			}
		}
	}
}