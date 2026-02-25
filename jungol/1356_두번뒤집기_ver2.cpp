#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 10005;
int arr[LM], tmp[LM];
int N;

bool isSorted(){
	for(int i=1;i<=N;i++){
		if(tmp[i] != i) return false;
	}
	return true;
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/1356.txt", "r", stdin);
#endif
		scanf("%d", &N);
		for(int i=1;i<=N;i++) scanf("%d", &arr[i]);

		vector<int> cand;
		cand.push_back(1);
		for(int i=1;i<N;i++){
			if(abs(arr[i+1] - arr[i]) > 1){
				cand.push_back(i);
				cand.push_back(i+1);
			}
		}
		cand.push_back(N);

		sort(cand.begin(), cand.end());
		cand.erase(unique(cand.begin(), cand.end()), cand.end());

		for(int i=0;i<cand.size();i++){
			for(int j=i;j<cand.size();j++){
				int a = cand[i];
				int b = cand[j];

				for(int k=1;k<=N;k++) tmp[k] = arr[k];
				reverse(tmp+a, tmp+b+1);

				if(isSorted()){
					printf("%d %d\n1 1\n", a,b);
					return 0;
				}

				int c=1, d=N;
				for(;c<=N;c++) if(tmp[c]!=c) break;
				for(;d>=1;d--) if(tmp[d]!=d) break;

				reverse(tmp+c, tmp+d+1);

				if(isSorted()){
					printf("%d %d\n%d %d",a,b,c,d);
					return 0;
				}
			}
		}
}