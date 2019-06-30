#include "gtest/gtest.h"
#include "min_heap.h"

namespace {
  class MinHeapFixture : public ::testing::Test {
   protected:

    MinHeapFixture() {
    // You can do set-up work for each test here.
    }

    ~MinHeapFixture() override {
    // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override {
      my_min_heap->insert(1);
      my_min_heap->insert(2);
      my_min_heap->insert(2);
      my_min_heap->insert(3);
      my_min_heap->insert(4);
      my_min_heap->insert(5);
      my_min_heap->insert(6);
      my_min_heap->insert(8);
      my_min_heap->insert(9);
    }
    void TearDown() override {
      delete my_min_heap;
    }

    MinHeap *my_min_heap = new MinHeap;
  };

  TEST(MinHeap, BlankHeap) {
    MinHeap *my_min_heap = new MinHeap;
    //check size
    EXPECT_EQ(0, my_min_heap->size());
    //extract max
    EXPECT_EQ(-1, my_min_heap->extract_min());
  }

  TEST(MinHeap, CreateHeap) {
    MinHeap *my_min_heap = new MinHeap;
    //check size
    EXPECT_EQ(0, my_min_heap->size());
    //insert an element
    my_min_heap->insert(5);
    EXPECT_EQ(1, my_min_heap->size());
    //insert two more
    my_min_heap->insert(3);
    my_min_heap->insert(4);
    EXPECT_EQ(3, my_min_heap->size());
  }

  TEST_F(MinHeapFixture, ExtractMin) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_min_heap->size()); //check size
    //Extract min #1
    my_min_heap->print_heap();
    EXPECT_EQ(1, my_min_heap->extract_min());
    EXPECT_EQ(2, my_min_heap->extract_min());
    EXPECT_EQ(2, my_min_heap->extract_min());
    EXPECT_EQ(3, my_min_heap->extract_min());
    EXPECT_EQ(4, my_min_heap->extract_min());
    EXPECT_EQ(5, my_min_heap->extract_min());
    EXPECT_EQ(6, my_min_heap->extract_min());
    EXPECT_EQ(8, my_min_heap->extract_min());
    EXPECT_EQ(9, my_min_heap->extract_min());
  }

  TEST_F(MinHeapFixture, ViewMin) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_min_heap->size()); //check size
    //View min repeatedly
    my_min_heap->print_heap();
    EXPECT_EQ(1, my_min_heap->view_min());
    EXPECT_EQ(1, my_min_heap->view_min());
    EXPECT_EQ(1, my_min_heap->view_min());
  }

  TEST_F(MinHeapFixture, Insert) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    std::cout << "Heap before inserting:" << std::endl;
    my_min_heap->print_heap();
    //Insert #1
    my_min_heap->insert(4);
    std::cout << "Heap after inserting 4:" << std::endl;
    my_min_heap->print_heap();
    my_min_heap->insert(13);
    std::cout << "Heap after inserting 13:" << std::endl;
    my_min_heap->print_heap();
    //Extract min#1
    EXPECT_EQ(1, my_min_heap->extract_min());
    EXPECT_EQ(2, my_min_heap->extract_min());
    EXPECT_EQ(2, my_min_heap->extract_min());
    EXPECT_EQ(3, my_min_heap->extract_min());
    EXPECT_EQ(4, my_min_heap->extract_min());
    EXPECT_EQ(4, my_min_heap->extract_min());
    EXPECT_EQ(5, my_min_heap->extract_min());
    EXPECT_EQ(6, my_min_heap->extract_min());
    EXPECT_EQ(8, my_min_heap->extract_min());
    EXPECT_EQ(9, my_min_heap->extract_min());
    EXPECT_EQ(13, my_min_heap->extract_min());
  }

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
Compile:
g++ -Igoogletest-release-1.8.0/googletest/include -Isrc -pthread tests/test_min_heap.cpp src/min_heap.cpp googletest-release-1.8.0/libgtest.a -o tests/test_min_heap


*/
