#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solve(int size, int num) {
	int cnt = 0;

	while(size >= num) {
		cnt += size / num;
		size /= num;
	}

	return cnt;
}

int main(int argc, char** argv) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int N, M, five, two;
	cin >> N >> M;

	five = solve(N, 5) - solve(N-M, 5) - solve(M, 5);
	two = solve(N, 2) - solve(N-M, 2) - solve(M, 2);

	if(five >= two) 
		cout << two << '\n';
	else 
		cout << five << '\n';

	return 0;
}
