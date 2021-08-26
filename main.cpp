#include <iostream>
#include "disjointSet.h"

using namespace std;
int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int size;
  DisjointSet set;
  cin >> size;
  if(size < 3) size = 3;
  set = createDSU(size);
  printDSU(set);
  unionDSU(&set, 1, 2);
  cout << endl;
  printDSU(set);
  return 0;
}
