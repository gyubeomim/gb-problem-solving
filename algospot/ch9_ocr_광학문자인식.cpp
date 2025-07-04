#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 505;
int n,m,q;

// 분류기가 반환한 문장, 단어 번호로 변환되어 있음
int R[LM];
double B[LM];
// T[i][j] = i 단어 이후에 j 단어가 나올 확률의 로그값
double T[LM][LM];
// M[i][j] = i 단어가 j 단어로 분류될 확률의 로그값
double M[LM][LM];

int choice[LM][LM];
double cache[LM][LM]; // 1로 초기화한다 (확률이기 때문)

string corpus[LM];  // 입력받은 단어들의 목록

void initCache(){
	for(int i=0; i<n; i++){
		for(int j=0; j<=m; j++){
			cache[i][j] = 1.0;
		}
	}
}

// Q[segment] 이후를 채워서 얻을 수 있는 최대 g() 곱의 로그값을 반환한다
// Q[segment-1] == previousMatch라고 가정한다
double recognize(int segment, int previousMatch){
	if(segment==n) return 0;

	double &ret = cache[segment][previousMatch];
	if(ret != 1.0) return ret;

	ret = -1e200;  // log(0) = 음의 무한대에 해당하는 값
	int& choose = choice[segment][previousMatch];

	// R[segment]에 해당하는 단어를 찾는다
	for(int thisMatch=1; thisMatch<=m; thisMatch++){
		// g(thisMatch) = T(previousMatch, thisMatch) * M(thisMatch, R[segment])
		double cand = T[previousMatch][thisMatch]
								+ M[thisMatch][R[segment]] 
								+ recognize(segment+1, thisMatch);
		if(ret < cand){
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}

string reconstruct(int segment, int previousMatch){
	int choose = choice[segment][previousMatch];
	string ret = corpus[choose];
	if(segment < n-1) 
		ret = ret + " " + reconstruct(segment+1, choose);
	return ret;
}

int main(int argc, char **argv){
	// freopen("data/d1233.txt", "r", stdin);

	scanf("%d%d",&m, &q);
	for(int i=1; i<=m; i++)
		cin >> corpus[i];
	
	for(int i=1; i<=m; i++){
		// scanf("%lf", &B[i]);
		cin >> B[i];
		B[i] = log(B[i]);
	}

	for(int i=0; i<=m; i++){
		for(int j=1; j<=m; j++){
			if(i==0) T[i][j] = B[j];
			else {
				// scanf("%lf", &T[i][j]);
				cin >> T[i][j];
				T[i][j] = log(T[i][j]);
			}
		}
	}

	for(int i=1; i<=m; i++){
		for(int j=1; j<=m; j++){
			// scanf("%lf", &M[i][j]);
			cin >> M[i][j];
			M[i][j] = log(M[i][j]);
		}
	}

	while(q--){
		scanf("%d", &n);
		initCache();
		for(int i=0; i<n; i++){
			string s; cin >> s;
			for(int j=1; j<=m; j++){
				if(s == corpus[j]){
					R[i] = j;
					break;
				}
			}
		}
		recognize(0, 0);
		string ans = reconstruct(0,0);
		printf("%s\n", ans.c_str());
	}
}