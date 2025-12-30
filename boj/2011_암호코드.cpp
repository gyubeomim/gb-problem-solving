#include<iostream>
#include<string>
using namespace std;
 
#define div 1000000
 
string n;
int d[5001], ten, one;
 
int main(void){
    cin >> n;
    ten = n[0] - '0';
    one = n[1] - '0';
    if(ten != 0) d[0] = 1;
    if(9 < 10 * ten + one && 10 * ten + one < 27) d[-1] = 1;
    for(int i = 1; i < n.size(); i++){
        ten = n[i-1] - '0';
        one = n[i] - '0';
        if(one > 0) d[i] += d[i-1];
        if(9 < 10 * ten + one && 10 * ten + one < 27)
            d[i] += d[i-2];
        d[i] %= div;
    }
    cout << d[n.size() - 1] << "\n";
    return 0;
}