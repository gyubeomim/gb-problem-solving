#include <bits/stdc++.h>
using namespace std;
const double EPS=1e-9;
const double INF=1e200;
const int LM = 55;

struct vector2 {
	double x,y;
	explicit vector2(double x_=0, double y_=0) :x(x_),y(y_) {}

	vector2 operator+(const vector2& r) const { return vector2(x+r.x, y+r.y); }
	vector2 operator-(const vector2& r) const { return vector2(x-r.x, y-r.y); }
	vector2 operator*(double r) const { return vector2(x*r, y*r); }

	double dot(const vector2& r) const{ return x*r.x + y*r.y; }
	double norm() const { return hypot(x,y); }
	vector2 normalize() const{ return vector2(x/norm(), y/norm()); }
	vector2 project(const vector2& r) const {
		vector2 r_ = r.normalize();
		return r_ * r_.dot(*this);
	}
};
int N;
vector2 center[LM];
int radius[LM];

// 2차방정식 ax^2+bx+c=0의 모든 실근을 크기 순서대로 반환한다
vector<double> solve2(double a, double b, double c){
	double d = b*b - 4*a*c;
	// 해가 없는 경우
	if(d < -EPS) return vector<double>();
	// 중근
	if(d < EPS) return vector<double>(1, -b/(2*a));

	vector<double> ret;
	ret.push_back((-b-sqrt(d))/ (2*a));
	ret.push_back((-b+sqrt(d))/ (2*a));
	return ret;
}

double hitCircle(vector2 here, vector2 dir, vector2 center, int radius){
	double a = dir.dot(dir);
	double b = 2*dir.dot(here - center);
	double c = center.dot(center) + here.dot(here) - 2*here.dot(center) - radius*radius;

	vector<double> sols = solve2(a,b,c);
	if(sols.empty() || sols[0] < EPS) return INF;
	return sols[0];
}

// here에 있던 공이 dir 방향으로 굴러와 center를 중심으로 하는 장애물에서 
// contact의 위치에서 충돌했을 때 공의 새로운 방향을 반환한다 
vector2 reflect(vector2 dir, vector2 center, vector2 contact){
	return (dir - dir.project(contact - center)*2).normalize();
}

// 공의 현재 위치와 방향이 주어질 때 최대 10번의 충돌을 출력한다
void simulate(vector2 here, vector2 dir){
	// 방향은 항상 단위 벡터로 저장하자
	dir = dir.normalize();

	int hitCount = 0;
	while(hitCount<100){
		// 이번에 충돌할 장애물을 찾는다
		int circle = -1;
		double time = INF*0.5;

		// 각 장애물을 순회하며 가장 먼저 만나는 장애물을 찾는다
		for(int i=0; i<N; i++){
			double cand = hitCircle(here, dir, center[i], radius[i]+1);
			if(cand < time) {
				time = cand;
				circle = i;
			}
		}

		// 더이상 장애물에 충돌하지 않고 게임판을 벗어난 경우
		if(circle==-1) break;

		if(hitCount++) printf(" ");
		printf("%d", circle);

		// 공의 새 위치를 계산한다
		vector2 contact = here + dir*time;
		dir = reflect(dir, center[circle], contact);
		here = contact;
	}
	puts("");
}

int main(int argc, char **argv){
	// freopen("data/s_in_3344.txt", "r", stdin);
	int C; scanf("%d",&C);
	while(C--){
		int x,y,dx,dy;
		cin>>x>>y>>dx>>dy>>N;

		vector2 here, dir;
		here = vector2(x,y);
		dir = vector2(dx,dy).normalize();

		for(int i=0; i<N;i++){
			radius[i] = 0;
			center[i] = vector2(0,0);

			int x,y;
			cin>> x >> y >> radius[i];
			center[i] = vector2(x,y);
		}

		simulate(here, dir);
	}
}
