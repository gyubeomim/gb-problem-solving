#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

vector<pii> arr;
int n;

tuple<int, vector<bool>> lis(){
	vector<int> tails_idx;
	vector<int> prev(n+5);

	for(int i=0; i<n; i++){
		auto it = lower_bound(tails_idx.begin(), tails_idx.end(), arr[i].Y,
						[&](int idx, int val){ return arr[idx].Y < val; });

		int p = it - tails_idx.begin();
		prev[i] = (p > 0) ? tails_idx[p-1] : -1;

		if(it == tails_idx.end()) { tails_idx.push_back(i); }
		else *it = i;
	}

	vector<bool> in_lis(n+5, false);

	if(!tails_idx.empty()){
		int cur = tails_idx.back();
		while(cur != -1) { 
			in_lis[cur] = true;
			cur = prev[cur];
		}
	}
	return {tails_idx.size(), in_lis};
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/1257.txt", "r", stdin);
#endif

	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a,b; scanf("%d%d",&a,&b);
		arr.push_back({a,b});
	}

	sort(arr.begin(), arr.end());

	auto [ len, in_lis ] = lis();

	int ans = n - len;
	printf("%d\n", ans);

	for(int i=0; i<n; i++){
		if(!in_lis[i]){
			printf("%d\n", arr[i].X);
		}
	}
	
}