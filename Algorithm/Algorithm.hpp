//
//  Algorithm.hpp
//  Algorithm
//
//  Created by hebaotong on 6/21/16.
//  Copyright © 2016 hebaotong. All rights reserved.
//

#ifndef Algorithm_hpp
#define Algorithm_hpp

#include <map>

using namespace std;

struct Node
{
    Node(int num)
    : data(num)
    {
    }
    
    int data = 0;
    Node *left = NULL;
    Node *right = NULL;
};

struct LinkedNode
{
    LinkedNode(int num)
    : data(num)
    {
    }
    
    int data = 0;
    LinkedNode *next = NULL;
};

class Algorithm
{
public:
    Algorithm();
    ~Algorithm();
    
    void doQSort(int arry[], int length);
    
    long calFactorial(int n);
    
    long calFibonacci(int n);
    
    void reverseBTree();
    int calBTreeDepth();
    bool isSameBTree();
    int calNodeNum();
    Node* searchBTree();
    void traverseBTree();
    
    void reverseLinkedList();
    
private:
    void qSort(int array[], int min, int max);
    
    long factorialRecursive(int n);
    long factorialLoop(int n);
    
    long fibonacciRecursive(int n);
    long fibonacciDynamic(int n);
    
    void createBTree();
    void traverseBTree(Node *root);
    void reverseBTree(Node *root);
    int bTreeDepth(Node *root);
    void createNewBTree();
    bool isSameBTree(Node *leftRoot, Node *rightRoot);
    int calNodeNum(Node *root);
    Node* searchBTree(Node *root, int data);
    void levelTraverse(Node *root);
    
    void createLinkedList();
    void printLinkedList(LinkedNode *head);
    void reverse(LinkedNode *head);
    void reverseRecursive(LinkedNode *p);
    
private:
    map<int, long> *mFibonacci;
    Node *mRoot;
    Node *mNewRoot;
    int mNodeNum;
    LinkedNode *mLink;
    LinkedNode *mLinkNew;
};

#endif /* Algorithm_hpp */
