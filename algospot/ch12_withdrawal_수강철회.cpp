#include <bits/stdc++.h>
using namespace std;

const int LM = 1005;
int N,K;
int c[LM], r[LM];

// 누적 등수 x가 되도록 할 수 있나?
bool decision(double x){
	vector<double> v;
	for(int i=0; i<N;i++){
		v.push_back(x*c[i] - r[i]);
	}
	sort(v.begin(), v.end());
	// 이 문제는 v중 k개의 합이 0 이상이 될 수 있는지로 바뀐다. 탐욕법으로 해결
	double sum=0;
	for(int i=N-K; i<N; i++) sum += v[i];
	return sum>=0;
}

// 얻을 수 있는 최소의 누적등수를 계산한다
double optimize(){
	double lo=-1e-9, hi=1;
	for(int i=0;i<100;i++){
		double m = (lo+hi)/2;
		if(decision(m)) hi=m;
		else lo=m;
	}
	return hi;
}

int main(int argc, char **argv){
	// freopen("data/s_in_1123.txt", "r", stdin);
	int C; scanf("%d",&C);
	while(C--) {
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++){
			scanf("%d%d",&r[i],&c[i]);
		}
		double ans = optimize();
		printf("%.10lf\n", ans);
	}
}
