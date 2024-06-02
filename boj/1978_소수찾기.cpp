#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM = 1005;
int ans=0;

bool checkIsPrimeNumber(int n) {
	if(n==1) return false;
	
	for(int i=2; i<=n-1; i++){
		if(n % i ==0) return false;
	}

	return true;
}

bool is_prime[LM];
bool checkIsPrimeNumber2(int n) {
	return is_prime[n];
}

int main(int argc, char **argv){
	int N;
	scanf("%d",&N);
	
	memset(is_prime, 1, sizeof(is_prime));
	// 에라토스테네스의 체
	is_prime[0] = false;
	is_prime[1] = false;
	for(int i=2; i*i<=LM; i++){
		if(is_prime[i] == false) continue;
		for(int j=i*i; j<=LM; j+=i) {
			is_prime[j] = false;
		}
	}
	
	for(int i=0; i<N; i++){
		int num;
		scanf("%d",&num);
		// ans += checkIsPrimeNumber(num);
		ans += checkIsPrimeNumber2(num);
	}

	print(ans)
}
