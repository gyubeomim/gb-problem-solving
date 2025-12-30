#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;


typedef struct {
  int height;
  int weight;
  int rank;
} Man;



int main() {
  int N;
  cin>> N;

  vector<Man> v;

  for(int i=0; i<N; i++){
    int height, weight;

    cin>>weight >> height;

    Man t;
    t.height = height;
    t.weight = weight;
    t.rank=1;

    v.push_back(t);
  }

  for(int i=0; i<v.size();i++){
    for(int j=0;j<v.size();j++){
      if(i!=j){
        if(v[i].height>v[j].height && v[i].weight > v[j].weight){
          v[j].rank+=1;
        }
      }
    }
  }

  for(auto it : v){
    cout << it.rank << " ";
  }


  return 0;
}
