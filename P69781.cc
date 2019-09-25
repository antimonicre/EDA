#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, int> nums;
  int x, y, n, next, count;

  while(cin >> x >> y >> n) {
    //Se vacia el set y se reinician it y next
    nums.clear();
    count = 1;

    //Calcula next hasta que encuentra el bucle o excede de 10⁸
    while(nums.count(n)==0 and n<=100000000) {
      if(n%2==0) {
        next = (n/2) + x; //n par
      }

      else {
        next = (3*n)+y; //n impar
      }

      nums[n]=next;
      n=next;
    }

    //Si se ha encontrado un bucle
    if(nums.count(n)>0){
      next=nums[n];
      while(n!=next){
        count++;
        next=nums[next];
      }
      cout << count << endl;
    }

    //Si ha excedido
    else cout << n << endl;
  }

}
