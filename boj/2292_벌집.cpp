#include <bits/stdc++.h>

using namespace std;


int main() {
	int number;
	cin >> number;

    int i=0;
    for(int sum=2; sum<=number; i++){
        sum += 6*i;
    }
    
    if(number==1) i=1;
    
    cout << i << endl;


	return 0;
}