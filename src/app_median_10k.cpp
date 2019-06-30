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
    std::cout << d << std::endl;

    //as of this point i is the total # parsed integers
    //1. insert to heaps
    if((h_high->size() == 0) || (h_low->size() == 0)){
      
    }
  }
  std::cout << "Successfully loaded " << filename << "with " << i << " lines." << std::endl;
  //u_graph->print_graph(9);
}
