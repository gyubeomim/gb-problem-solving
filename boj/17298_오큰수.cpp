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

int main(int argc, char **argv){
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	
	for(int i=0; i<N; i++){
		bool found = false;
		for(int j=i+1; j<N; j++){
			if(A[i] < A[j]) {
				found = true;
				printf("%d ", A[j]);
				break;
			}
		}
		if(!found) printf("-1 ");
	}


}
