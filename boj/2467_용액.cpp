#include <cstdio>
#include <algorithm>

using namespace std;
constexpr int LM = 100005;

int A[LM];
int N;

int main(int argc, char **argv){
	scanf("%d", &N);

	for(int i=0; i<N; i++){ 
		scanf("%d", &A[i]);
	}

	sort(A, A+N, [](const int&a, const int&b){
			int c = abs(a);
			int d = abs(b);

			return c < d;
			});

	int ansA, ansB;
	int sum=0, total=1100000000;

	for(int i=0; i<N-1;i++){
		sum = abs(A[i] + A[i+1]);

		if(sum < total) {
			total = sum;
			ansA = A[i] < A[i+1] ? A[i] : A[i+1];
			ansB = A[i] > A[i+1] ? A[i] : A[i+1];
		}

		if(total==0) break;
	}

	printf("%d %d", ansA, ansB);

	return 0;
}
