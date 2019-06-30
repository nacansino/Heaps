#include "gtest/gtest.h"
#include "max_heap.h"

namespace {
  class MaxHeapFixture : public ::testing::Test {
   protected:

    MaxHeapFixture() {
    // You can do set-up work for each test here.
    }

    ~MaxHeapFixture() override {
    // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override {
      my_max_heap->insert(1);
      my_max_heap->insert(2);
      my_max_heap->insert(2);
      my_max_heap->insert(3);
      my_max_heap->insert(4);
      my_max_heap->insert(5);
      my_max_heap->insert(6);
      my_max_heap->insert(8);
      my_max_heap->insert(9);
    }
    void TearDown() override {
      delete my_max_heap;
    }

    MaxHeap *my_max_heap = new MaxHeap;
  };

  TEST(MaxHeap, BlankHeap) {
    MaxHeap *my_max_heap = new MaxHeap;
    //check size
    EXPECT_EQ(0, my_max_heap->size());
    //extract max
    EXPECT_EQ(-1, my_max_heap->extract_max());
  }

  TEST(MaxHeap, CreateHeap) {
    MaxHeap *my_max_heap = new MaxHeap;
    //check size
    EXPECT_EQ(0, my_max_heap->size());
    //insert an element
    my_max_heap->insert(5);
    EXPECT_EQ(1, my_max_heap->size());
    //insert two more
    my_max_heap->insert(3);
    my_max_heap->insert(4);
    EXPECT_EQ(3, my_max_heap->size());
  }

  TEST_F(MaxHeapFixture, ExtractMax) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_max_heap->size()); //check size
    //Extract max #1
    my_max_heap->print_heap();
    EXPECT_EQ(9, my_max_heap->extract_max());
    EXPECT_EQ(8, my_max_heap->extract_max());
    EXPECT_EQ(6, my_max_heap->extract_max());
    EXPECT_EQ(5, my_max_heap->extract_max());
    EXPECT_EQ(4, my_max_heap->extract_max());
    EXPECT_EQ(3, my_max_heap->extract_max());
    EXPECT_EQ(2, my_max_heap->extract_max());
    EXPECT_EQ(2, my_max_heap->extract_max());
    EXPECT_EQ(1, my_max_heap->extract_max());
  }

  TEST_F(MaxHeapFixture, ViewMax) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_max_heap->size()); //check size
    //View max repeatedly
    my_max_heap->print_heap();
    EXPECT_EQ(9, my_max_heap->view_max());
    EXPECT_EQ(9, my_max_heap->view_max());
    EXPECT_EQ(9, my_max_heap->view_max());
  }

  TEST_F(MaxHeapFixture, Insert) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    std::cout << "Heap before inserting:" << std::endl;
    my_max_heap->print_heap();
    //Insert #1
    my_max_heap->insert(4);
    std::cout << "Heap after inserting 4:" << std::endl;
    my_max_heap->print_heap();
    my_max_heap->insert(13);
    std::cout << "Heap after inserting 13:" << std::endl;
    my_max_heap->print_heap();
    //Extract min#1
    EXPECT_EQ(13, my_max_heap->extract_max());
    EXPECT_EQ(9, my_max_heap->extract_max());
    EXPECT_EQ(8, my_max_heap->extract_max());
    EXPECT_EQ(6, my_max_heap->extract_max());
    EXPECT_EQ(5, my_max_heap->extract_max());
    EXPECT_EQ(4, my_max_heap->extract_max());
    EXPECT_EQ(4, my_max_heap->extract_max());
    EXPECT_EQ(3, my_max_heap->extract_max());
    EXPECT_EQ(2, my_max_heap->extract_max());
    EXPECT_EQ(2, my_max_heap->extract_max());
    EXPECT_EQ(1, my_max_heap->extract_max());
  }

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
Compile:
g++ -Igoogletest-release-1.8.0/googletest/include -Isrc -pthread tests/test_max_heap.cpp src/max_heap.cpp googletest-release-1.8.0/libgtest.a -o tests/test_max_heap

*/
