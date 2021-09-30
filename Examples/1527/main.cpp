#include <iostream>
#include "disjointSet.hpp"

#define breakl "\n"
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int qtt_actions, qtt_players, count_vitories;
  DisjointSet set;

  int operation, guild1, guild2, repr1, repr2;

  while(cin >> qtt_players >> qtt_actions)
  {
    if(qtt_players == 0 && qtt_actions == 0) break;
    count_vitories = 0;
    set = createDSU(qtt_players);
    for(int i = 0; i < qtt_players; i++) cin >> set.ranks[i];

    while(qtt_actions--){
      cin >> operation >> guild1 >> guild2;
      guild1--;
      guild2--;
      if(operation == 1){
        unionDSU(set, guild1, guild2);
      }
      else{
        repr1 = findDSU(set, guild1);
        repr2 = findDSU(set, guild2);

        if(set.ranks[repr1] < set.ranks[repr2]){
          std::swap(repr1, repr2);
        }

        if(repr1 == 0) count_vitories++;
      }
    }
    cout << count_vitories << breakl;
  }
  return 0;
}
