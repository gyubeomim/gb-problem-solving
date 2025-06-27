#include <bits/stdc++.h>
using namespace std;
int N;

struct vector2{
  double x,y;
  explicit vector2(double x_=0,double y_=0) 
    : x(x_), y(y_) {}

	bool operator==(const vector2 r) const { return x==r.x && y==r.y; }
	bool operator<(const vector2 r) const { return x!=r.x ? x<r.x : y<r.y; }
	bool operator>(const vector2 r) const { return x!=r.x ? x>r.x : y>r.y; }

  vector2 operator+(const vector2& r) const { return vector2(x+r.x, y+r.y); }
  vector2 operator-(const vector2& r) const { return vector2(x-r.x, y-r.y); }
  vector2 operator*(double r) const { return vector2(x*r, y*r); }

  double dot(const vector2& r) const{ return x*r.x + y*r.y; }
  double cross(const vector2& r) const{ return x*r.y - r.x*y; }
  double norm() const { return hypot(x,y); }

  vector2 normalize() const { return vector2(x/norm(), y/norm()); }
  vector2 project(const vector2& r) const { 
    vector2 r_ = r.normalize(); 
    return r_*r_.dot(*this);
  }
};
typedef vector2 v2;
typedef vector<v2> poly;

// 원점에서 벡터 b가 a의 반시계 방향이면 양수, 시계방향이면 음수, 평행이면 0을 반환
double ccw(v2 a, v2 b) { return a.cross(b); }
// 점 p를 기준으로 벡터 b가 a의 반시계 방향이면 양수, 시계방향이면 음수, 평행이면 0을 반환
double ccw(v2 p, v2 a, v2 b) { return ccw(a-p, b-p); }

poly convexHull(const poly& points){
	int n = points.size();
	poly hull;

	// 가장 왼쪽 아래 점을 찾는다. 이 점은 껍질에 반드시 포함된다
	v2 pivot = *min_element(points.begin(), points.end());
	hull.push_back(pivot);

	while(1){
		// ph에서 시작하는 벡터가 가장 왼쪽인 점 next를 찾는다
		// 평행인 점이 여러개 있으면 가장 먼 것을 찾는다
		v2 ph = hull.back();
		v2 next = points[0];

		for(int i=1; i<n; i++){
			double cross = ccw(ph, next, points[i]);
			double dist = (next-ph).norm() - (points[i]-ph).norm();
			if(cross > 0 || (cross==0 && dist<0)) 
				next = points[i];
		}

		// 시작점으로 돌아왔으면 종료한다
		if(next == pivot) break;
		// next를 볼록 껍질에 포함시킨다
		hull.push_back(next);
	}
	return hull;
}

// 점 q가 다각형 p 안에 포함되어 있을 경우 참, 아닌 경우 거짓
bool isInside(v2 q, const poly& p){
	int crosses=0;
	for(int i=0; i<p.size(); i++){
		int j=(i+1)%p.size();
		// (p[i],p[j])가 반직선을 세로로 가로지르는가?
		if((p[i].y > q.y) != (p[j].y > q.y)) {
			// 가로지르는 x 좌표 계산
			double atX = (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if(q.x < atX) ++crosses;
		}
	}
	return crosses % 2 > 0;
}

bool segmentIntersects(v2 a, v2 b, v2 c, v2 d){
	double ab = ccw(a,b,c) * ccw(a,b,d);
	double cd = ccw(c,d,a) * ccw(c,d,b);

	// 두 선분이 한 직선 위에 있거나 끝점이 겹치는 경우	
	if(ab==0 && cd==0){
		if(b<a) swap(a,b);
		if(d<c) swap(c,d);
		return !(b<c || d>a);
	}
	return ab<=0 && cd<=0;
}

// 두 다각형이 서로 닿거나 겹치는 부분이 있는지 판단한다
bool polygonIntersects(const poly& p, const poly& q){
	int n = p.size(), m = q.size();
	// 우선 한 다각형이 다른 다각형에 포함되어 있는지 여부 판단
	if(isInside(p[0],q) || isInside(q[0],p)) return true;

	// 이 외의 경우 두 다각형이 서로 겹친다면 서로 닿는 두 변이 반드시 존재한다
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(segmentIntersects(p[i], p[(i+1)%n], q[j], q[(j+1)%m])) return true;
		}
	}
	return false;
}

int main(int argc, char **argv){
	//freopen("data/s_in_3345.txt", "r", stdin);
  int C; scanf("%d",&C);
	while(C--) {
		poly inputs[2];
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			int type,x,y;
			scanf("%d%d%d",&type,&x,&y);
			inputs[type].push_back(v2(x,y));
		}

		poly hulls[2];
		for(int i=0; i<2; i++){
			hulls[i] = convexHull(inputs[i]);
		}

		if(polygonIntersects(hulls[0], hulls[1])) printf("THEORY IS INVALID\n");
		else printf("THEORY HOLDS\n");
	}
}
