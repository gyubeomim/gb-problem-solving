#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int n;
bool areFriends[10][10];

// taken[i] = i번째 학생이 짝을 이미 찾았으면 true 아니면 false
int countPairings(bool taken[10]){
	// base condition : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다
	bool finished=true;
	for(int i=0;i<n;i++) if(!taken[i]) finished = false;
	if(finished) return 1;

	int ret=0;

	// 서로 친구인 두 학생을 찾아 짝을 지어 준다
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}
	return ret;
}

int main(int argc, char **argv){
	 
}
