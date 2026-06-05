//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H

template<typename T>
class DoublyLinkedNode {
 public:
  T val;
  DoublyLinkedNode<T>* next;
  DoublyLinkedNode<T>* prev;

  explicit DoublyLinkedNode(const T& v){
    val=v;
    next=nullptr;
    prev=nullptr;
  }

};

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
