//
// Created by mfbut on 11/24/2019.
//

#ifndef DLLPROJECT_REVERSEDOUBLYLINKEDLISTITERATOR_H
#define DLLPROJECT_REVERSEDOUBLYLINKEDLISTITERATOR_H

#include <iterator>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedListOutOfBoundsError.h"

template<typename T>
class ReverseDoublyLinkedListIterator {
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using iterator_concept = std::bidirectional_iterator_tag;
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using difference_type = ptrdiff_t;

    ReverseDoublyLinkedListIterator(){
        curNode=nullptr;
    }

    explicit ReverseDoublyLinkedListIterator(DoublyLinkedNode<T>* p){
        curNode=p;
    }

    //are the two iterators equal?
    bool operator==(const ReverseDoublyLinkedListIterator<T>& rhs) const{
        return curNode==rhs.curNode;
    }

    //are the two iterators different?
    bool operator!=(const ReverseDoublyLinkedListIterator<T>& rhs) const{
        return curNode!=rhs.curNode;
    }

    //is the iterator safe to dereference?
    explicit operator bool() const{
        return curNode!=nullptr;
    }

    //go to the next element
    ReverseDoublyLinkedListIterator<T>& operator++(){
        if(curNode!=nullptr){
            curNode=curNode->prev;
        }
        return *this;
    }
    const ReverseDoublyLinkedListIterator<T> operator++(int){
        ReverseDoublyLinkedListIterator<T> old=*this;
        ++(*this);
        return old;
    }

    //go to the previous element
    ReverseDoublyLinkedListIterator<T>& operator--(){
        if(curNode!=nullptr){
            curNode=curNode->next;
        }
        return *this;
    }
    const ReverseDoublyLinkedListIterator<T> operator--(int){
        ReverseDoublyLinkedListIterator<T> old=*this;
        --(*this);
        return old;
    }

    //get a reference to the value
    [[nodiscard]] const_reference operator*() const{
        if(curNode==nullptr){
            throw DoublyLinkedListOutOfBoundsError();
        }
        return curNode->val;
    }

    [[nodiscard]] reference operator*(){
        if(curNode==nullptr){
            throw DoublyLinkedListOutOfBoundsError();
        }
        return curNode->val;
    }

    [[nodiscard]] DoublyLinkedNode<T>*& getCurNode(){
        return curNode;
    }

    [[nodiscard]] const DoublyLinkedNode<T>*& getCurNode() const{
        return reinterpret_cast<const DoublyLinkedNode<T>*&>(curNode);
    }

private:
    DoublyLinkedNode<T>* curNode;
};



#endif //DLLPROJECT_REVERSEDOUBLYLINKEDLISTITERATOR_H
