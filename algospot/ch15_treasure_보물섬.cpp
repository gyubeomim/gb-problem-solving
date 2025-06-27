#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

int N;

struct vector2{
  double x,y;
  explicit vector2(double x_=0,double y_=0) 
    : x(x_), y(y_) {}

  vector2 operator+(const vector2& r){ return vector2(x+r.x, y+r.y); }
  vector2 operator-(const vector2& r){ return vector2(x-r.x, y-r.y); }
  vector2 operator*(double r){ return vector2(x*r, y*r); }

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

bool lineIntersection(v2 a, v2 b, v2 c, v2 d, v2& x){
  double det = (b-a).cross(d-c);
  // 두 선이 평행한 경우
  if(fabs(det) < EPS) return false;
  x = a + (b-a)*((c-a).cross(d-c)/det);
  return true;
}

poly cutPoly(const poly& p, const v2&a, const v2& b) {
  int n = p.size();
  // 각 점이 반평면 내에 있는지 여부를 우선 확인
  vector<bool> inside(n);
  for(int i=0; i<n; i++){
    inside[i] = (ccw(a,b,p[i]) >= 0);
  }

  poly ret;
  // 다각형의 각 변을 순회하면서 결과 다각형의 각 점을 발견한다
  for(int i=0; i<n; i++){
    int j=(i+1)%n;
    // 반평면 내에 있는 점 p[i]는 항상 결과 다각형에 포함된다
    if(inside[i]) ret.push_back(p[i]);
    if(inside[i] != inside[j]){
      v2 cross;
      assert(lineIntersection(p[i], p[j], a, b, cross));
      ret.push_back(cross);
    }
  }
  return ret;
}

// 서덜랜드-호지(Sutherland-Hodgman) 알고리즘을 이용한 다각형 클리핑
poly intersection(const poly& p, double x1, double y1, double x2, double y2) {
  v2 a(x1,y1),b(x2,y1),c(x2,y2),d(x1,y2);

  poly ret = cutPoly(p, a, b);
  ret = cutPoly(ret, b, c);
  ret = cutPoly(ret, c, d);
  ret = cutPoly(ret, d, a);
  return ret;
}

double area(const poly& p){
  double ret = 0;
  for(int i=0; i < p.size(); i++){
    int j = (i+1) % p.size();
    ret += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return fabs(ret)/2.0;
}

int main(int argc, char **argv){
  

  int C; scanf("%d",&C);
  while(C--) {
    double x1,y1,x2,y2;
    scanf("%lf %lf %lf %lf %d",&x1,&y1,&x2,&y2,&N);
    
    if(x1>x2) swap(x1, x2);
    if(y1>y2) swap(y1, y2);

    poly p(N);
    for(int i=0; i<N; i++){
      scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    p = intersection(p, x1,y1,x2,y2);

    double ans = area(p);
    printf("%.7lf\n", ans);
  } 
}
