#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int N;
string S;

bool isBadSequence(int len){
	for(int l=1; l<=len/2; l++){
		bool same = true;
		for(int i=0; i<l; i++){
			if(S[len-l+i] != S[len-2*l+i]){
				same = false;
				break;
			}
		}
		if(same) return true;
	}
	return false;
}

bool dfs(int len){
	if(len == N) return true;

	for(int i=1; i<=3; i++){
		S.push_back('0' + i);

		if(!isBadSequence(len+1))
			if(dfs(len+1)) 	
				return true;

		S.pop_back();
	}
	return false;
}


int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1027.txt", "r", stdin);
	#endif

	scanf("%d", &N);
	dfs(0);

	printf("%s\n", S.c_str());
}