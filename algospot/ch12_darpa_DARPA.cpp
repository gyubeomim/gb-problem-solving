#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<double> locations;

// 결정 문제: 정렬되어 있는 locations들 중 cameras를 선택해 모든 카메라 간의 
// 간격이 gap 이상이 되는 방법이 있는지 반환
bool decision(const vector<double> &locations, int cameras, double gap){
	// 카메라를 설치할 수 있을 때마다 설치하는 탐욕적 알고리즘
	double limit = -1;
	int installed = 0;
	for(int i=0;i<locations.size();i++){
		if(limit <= locations[i]){
			++installed;
			// locations[i]+gap 이후는 되어야 카메라를 설치할 수 있다
			limit = locations[i] + gap;
		}
	}
	// 결과적으로 cameras 대 이상을 설치할 수 있었으면 성공
	return installed >= cameras;
}

double optimize(const vector<double>& locations, int cameras){
	double lo=0, hi=241;
	for(int i=0;i<100;i++){
		double m = (lo+hi)/2;
		if(decision(locations, cameras, m)) lo = m;
		else hi = m;
	}
	return lo;
}

int main(int argc, char **argv){
	// freopen("data/s_in_4321.txt", "r", stdin);
	int C; scanf("%d",&C);
	while(C--) {
		scanf("%d%d",&N,&M);

		locations.clear();
		for(int i=0; i<M; i++){
			double pos; scanf("%lf", &pos);
			locations.push_back(pos);
		}
		double ans = optimize(locations, N);
		printf("%.2lf\n", ans);
	}
}
