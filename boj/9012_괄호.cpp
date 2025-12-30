#include <cstdio>
#include <iostream>
using namespace std;

string valid(string s) {
  int cnt=0;
  for(int i=0; i<s.size(); i++) {
    if(s[i] == '(') cnt++;
    else cnt--;

    if(cnt<0) return "NO";
  }

  if(cnt==0) return "YES";
  else return "NO";
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    cout << valid(s) << endl;
  }
  return 0;
}
