#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

int main() {
    string instr;
    int x;
    priority_queue<int> q;
    
    while (cin >> instr) {
        if(instr=="S") {
            cin >> x;
            q.push(x);
        }
        
        else if (instr=="A") {
            if(q.empty()) cout << "error!" << endl;
            else { 
                int res= q.top();
                cout << res << endl;
            }
        }
        
        else if(instr=="R") {
            if(q.empty()) cout << "error!" << endl;
            else { 
                q.pop();
            }
        }
            
        else if(instr=="I") {
            cin >> x;
            if(q.empty()) cout << "error!" << endl;
            else {
                int aux = q.top();
                q.pop();
                aux += x;
                q.push(aux);
            }
        }
            
        else if(instr=="D") {
            cin >> x;
            if(q.empty()) cout << "error!" << endl;
            else {
                int aux = q.top();
                q.pop();
                aux -= x;
                q.push(aux);
            }
        }
            
        else {
            cout << "error!" << endl;
        }
    }
}
