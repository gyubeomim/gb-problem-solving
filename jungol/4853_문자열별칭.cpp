#include <bits/stdc++.h>
using namespace std;

int N;
char str[12];
unordered_set<string> prefix;     
unordered_map<string, int> name;   

int main(int argc, char **argv) {
  scanf("%d", &N);
  while (N--) {
    scanf("%s", str);
    name[str]++;   

    
    string pre = "";
    string alias = "";    
    for (int i = 0; str[i]; i++) {
      pre += str[i];
      if (alias == "" && prefix.count(pre) == 0) 
        alias = pre;     
      prefix.insert(pre); 
    }

    if (alias == "") {   
      alias = str;
      if (name[str] > 1) alias += to_string(name[str]);   
    }

    printf("%s\n", alias.c_str());  
  }
}
