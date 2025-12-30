#include <bits/stdc++.h>

using namespace std;



typedef struct student {

    
    
	int Kor;
	int Math;
	int Eng;
	string Name;



} Student;




int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

	int N;
	cin >> N;


	
	vector<Student> s;


	for(int i=0; i<N; i++) {
		Student tmp;
		cin >> tmp.Name >> tmp.Kor >> tmp.Eng >> tmp.Math;


		s.push_back(tmp);




	}





	sort(s.begin(), s.end(), [](const Student &a,
				                      const Student &b) {
			if(a.Kor != b.Kor) {
			return a.Kor > b.Kor;
			}
			else if(a.Eng != b.Eng) {
			return a.Eng < b.Eng;
			}
			else if(a.Math != b.Math) {
			return a.Math > b.Math;
			}
			else {
			return a.Name < b.Name;
			}


			});



	for(auto it : s) {
		cout << it.Name << '\n';
	}





	

	return 0;
}
