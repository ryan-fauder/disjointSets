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
  int amount_banks, loop, first, second;
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
    set.parents[representative1] = representative2;
  }
}
