#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int N,K;
string S;

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d4520.txt", "r", stdin);
	#endif

	scanf("%d%d", &N, &K);
	cin >> S;

	int ans = 0;

	for(int i=0; i<S.size(); i++){
		char &c = S[i];
		if(c == 'P'){
			for(int j=i-K; j<=i+K; j++){
				if(i == j) continue;
				if(S[j] == 'H') {
					S[j] = '0';
					S[i] = '1';
					ans++;
					break;
				}
			}
		}
	}

	printf("%d\n", ans);
}