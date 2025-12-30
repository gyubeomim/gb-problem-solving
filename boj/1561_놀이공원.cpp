#include <iostream>
using namespace std;

int time_[10000];
int child, amuse;

int main(){
    cin >> child >> amuse;
    
    for(int i=0; i<amuse; i++){
        cin >> time_[i];
    }
    
    if(child <= amuse){
        cout << child << '\n';
        return 0;
    }
    
    long long left = 0;
    long long right = 2000000000LL * 1000000LL;
        
    while(left <= right){
        long long mid = (left+right)/2;
        long long begin, end;
        
        begin = end = 0;
        end = amuse;
        for(int i=0; i<amuse; i++){
            end += mid / time_[i];
        }
        begin = end;
        for(int i=0; i<amuse; i++){
            if(mid % time_[i] == 0){
                begin -= 1;
            }
        }
        begin += 1;
        
        if(child < begin)
            right = mid-1;
        else if(child > end)
            left = mid+1;
        else {
            for(int i=0; i<amuse; i++){
                if(mid % time_[i] == 0){
                    if(child == begin){
                        cout << i+1 << '\n';
                        return 0;
                    }
                    begin += 1;
                }
            }
        }
    }
    return 0;
}