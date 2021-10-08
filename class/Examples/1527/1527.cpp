#include <iostream>
#include <vector>

struct DisjointSet{ 
  std::vector<int> parents, ranks;
  int size;
};

DisjointSet createDSU(int size);

int findDSU(DisjointSet & set, int child);

void unionDSU(DisjointSet & set, int child1, int child2);

void printDSU(DisjointSet set);

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
        
        if(repr1 == repr2) continue;

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

DisjointSet createDSU(int size){
  DisjointSet set;
  
  set.parents.resize(size);
  set.ranks.resize(size);
  set.size = size;

  for (int i = 0; i < size; i++)
  {
    set.parents[i] = i;
    set.ranks[i] = 0;
  }
  
  return set;
}

int findDSU(DisjointSet & set, int child){
  if(child != set.parents[child]){
    set.parents[child] = findDSU(set, set.parents[child]);
  }
  return set.parents[child];
}

void printDSU(DisjointSet set){
  std::cout << "Size: " << set.size << std::endl;
  std::cout << " -- Ranks -- " << std::endl;
  for(int i = 0; i < set.size; i++){
    std::cout << set.ranks[i] << " ";
  }
  std::cout << std::endl;
  std::cout << " -- Parents -- " << std::endl;
  for(int i = 0; i < set.size; i++){
    std::cout << set.parents[i] << " ";
  }
  std::cout << std::endl;
}

void unionDSU(DisjointSet & set, int child1, int child2){
  int representative1 = findDSU(set, child1);
  int representative2 = findDSU(set, child2);

  if(representative1 != representative2){
    if(representative1 == 0){
      std::swap(representative1, representative2);
    }
    set.parents[representative1] = representative2;
    set.ranks[representative2] += set.ranks[representative1];
  }
}