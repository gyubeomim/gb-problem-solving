#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
	while(true){
		string S;
		getline(cin, S);
		if(S==".") break;
		stack<int> st;
		bool isValid = true;

		for(auto c : S){
			if(c=='(' || c == '[') st.push(c);
			else if(c==')'){
				if(st.empty() || st.top() != '(') {
					isValid = false;
					break;
				}
				st.pop();
			}
			else if(c==']') {
				if(st.empty() || st.top() != '[') {
					isValid = false;
					break;
				}
				st.pop();
			}
		}

		if(!st.empty()) isValid = false;
		if(isValid) printf("yes\n");
		else printf("no\n");
	}
}
