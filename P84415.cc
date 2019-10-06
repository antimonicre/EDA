#include <iostream>
#include <map>
using namespace std;

int main() {
  map<string,int> bag;
  map<string,int>::iterator it;
  string word, instr;

  while (cin >> instr) {
    if (instr=="store") {
      cin >> word;
      it = bag.find(word);
      if(it==bag.end()) {
        bag[word]=1;
      }
      else  {
        ++bag[word];
      }
    }
    else if (instr=="delete") {
      cin >> word;
      it = bag.find(word);
      if(it!=bag.end()) {
        --bag[word];
        if(it->second == 0) bag.erase(word);
      }
    }
    else if (instr=="minimum?"){
      if(bag.empty()) cout << "indefinite minimum" << endl;
      else {
        it = bag.begin();
        cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
      }
    }
    else if (instr=="maximum?"){
      if(bag.empty()) cout << "indefinite maximum" << endl;
      else {
        it = bag.end();
        --it;
        cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
      }
    }
  }

}
