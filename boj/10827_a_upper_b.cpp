#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

string Add(string &s1, string &s2){
	string result(max(s1.size(), s2.size()), '0');

	bool carry = false;
	for(int i=0; i<result.size(); i++){
		int temp = carry;
		carry = false;

		if(i < s1.size()) temp += s1[s1.size()-i-1] - '0';
		if(i < s2.size()) temp += s2[s2.size()-i-1] - '0';
		if(temp >= 10){
			carry = true;
			temp -= 10;
		}
		result[result.size()-i-1] = temp + '0';
	}
	if(carry) result.insert(result.begin(), '1');
	return result;
}

string Multiply(string &s1, string &s2){
	string result = "0";

	for(int i=0; i<s2.size(); i++){
		string line(s1);
		int carry = 0;
		for(int j=s1.size()-1; j>=0; j--){
			int temp = carry;
			carry = 0;
			temp += (s1[j] - '0') * (s2[s2.size()-i-1] - '0');
			if(temp>=10){
				carry = temp / 10;
				temp %= 10;
			}
			line[j] = temp + '0';
		}
		if(carry > 0) line.insert(line.begin(), carry + '0');
		line += string(i, '0');
		result = Add(result, line);
	}
	return result;
}

string power(string &s1, int p){
	if(p==1) return s1;
	string result = power(s1, p-1);
	result = Multiply(result, s1);
	return result;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1212.txt", "r", stdin);
	#endif

	string s;
	int p;
	cin >> s >> p;

	auto finder = find(s.begin(), s.end(), '.');
	int idx=0;

	if(finder != s.end()){
		idx = s.end() - finder -1;
		s.erase(finder);
	}
	idx *= p;

	string result = power(s, p);
	if(idx > 0) result.insert(result.end() - idx, '.');
	cout << result << '\n';
}