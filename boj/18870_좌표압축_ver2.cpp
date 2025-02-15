#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

const int LM = 1'000'005;

int N;
int X[LM];
vector<int> tmp, uni;  // unique

int lowerIndex(int t){
	int l=0, r=uni.size();

	while(l<r){
		int m = (l+r)/2;
		if(uni[m]>=t) r=m;
		else l=m+1;
	}
	return l;
}

int main(int argc, char **argv){
	 scanf("%d",&N);
	 for(int i=0; i<N; i++){
		 scanf("%d",&X[i]);
		 tmp.push_back(X[i]);
	 }

	 sort(tmp.begin(), tmp.end());

	 for(int i=0; i<N; i++){
		 if(i==0 || tmp[i-1] != tmp[i]) 
			 uni.push_back(tmp[i]);
	 }

	 // tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());  // or using STL
	 // uni = tmp;

	 for(int i=0;i<N;i++){
		 printf("%d ", lowerIndex(X[i]));
	 }
	 puts("");
}
