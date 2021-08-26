class DisjointSet:
  size = 0
  ranks = parents = [0]
  def __init__(self, size):
    self.size = size
    self.ranks = [0] * size
    self.parents = [x for x in range(size)]
  def __repr__(self):
    return "Size: {0}\nParents:\n{1}\nRanks\n{2}\n".format(self.size, " ".join(map(str, self.parents)), " ".join(map(str, self.ranks)))

if(__name__ == "__main__"):
  size = int(input())
  tree = DisjointSet(size)
  print(tree)