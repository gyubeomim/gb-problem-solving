#include <bits/stdc++.h>

using namespace std;

int visit[100]={0};
int arr[100] ={0};
int N, M;


int main() {
	cin >> N >> M;

	for(int i=0; i<N;i++){
		cin >> arr[i];
	}

	int min=999999;
	int goal=0, sum=0;

	for(int i=0; i<N-2; i++){
		for(int j=i+1; j<N-1; j++){
			for(int k=j+1; k<N; k++){
				sum = arr[i] + arr[j] + arr[k];

				if(M>=sum && min > M-sum){
					min = M-sum;
					goal = sum;
				}
			}
		}
	}

	cout << goal << '\n';

	return 0;
}