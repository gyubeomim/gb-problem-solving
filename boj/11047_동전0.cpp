#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int n,k;
int a[15];

int main(int argc, char **argv){
	 int ans =0;

	 scanf("%d%d",&n,&k);
	 for(int i=0; i<n; i++) scanf("%d", &a[i]);

	 // Greedy (a[i]가 배수이므로 그리디 사용 가능)
	 for(int i=n-1; i>=0; i--) {
		 ans += k / a[i];
		 k %= a[i];
	 }

	 printf("%d\n", ans);
}
