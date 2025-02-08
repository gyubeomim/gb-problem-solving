#include <algorithm>
#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int main(int argc, char **argv){
	while(true) {
		int K;
		scanf("%d", &K);

		if(K==0) break;

		vector<int> nums(K);
		vector<int> comb_index(K);

		for(int i=0; i<K; i++){
			scanf("%d", &nums[i]);
		}

		fill(comb_index.begin(), comb_index.begin()+6, 1);

		do{
			for(int i=0; i<K; i++){
				if(comb_index[i]) {
					printf("%d ", nums[i]);
				}
			}	puts("");
		}while(prev_permutation(comb_index.begin(), comb_index.end()));

		puts("");
	}

}
