#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int N;
vector<pii> points;

struct Event{
	int pos, delta;
	bool operator<(const Event& r)const{
		if(pos != r.pos) return pos < r.pos;
		return delta < r.delta;
	}
};

int solve(){
	vector<Event> events;

	// Horizontal
	for(int i=0;i<N;i++){
		int j=(i+1)%N;
		if(points[i].X == points[j].X){
			int y1 = points[i].Y;
			int y2 = points[j].Y;
			int ymin = min(y1,y2);
			int ymax = max(y1,y2);

			if(ymin < ymax){
				events.push_back({ymin, +1});
				events.push_back({ymax, -1});
			}
		}
	}

	sort(events.begin(), events.end());

	int active = 0, maxh = 0;
	for(auto &e : events){
		active += e.delta;
		maxh = max(maxh, active);
	}

	// Vertical
	events.clear();

	for(int i=0;i<N;i++){
		int j=(i+1)%N;
		if(points[i].Y == points[j].Y){
			int x1 = points[i].X;
			int x2 = points[j].X;
			int xmin = min(x1,x2);
			int xmax = max(x1,x2);

			if(xmin < xmax){
				events.push_back({xmin, +1});
				events.push_back({xmax, -1});
			}
		}
	}

	sort(events.begin(), events.end());

	active = 0;
	int maxv = 0;
	for(auto &e : events){
		active += e.delta;
		maxv = max(maxv, active);
	}

	return max(maxh, maxv);
}


int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d3336.txt", "r", stdin);
	#endif

	scanf("%d", &N);

	points.resize(N);
	for(int i=0; i<N; i++) {
		scanf("%d%d", &points[i].X, &points[i].Y);
	}

	// printf("%d %d\n", h, v);
	printf("%d\n", solve());
}