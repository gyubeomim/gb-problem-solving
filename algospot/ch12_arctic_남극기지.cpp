#include <bits/stdc++.h>
#define X first
#define Y second
using pdd = std::pair<double,double>;
using namespace std;

const int LM = 105;
int N;
double dist[LM][LM]; // 두 기지 사이의 거리
vector<pdd> loc;


// 거리가 d 이하인 기지들만을 연결했을 때 모든 기지가 연결되는지 여부를 반환
bool decision(double d){
	vector<bool> visited(N, false);
	visited[0]=true;
	queue<int> q;
	q.push(0);
	int seen=0;

	while(!q.empty()){
		int here=q.front(); q.pop();
		++seen;
		for(int there=0; there<N; there++){
			if(!visited[there] && dist[here][there]<=d){
				visited[there]=true;
				q.push(there);
			}
		}
	}
	return seen == N;
}

double optimize(){
	double lo=0, hi=1416.00;
	for(int i=0;i<100;i++){
		double m = (lo+hi)/2;
		if(decision(m)) hi = m;
		else lo = m;
	}
	return hi;
}

void calcDist(){
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			dist[i][j]=dist[j][i]=hypot(loc[i].X-loc[j].X,
			                          	loc[i].Y-loc[j].Y);
		}
	}
}

int main(int argc, char **argv){
	// freopen("data/s_in_4456.txt", "r", stdin);
	int C; scanf("%d",&C);
	while(C--) {
		loc.clear();
		memset(dist,0,sizeof(dist));

		scanf("%d",&N);

		for(int i=0; i<N;i++){
			double x,y;
			scanf("%lf%lf",&x,&y);
			loc.push_back({x,y});
		}
		calcDist();
		double ans = optimize();
		printf("%.2lf\n", ans);
	}
}
