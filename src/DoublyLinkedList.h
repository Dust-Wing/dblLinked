//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <iostream>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedListEmptyError.h"
#include "ConstDoublyLinkedListIterator.h"
#include "DoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedIterator.h"
#include "ReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedList {
public:
    using Node_Ptr = DoublyLinkedNode<T>*;

    using iterator = DoublyLinkedListIterator<T>; //put the type of your iterator here
    using const_iterator = ConstDoublyLinkedListIterator<T>; //put the type of your const iterator here
    using reverse_iterator = ReverseDoublyLinkedListIterator<T>; //put the type of your reverse iterator here
    using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>;
    //put the type of your const reverse iterator here

    //create a Doubly Linked List that has the same values
    //as in the vector and in the same order
    explicit DoublyLinkedList(const std::vector<T>& values);

    //create an empty DoublyLinkedList
    DoublyLinkedList();


    virtual ~DoublyLinkedList();

    //remove all of the elements from your list
    void clear();

    //get a reference to the front element in the list
    const T& front() const;

    T& front();

    //get a reference to the last element in the list
    [[nodiscard]] const T& back() const;

    [[nodiscard]] T& back();

    //add a value to the front of the list
    void push_front(const T& value);

    //add a value to the back of the list
    void push_back(const T& value);

    //is the list empty?
    [[nodiscard]] bool empty() const;

    //return the number of elements in the list
    [[nodiscard]] int size() const;

    //return a constant bidirectional iterator to the front of the list
    [[nodiscard]] const_iterator begin() const;

    [[nodiscard]] const_iterator end() const;

    //return a nonconstant bidirectional iterator to the front of the list
    [[nodiscard]] iterator begin();

    [[nodiscard]] iterator end();

    [[nodiscard]] const_reverse_iterator crbegin() const;

    [[nodiscard]] const_reverse_iterator crend() const;

    [[nodiscard]] reverse_iterator rbegin();

    [[nodiscard]] reverse_iterator rend();

    //insert the value at the position in the list
    //I promise not to use the iterator again after the insertion is done
    //An example if we had the list 1 <-> 9 <-> 17
    //And the iterator was pointing to the 9 and we wanted to
    //insert -22 the result would be
    //1 <-> 22 <-> 9 <-> 17
    void insert(iterator& position, const T& value);

    //remove the element at the position pointed to
    //by the iterator.
    //I promise not to use the iterator again after the erase is done
    //An example if we had the list 1 <-> 9 <-> 17
    //And when the wanted to erase the iterator was at the 9
    //1 <-> 17
    void erase(iterator& position);

private:
    Node_Ptr head;
    Node_Ptr tail;
    int ct;
};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head=nullptr;
    tail=nullptr;
    ct=0;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T>& values){
    head=nullptr;
    tail=nullptr;
    ct=0;
    for(const auto& x:values){
        push_back(x);
    }
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    clear();
}

template<typename T>
void DoublyLinkedList<T>::clear(){
    Node_Ptr cur=head;
    while(cur!=nullptr){
        Node_Ptr nxt=cur->next;
        delete cur;
        cur=nxt;
    }
    head=nullptr;
    tail=nullptr;
    ct=0;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const{
    if(empty()){
        throw DoublyLinkedListEmptyError();
    }
    return head->val;
}

template<typename T>
T& DoublyLinkedList<T>::front(){
    if(empty()){
        throw DoublyLinkedListEmptyError();
    }
    return head->val;
}

template<typename T>
const T& DoublyLinkedList<T>::back() const{
    if(empty()){
        throw DoublyLinkedListEmptyError();
    }
    return tail->val;
}

template<typename T>
T& DoublyLinkedList<T>::back(){
    if(empty()){
        throw DoublyLinkedListEmptyError();
    }
    return tail->val;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value){
    Node_Ptr n=new DoublyLinkedNode<T>(value);
    if(empty()){
        head=n;
        tail=n;
    }else{
        n->next=head;
        head->prev=n;
        head=n;
    }
    ct++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value){
    Node_Ptr n=new DoublyLinkedNode<T>(value);
    if(empty()){
        head=n;
        tail=n;
    }else{
        n->prev=tail;
        tail->next=n;
        tail=n;
    }
    ct++;
}

template<typename T>
bool DoublyLinkedList<T>::empty() const{
    return ct==0;
}

template<typename T>
int DoublyLinkedList<T>::size() const{
    return ct;
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::begin() const{
    return const_iterator(head);
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::end() const{
    return const_iterator(nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin(){
    return iterator(head);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end(){
    return iterator(nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crbegin() const{
    return const_reverse_iterator(tail);
}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crend() const{
    return const_reverse_iterator(nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rbegin(){
    return reverse_iterator(tail);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rend(){
    return reverse_iterator(nullptr);
}

template<typename T>
void DoublyLinkedList<T>::insert(iterator& position,const T& value){
    if(empty()){
        push_back(value);
        return;
    }
    if(!position){
        push_back(value);
        return;
    }
    Node_Ptr cur=position.getCurNode();
    if(cur==head){
        push_front(value);
        return;
    }
    Node_Ptr n=new DoublyLinkedNode<T>(value);
    n->next=cur;
    n->prev=cur->prev;
    cur->prev->next=n;
    cur->prev=n;
    ct++;
}

template<typename T>
void DoublyLinkedList<T>::erase(iterator& position){
    if(!position){
        return;
    }
    Node_Ptr cur=position.getCurNode();
    if(head==tail){
        delete cur;
        head=nullptr;
        tail=nullptr;
        ct=0;
        return;
    }
    if(cur==head){
        head=head->next;
        head->prev=nullptr;
        delete cur;
        ct--;
        return;
    }
    if(cur==tail){
        tail=tail->prev;
        tail->next=nullptr;
        delete cur;
        ct--;
        return;
    }
    cur->prev->next=cur->next;
    cur->next->prev=cur->prev;
    delete cur;
    ct--;
}

template<typename T>
std::ostream& operator<<(std::ostream& out,const DoublyLinkedList<T>& doublyLinkedList){
    auto it=doublyLinkedList.begin();
    bool first=true;
    while(it!=doublyLinkedList.end()){
        if(!first){
            out<<" ";
        }
        out<<*it;
        first=false;
        ++it;
    }
    return out;
}

template<typename T>
std::istream& operator>>(std::istream& in,DoublyLinkedList<T>& doublyLinkedList){
    doublyLinkedList.clear();
    T x;
    while(in>>x){
        doublyLinkedList.push_back(x);
        int c=in.peek();
        while(c==' '||c=='\t'||c=='\r'){
            in.get();
            c=in.peek();
        }
        if(c=='\n'){
            in.get();
            break;
        }
    }
    return in;
}

#endif
