#include <bits/stdc++.h>
using namespace std;

class SquareMatrix {
  public:
    vector<vector<long long>> mat;
    int n;
    SquareMatrix(int n) : n(n), mat(n, vector<long long>(n, 0)) {}
    SquareMatrix(const vector<vector<long long>>& arr)
      : n((int)arr.size()), mat(arr) {}

    int size() const { return n; } // 행렬 크기 반환

    SquareMatrix operator*(const SquareMatrix &r) const {
      SquareMatrix ret(n);
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          long long sum = 0;
          for(int k=0; k<n; k++){
            sum += mat[i][k] * r.mat[k][j];
          }
          ret.mat[i][j] = sum;
        }
      }
      return ret;
    }
};

SquareMatrix identity(int n){
  SquareMatrix I(n);
  for(int i=0; i<n; i++){
    I.mat[i][i] = 1;
  }
  return I;
}

// 분할 정복으로 행렬 거듭제곱
// 시간복잡도: O(n^3 log m),  n: 행렬 크기, m: 거듭제곱 횟수
SquareMatrix pow(const SquareMatrix& A, int m) {
  if(m == 0) return identity(A.size());
  if(m % 2 > 0) return pow(A, m - 1) * A;
  SquareMatrix half = pow(A, m / 2);
  return half * half;
}

int main(){
  SquareMatrix M({{1,2},{3,4}}); // 2x2 행렬 예시
  int exponent = 5;

  SquareMatrix result = pow(M, exponent);

  for(int i=0; i<result.size(); i++){
    for(int j=0; j<result.size(); j++){
      cout << result.mat[i][j] << " ";
    }
    cout << "\n";
  }
}

