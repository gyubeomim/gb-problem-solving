#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX=1000001;
int A,p,visited[MAX];

void dfs(int num) {
  visited[num] += 1;
  if(visited[num] == 3) return;

  int sum = 0;
  while(num) {
    sum += (int)floor(pow(num%10, p)+0.5);
    num /= 10;
  }
  dfs(sum);
}

int main() {
  cin >> A >> p;

  dfs(A);

  int result = 0;
  for(int i=0; i<MAX; i++) {
    if(visited[i] == 1) {
      result += 1;
    }
  }
  cout << result << '\n';
  return 0;
}