#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int N;
int A[1005];
vector<int> two;

int main(int argc, char **argv){
	scanf("%d",&N);

	for(int i=0;i<N;i++) scanf("%d", &A[i]);
	sort(A, A+N);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			two.push_back(A[i]+A[j]);
		}
	}
	sort(two.begin(), two.end());

	// A[i]+A[j]+A[k] = A[l]   O(n^4) X too slow
	// A[i]+A[j] => two        O(n^2)
	// A[l]-A[k] == two ?      O(logn)
	// Total: O(n^2 logn)
	for(int i=N-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(binary_search(two.begin(), two.end(), A[i]-A[j])){
				printf("%d\n", A[i]);
				return 0;
			}
		}
	}
	 
}
