#include <iostream>
#include <vector>
#include <algorithm>
#include "min_heap.h"

/*CONSTRUCTOR*/
MinHeap::MinHeap(void) {
    size_ = 0;
}

/*PRIVATE FUNCTIONS*/

int MinHeap::parent(int i){
  return (int)(i-1)/2;
}

int MinHeap::left_child(int i){
  return 2*i+1;
}

int MinHeap::right_child(int i){
  return 2*i+2;
}

void MinHeap::sift_down(int i){
  int min_index = i;
  int l = left_child(i);
  if (l<size_ && data_[l] < data_[min_index])
    min_index = l;
  int r = right_child(i);
  if (r<size_ && data_[r] < data_[min_index])
    min_index = r;
  if (i != min_index){
    std::swap(data_[i], data_[min_index]);
    //sift down
    sift_down(min_index);
  }
}

void MinHeap::sift_up(int i){
  while(i>0 && data_[i] < data_[parent(i)]){
    std::swap(data_[parent(i)], data_[i]);
    i = parent(i);
  }
}

/*PUBLIC FUNCTIONS*/

size_t MinHeap::size(void){
  return size_;
}

void MinHeap::insert(int v){
  //Inserts the int v to the heap
  size_++;
  data_.push_back(v);
  sift_up(size_-1); //sift up the recently inserted elemenet
}

int MinHeap::extract_min(void){
  if(size_ == 0){
    std::cout << "ERROR: Blank Heap" << std::endl;
    return -1;
  }
  int result = data_[0];  //the min value is the head of the tree
  data_[0] = data_[size_-1]; //replace head with the latest leaf
  size_--;
  data_.pop_back(); //remove last element of heap
  sift_down(0); //put the new head to its right position to maintain heap property
  return result;
}

int MinHeap::view_min(void){
  if(size_ == 0){
    std::cout << "ERROR: Blank Heap" << std::endl;
    return -1;
  }
  return data_[0];
}

void MinHeap::print_heap(){
  for(size_t i = 0; i < data_.size(); ++i){
    std::cout << "i[" << i << "]: " << data_[i] << std::endl;
  }
}
