/*
  c++ ==> 백준 4344, 평균은 넘겠지 문제를 풀어본 코드 (틀렸습니다 나옴)

  시간 때문인지 정확한 소수점 3자리가 안나와서 그런지 틀렸습니다를 출력했다
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int C;
  cin >> C;

  int** x = new int*[C];
  for(int i=0; i<C; i++) {
    x[i] = new int[1000];
  }

  int* N = new int[C];

  for(int i=0; i<C; i++) {
    cin >> *(N+i);
    for(int j=0; j<*(N+i); j++) {
      cin >> x[i][j];
    }
  }

  double sum = 0;
  double average = 0;
  double uppercount = 0;

  for(int i=0; i<C; i++) {
    sum = 0;
    uppercount =0;
    for(int j=0; j<*(N+i); j++) {
      sum += x[i][j];
    }
    average = sum / *(N+i);
    for(int j=0; j<*(N+i); j++) {
      if(x[i][j] > average) {
        uppercount++;
      }
    }
    /* cout << uppercount / *(N+i)*100<< "%" << setprecision(5) << endl; */
    printf("%.3lf%%\n", uppercount / *(N+i)*100.0);
  }

  return 0;
}
