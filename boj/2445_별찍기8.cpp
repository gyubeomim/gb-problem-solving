#include<iostream>
#include<cstdio>

using namespace std;

int main() {
  int N;
  cin >> N;

  for(int i=1; i<N; i++) {
    for(int j=0; j<i; j++)
      cout << "*";
    for(int k=(N-i)*2; k>0; k--)
      cout << " ";
    for(int j=i; j>0; j--)
      cout << "*";
    cout << '\n';
  }
  for(int i=N; i>0; i--) {
    for(int j=i; j>0; j--)
      cout << "*";
    for(int k=0; k<2*(N-i); k++)
      cout << " ";
    for(int j=i; j>0; j--)
      cout << "*";
    cout << '\n';
  }

  return 0;
}