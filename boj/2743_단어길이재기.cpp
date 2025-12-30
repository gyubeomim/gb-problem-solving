#include <iostream>
using namespace std;

int main(){
    char s[100];
    scanf("%s", s);
    
    int len = 0;
    for(int i=0; s[i]; i++){
        len += 1;
    }
    cout << len << endl;
    return 0;
}