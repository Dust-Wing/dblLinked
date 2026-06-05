//
// Created by mfbut on 11/24/2019.
//

#include "DoublyLinkedListEmptyError.h"

const char* DoublyLinkedListEmptyError::what() const noexcept{
  return "doubly linked list is empty";
}

