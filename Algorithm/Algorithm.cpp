//
//  Algorithm.cpp
//  Algorithm
//
//  Created by hebaotong on 6/21/16.
//  Copyright © 2016 hebaotong. All rights reserved.
//

#include <iostream>
#include <queue>

#include "Algorithm.hpp"

using namespace std;

Algorithm::Algorithm()
: mRoot(NULL), mNewRoot(NULL), mNodeNum(0), mLink(NULL), mLinkNew(NULL)
{
    mFibonacci = new map<int, long>();
    mFibonacci->insert(make_pair(0, 0));
    mFibonacci->insert(make_pair(1, 1));
}

Algorithm::~Algorithm()
{
    if (mFibonacci != NULL)
    {
        delete mFibonacci;
    }
}

void Algorithm::doQSort(int arry[], int length)
{
    if (length < 2)
    {
        return;
    }
    
    qSort(arry, 0, length - 1);
}

void Algorithm::qSort(int array[], int min, int max)
{
    if (min >= max)
    {
        return;
    }
    
    int left = min;
    int right = max;
    int pivot = array[(min + max) / 2];
    int temp;
    
    while (left <= right)
    {
        while (array[left] < pivot)
        {
            ++left;
        }
        
        while (array[right] > pivot)
        {
            --right;
        }
        
        if (left <= right)
        {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            ++left;
            --right;
        }
    }
    
    if (left < max)
    {
        qSort(array, left, max);
    }
    
    if (right > min)
    {
        qSort(array, min, right);
    }
}

long Algorithm::calFactorial(int n)
{
    // recursive
//    return factorialRecursive(n);
    // loop
    return factorialLoop(n);
}

long Algorithm::factorialRecursive(int n)
{
    if (n <= 1)
    {
        return n;
    }
    
    return n * factorialRecursive(n - 1);
}

long Algorithm::factorialLoop(int n)
{
    if (n <= 1) {
        return n;
    }
    
    long value = 1;
    
    for (int i = n; i > 0; --i)
    {
        value *= i;
    }
    
    return value;
}

long Algorithm::calFibonacci(int n)
{
    // recursive
    return fibonacciRecursive(n);
    // loop
//    return fibonacciDynamic(n);
}

long Algorithm::fibonacciRecursive(int n)
{
    if (0 == n)
    {
        return 0;
    }
    
    if (1 == n)
    {
        return 1;
    }
    
    return calFibonacci(n - 1) + calFibonacci(n - 2);
}

long Algorithm::fibonacciDynamic(int n)
{
    if (0 == n)
    {
        return 0;
    }
    
    if (1 == n)
    {
        return 1;
    }
    
    if (mFibonacci != nullptr) {
        map<int, long>::iterator iter;
        long a = 0;
        long b = 0;
        
        iter = mFibonacci->find(n - 1);
        if (iter != mFibonacci->end()) {
            a = iter->second;
        }
        
        iter = mFibonacci->find(n - 2);
        if (iter != mFibonacci->end()) {
            b = iter->second;
        }
        
        mFibonacci->insert(make_pair(n, a + b));
        return a + b;
    }
    
    return -1;
}

void Algorithm::createBTree()
{
    mRoot = new Node(12);
    mRoot->left = new Node(1);
    mRoot->right = new Node(56);
    
    mRoot->left->left = new Node(3);
    mRoot->left->right = new Node(67);
    
    mRoot->right->left = new Node(32);
    mRoot->right->right = new Node(78);
}

void Algorithm::traverseBTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    
    traverseBTree(root->left);
    traverseBTree(root->right);
    cout << root->data << " ";
}

void Algorithm::reverseBTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    
    reverseBTree(root->left);
    reverseBTree(root->right);
    
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void Algorithm::reverseBTree()
{
    createBTree();
    traverseBTree(mRoot);
    reverseBTree(mRoot);
    traverseBTree(mRoot);
}

int Algorithm::calBTreeDepth()
{
    createBTree();
    return bTreeDepth(mRoot);
}

int Algorithm::bTreeDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    
    int left = bTreeDepth(root->left);
    int right = bTreeDepth(root->right);
    return ((left > right) ? left : right) + 1;
}

void Algorithm::createNewBTree()
{
    mNewRoot = new Node(12);
    mNewRoot->left = new Node(1);
    mNewRoot->right = new Node(56);
    
    mNewRoot->left->left = new Node(3);
    mNewRoot->left->right = new Node(67);
    
    mNewRoot->right->left = new Node(32);
    mNewRoot->right->right = new Node(7);
}

bool Algorithm::isSameBTree(Node *leftRoot, Node *rightRoot)
{
    if ((leftRoot == NULL) && (rightRoot == NULL))
    {
        return true;
    }
    
    if (leftRoot != NULL
        && rightRoot != NULL
        && leftRoot->data == rightRoot->data)
    {
        if (isSameBTree(leftRoot->left, rightRoot->left))
        {
            if (isSameBTree(leftRoot->right, rightRoot->right))
            {
                return true;
            }
        }
    }
    
    return false;
}

bool Algorithm::isSameBTree()
{
    createBTree();
    createNewBTree();
    return isSameBTree(mRoot, mNewRoot);
}

int Algorithm::calNodeNum()
{
    createBTree();
    return calNodeNum(mRoot);
}

int Algorithm::calNodeNum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    
    return calNodeNum(root->left) + calNodeNum(root->right) + 1;
}

Node* Algorithm::searchBTree()
{
    createBTree();
    return searchBTree(mRoot, 56);
}


Node* Algorithm::searchBTree(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    if (root->data == data)
    {
        return root;
    }
    
    Node *result = searchBTree(root->left, data);
    return result == NULL ? searchBTree(root->right, data) : result;
}

void Algorithm::traverseBTree()
{
    createBTree();
    
    // preOrder
    // inOrder
    // postOrder
//    traverseBTree(mRoot);
    
    // levelOrder
    levelTraverse(mRoot);
}

void Algorithm::levelTraverse(Node *root)
{
    queue<Node*> nodes;
    nodes.push(root);
    
    do
    {
        Node *temp = nodes.front();
        cout << temp->data << " ";
        nodes.pop();
        
        if (temp->left != NULL)
        {
            nodes.push(temp->left);
        }
        
        if (temp->right != NULL)
        {
            nodes.push(temp->right);
        }
    }
    while(!nodes.empty());
}

void Algorithm::reverseLinkedList()
{
    createLinkedList();
    printLinkedList(mLink);
    cout << "\n";
//    reverse(mLink);
    reverseRecursive(mLink->next);
    cout << "\n";
    printLinkedList(mLinkNew);
}

void Algorithm::createLinkedList()
{
    mLink = new LinkedNode(0);
    LinkedNode *temp = mLink;
    for (int i = 0; i < 5; ++i)
    {
        temp->next = new LinkedNode(i + 10);
        temp = temp->next;
    }
    temp = NULL;
}

void Algorithm::printLinkedList(LinkedNode *head)
{
    LinkedNode *first = head->next;
    while (first != NULL) {
        cout << first->data << " ";
        first = first->next;
    }
}

void Algorithm::reverse(LinkedNode *head)
{
    LinkedNode *prev, *current, *next;
    prev = NULL;
    current = head->next;
    
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head->next = prev;
}

void Algorithm::reverseRecursive(LinkedNode *p)
{
    if (p->next == NULL)
    {
        mLinkNew =  new LinkedNode(0);
        mLinkNew->next = p;
        return;
    }
    
    reverseRecursive(p->next);
    
    LinkedNode *q = p->next;
    q->next = p;
    p->next = NULL;
}
























