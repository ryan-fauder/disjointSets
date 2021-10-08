#include "disjointSet.hpp"
#include <iostream>

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
