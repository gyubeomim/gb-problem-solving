#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> trees;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		int tree;
		cin >> tree;
		trees.push_back(tree);
	}

	ll lo=0;
	ll hi=1000000000;
	ll mid;

	while(lo < hi) {
		mid = (lo+hi) >> 1;
	
		ll result=0;
		for(int i=0; i<trees.size(); i++) {
			int cut = trees[i] - mid;
			if(cut > 0) {
				result += cut;
			}
		}

		if (result >= M) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
		
	}

	cout << lo - 1 << '\n';

	
	return 0;
}
