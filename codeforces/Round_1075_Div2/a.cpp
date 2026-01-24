#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

/*
	n : size of array
	h : height
	l : width
*/
const int LM = 105;
int n,h,l;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/1075a.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
		while(T--) {
		scanf("%d%d%d", &n,&h,&l);

		int A = 0, B = 0;

		if(h > l) swap(h,l);  // h <= l

		for(int i=0;i<n;i++){
			int v; scanf("%d", &v);
			if(v <= h) A++;
			if(v > h && v <= l) B++;
		}

		printf("%d\n", min(A, ( A+B )/2));

	}
}