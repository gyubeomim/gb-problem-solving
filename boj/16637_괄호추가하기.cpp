#include <bits/stdc++.h>

using namespace std;

int N,ans=-9999;
string s;

int calc(int a, int b, char op){
	switch(op){
		case '+':
			a+=b;
			break;
		case '-':
			a-=b;
			break;
		case '*':
			a*=b;
			break;
	}

	return a;
}


void dfs(int idx, int cur){
	if(idx >= N){
		ans = max(ans, cur);
		return;
	}

	char op = idx == 0 ? '+' : s[idx-1];

	if(idx+2 < N){
		int bracket = calc(s[idx]-'0', s[idx+2]-'0', s[idx+1]);
		dfs(idx+4, calc(cur, bracket, op));
	}

	dfs(idx+2, calc(cur, s[idx]-'0', op));

}


int main(int argc, char **argv){
	
ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> s;

	dfs(0,0);

	cout << ans;
	 

	return 0;
}
