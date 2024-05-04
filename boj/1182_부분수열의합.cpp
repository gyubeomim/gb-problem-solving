#include <bits/stdc++.h>

#define rnt register int
using namespace std;

using pii = pair<int,int>;
using ll = long long;

constexpr int LM =25;
int arr[LM] = {0};
int visited[LM] = {0};
int ans = 0;
int N,S;

void backTracking(int idx, int tmp) {
	if(idx==N) return;
	if(tmp + arr[idx] == S) ans++;

	backTracking(idx+1, tmp);          // 현재 원소를 더하지 않을 때 
	backTracking(idx+1, tmp+arr[idx]); // 현재 원소를 더할 때
}

int main(int argc, char **argv){
	cin.tie(0)->sync_with_stdio(false);

	scanf("%d %d", &N, &S);

	for(int i=0;i<N;i++){
		scanf("%d", &arr[i]);
	}

	backTracking(0,0);

	printf("%d",ans);

	return 0;
}
