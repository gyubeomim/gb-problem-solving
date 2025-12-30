#include <bits/stdc++.h>

using namespace std;
int N;
int operands[11];
int operators[4];
int mymin=1000000001;
int mymax=-1000000001;


void Solution(int now, int idx){
	if(idx == N){
		if(now > mymax) mymax = now;
		if(now < mymin) mymin = now;
		return;
	}


	for(int i=0;i<4;i++){
		if(operators[i]!=0){
			operators[i]--;

			if(i==0) Solution(now + operands[idx], idx+1);
			else if(i==1)				Solution(now - operands[idx], idx + 1);
			else if (i == 2)				Solution(now * operands[idx], idx + 1);
			else 				Solution(now / operands[idx], idx + 1);

			operators[i]++;
		}
	}


}


int main() {
	cin>>N;

	for(int i=0;i<N;i++){
		cin >> operands[i];
	}

	for(int i=0;i<4;i++){
		cin>>operators[i];
	}

	Solution(operands[0],1);

	cout << mymax<<'\n' << mymin<<'\n';

}