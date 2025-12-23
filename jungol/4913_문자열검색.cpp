#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

set<string> S;
int Q;

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1198.txt", "r", stdin);
	#endif
	scanf("%d", &Q);	
	while(Q--){
		string s; cin>>s;
		auto it = S.find(s);
		if(it != S.end()) S.erase(it);
		else S.insert(s);
	}
	printf("%d\n", S.size());
}