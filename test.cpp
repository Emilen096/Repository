#include "pch.h"
#include "C:\Users\EMIL\.vscode\c++\Deque.h"
#include "C:\Users\EMIL\.vscode\c++\Deque.cpp"
#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>

// 1) Test default construction, empty(), size(), and that toString shows "[ ]"
TEST(DequeBasic, DefaultConstruction) {
    Deque d;
    EXPECT_TRUE(d.empty());
    EXPECT_EQ(d.size(), 0u);
    EXPECT_EQ(d.toString(), "[ ]");
}

// 2) Test initializer‐list constructor, size(), empty(), toString(), front(), back()
TEST(DequeBasic, InitializerList) {
    Deque d{ 1, 2, 3, 4 };
    EXPECT_FALSE(d.empty());
    EXPECT_EQ(d.size(), 4u);
    EXPECT_EQ(d.front(), 1);
    EXPECT_EQ(d.back(), 4);
    EXPECT_EQ(d.toString(), "[ 1 2 3 4 ]");
}

// 3) Test push_back(), push_front(), and that toString, front, back, size update correctly
TEST(DequeBasic, PushBackAndPushFront) {
    Deque d{ 1, 2, 3, 4 };
    d.push_back(5);
    EXPECT_EQ(d.size(), 5u);
    EXPECT_EQ(d.back(), 5);
    EXPECT_EQ(d.front(), 1);
    EXPECT_EQ(d.toString(), "[ 1 2 3 4 5 ]");

    d.push_front(0);
    EXPECT_EQ(d.size(), 6u);
    EXPECT_EQ(d.front(), 0);
    EXPECT_EQ(d.back(), 5);
    EXPECT_EQ(d.toString(), "[ 0 1 2 3 4 5 ]");
}

// 4) Test pop_front(), pop_back(), and that front/back/size/toString update correctly
TEST(DequeBasic, PopFrontAndPopBack) {
    Deque d{ 1, 2, 3, 4 };
    d.pop_front();  // Remove 1
    EXPECT_EQ(d.size(), 3u);
    EXPECT_EQ(d.front(), 2);
    EXPECT_EQ(d.back(), 4);
    EXPECT_EQ(d.toString(), "[ 2 3 4 ]");

    d.pop_back();  // Remove 4
    EXPECT_EQ(d.size(), 2u);
    EXPECT_EQ(d.front(), 2);
    EXPECT_EQ(d.back(), 3);
    EXPECT_EQ(d.toString(), "[ 2 3 ]");
}

// 5) Test chained pop until empty, then empty()==true, size()==0, toString=="[ ]"
TEST(DequeEdge, PopUntilEmpty) {
    Deque d{ 10, 20, 30 };
    d.pop_front();  // [20,30]
    d.pop_front();  // [30]
    d.pop_front();  // []
    EXPECT_TRUE(d.empty());
    EXPECT_EQ(d.size(), 0u);
    EXPECT_EQ(d.toString(), "[ ]");

    // Popping on empty should not throw (per main.cpp behavior in demonstration)
    EXPECT_NO_THROW(d.pop_front());
    EXPECT_NO_THROW(d.pop_back());
}

// 6) Test that front() and back() on empty throw std::out_of_range
TEST(DequeEdge, AccessorsOnEmpty) {
    Deque d;
    EXPECT_THROW(d.front(), std::out_of_range);
    EXPECT_THROW(d.back(), std::out_of_range);
}

// 7) Test size() and empty() on non‐empty
TEST(DequeBasic, SizeAndEmpty) {
    Deque d;
    EXPECT_TRUE(d.empty());
    EXPECT_EQ(d.size(), 0u);

    d.push_back(42);
    EXPECT_FALSE(d.empty());
    EXPECT_EQ(d.size(), 1u);
    EXPECT_EQ(d.front(), 42);
    EXPECT_EQ(d.back(), 42);
}

// 8) Test >> operator: reading space‐separated ints until EOF/newline
TEST(DequeIO, InputOperator) {
    std::istringstream iss("5 15 25 35");
    Deque d;
    iss >> d;  // will read all ints
    EXPECT_EQ(d.size(), 4u);
    EXPECT_EQ(d.front(), 5);
    EXPECT_EQ(d.back(), 35);
    EXPECT_EQ(d.toString(), "[ 5 15 25 35 ]");
}

// 9) Test copy constructor: modifying copy does not affect original
TEST(DequeCopyMove, CopyConstructor) {
    Deque original{ 7, 8, 9 };
    Deque copy = original;
    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.front(), original.front());
    EXPECT_EQ(copy.back(), original.back());

    copy.push_back(100);
    EXPECT_EQ(copy.back(), 100);
    EXPECT_EQ(original.back(), 9);  // original unchanged
}

// 10) Test copy assignment operator: modifying target does not affect source
TEST(DequeCopyMove, CopyAssignment) {
    Deque a{ 2, 4, 6 };
    Deque b;
    b = a;
    EXPECT_EQ(b.size(), a.size());
    EXPECT_EQ(b.front(), a.front());
    EXPECT_EQ(b.back(), a.back());

    b.push_front(-2);
    EXPECT_EQ(b.front(), -2);
    EXPECT_EQ(a.front(), 2);
}

// 11) Test move constructor: moved‐from becomes empty
TEST(DequeCopyMove, MoveConstructor) {
    Deque src{ 11, 12, 13 };
    Deque dst = std::move(src);
    EXPECT_EQ(dst.size(), 3u);
    EXPECT_EQ(dst.toString(), "[ 11 12 13 ]");
    EXPECT_TRUE(src.empty());
    EXPECT_EQ(src.size(), 0u);
}

// 12) Test move assignment operator: moved‐from becomes empty
TEST(DequeCopyMove, MoveAssignment) {
    Deque src{ 21, 22, 23 };
    Deque dst;
    dst = std::move(src);
    EXPECT_EQ(dst.size(), 3u);
    EXPECT_EQ(dst.toString(), "[ 21 22 23 ]");
    EXPECT_TRUE(src.empty());
    EXPECT_EQ(src.size(), 0u);
}

// 13) Test a sequence matching main.cpp demonstration
TEST(DequeMainDemo, SequenceMatchesMain) {
    // Step 1: initializer list
    Deque d1{ 1, 2, 3, 4 };
    EXPECT_EQ(d1.toString(), "[ 1 2 3 4 ]");

    // Step 2: push_back(5)
    d1.push_back(5);
    EXPECT_EQ(d1.toString(), "[ 1 2 3 4 5 ]");

    // Step 3: push_front(0)
    d1.push_front(0);
    EXPECT_EQ(d1.toString(), "[ 0 1 2 3 4 5 ]");

    // Step 4: pop_front()
    d1.pop_front();
    EXPECT_EQ(d1.toString(), "[ 1 2 3 4 5 ]");

    // Step 5: pop_back()
    d1.pop_back();
    EXPECT_EQ(d1.toString(), "[ 1 2 3 4 ]");

    // Step 6: front() and back() are 1 and 4
    EXPECT_EQ(d1.front(), 1);
    EXPECT_EQ(d1.back(), 4);

    // Step 7: size() == 4, empty() == false
    EXPECT_EQ(d1.size(), 4u);
    EXPECT_FALSE(d1.empty());
}

// Main entry for Google Test
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}