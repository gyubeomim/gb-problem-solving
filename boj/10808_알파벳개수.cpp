#include <iostream>
#include <string>
using namespace std;


int main(int argc, char **argv){
	string S;
	cin >> S;

	for(char c='a'; c<='z'; c++) {
		int cnt=0;
		for(char s : S) 
			if(s == c) cnt++;
		cout << cnt << ' ';
	}

	return 0;
}
