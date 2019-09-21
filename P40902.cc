#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,int> adictos;
    string player, action;
    int coins, pocket;
    map<string,int>::iterator it;

    while(cin >> player >> action) {
      it= adictos.find(player);

        if(action=="enters") {
            if(it!=adictos.end()) cout << player << " is already in the casino" << endl;
            else adictos.insert(make_pair(player,0));
        }

        else if(action=="wins") {
          cin >> coins;
          if(it==adictos.end()) cout << player << " is not in the casino" << endl;
          else {
            pocket = it->second;
            pocket += coins;
            it->second = pocket;
          }

        }

        else if(action=="leaves") {
            if(it==adictos.end()) cout << player << " is not in the casino" << endl;
            else {
              cout << it->first << " has won " << it->second << endl;
              adictos.erase(player);
            }
        }

    }

    cout << "----------" << endl;
    for (it=adictos.begin(); it!=adictos.end(); ++it) {
        cout << it->first << " is winning " << it->second << endl;
    }

}
