#include <algorithm>
#include <bits/stdc++.h>
#define rnt register int
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define watch(x) cout << #x << " : " << x << '\n';
#define print(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int A[9]={0};

int main(int argc, char **argv){
	 for(int i=0; i<9;i++){
		 scanf("%d", &A[i]);
	 }
	
	 vector<int> v(9, 0);
	 fill(v.begin()+2, v.end(), 1);

	 do{
		 int B[7];
		 int j=0;

		 for(int i=0; i<v.size(); i++){
			 if(v[i]) B[j++] = A[i];
		 }
	
		 int sum=0;
		 for(int i=0; i<j;i++){
				sum += B[i];
		 }

		 if(sum == 100) {
			 sort(B, B+7);
			 for(int i=0; i<j; i++){
				 printf("%d\n", B[i]);
			 }
			 break;
		 }
		 
	 }while(next_permutation(v.begin(), v.end()));
}
