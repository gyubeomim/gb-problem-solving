#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM=1000005;
int A[LM];
stack<int> S;

int main(int argc, char **argv){
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
		
	int NGE[LM] = {0};

	for(int i=N-1; i>=0; i--) {
		while(!S.empty() && S.top() <= A[i]) 
				S.pop();
		 
		if(S.empty()) NGE[i] = -1;
		else          NGE[i] = S.top();

		S.push(A[i]);
	}

	for(int i=0; i<N; i++){
		printf("%d ", NGE[i]);
	}
}
