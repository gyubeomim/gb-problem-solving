#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

int N,M;
int arr[9];

void dfs(int num, int k){
	if(k==M){
		for(int i=0; i<M;i++){
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for(int i=1; i<=N; i++){
			arr[k] = i;
			dfs(i, k+1);
		}
	}

}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	cin>>N>>M;

	dfs(1,0);
	 

	return 0;
}
