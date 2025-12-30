#include <bits/stdc++.h>

using namespace std;



class GirlGroup {
	public:
		GirlGroup() {}


		void SetName(string name) {
			name_ = name;
		}


		void SetMembers(string member) {
			members_.push_back(member);
		}

		void ShowName() {
			cout << name_ << '\n';
		}

		void ShowMembers() {
			sort(members_.begin(), members_.end());

			for(auto it : members_) {
				cout << it << '\n';
			}
		}



		bool FindMembers(string name) {
			for(auto it : members_) {
				if(name == it) {
					return true;
				}
			}


			return false;
		}



		string GetName() {
			return name_;
		}


	private:


	string name_;

	vector<string> members_;



};









int main() {
	int N, M;

	vector<GirlGroup> ggs;


	cin >> N >> M;

	while(N--) {
		string name;
		int number;
string member;


		GirlGroup gg;


		cin >> name;
		gg.SetName(name);


		cin >> number;



		for(int i=0; i<number; i++) {
			cin >> member;
			gg.SetMembers(member);
		}





		ggs.push_back(gg);


	}	






	while(M--) {
		string str;
		int mode;

		cin >> str;
		cin >> mode;




		if(mode == 1) {
			for(auto gg : ggs) {
				if(gg.FindMembers(str)) {
					gg.ShowName();
				}
			}

		}
		else if (mode == 0) {
			for(auto gg : ggs) {
				if(str == gg.GetName()) {
					gg.ShowMembers();
				}
			}

		}

	}







	return 0;
}