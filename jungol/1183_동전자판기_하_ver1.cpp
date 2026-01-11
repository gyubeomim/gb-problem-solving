#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int coin[6] = {500,100,50,10,5,1};
int cnt[6];
int ans[6];

bool useMoney(int i, int m){
	if(m % coin[i] != 0) return false;

	if(i==0){  // base condition
		if(m % coin[i] == 0){
			int c = m / coin[i];
			if(c <= cnt[0]) {
				ans[0] = c;
				return true;
			}
		}
		return false;
	}

	int c = min(m / coin[i], cnt[i]);
	for(int j=c; j>=0; j--){
		int remain = m - coin[i]*j;
		ans[i] = j;
		if(useMoney(i-1, remain)) return true;
	}
	return false;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1183.txt", "r", stdin);
	#endif

	int money; scanf("%d", &money);
	for(int i=0; i<6; i++){
		scanf("%d", &cnt[i]);
	}

 	useMoney(5, money);

	int sum=0;
	for(int i=0;i<6;i++){
		sum += ans[i];
	}
	printf("%d\n", sum);
	for(int i=0;i<6;i++){
		printf("%d ", ans[i]);
	}
}