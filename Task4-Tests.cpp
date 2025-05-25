#include "Deque.h"
#include <iostream>
#include <cassert>

// Helper function to print test results
void printTestResult(const std::string& testName, bool passed) {
    std::cout << "[ " << (passed ? "PASSED" : "FAILED") << " ] " << testName << std::endl;
}

// Test 1: Initializer list constructor
void testInitializerListConstructor() {
    Deque d({1, 2, 3});
    assert(d.size() == 3);
    assert(d.front() == 1);
    assert(d.back() == 3);
    printTestResult("Initializer List Constructor", true);
}

// Test 2: Push back operation
void testPushBack() {
    Deque d;
    d.push_back(4);
    assert(d.size() == 1);
    assert(d.back() == 4);
    printTestResult("Push Back", true);
}

// Test 3: Push front operation
void testPushFront() {
    Deque d;
    d.push_front(5);
    assert(d.size() == 1);
    assert(d.front() == 5);
    printTestResult("Push Front", true);
}

// Test 4: Pop back operation
void testPopBack() {
    Deque d({1, 2, 3});
    d.pop_back();
    assert(d.size() == 2);
    assert(d.back() == 2);
    printTestResult("Pop Back", true);
}

// Test 5: Pop front operation
void testPopFront() {
    Deque d({1, 2, 3});
    d.pop_front();
    assert(d.size() == 2);
    assert(d.front() == 2);
    printTestResult("Pop Front", true);
}

// Test 6: Empty check
void testEmptyCheck() {
    Deque d;
    assert(d.empty());
    d.push_back(1);
    assert(!d.empty());
    printTestResult("Empty Check", true);
}

// Test 7: Edge access (front/back on empty deque)
void testEdgeAccess() {
    Deque d({5});
    assert(d.front() == 5);
    assert(d.back() == 5);

    d.pop_front();
    bool exceptionThrown = false;
    try {
        d.front();
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    exceptionThrown = false;
    try {
        d.back();
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    printTestResult("Edge Access", true);
}

// Test 8: Copy assignment and move semantics
void testCopyAndMove() {
    Deque d1({10, 20});
    Deque d2 = d1; // Copy constructor
    assert(d2.size() == 2);
    assert(d2.front() == 10);
    assert(d2.back() == 20);

    Deque d3(std::move(d1)); // Move constructor
    assert(d3.size() == 2);
    assert(d3.front() == 10);
    assert(d3.back() == 20);
    assert(d1.empty()); // Original should be empty after move

    Deque d4;
    d4 = d3; // Copy assignment
    assert(d4.size() == 2);
    assert(d4.front() == 10);
    assert(d4.back() == 20);

    Deque d5;
    d5 = std::move(d3); // Move assignment
    assert(d5.size() == 2);
    assert(d5.front() == 10);
    assert(d5.back() == 20);
    assert(d3.empty()); // Original should be empty after move

    printTestResult("Copy and Move Semantics", true);
}

// Main test runner
int main() {
    std::cout << "=== Running Deque Tests ===" << std::endl;

    testInitializerListConstructor();
    testPushBack();
    testPushFront();
    testPopBack();
    testPopFront();
    testEmptyCheck();
    testEdgeAccess();
    testCopyAndMove();

    std::cout << "=== All Tests Completed ===" << std::endl;
    return 0;
}