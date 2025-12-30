#include <bits/stdc++.h>

using namespace std;

char digit[10] = {'0','1','2','3','4','5','6','7','8','9'};
char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int result = 0;
string input;
string output;
int sz=0;
map<string, int> m_output;

void add_digit(int cur);
void add_alpha(int cur);

void add_digit(int cur){
	for(int i=0; i<10; i++){
		if(cur!=0){
			if(output[cur-1] == digit[i])
				continue;
		}

		output[cur] = digit[i];

		if(input[cur+1] == 'c') {
			add_alpha(cur+1);
		}
		else if(input[cur+1] == 'd') {
			add_digit(cur+1);
		}

		if(!m_output[output]){
			m_output[output] = 1;
			result++;
		}
	}
}

void add_alpha(int cur){
	for(int i=0; i<26; i++){
		if(cur!=0){
			if(output[cur-1] == alpha[i])
				continue;
		}

		output[cur] = alpha[i];

		if(input[cur+1] == 'c') {
			add_alpha(cur+1);
		}
		else if(input[cur+1] == 'd') {
			add_digit(cur+1);
		}

		if(!m_output[output]){
			m_output[output] = 1;
			result++;
		}
	}
}

void solve() {
	sz = input.size();
	output.resize(sz);
	
	if(input[0] == 'c'){
		add_alpha(0);
	}
	else if(input[0] == 'd'){
		add_digit(0);
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> input;


	solve();
	
	cout << result << '\n';

	return 0;
}
