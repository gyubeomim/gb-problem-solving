#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>
#include <algorithm>

const int MAX = 50000000;
// const int MAX = 100;

using namespace std;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 0;
	cin >> T;


	while(T--) {

		string command, input;

		int M,C,I;
		cin>>M>>C>>I;

		int* mem = new int[M];
		fill(mem, mem+M, 0);

		cin >> command;
		cin >> input;

		reverse(input.begin(), input.end());

		int bracket_left[4096] = {0};
		int bracket_right[4096] = {0};

		stack<int> s;

		for(int i=0; i<C; i++){
			if(command[i] == '[')
				s.push(i);

			if(command[i] == ']') {
				bracket_right[i] = s.top();
				bracket_left[s.top()] = i;
				s.pop();
			}
		}


		int count = 2*MAX;

		int start_loop_idx = -1;
		int end_loop_idx = -1;

		int mptr = 0;
		int cptr = 0;

		// for(cptr=0; cptr<C; cptr++) {
		while(cptr < C) {
			if(count == MAX) {
				start_loop_idx = end_loop_idx = cptr;
			}

			if(count <= 0) {
				cout << "Loops " 
					<< start_loop_idx-1
					<< ' ' 
					<< end_loop_idx 
					<< '\n';

				break;
			}

			switch(command[cptr]){
				case '+':
					mem[mptr]++;
					if(mem[mptr] > 255) mem[mptr] = 0;
					cptr++;
					break;
				case '-':
					mem[mptr]--;
					if(mem[mptr] < 0) mem[mptr] = 255;
					cptr++;
					break;
				case '<':
					mptr--;
					if(mptr < 0) mptr = M-1;
					cptr++;
					break;
				case '>':
					mptr++;
					if(mptr > M-1) mptr = 0;
					cptr++;
					break;
				case '[':
					if (mem[mptr] == 0) {
						cptr = bracket_left[cptr];
					}
					cptr++;
					break;
				case ']':
					if (mem[mptr] != 0) {
						cptr = bracket_right[cptr];
					}
					cptr++;
					break;
				case '.':
					cptr++;
					break;
				case ',':
					if(!input.empty()) {
						mem[mptr] = input.back();
						input.pop_back();
					}
					else {
						mem[mptr] = 255;
					}
					cptr++;
					break;
			}
			count--;

			if(count < MAX) {
				start_loop_idx = min(cptr, start_loop_idx);
				end_loop_idx = max(cptr, end_loop_idx);
			}
		}
		
		if(cptr == C)
			cout << "Terminates\n";
	}


	return 0;
}
