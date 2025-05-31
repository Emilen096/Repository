#include "Deque.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <stdexcept>

// Function to print test results
void printTestResult(const std::string& testName, bool passed) {
    std::cout << "[ " << (passed ? "PASSED" : "FAILED") << " ] " << testName << std::endl;
}

// Test 1: Default constructor
void testDefaultConstructor() {
    Deque d;
    assert(d.size() == 0);
    assert(d.empty());
    printTestResult("Default Constructor", true);
}

// Test 2: Initializer list constructor
void testInitializerListConstructor() {
    Deque d({1, 2, 3});
    assert(d.size() == 3);
    assert(d.front() == 1);
    assert(d.back() == 3);
    printTestResult("Initializer List Constructor", true);
}

// Test 3: Push back operation
void testPushBack() {
    Deque d;
    d.push_back(4);
    assert(d.size() == 1);
    assert(d.back() == 4);
    
    d.push_back(5);
    assert(d.size() == 2);
    assert(d.back() == 5);
    printTestResult("Push Back Operation", true);
}

// Test 4: Push front operation
void testPushFront() {
    Deque d;
    d.push_front(5);
    assert(d.size() == 1);
    assert(d.front() == 5);
    
    d.push_front(6);
    assert(d.size() == 2);
    assert(d.front() == 6);
    printTestResult("Push Front Operation", true);
}

// Test 5: Pop back operation
void testPopBack() {
    Deque d({1, 2, 3});
    d.pop_back();
    assert(d.size() == 2);
    assert(d.back() == 2);
    
    d.pop_back();
    assert(d.size() == 1);
    assert(d.back() == 1);
    
    d.pop_back();
    assert(d.empty());
    printTestResult("Pop Back Operation", true);
}

// Test 6: Pop front operation
void testPopFront() {
    Deque d({1, 2, 3});
    d.pop_front();
    assert(d.size() == 2);
    assert(d.front() == 2);
    
    d.pop_front();
    assert(d.size() == 1);
    assert(d.front() == 3);
    
    d.pop_front();
    assert(d.empty());
    printTestResult("Pop Front Operation", true);
}

// Test 7: Empty check
void testEmptyCheck() {
    Deque d;
    assert(d.empty());
    
    d.push_back(1);
    assert(!d.empty());
    
    d.pop_back();
    assert(d.empty());
    printTestResult("Empty Check", true);
}

// Test 8: Edge case handling (access on empty deque)
void testEdgeAccess() {
    Deque d;
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
    
    exceptionThrown = false;
    try {
        d.pop_front();
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    
    exceptionThrown = false;
    try {
        d.pop_back();
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    
    d.push_back(5);
    assert(d.front() == 5);
    assert(d.back() == 5);
    
    d.pop_front();
    exceptionThrown = false;
    try {
        d.front();
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    printTestResult("Edge Case Handling", true);
}

// Test 9: Copy constructor
void testCopyConstructor() {
    Deque d1({10, 20});
    Deque d2 = d1;
    
    assert(d2.size() == 2);
    assert(d2.front() == 10);
    assert(d2.back() == 20);
    
    d1.push_back(30);
    assert(d1.size() == 3);
    assert(d2.size() == 2);
    
    d2.push_front(5);
    assert(d1.front() == 10);
    assert(d2.front() == 5);
    
    printTestResult("Copy Constructor", true);
}

// Test 10: Move constructor
void testMoveConstructor() {
    Deque d1({10, 20});
    Deque d2(std::move(d1));
    
    assert(d2.size() == 2);
    assert(d2.front() == 10);
    assert(d2.back() == 20);
    assert(d1.empty());
    
    d2.push_back(30);
    assert(d2.size() == 3);
    assert(d1.empty());
    
    printTestResult("Move Constructor", true);
}

// Test 11: Copy assignment
void testCopyAssignment() {
    Deque d1({10, 20});
    Deque d2;
    d2 = d1;
    
    assert(d2.size() == 2);
    assert(d2.front() == 10);
    assert(d2.back() == 20);
    
    d1.push_back(30);
    assert(d1.size() == 3);
    assert(d2.size() == 2);
    
    d2.push_front(5);
    assert(d1.front() == 10);
    assert(d2.front() == 5);
    
    d2 = d2;
    assert(d2.size() == 3);
    assert(d2.front() == 5);
    
    printTestResult("Copy Assignment", true);
}

// Test 12: Move assignment
void testMoveAssignment() {
    Deque d1({10, 20});
    Deque d2;
    d2 = std::move(d1);
    
    assert(d2.size() == 2);
    assert(d2.front() == 10);
    assert(d2.back() == 20);
    assert(d1.empty());
    
    d2.push_back(30);
    assert(d2.size() == 3);
    assert(d1.empty());
    
    d2 = std::move(d2);
    assert(d2.size() == 3);
    
    printTestResult("Move Assignment", true);
}

// Test 13: ToString method
void testToString() {
    Deque d;
    assert(d.toString() == "[]");
    
    d.push_back(1);
    assert(d.toString() == "[1]");
    
    d.push_front(2);
    assert(d.toString() == "[2 1]");
    
    d.push_back(3);
    assert(d.toString() == "[2 1 3]");
    
    printTestResult("ToString Method", true);
}

// Test 14: Stream insertion operator (<<)
void testStreamInsertion() {
    Deque d({1, 2, 3});
    std::ostringstream oss;
    oss << d;
    assert(oss.str() == "[1 2 3]");
    
    d.push_front(0);
    oss.str("");
    oss << d;
    assert(oss.str() == "[0 1 2 3]");
    
    Deque empty;
    oss.str("");
    oss << empty;
    assert(oss.str() == "[]");
    
    printTestResult("Stream Insertion Operator", true);
}

// Test 15: Stream extraction operator (>>)
void testStreamExtraction() {
    Deque d;
    std::istringstream iss("10 20 30");
    iss >> d;
    
    assert(d.size() == 3);
    assert(d.front() == 10);
    assert(d.back() == 30);
    assert(d.toString() == "[10 20 30]");
    
    std::istringstream iss2("100 200");
    iss2 >> d;
    assert(d.size() == 2);
    assert(d.toString() == "[100 200]");
    
    std::istringstream iss3("");
    Deque d2;
    iss3 >> d2;
    assert(d2.empty());
    
    printTestResult("Stream Extraction Operator", true);
}

// Main function to run all tests
int main() {
    std::cout << "=== Running Deque Unit Tests ===" << std::endl;
    
    testDefaultConstructor();
    testInitializerListConstructor();
    testPushBack();
    testPushFront();
    testPopBack();
    testPopFront();
    testEmptyCheck();
    testEdgeAccess();
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignment();
    testMoveAssignment();
    testToString();
    testStreamInsertion();
    testStreamExtraction();
    
    std::cout << "=== All Tests Completed ===" << std::endl;
    return 0;
}
