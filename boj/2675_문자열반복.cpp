#include <bits/stdc++.h>

using namespace std;


int main(){
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++){
      for(int j=0; j<n; j++){
        cout << s[i];
      }
    }
  cout << endl;
  }

}
