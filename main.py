class DisjointSet:
  size = 0
  ranks = parents = [0]
  def __init__(self, size):
    self.size = size
    self.ranks = [0] * size
    self.parents = [x for x in range(size)]
  def __repr__(self):
    return "Size: {0}\nParents:\n{1}\nRanks\n{2}\n".format(self.size, " ".join(map(str, self.parents)), " ".join(map(str, self.ranks)))
  def findRepr(self, child):
    if(child != self.parents[child]):
      return findRepr(self, self.parents[child])
    return self.parents[child]
  def union(self, child1, child2):
    repr1, repr2 = self.findRepr(child1), self.findRepr(child2)
    if(repr1 != repr2):
      self.parents[repr1] = repr2

if(__name__ == "__main__"):
  size = int(input())
  if size < 4:
    size = 4
  tree = DisjointSet(size)
  print(tree)
  tree.union(1, 2)
  tree.union(2, 3)
  print(tree)