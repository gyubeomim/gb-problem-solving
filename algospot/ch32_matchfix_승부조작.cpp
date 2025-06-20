#include <bits/stdc++.h>
using namespace std;

const int LM = 105;
const int INF = 0x3f3f3f3f;

int cnt;
int N,M;
int wins[20], match[200][2];

int V,E;
int capacity[LM][LM];
int flow[LM][LM];

// flow[]를 계산하고 총 유량을 반환한다
int networkFlow(int source, int sink){
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;

	while(true){
		// 너비우선탐색으로 증가 경로를 찾는다
		vector<int> parent(LM, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);

		while(!q.empty() && parent[sink]==-1) {
			int here = q.front(); q.pop();
			for(int there=0; there < V; there++){
				// 잔여용량이 남아 있는 간선을 따라 탐색한다
				if(capacity[here][there] - flow[here][there] > 0 
						&& parent[there]==-1)
				{
					q.push(there);
					parent[there] = here;
				}
			}
		}
		// 증가경로가 없으면 종료한다
		if(parent[sink]==-1) break;
		
		// 증가경로를 통해 유량을 얼마나 보낼지 결정한다
		int amount = INF;
		for(int p=sink; p!=source; p=parent[p]){
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
		}
		// 증가경로를 통해 유량을 보낸다
		for(int p=sink; p!=source; p=parent[p]){
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		
		totalFlow += amount;
	}

	return totalFlow;
}

// 0번 선수가 총 totalWins승으로 우승할 수 있는지 여부를 확인한다
bool canWinWith(int totalWins){
	if(*max_element(wins+1, wins+N) >= totalWins){
		return false;
	}

	// 0번은 소스, 1번은 싱크
	V=2+M+N;

	memset(capacity, 0, sizeof(capacity));
	for(int i=0; i<M; i++){
		// 소스에서 각 경기로 가는 간선
		capacity[0][2+i] = 1;
		// 각 경기에서 두 선수로 가는 간선
		for(int j=0; j<2; j++){
			capacity[2+i][2+M+match[i][j]] = 1;
		}
	}

	// 각 선수에서 싱크로, 가능한 최대 승수를 용량으로 하는 간선을 추가
	for(int i=0; i<N; i++){
		int maxWin = (i==0 ? totalWins : totalWins-1);
		capacity[2+M+i][1] = maxWin - wins[i];
	}

	// 이 때, 모든 경기에 승자를 지정할 수 있는가?
	return networkFlow(0, 1) == M;
}

int main(int argc, char **argv){
	//freopen("s_in_2245.txt", "r", stdin);
	
	int C; scanf("%d",&C);
	while(C--){
		scanf("%d%d",&V,&E);
		
		cnt = 0;
		N = V, M = E;
		memset(capacity, 0, sizeof(capacity));

		for(int i=0; i<V; i++) {
			scanf("%d", &wins[i]);
		}

		for(int i=0; i<E; i++){
			int a,b;
			scanf("%d%d", &a, &b);
			match[i][0] = a;
			match[i][1] = b;
			if(a == 0 || b == 0) cnt++;
		}

		int flag = 0;
		for(int i=wins[0]; i<=wins[0]+cnt; i++){
			if(canWinWith(i)){
				printf("%d\n", i);
				flag = 1;
				break;
			}
		}
		if(!flag) printf("-1\n");
	}
}
