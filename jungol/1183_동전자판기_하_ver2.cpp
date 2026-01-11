#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int target, total, mis;
int money[6] = {500,100,50,10,5,1};
int cnt[6], used[6];
int sum;

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1183.txt", "r", stdin);
	#endif

	scanf("%d", &target);
	for(int i=0; i<6; i++){
		scanf("%d", &cnt[i]);
	}

	total = 500*cnt[0] + 100*cnt[1] + 50*cnt[2] + 10*cnt[3] + 5*cnt[4] + 1*cnt[5];
	mis = total - target;

	for(int i=0; i<6;i++){
		int c = mis/money[i];
		if(c > cnt[i]){
			used[i] = cnt[i];
			c = cnt[i];
		}else{
			used[i] = c;
		}

		sum += c;
		mis -= c*money[i];
	}

	int ans[6] = {0};

	for(int i=0; i<6; i++){
		ans[i] = cnt[i] - used[i];
	}

	int sum = 0;
	for(int i=0; i<6; i++){
		sum += ans[i];
	}

	printf("%d\n", sum);
	for(int i=0; i<6; i++){
		printf("%d ", ans[i]);
	}puts("");

}