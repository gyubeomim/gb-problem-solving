#include <bits/stdc++.h>
using namespace std;

stack<char> S;

int main(int argc, char **argv){
  int C; scanf("%d",&C);
  while(C--) {
    string s;
    cin >> s;

    bool success = true;

    while(!S.empty()) S.pop();

    for(int i=0; i<s.size(); i++){
      char c = s[i];

      if(c == '(' || c == '[' || c == '{') {
        S.push(c);
      }
      else if(c == ')' || c == ']' || c == '}') {
        if(S.empty()) { success = false; break;}

        char top = S.top(); 

        if(c == ')' && top != '(') { success = false; break; }
        if(c == ']' && top != '[') { success = false; break; }
        if(c == '}' && top != '{') { success = false; break; }

        S.pop();
      }
    }

    if(!S.empty()) { success = false;}

    if(success) printf("YES\n");
    else printf("NO\n");
  } 
}