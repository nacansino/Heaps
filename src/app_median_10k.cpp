#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "max_heap.h"
#include "min_heap.h"

int main(){
  //Variables for parsing the string
  std::string filename = "tests/median.txt";
  std::string s;  //for line parse
  //-----------------------------------
  //Variables for the median
  int d;  //data integer
  long long int sum = 0;  //sum accumulator
  int i = 0;  //counter
  std::vector <int> median; //median vector
  MinHeap *h_high = new MinHeap;  //heap that contains the upper half parsed integers
  MaxHeap *h_low = new MaxHeap; //heap that contains the lower half parsed integers

  //START
  std::ifstream inFile(filename, std::ios::in);
  if (!inFile) {
    std::cerr << "Unable to open file " << filename << std::endl;
    exit(1);   // call system to stop
  }
  //loop through all lines
  while (!inFile.eof()){
    //1: get line
    std::getline(inFile, s);
    //2: we expect nondelimited lines here so we directly convert them to int
    if(s.length() == 0) continue;
    i++;
    //convert string line to integer
    d = std::stoi(s);

    //as of this point i is the total # parsed integers
    //1. insert to heap
    if(h_low->size() == 0){//Case h_low is empty:
      h_low->insert(d);
    }else{
      if(d <= h_low->view_max()){
        h_low->insert(d);
      }else{
        h_high->insert(d);
      }
    }
    //rebalance
    if(h_low->size() > h_high->size() + 1){//h_low is heavier by more than 1 element
      //move one element of low to high
      h_high->insert(h_low->extract_max());
    }
    if(h_high->size() > h_low->size()){//h_high is heavier
      h_low->insert(h_high->extract_min());
    }

    //h_low's max is the (i/2) th element of x_1 to x_i
    //or if i is odd, (i+1)/2 th element
    median.push_back(h_low->view_max());
    sum += median.back();
    std::cout << d << " | " << median.back() << std::endl;
  }
  std::cout << "Successfully loaded " << filename << " with " << i << " lines." << std::endl;
  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Sum %% 10000: " << sum % 10000 << std::endl;
  //u_graph->print_graph(9);
}
