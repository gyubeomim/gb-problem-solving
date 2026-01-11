#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int OFFSET = 500'001;
const int MAX_COORD = 1'000'002;

int N;
vector<pii> points;

int solve(){
	vector<int> w(MAX_COORD, 0);

	for(int i=0;i<N;i++){
		int j=(i+1)%N;
		if(points[i].X == points[j].X){
			int y1 = points[i].Y + OFFSET;
			int y2 = points[j].Y + OFFSET;
			int ymin = min(y1,y2);
			int ymax = max(y1,y2);

			if(ymin < ymax){
				w[ymin]++;  
				w[ymax]--;    
			}
		}
	}

	int active = 0, maxh = 0;
	for(int i=0; i<MAX_COORD; i++){
		active += w[i];
		maxh = max(maxh, active);
	}

	w = vector<int>(MAX_COORD, 0);

	for(int i=0;i<N;i++){
		int j=(i+1)%N;
		if(points[i].Y == points[j].Y){
			int x1 = points[i].X + OFFSET;
			int x2 = points[j].X + OFFSET;
			int xmin = min(x1,x2);
			int xmax = max(x1,x2);

			if(xmin < xmax){
				w[xmin]++;  // 시작
				w[xmax]--;    // 끝
			}
		}
	}

	active = 0;
	int maxv = 0;
	for(int i=0; i<MAX_COORD; i++){
		active += w[i];
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

	printf("%d\n", solve());
}