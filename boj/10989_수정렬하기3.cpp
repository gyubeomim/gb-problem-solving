#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int arr[10001];

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;
		
	for(int i=0; i<N; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}

	for(int i=1; i<=10000; i++) {
		for(int j=0; j<arr[i]; j++) {
			cout << i << '\n';
		}
	}

	return 0;
}
