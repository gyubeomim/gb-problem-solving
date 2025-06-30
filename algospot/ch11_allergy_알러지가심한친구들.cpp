#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 55;
int N,M;

unordered_map<string, int> names;

// canEat[i]: i번 친구가 먹을 수 있는 음식의 집합
// eaters[i]: i번 음식을 먹을 수 있는 친구들의 집합
vector<int> canEat[LM], eaters[LM];
int best;

// food: 이번에 고려해야 하는 음식의 번호
// chosen: 지금까지 고른 음식의 수
// edible: 지금까지 고른 음식 중 i번째 친구가 먹을 수 있는 음식의 수
void slowSearch(int food, vector<int>& edible, int chosen){
	if(chosen>=best) return; // 간단한 가지치기
	// 기저 사례: 모든 음식에 대해 만들지 여부를 결정했으면
	// 모든 친구가 음식을 먹을 수 있을 지 확인하고 그렇다면 최적해를 갱신한다
	if(food == M) {
		if(find(edible.begin(), edible.end(), 0) == edible.end()) 
			best = chosen;
		return;
	}
	// food를 만들지 않는 경우
	slowSearch(food+1, edible, chosen);

	// food를 만드는 경우
	for(int j=0; j<eaters[food].size(); j++)
		edible[eaters[food][j]]++;
	slowSearch(food+1, edible, chosen);
	for(int j=0; j<eaters[food].size(); j++)
		edible[eaters[food][j]]--;
}

// chosen: 지금까지 고른 음식의 수
// edible[i] 지금까지 고른 음식 중 i번 친구가 먹을 수 있는 음식의 수 
void search(vector<int>& edible, int chosen){
	if(chosen >= best) return;

	// 아직 먹을 음식이 없는 첫번째 친구를 찾는다
	int first = 0;
	while(first < N && edible[first] > 0) first++;

	// 모든 친구가 먹을 음식이 있는 경우 종료한다
	if(first == N) { best = chosen; return; }

	for(int i=0; i<canEat[first].size(); i++){
		int food = canEat[first][i];

		for(int j=0; j<eaters[food].size(); j++)
			edible[eaters[food][j]]++;
		search(edible, chosen+1);
		for(int j=0; j<eaters[food].size(); j++)
			edible[eaters[food][j]]--;
	}
}

int solve() {
	vector<int> edible(N, 0);
	best = M;
	search(edible, 0);
	return best;
}

int main(int argc, char **argv){
	// freopen("data/s_in_1431.txt", "r", stdin);
	int C; scanf("%d", &C);
	while(C--) {
		scanf("%d%d",&N,&M);
		for(int i=0; i<LM; i++){
			canEat[i].clear();
			eaters[i].clear();
		}

		names.clear();
		for(int i=0; i<N; i++){
			string s; cin>>s;
			names[s] = i;
		}

		for(int food=0; food<M; food++) {
			int num; scanf("%d",&num);
			for(int j=0; j<num; j++){
				string s; cin>>s;
				int eater = names[s];
				canEat[eater].push_back(food);
				eaters[food].push_back(eater);
			}
		}
		int ans = solve();
		printf("%d\n", ans);
	}
}