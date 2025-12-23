#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

constexpr int LM = 5005;

struct Point{
	int x,y;
	bool operator<(const Point& r) const {
		if(y == r.y) return x < r.x;
		return y < r.y;
	}
};

struct Bus{
	int bid;
	Point s, e;
};

bool isCross(Point as, Point ae, Point bs, Point be){
	// map<Point, int> M;

	// for(int x=as.x; x<=ae.x; x++){
	// 	for(int y=as.y; y<=ae.y; y++){
	// 		Point p = {x,y};
	// 		M[p]++;
	// 	}
	// }

	// for(int x=bs.x; x<=be.x; x++){
	// 	for(int y=bs.y; y<=be.y; y++){
	// 		Point p = {x,y};
	// 		auto it = M.find(p);

	// 		if(it != M.end()) return true;
			
	// 		M[p]++;
	// 	}
	// }
	// return false;

	int left = max(as.x, bs.x);
	int right = min(ae.x, be.x);
	int top = max(as.y, bs.y);
	int bottom = min(ae.y, be.y);
	return (left<=right && top<=bottom);
}

bool isIn(Point s, Point e, Point t){
	// for(int x=s.x; x<=e.x; x++){
	// 	for(int y=s.y; y<=e.y; y++){
	// 		if(t.x == x && t.y == y) return true;				
	// 	}
	// }
	// return false;

	if (t.x < min(s.x, e.x) || t.x > max(s.x, e.x) || t.y < min(s.y, e.y) || t.y > max(s.y, e.y)) {
			return false;
	}
	// 수직선 (x1==x2) 또는 수평선 (y1==y2)일 때만 가능
	return (s.x == e.x && t.x == s.x) || (s.y == e.y && t.y == s.y);
}

int m,n,k;
vector<int> adj[LM];

vector<int> start_buses;
unordered_set<int> end_set;

int que[LM*LM];
int fr, re;
int dist[LM];

int bfs(){
	memset(dist, -1, sizeof(dist));

	for(int bid : start_buses){
		dist[bid] = 1;
		que[re++] = bid;
	}

	while(fr<re){
		int cur = que[fr++];
		if(end_set.find(cur) != end_set.end()){
			return dist[cur];
		}

		for(int next : adj[cur]){
			if(dist[next] != -1) continue;

			que[re++] = next;
			dist[next] = dist[cur] + 1;
		}
	}
	return -1;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d9999.txt", "r", stdin);
	#endif

	scanf("%d%d", &m, &n);
	scanf("%d", &k);

	vector<Bus> V;

	for(int i=0; i<k; i++){
		Bus bus;
		scanf("%d%d%d%d%d", &bus.bid, &bus.s.x, &bus.s.y, &bus.e.x, &bus.e.y);

		if(bus.s.x > bus.e.x) swap(bus.s.x, bus.e.x);
		if(bus.s.y > bus.e.y) swap(bus.s.y, bus.e.y);

		V.push_back(bus);
	}

	for(int i=0; i<k; i++){
		for(int j=i+1; j<k; j++){
			Bus b1 = V[i];
			Bus b2 = V[j];
			if(isCross(b1.s, b1.e, b2.s, b2.e)){
				adj[b1.bid].push_back(b2.bid);
				adj[b2.bid].push_back(b1.bid);
			}
		}
	}

	Point start, end;
	scanf("%d%d%d%d", &start.x, &start.y, &end.x, &end.y);


	for(int i=0; i<V.size(); i++){
		Bus b = V[i];
		if(isIn(b.s, b.e, start)){
			// start_id = b.bid;
			start_buses.push_back(b.bid);
		}

		if(isIn(b.s, b.e, end)){
			// end_id = b.bid;
			end_set.insert(b.bid);
		}
	}

	int ans = bfs();
	printf("%d\n", ans);
}