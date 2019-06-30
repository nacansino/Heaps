#include <iostream>
#include <vector>
#include <algorithm>
#include "max_heap.h"

/*CONSTRUCTOR*/
MaxHeap::MaxHeap(void) {
    size_ = 0;
}

/*PRIVATE FUNCTIONS*/

int MaxHeap::parent(int i){
  return (int)(i-1)/2;
}

int MaxHeap::left_child(int i){
  return 2*i+1;
}

int MaxHeap::right_child(int i){
  return 2*i+2;
}

void MaxHeap::sift_down(int i){
  int max_index = i;
  int l = left_child(i);
  if (l<size_ && data_[l] > data_[max_index])
    max_index = l;
  int r = right_child(i);
  if (r<size_ && data_[r] > data_[max_index])
    max_index = r;
  if (i != max_index){
    std::swap(data_[i], data_[max_index]);
    //sift down
    sift_down(max_index);
  }
}

void MaxHeap::sift_up(int i){
  while(i>0 && data_[i] > data_[parent(i)]){
    std::swap(data_[parent(i)], data_[i]);
    i = parent(i);
  }
}

/*PUBLIC FUNCTIONS*/

size_t MaxHeap::size(void){
  return size_;
}

void MaxHeap::insert(int v){
  //Inserts the int v to the heap
  size_++;
  data_.push_back(v);
  sift_up(size_-1); //sift up the recently inserted elemenet
}

int MaxHeap::extract_max(void){
  if(size_ == 0){
    std::cout << "ERROR: Blank Heap" << std::endl;
    return -1;
  }
  int result = data_[0];  //the max value is the head of the tree
  data_[0] = data_[size_-1]; //replace head with the latest leaf
  size_--;
  data_.pop_back(); //remove last element of heap
  sift_down(0); //put the new head to its right position to maintain heap property
  return result;
}

int MaxHeap::view_max(void){
  if(size_ == 0){
    std::cout << "ERROR: Blank Heap" << std::endl;
    return -1;
  }
  return data_[0];
}

void MaxHeap::print_heap(){
  for(size_t i = 0; i < data_.size(); ++i){
    std::cout << "i[" << i << "]: " << data_[i] << std::endl;
  }
}
