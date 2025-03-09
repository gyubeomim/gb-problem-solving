#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 1000005;

struct Stack{
    int stack[LM];
    int pos=0;

    void push(int x) { stack[pos++] = x; }
    void pop() { pos--; }
		bool empty() { return (pos==0); }
    int top() { return stack[pos-1]; }

} S;

int main(int argc, char **argv){
	while(true){
		string S;
		getline(cin, S);
		if(S==".") break;
		Stack st;
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
