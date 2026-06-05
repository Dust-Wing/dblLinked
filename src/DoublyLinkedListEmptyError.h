//
// Created by mfbut on 11/24/2019.
//

#ifndef TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTEMPTYERROR_H
#define TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTEMPTYERROR_H
#include "DoublyLinkedListError.h"

class DoublyLinkedListEmptyError : public DoublyLinkedListError {
 public:
  const char* what() const noexcept override;
};


#endif //TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTEMPTYERROR_H
