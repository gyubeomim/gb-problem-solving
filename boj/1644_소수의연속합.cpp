#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX 4000000

int main() {
  int N;
  cin >> N;

  bool np[MAX] = {false};
  vector<int> prime(1,2);

  for(int i=3; i<MAX; i+=2) {
    if(np[i]) continue;
    prime.push_back(i);
    if(1LL*i*i > MAX) continue;
    for(int j=i*i; j<MAX; j+=i*2) {
      np[j] = true;
    }
  }

  int result=0, low=0, high=0, sum=0;
  while(true) {
    if(sum >= N) sum -= prime[low++];
    else if(high == prime.size()) break;
    else sum += prime[high++];

    if(sum == N) result++;
  }
  std::cout << result << endl;

  return 0;
}
