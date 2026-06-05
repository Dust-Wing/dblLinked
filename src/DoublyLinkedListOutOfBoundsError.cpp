//
// Created by mfbut on 11/24/2019.
//

#include "DoublyLinkedListOutOfBoundsError.h"

const char* DoublyLinkedListOutOfBoundsError::what() const noexcept{
  return "iterator out of bounds";
}

