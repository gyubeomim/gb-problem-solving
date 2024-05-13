#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;

vector<int> ans;
void printAnswer() {
	for(auto it = ans.rbegin(); it!=ans.rend(); it++) {
		int n = *it;
		if(n > 9) printf("%c", 'A' + n - 10);
		else printf("%d", n);
	}
	printf("\n");
}

int main(int argc, char **argv){
	int N;
	scanf("%d", &N);

	int B;
	scanf("%d", &B);
	
	if(N >= B) {
		while(N >= B) {
			int mod = N % B;
			N = N / B;
			ans.push_back(mod);
		}
		ans.push_back(N);
	}
	else {
		ans.push_back(N);
	}
	printAnswer();
}
