#include <iostream>
#include <string>
using namespace std;

int freq[26];

int main(int argc, char **argv){
	string S;
	cin >> S;
	
	for(auto c : S) 
		freq[c-'a']++;

	for(int i=0;i<26;i++){
		printf("%d ", freq[i]);
	}
	puts("");
}
