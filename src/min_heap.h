#ifndef min_heap
#define min_heap

#include <vector>

class MinHeap {
/*  This is integer heap implementation
*/
 private:
  std::vector<int> data_;

  size_t size_;

  int parent(int);
  int left_child(int);
  int right_child(int i);
  void sift_down(int);
  void sift_up(int);

 public:
  void insert(int);
  int extract_min(void);
  int view_min(void);
  void print_heap();
  size_t size();
  MinHeap();
};

#endif
