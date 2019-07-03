//
//  main.cpp
//  Algorithm
//
//  Created by hebaotong on 6/21/16.
//  Copyright © 2016 hebaotong. All rights reserved.
//

#include <iostream>

#include "Algorithm.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Algorithm algo;
    
    // QSort
    int array[] = {43, 2, 45, 67, 12, 3, 9, 1, 5, 33};
    algo.doQSort(array, 10);
    for (int a : array)
    {
        cout << a << "\n";
    }

    // Factorial
//    int n = 10;
//    cout << n << "! = " << algo.calFactorial(n) << "\n";
    
    // Fibonacci
//    for (int i = 0; i < 100; ++i)
//    {
//        cout << "f(" << i << ") = " << algo.calFibonacci(i) << "\n";
//    }
    
    // Binary Tree
//    algo.reverseBTree();
//    cout << algo.calBTreeDepth() << "\n";
//    cout << algo.isSameBTree() << "\n";
//    cout << algo.calNodeNum() << "\n";
//    cout << algo.searchBTree()->data << "\n"
//         << algo.searchBTree()->left->data << "\n"
//         << algo.searchBTree()->right->data << "\n";
//    algo.traverseBTree();
    
    // linkedlist
//    algo.reverseLinkedList();
    
    return 0;
}
