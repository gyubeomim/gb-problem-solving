#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 100005;

int M,K;
ll A[LM];

bool canSplit(ll val){
	int used = 1;
	ll sum = 0;

	for(int i=0; i<M; i++){
		if(A[i] > val) return false;

		if(sum + A[i] <= val) { sum += A[i]; }
		else{
			used++;
			sum = A[i];
			if(used > K) return false;
		}
	}
	return true;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/1156.txt", "r", stdin);
	#endif
	scanf("%d%d", &M, &K);

	ll lmax = 0, tot = 0;

	for(int i=0;i<M;i++){
		scanf("%lld", &A[i]);

		lmax = max(lmax, A[i]);
		tot += A[i];
	}

	ll l = lmax;
	ll r = tot;
	ll split_n = 0;

	while(l <= r){
		ll mid = (l+r)/2;
		if(!canSplit(mid)) {   // fail to split (used > K)
			// printf("FAIL %lld\n", mid);
			l = mid+1;
		}else{                 // suc to split (used < K)
			// printf("SUC %lld\n", mid);
			split_n = mid;
			r = mid-1;
		}
	}

	ll sum = 0;
	int used = 1;
	vector<int> segment;

	for(int i=M-1; i>=0; i--){
		if(i != M-1 && used < K && i+1 == K-used) {
			used++;
			sum = A[i];
			segment.push_back(1);
		}else{
			if(sum + A[i] <= split_n) { 
				sum += A[i];
				segment.push_back(0);
			}
			else {
				sum = A[i];
				used++;
				segment.push_back(1);
			}
		}
	}

	reverse(segment.begin(), segment.end());

	for(int i=0; i<M; i++){
		if(segment[i] == 0) printf("%lld ", A[i]);
		else printf("%lld / ", A[i]);
	}
}