//
// Created by mfbut on 11/24/2019.
//

#ifndef DLLPROJECT_REVERSEDOUBLYLINKEDLISTITERATOR_H
#define DLLPROJECT_REVERSEDOUBLYLINKEDLISTITERATOR_H

#include <iterator>
#include "DoublyLinkedNode.h"

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


    //are the two iterators equal?
    bool operator==(const ReverseDoublyLinkedListIterator<T>& rhs) const;

    //are the two iterators different?
    bool operator!=(const ReverseDoublyLinkedListIterator<T>& rhs) const;

    //is the iterator safe to dereference?
    explicit operator bool() const;

    //go to the next element
    ReverseDoublyLinkedListIterator<T>& operator++(); //pre
    const ReverseDoublyLinkedListIterator<T> operator++(int); //post

    //go to the previous element
    ReverseDoublyLinkedListIterator<T>& operator--(); //pre
    const ReverseDoublyLinkedListIterator<T> operator--(int); //post

    //get a reference to the value
    [[nodiscard]] const_reference operator*() const;

    [[nodiscard]] reference operator*();

    [[nodiscard]] DoublyLinkedNode<T>*& getCurNode();

    [[nodiscard]] const DoublyLinkedNode<T>*& getCurNode() const;

private:
    //your members
};



#endif //DLLPROJECT_REVERSEDOUBLYLINKEDLISTITERATOR_H
