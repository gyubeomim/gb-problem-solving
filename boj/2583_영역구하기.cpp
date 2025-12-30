#include <bits/stdc++.h>

using namespace std;


int visit[100][100] = {0};



const int dx[5]={-1,1,0,0, 0};
const int dy[5]={0,0,1,-1, 0};


int M,N,K;






int bfs(int x, int y) {
	queue<int> q;
	q.push(x*100 + y);


	int area=0;



	while(!q.empty()) {
		int qsize = q.size();

		for(int i=0; i<qsize; i++) {
			int cx = q.front() /100;
			int cy = q.front() %100;
			q.pop();


			for(int d=0; d<5; d++) {
				int nx = cx + dx[d];
				int ny = cy + dy[d];


				if(nx < 0 || nx >=N || ny < 0 || ny>=M) continue;
				if(visit[nx][ny]) continue;

				// cout << nx << ", " << ny << endl;

				visit[nx][ny] = 1;
				q.push(nx*100 + ny);
				area += 1;
			}

		}
	}

		// cout << endl;

	return area;
}







int main() {
	cin >> M >> N >> K;





	for(int i=0;i<K; i++) {
		int x1,y1, x2,y2;
		cin >> x1>>y1>>x2>>y2;


		for(int a=x1;a<x2; a++){
			for(int b=y1; b<y2; b++) {
				visit[a][b] = 1;
				// cout << "x1ay1b: " << x1+a << ", " << y1+b << endl;
			}
		}


	}




	vector<int> areas;



	for(int x=0; x<N; x++) {
		for(int y=0; y<M; y++) {
			int area=0;

			if(!visit[x][y]) {
				area = bfs(x,y);
			}

			// cout << "area: " << area << endl;
			if(area != 0) areas.push_back(area);
		}
	}


	int num_area = areas.size();


	sort(areas.begin(), areas.end());


	cout << num_area << '\n';


	for(auto it : areas) {
		cout << it << " ";
	}





	return 0;
}