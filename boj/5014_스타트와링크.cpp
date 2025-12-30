#include <bits/stdc++.h>

using namespace std;
int F,S,G,U,D;
int dx[2];
int visit[1000001];

void bfs(){
	queue<int> Q;
	Q.push(S);
	visit[S] = 1;

	while(!Q.empty()){
		int qsize = Q.size();
		for(int i=0;i<qsize;i++){
			int curr = Q.front();
			Q.pop();

			if(curr == G){
				cout << visit[curr]-1 << '\n';
				return;
			}

			for(int d=0;d<2;d++){
				int next = curr + dx[d];

				if(next > F || next < 1) continue;

				if(visit[next] == 0){
					visit[next] = visit[curr] + 1;
					Q.push(next);
				}

			}
		}
	}

	cout << "use the stairs\n";
}

int main() {
	cin>>F>>S>>G>>U>>D;

	dx[0]=U;
	dx[1]=-D;	

	bfs();

	return 0;
}