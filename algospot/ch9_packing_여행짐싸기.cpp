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

const int LM = 105;
int N, W;
int volume[LM], need[LM];
int cache[1005][LM];
string name[LM];

// 캐리어에 남은 용량이 capacity일 때 item 이후의 물건들을
// 담아 얻을 수 있는 최대 절박도의 합을 반환한다
int pack(int capacity, int item){
	// 기저 사례: 더 담을 물건이 없을 때
	if(item == N) return 0;

	int& ret = cache[capacity][item];
	if(ret != -1) return ret;
	// 이 물건을 담지 않을 경우
	ret = pack(capacity, item+1);
	// 이 물건을 담을 경우
	if(capacity >= volume[item]) 
		ret = max(ret, pack(capacity-volume[item], item+1) + need[item]);

	return ret;
}

// pack(capacity, item)이 선택한 물건들의 목록을 picked에 저장한다
void reconstruct(int capacity, int item, vector<string>& picked){
	// 기저 사례: 모든 물건을 다 고려했음
	if(item == N) return;

	if(pack(capacity,item) == pack(capacity,item+1)) {
		reconstruct(capacity, item+1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capacity-volume[item], item+1, picked);
	}
}

int main(int argc, char **argv){
	// freopen("data/d3112.txt", "r", stdin);
	int C; scanf("%d", &C);
	while(C--) {
		memset(cache, -1, sizeof(cache));

		scanf("%d%d",&N,&W);
		for(int i=0; i<N; i++){
			cin >> name[i] >> volume[i] >> need[i];
		}
		int ans = pack(W,0);

		vector<string> seq;
		reconstruct(W,0,seq);
		printf("%d %lu\n", ans, seq.size());
		for(int i=0; i<seq.size(); i++)
			printf("%s\n", seq[i].c_str());
	}
}