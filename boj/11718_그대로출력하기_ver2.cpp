#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv){
	string s;
	
	while(true) {
		getline(cin, s);
		if(s=="") break;
		cout << s << '\n';
	}

	return 0;
}
