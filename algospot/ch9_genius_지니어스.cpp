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

const int LM = 55;
int N, K, M, L[LM], Q[LM];
double T[LM][LM];

using matrix = vector<vector<double>>;
struct Matrix{
	matrix mat;
	int r_,c_;

	Matrix(int r, int c) : r_(r), c_(c), mat(r, vector<double>(c,0)) {}
	Matrix(const matrix& v) : mat(v), r_(v.size()), c_(v[0].size()) {}

	Matrix operator*(const Matrix& B) const {
		Matrix ret(r_, B.c_);
		for(int i=0; i<r_; i++){
			for(int j=0; j<B.c_; j++){
				for(int k=0; k<c_; k++){
					ret.mat[i][j] += mat[i][k] * B.mat[k][j];
				}
			}
		}
		return ret;
	}

	Matrix fastPow(int k) const {
		if(k==1) return *this;
		if(k%2 == 1) return (*this) * fastPow(k-1);
		Matrix t = fastPow(k/2);
		return t*t;
	}
};

#if 0
matrix operator*(const matrix&a, const matrix& b){
	matrix c(a.size(), vector<double>(b[0].size()));
	for(int i=0;i<a.size(); i++){
		for(int j=0; j<b[0].size();j++){
			for(int k=0;k<b.size();k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

matrix fastPow(const matrix& a, int k){
	if(k==1) return a;
	if(k%2==1) return a*fastPow(a, k-1);
	matrix t = fastPow(a, k/2);
	return t*t;
}
#endif

vector<double> getProb1(){
	// c[time][song] = time분 후에 song번 노래가 시작할 확률
	double c[5][50];
	memset(c, 0, sizeof(c));
	c[0][0] = 1.0;

	for(int time=1; time<=K; time++){
		for(int song=0; song<N; song++){
			double& prob = c[time%5][song];
			prob = 0;
			for(int last = 0; last<N; last++){
				prob += c[(time-L[last]+5)%5][last] * T[last][song];
			}
		}
	}

	vector<double> ret(N);
	// song번 노래가 재생되고 있을 확률을 계산한다
	for(int song=0; song<N; song++){
		// song번 노래가 시작했을 시간을 모두 찾아 더한다
		for(int start=K-L[song]+1; start<=K; start++){
			ret[song] += c[start%5][song];
		}
	}
	return ret;
}

vector<double> getProb2(){
	Matrix W(4*N, 4*N);
	for(int i=0; i<3*N; i++) W.mat[i][i+N] = 1.0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			W.mat[3*N + i][(4-L[j])*N + j] = T[j][i];
		}
	}

	Matrix Wk = W.fastPow(K);

	vector<double> ret(N);
	for(int song=0; song<N; song++){
		for(int start=0; start<L[song]; start++){
			ret[song] += Wk.mat[(3-start)*N+song][3*N];
		}
	}
	return ret;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		// freopen("data/d1922.txt", "r", stdin);
	#endif
		int C; scanf("%d", &C);
		while(C--) {
			scanf("%d%d%d", &N, &K, &M);

			for(int i=0;i<N;i++) scanf("%d", &L[i]);
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					scanf("%lf", &T[i][j]);
				}
			}

			auto prob = getProb2();

			while(M--){
				int q; scanf("%d\n", &q);
				printf("%.8lf ", prob[q]);
			}puts("");
		}
}