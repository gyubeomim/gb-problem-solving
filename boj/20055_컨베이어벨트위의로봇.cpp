#include <bits/stdc++.h>

using namespace std;
int N,K;
vector<int> A;
vector<int> B;

void Rotate() {
	int tmp = A.back();
	for(int i=2*N-2; i>=0; i--){
		A[i+1] = A[i];

		if(i <= N-1) {
			if(B[i] && i == N-1) {
				B[i] = 0;
			}
			else if(B[i] && i == N-2) {
				B[i] = 0;
			}
			else{
				if(i != N-1 && B[i+1] != 1) {
					B[i+1] = B[i];
					B[i] = 0;
				}
			}
		}
	}
	A[0] = tmp;
}

void RobotMove() {
	for(int i=N-1; i>=0; i--) {
		if(B[i] && i != N-1 && A[i+1] != 0)  {
			if(B[i+1] ==0) {
				A[i+1]--;
				B[i+1] = B[i];
				B[i] = 0;
			}
		}
	}
}

void RobotIn() {
	if(A[0] != 0) {
		B[0]  = 1;
		A[0]--;
	}
}

bool Check() {
	int cnt=0;
	for(int i=0; i<2*N; i++) {
		if(A[i]==0) {
			cnt++;
		}
	}

	if(cnt>=K) return true;

	return false;
}



int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>K;

	A.resize(2*N);
	B.resize(N);

	for(int i=0; i<2*N; i++){
		cin>>A[i];
	}
	int cnt=1;
	while(true) {
		// cout << B.size() << ", " << A.size()<<endl;
		// cout << "=======START===========" << endl;
		// for(int i=0; i<B.size(); i++) {
		// 	cout << B[i] << ' ';
		// }cout << endl;
		// cout << "```````````````````````" << endl;
		// for(int i=0; i<N; i++) {
		// 	cout << A[i] << ' ';
		// }cout << endl;
        //
		// cout << "-----------------------" << endl;
		// for(int i=2*N-1; i>=N; i--) {
		// 	cout << A[i] << ' ';
		// }cout << endl;
		// cout << "========================" << endl;


		Rotate();
        //
		// cout << "=======ROTATE===========" << endl;
		// for(int i=0; i<B.size(); i++) {
		// 	cout << B[i] << ' ';
		// }cout << endl;
		// cout << "```````````````````````" << endl;
		// for(int i=0; i<N; i++) {
		// 	cout << A[i] << ' ';
		// }cout << endl;
        //
		// cout << "-----------------------" << endl;
		// for(int i=2*N-1; i>=N; i--) {
		// 	cout << A[i] << ' ';
		// }cout << endl;
		// cout << "========================" << endl;
        //
        //

		RobotMove();


		// cout << "=======ROBOT MOVE===========" << endl;
		// for(int i=0; i<B.size(); i++) {
		// 	cout << B[i] << ' ';
		// }cout << endl;
		// cout << "```````````````````````" << endl;
		// for(int i=0; i<N; i++) {
		// 	cout << A[i] << ' ';
		// }cout << endl;
        //
		// cout << "-----------------------" << endl;
		// for(int i=2*N-1; i>=N; i--) {
		// 	cout << A[i] << ' ';
		// }cout << endl;
		// cout << "========================" << endl;

		RobotIn();

		// cout << "=======ROBOT IN===========" << endl;
		// for(int i=0; i<B.size(); i++) {
		// 	cout << B[i] << ' ';
		// }cout << endl;
		// cout << "```````````````````````" << endl;
		// for(int i=0; i<N; i++) {
		// 	cout << A[i] << ' ';
		// }cout << endl;
        //
		// cout << "-----------------------" << endl;
		// for(int i=2*N-1; i>=N; i--) {
		// 	cout << A[i] << ' ';
		// }cout << endl;
		// cout << "========================" << endl;

		if(Check()) {
			// cout<<"Checked"<<endl;
			// for(int i=0; i<A.size(); i++) {
			// 	cout << A[i] << ' ';
			// } cout << endl;

			break;
		}
		// cout<<"Not Checked cnt: " << cnt <<endl;
		// for(int i=0; i<A.size(); i++) {
		// 	cout << A[i] << ' ';
		// } cout << endl;
        //
		cnt++;
	}
	 
	cout << cnt;

	return 0;
}
