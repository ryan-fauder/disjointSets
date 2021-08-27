#include "disjointSet.h"
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

int findDSU(DisjointSet * set, int child){
  // It'll return the child's representative
  // Verifing if it has a parent. If they are not identical, so it has a parent.
  if(child != set->parents[child]){ 
  /** Path Compression:
   *  set->parents[child] = findDSU(set, set->parents[child]);
   */
  /** Standard mode
   * return findDSU(set, set->parents[child]);
   */
    return findDSU(set, set->parents[child]);
  }
  return set->parents[child];
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

void unionDSU(DisjointSet * set, int child1, int child2){
  int representative1 = findDSU(set, child1);
  int representative2 = findDSU(set, child2);

  /*If they arent identical, so they are in different sets*/
  if(representative1 != representative2){
    /** Standard version (without ranks):
     * set->parents[representative1] = representative2;
    */
    /** Ranks as size
     * if(set->ranks[representative1] < set->ranks[representative2]){
     *  std::swap(representative1, representative2);
     * }
     * set->parents[representative2] = representative1;
     * set->ranks[representative1] += set->ranks[representative2];
    */
    /** Ranks as depth
     * if(set->ranks[representative1] < set->ranks[representative2]){
     *  std::swap(representative1, representative2);
     * }
     * set->parents[representative2] = representative1;
     * if(set->ranks[representative1] == set->ranks[representative2])
     *  set->ranks[representative1] += 1;
    */
    set->parents[representative1] = representative2;
  }
}
