#include <bits/stdc++.h>
using namespace std;
bool visit[50][50] = {0};
int W,H;

const int dw[5] = {0,-1,1,0,0};
const int dh[5] = {0,0,0,-1,1};


class Wall {

public:
  bool W_;
  bool E_;
  bool S_;
  bool N_;

  Wall()
      : W_(false), E_(false), S_(false), N_(false) {}
};




Wall** wall;







int bfs(int now) {
	queue<int> Q;

	Q.push(now);



	int area=0;




	while (!Q.empty()) {

		int qsize= Q.size();


		for(int i=0; i<qsize; i++) {
			int h = Q.front() / 50;
			int w = Q.front() % 50;
			Q.pop();



			for(int d=0; d<5; d++) {
				// d=1(W), d=2(E), d=3(N), d=4(S)
				if(d==1 && wall[h][w].W_) continue;
				if(d==2 && wall[h][w].E_) continue;
				if(d==3 && wall[h][w].N_) continue;
				if(d==4 && wall[h][w].S_) continue;



				int nw = w + dw[d];
				int nh = h + dh[d];



				if(nw<0 || nw>=W || nh<0 || nh>=H) continue;
				if(visit[nh][nw]) continue;


				visit[nh][nw] = true;
				Q.push(nh*50 + nw);

				area++;
				// cout << "nhnw: " << nh << ", " << nw << ", " << area << endl;
			}


		}

	}



	return area;
}









int main() {

	cin >> W >> H;




	wall = new Wall*[H];

	for(int i=0; i<H; i++) {
		wall[i] = new Wall[W];
	}







	for(int h=0; h<H; h++) {
		for(int w=0; w<W; w++) {
			int n;

			cin >> n;


			if(n & 0b0001) {
				// cout << "W\n";
				wall[h][w].W_ = true;
			}


			if(n & 0b0010) {
				// cout << "N\n";
				wall[h][w].N_ = true;
			}


			if(n & 0b0100) {
				// cout << "E\n";
				wall[h][w].E_ = true;
			}


			if(n & 0b1000) {
				// cout << "S\n";
				wall[h][w].S_ = true;
			}
			// cout << "\n";
		}
	}




	int count=0;

	int max_ = -9999;






	for(int h=0; h<H; h++) {
		for(int w=0; w<W; w++) {
			if(!visit[h][w]) {

				int area = bfs(h*50 + w);

				// cout << "\narea: " << area << ", " << h << ", " << w << endl<<endl;

				count++;


				if(area > max_) 
					max_ = area;

			}
		}
	}



	cout << count << "\n" << max_ << "\n";



	vector<int> newmax(4, -9999);
	memset(visit, 0, sizeof(visit));


	for(int k=0; k<4; k++) {

		for(int h=0; h<H; h++) {
			for(int w=0; w<W; w++) {

					if(k==0 && wall[h][w].E_) {
						wall[h][w].E_ = false;

						if(!visit[h][w]) {

							int area = bfs(h*50 + w);

							// cout << "\narea: " << area << ", " << h << ", " << w << endl<<endl;

							if(area > newmax[0]) 
								newmax[0] = area;

						}
						wall[h][w].E_ = true;
					}

					if(k==1 && wall[h][w].W_) {
						wall[h][w].W_ = false;

						if(!visit[h][w]) {

							int area = bfs(h*50 + w);

							if(area > newmax[1]) 
								newmax[1] = area;

						}
						wall[h][w].W_ = true;
					}

					if(k==2 && wall[h][w].N_) {
						wall[h][w].N_ = false;

						if(!visit[h][w]) {

							int area = bfs(h*50 + w);


							if(area > newmax[2]) 
								newmax[2] = area;

						}
						wall[h][w].N_ = true;
					}

					if(k==3 && wall[h][w].S_) {
						wall[h][w].S_ = false;

						if(!visit[h][w]) {

							int area = bfs(h*50 + w);


							if(area > newmax[3]) 
								newmax[3] = area;

						}
						wall[h][w].S_ = true;
					}
				memset(visit, 0, sizeof(visit));
			}
		}
	}

	sort(newmax.begin(), newmax.end(), greater<int>());



	cout << newmax[0] << '\n';



	

	return 0;
}