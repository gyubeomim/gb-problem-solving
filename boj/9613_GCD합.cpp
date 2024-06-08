#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr int LM = 105;
int num[LM] = {0};
int T; 
int N;

int getGCD(int a, int b){
	int ans=1;
	int div=2;

	while(true) {
		if(a%div==0 && b%div==0) {
			a/=div; b/=div;	ans*=div;
		}
		else 
			div++;

		if(div>a || div>b) break;
	}
	return ans;
}

int main(int argc, char **argv){
	scanf("%d",&T);
		
	while(T--){
		memset(num, 0, sizeof(num));
		scanf("%d", &N);

		for(int i=0; i<N; i++){
			scanf("%d", &num[i]);
		}

		vector<int> v(N);
		fill(v.end()-2, v.end(), true);
		
		ll sum=0;
		do{
			int a=0, b=0;
			for(int i=0; i<N; i++) {
				if(v[i])  {
					if(!a) a = num[i];
					else if(a && !b) b = num[i];
					if(a && b) break;
				}
			}

			sum += getGCD(a, b);
		}while(next_permutation(v.begin(), v.end()));
		
		printf("%lld\n", sum);
	}
}

