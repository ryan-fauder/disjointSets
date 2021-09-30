#ifndef __DISJOINTSET_H__
#define __DISJOINTSET_H__
#include <vector>
struct DisjointSet{ 
  std::vector<int> parents, ranks;
  int size;
};

DisjointSet createDSU(int size);

int findDSU(DisjointSet & set, int child);

void unionDSU(DisjointSet & set, int child1, int child2);

void printDSU(DisjointSet set);
#endif // __DISJOINTSET_H__