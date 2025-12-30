#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(int argc, char **argv) {
  int N;
  cin >> N;
  cin.ignore();

  for(int i=0; i<N; i++) {
    int len=0;
    char S[151], c;

    while((c=getchar()) != '\n') {
      S[len] = c;
      len++;
    }

    int level=0, maxlevel=0;

    for(int j=0; j<len; j++) {
      if(S[j] == '[') {
        level++;
        if(level > maxlevel)  maxlevel = level;
      }
      else
        level--;
    }
    int ans = pow(2,maxlevel);
    cout << ans << endl;
  }

  return 0;
}
