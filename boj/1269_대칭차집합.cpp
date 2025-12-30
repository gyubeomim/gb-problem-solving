#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int, int> A,B,Ac,Bc;
	int NA, NB;
	cin >> NA >> NB;

	for(int i=0; i<NA; i++) {
		int num;
		cin >> num;

		A[num]++;
	}

	for(int i=0; i<NB; i++) {
		int num;
		cin >> num;

		if(A.find(num) == A.end()) {
			B[num]++;
		}
		else {
			A.erase(A.find(num));
		}
	}

	cout << A.size() + B.size() << '\n';
}