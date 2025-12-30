#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int a[1000][1000];

void append(string &s, char c, int cnt) {
  for(int i=0; i<cnt; i++) {
    s += c;
  }
}

int main() {
  int n,m;
  cin >> n >> m;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> a[i][j];
    }
  }

  string s = "";
  if(n%2 == 1) {               // ed: n이 홀수인 경우
    for(int i=0; i<n; i++) {
      if(i%2 == 0) {
        append(s, 'R', m-1);
        if(i != n-1)
          append(s, 'D', 1);
      }
      else {
        append(s, 'L', m-1);
        append(s, 'D', 1);
      }
    }
  }
  else if(m%2 == 1) {          // ed: m이 홀수인 경우
    for(int j=0; j<m; j++) {
      if(j%2 == 0) {
        append(s, 'D', n-1);
        if(j != m-1) {
          append(s, 'R', 1);
        }
      }
      else {
        append(s,'U',n-1);
        append(s,'R',1);
      }
    }
  }
  else {                       // ed: 둘다 짝수인 경우
    int x,y;

    // ed: n,m이 둘 다 짝수이면 한 칸은 반드시 지나가지 못하므로 가장 작은 칸 하나를 제외시켜야 한다
    //     제외시킬 칸 하나를 찾는 구문
    x = 0;
    y = 1;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        if((i+j)%2 == 1) {
          if(a[x][y] > a[i][j]) {
            x = i;
            y = j;
          }
        }
      }
    }

    int x1 = 0;
    int y1 = 0;
    int x2 = n-1;
    int y2 = m-1;

    string s2 = "";

    // ed: height 방향 먼저
    while(x2 - x1 > 1) {
      if(x1/2 < x/2) {       // ed: 앞에서 움직이고
        append(s, 'R', m-1);
        append(s, 'D', 1);
        append(s, 'L', m-1);
        append(s, 'D', 1);
        x1 += 2;
      }
      if(x/2 < x2/2) {       // ed: 뒤에서도 움직인다
        append(s2, 'R', m-1);
        append(s2, 'D', 1);
        append(s2, 'L', m-1);
        append(s2, 'D', 1);
        x2 -= 2;
      }
    }

    // ed: width 방향
    while(y2 - y1 > 1) {
      if(y1/2 < y/2) {
        append(s, 'D', 1);
        append(s, 'R', 1);
        append(s, 'U', 1);
        append(s, 'R', 1);
        y1 += 2;
      }
      if(y/2 < y2/2) {
        append(s2, 'D', 1);
        append(s2, 'R', 1);
        append(s2, 'U', 1);
        append(s2, 'R', 1);
        y2 -= 2;
      }
    }

    if(y == y1) {
      append(s, 'R', 1);
      append(s, 'D', 1);
    }
    else {
      append(s, 'D', 1);
      append(s, 'R', 1);
    }
    reverse(s2.begin(), s2.end());
    s += s2;
  }
  cout << s << '\n';

  return 0;
}
