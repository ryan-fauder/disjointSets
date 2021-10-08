#include <iostream>
#include "disjointSet.hpp"

#define breakl "\n"
using namespace std;

int main(){
  long int amount_banks, loop, first, second;
  char operation;
  DisjointSet set;

  cin >> amount_banks >> loop;
  set = createDSU(amount_banks);
  while(loop--){
    cin >> operation >> first >> second;
    first--;
    second--;
    if(operation == 'C'){
      if(findDSU(set, first) == findDSU(set, second))
        cout << "S" << breakl;
      else cout << "N" << breakl;
    }
    else {
      unionDSU(set, first, second);
    }
  }
  return 0;
}
