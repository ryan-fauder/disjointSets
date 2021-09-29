#ifndef __DISJOINTSET_H__
#define __DISJOINTSET_H__
#include <vector>
#include <iostream>

class disjointSet
{
private:
  std::vector<int> parents, ranks;
  int size;

public:
  disjointSet();
  disjointSet( int size );
  int find( int child );
  void join( int child1, int child2 );
  void print();
};

disjointSet::disjointSet()
{
  this->size = 0;
}

disjointSet::disjointSet(int size)
{
  this->size = size;
  this->parents.resize(size);
  this->ranks.resize(size);
  this->size = size;

  for (int i = 0; i < size; i++)
  {
    this->parents[i] = i;
    this->ranks[i] = 0;
  }
}

int disjointSet::find(int child){
  // It'll return the child's representative
  // Verifing if it has a parent. If they are not identical, so it has a parent.
  if(child != this->parents[child]){ 
  /** Path Compression:
   *  this->parents[child] = this->find(this->parents[child]);
   */
  /** Standard mode
   * return this->find(this->parents[child]);
   */
    return this->find(this->parents[child]);
  }
  return this->parents[child];
}

void disjointSet::print(){
  std::cout << "Size: " << this->size << std::endl;
  std::cout << " -- Ranks -- " << std::endl;
  for(int i = 0; i < this->size; i++){
    std::cout << this->ranks[i] << " ";
  }
  std::cout << std::endl;
  std::cout << " -- Parents -- " << std::endl;
  for(int i = 0; i < this->size; i++){
    std::cout << this->parents[i] << " ";
  }
  std::cout << std::endl;
}

void disjointSet::join(int child1, int child2){
  int representative1 = this->find(child1);
  int representative2 = this->find(child2);

  /*If they arent identical, so they are in different sets*/
  if(representative1 != representative2){
    /** Standard version (without ranks):
     * this->parents[representative1] = representative2;
    */
    /** Ranks as size
     * if(this->ranks[representative1] < this->ranks[representative2]){
     *  std::swap(representative1, representative2);
     * }
     * this->parents[representative2] = representative1;
     * this->ranks[representative1] += this->ranks[representative2];
    */
    /** Ranks as depth
     * if(this->ranks[representative1] < this->ranks[representative2]){
     *  std::swap(representative1, representative2);
     * }
     * this->parents[representative2] = representative1;
     * if(this->ranks[representative1] == this->ranks[representative2])
     *  this->ranks[representative1] += 1;
    */
    this->parents[representative1] = representative2;
  }
}



#endif // __DISJOINTSET_H__