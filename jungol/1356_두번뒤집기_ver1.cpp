#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 10005;

int N;
int arr[LM], tmp[LM];

bool isSorted(){
	for(int i=1; i<=N; i++){
		if(i != tmp[i]) return false;
	}
	return true;
}

bool tryReverse(int l, int r){
	for(int i=1;i<=N;i++) tmp[i] = arr[i];
	reverse(tmp+l, tmp+r+1);

	vector<int> loc(N+5), state(N+5,0);
	for(int i=1;i<=N;i++) loc[tmp[i]] = i;

	for(int i=1;i<=N;i++){
		if(state[i]) continue;

		for(int i=1; i<=N; i++){
			if(state[i]) continue;
			if(i<N && tmp[i+1] == tmp[i]+1) state[i] = state[i+1] = 1;
			else if(i<N && tmp[i+1] == tmp[i]-1) state[i] = state[i+1] = 2;
			else state[i] = 3;
		}

		int s=1, e=N;
		for(;s<=N;s++) if(loc[s] != s) break;
		for(;e>=1;e--) if(loc[e] != e) break;

		if(s==N+1) return true;

		if(state[loc[s]] == 2) {
			reverse(tmp+s, tmp+loc[s]+1); 
			return isSorted();
		}else if(state[loc[e]] == 2){
			reverse(tmp+loc[e], tmp+e+1);
			return isSorted();
		}
	}
	return false;
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/1356.txt", "r", stdin);
#endif
	scanf("%d", &N);
	
	for(int i=1;i<=N;i++) scanf("%d", &arr[i]);

	for(int k=0; k<2; k++){
		vector<int> loc(N+5), state(N+5,0);
		
		for(int i=1; i<=N; i++) loc[arr[i]]=i;

		for(int i=1; i<=N; i++){
			if(state[i]) continue;
			if(i<N && arr[i+1] == arr[i]+1) state[i] = state[i+1] = 1;
			else if(i<N && arr[i+1] == arr[i]-1) state[i] = state[i+1] = 2;
			else state[i] = 3;
		}

		int s=1, e=N;
		for(;s<=N;s++) if(loc[s] != s) break;
		for(;e>=1;e--) if(loc[e] != e) break;

		if(s==N+1){
			printf("1 1\n"); 
			reverse(arr+1, arr+1+1);
			continue;
		}
		
		if(state[loc[s]] == 2){
			printf("%d %d\n", s, loc[s]);
			reverse(arr+s, arr+loc[s]+1);
		}
		else if(state[loc[e]] == 2){
			printf("%d %d\n", loc[e], e);
			reverse(arr+loc[e], arr+e+1);
		}else{
			if(tryReverse(s, loc[s])){
				printf("%d %d\n", s, loc[s]);
				reverse(arr+s, arr+loc[s]+1);
			}else{
				printf("%d %d\n", loc[e], e);
				reverse(arr+loc[e], arr+e+1);
			}
		}
	}
	
}