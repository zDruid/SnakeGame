#include "SnakeLinkedList.h"
#include <iostream>
#include <sstream>

/* Put the method definitions you wrote for Lab 8.5 Linked Lists Part 3 below.
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab continues the task of implementing a linked list class, SnakeLinkedList.

In this lab you need to implement two more methods of SnakeLinkedList, popBack and pushBack.

The popBack method removes the last SnakeListNode from the SnakeLinkedList. The pushBack
method adds a new SnakeListNode to the end of the SnakeLinkedList.

Two special cases to consider are:

- The SnakeLinkedList is empty. In this case popBack should have no effect.

- The SnakeLinkedList has only one SnakeListNode. In this case popBack will make it empty.

When removing a SnakeListNode be sure to free up its memory using the delete operator.

You will find that popBack and pushBack are trickier to implement than popFront and pushFront.
This is because operations on the front of the SnakeLinkedList can use the _head data member
to access the front of the SnakeLinkedList.

Hint: To implement pushBack you can use the tail method to get the last SnakeListNode. Then,
all you need to do is add the new SnakeListNode after it.

Hint: To implement popBack you will need to access the SnakeListNode _before_ the tail so you
can set its nextNode to nullptr. You can iterate the SnakeLinkedList looking for a node
whose nextNode is the tail.

*/



string SnakeListNode::toString() const {
  ostringstream oss;
  oss << "(row = " << _row << ", col = " << _col << ')';

  return oss.str();
}

SnakeLinkedList::~SnakeLinkedList() {
  SnakeListNode* curNode = _head;
  while (curNode != nullptr) {
    SnakeListNode* nextNode = curNode->nextNode();
    delete curNode;
    curNode = nextNode;
  }
}

int SnakeLinkedList::length() const {
  int result = 0;
  SnakeListNode *curNode = _head;
  while (curNode != nullptr) {
    ++result;
    curNode = curNode->nextNode();
  }

  return result;
}

SnakeListNode* SnakeLinkedList::tail() const {
  SnakeListNode* prevNode = nullptr;
  SnakeListNode* curNode = _head;
  while (curNode != nullptr) {
     prevNode = curNode;
     curNode = curNode->nextNode();
  }

  return prevNode;
}

void SnakeLinkedList::pushFront(int row, int col) {
  _head = new SnakeListNode(row, col, _head);
}



void SnakeLinkedList::popFront() {
  if (SnakeListNode* oldHead = _head) {
    _head = _head->nextNode();
    delete oldHead;
  }
}

void SnakeLinkedList::pushBack(int row, int col) {
   // *** needs implementation
   SnakeListNode *lastNode = tail(); 
   SnakeListNode *newLastNode = new SnakeListNode(row, col, nullptr);
   if (lastNode == nullptr) {
      _head = newLastNode; 
   }
   else {
      lastNode->setNextNode(newLastNode);
   }

}
/*
Hint: To implement popBack you will need to access the SnakeListNode _before_ the tail so you
can set its nextNode to nullptr. You can iterate the SnakeLinkedList looking for a node
whose nextNode is the tail.
*/

void SnakeLinkedList::popBack() {
   // *** needs implementation
   if (_head != nullptr) {
      SnakeListNode *curNode = _head;
      SnakeListNode *curTail = tail(); 
      if (_head == curTail) {
         _head = nullptr; 
         delete curTail; 
      }
      else {
         while (curNode != nullptr) {
            if (curNode->nextNode() == curTail) {
               delete curTail; 
               curNode->setNextNode(nullptr);
               break; 
            }
            curNode = curNode->nextNode();
         }
      }

   }



}

void SnakeLinkedList::printSnake() const {
  SnakeListNode* curNode = _head;
  int len = length();
  cout << "length = " << len;
  if (len > 1) {
    cout << ", head = " << head()->toString();
    cout << ", tail = " << tail()->toString();
  } if (len == 1) {
    cout << ", head = tail = " << head()->toString();
  }
 cout << endl;

  while (curNode != nullptr) {
    cout << " " << curNode->toString() << endl;
    curNode = curNode->nextNode();
  }

  cout << endl;
}
