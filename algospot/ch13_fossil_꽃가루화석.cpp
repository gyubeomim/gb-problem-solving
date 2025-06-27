#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N,M;

struct point{
	double y,x;
};

vector<point> hull1, hull2;  // 입력에 주어진 볼록 다각형
vector<pair<point,point>> upper, lower; // 위 껍질에 속하는 선분들과 아래 껍질에 속하는 선분들

// hull이 반시계 방향으로 주어지므로 인접한 두 점에 대해 x가
// 증가하는 방향이면 아래쪽 껍질, x가 감소하는 방향이면 위쪽 껍질이다
void decompose(const vector<point>& hull){
	int n = hull.size();
	for(int i=0;i<n;i++){
		if(hull[i].x < hull[(i+1)%n].x) 
			lower.push_back( {hull[i], hull[(i+1)%n]});
		else if(hull[i].x > hull[(i+1)%n].x) 
			upper.push_back( {hull[i], hull[(i+1)%n]});
	}
}

// [a.x, b.x] 구간 안에 x가 포함되나 확인한다
bool between(const point&a, const point&b, double x){
	return (a.x<=x && x<=b.x) || (b.x<=x && x<=a.x);
}

// (a,b) 선분과 주어진 위치의 수직선이 교차하는 위치를 반환한다
double at(const point&a, const point&b, double x){
	double dy = b.y-a.y;
	double dx = b.x-a.x;
	if(fabs(dx)<1e-9) return a.y;
	return a.y + dy*(x-a.x)/dx;
}

// 두 다각형의 교집합을 수직선으로 잘랐을 때 단면의 길이를 반환한다
double vertical(double x){
	double minUp = 1e20, maxLow = -1e20;

	// 위 껍질의 선분을 순회하며 최소 y 좌표를 찾는다
	for(int i=0; i<upper.size();i++) {
		if(between(upper[i].X, upper[i].Y, x)) {
			minUp = min(minUp, at(upper[i].X, upper[i].Y, x));
		}
	}
	// 아래 껍질의 선분을 순회하며 최대 y 좌표를 찾는다
	for(int i=0; i<lower.size();i++){
		if(between(lower[i].X, lower[i].Y, x)){
			maxLow = max(maxLow, at(lower[i].X, lower[i].Y, x));
		}
	}
	return minUp - maxLow;
}

double minX(vector<point>& hull) {
	double ret = 1e20;
	for(auto& p : hull) 
		ret = min(ret, p.x);
	return ret;
}
double maxX(vector<point>& hull) {
	double ret = -1e20;
	for(auto& p : hull) 
		ret = max(ret, p.x);
	return ret;
}

double solve(){
	// 수직선이 두 다각형을 모두 만나는 x 좌표의 범위를 구한다
	double lo = max(minX(hull1), minX(hull2));
	double hi = min(maxX(hull1), maxX(hull2));

	// 예외 처리: 두 다각형이 겹치지 않는 경우
	if(hi < lo) return 0;

	// 삼분 검색
	for(int iter=0; iter<100; iter++){
		double aab = (lo*2 + hi) /3.0;
		double abb = (lo + hi*2) /3.0;
		if(vertical(aab) < vertical(abb)) lo = aab;
		else hi = abb;
	}
	return max(0.0, vertical(hi));
}

int main(int argc, char **argv){
	// freopen("data/s_in_4363.txt", "r", stdin);
	int C; scanf("%d",&C);
	while(C--) {
		scanf("%d%d",&N,&M);

		hull1.resize(N); hull2.resize(M);
		upper.clear(); lower.clear();

		for(int i=0; i<N;i++){
			scanf("%lf%lf", &hull1[i].x, &hull1[i].y);
		}
		for(int i=0; i<M;i++){
			scanf("%lf%lf", &hull2[i].x, &hull2[i].y);
		}

		decompose(hull1); 
		decompose(hull2);

		double ans = max(0.0, solve());
		printf("%.10lf\n", ans);
	}
}
