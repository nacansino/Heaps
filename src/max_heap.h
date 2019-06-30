#ifndef max_heap
#define max_heap

#include <vector>

class MaxHeap {
/*  This is integer max heap implementation
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
  int extract_max(void);
  int view_max(void);
  void print_heap();
  size_t size();
  MaxHeap();
};

#endif
