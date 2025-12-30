#include <bits/stdc++.h>

#define pii pair<int,int>
#define ll long long

using namespace std;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ll A[1000001];
	int N;

	cin >> N;

	for(ll i=0; i<N; i++) {
		cin >> A[i];
	}

	int B,C;
	cin>> B >> C;

	ll ans=0;

	for(int i=0; i<N; i++) {
		if(A[i] > 0) {
			A[i] -= B;
			if(A[i] < 0) A[i] = 0;
			ans++;
		}
	}

	for(int i=0; i<N; i++) {
		if(A[i] > 0) {
			double D;
			D = (double)A[i] / C;
			ans += ceil(D);
		}
	}

	cout << ans;

	 

	return 0;
}
