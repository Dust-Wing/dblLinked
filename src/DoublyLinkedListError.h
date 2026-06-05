//
// Created by mfbut on 11/24/2019.
//

#ifndef TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
#define TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
#include <exception>

 class DoublyLinkedListError : public std::exception{
 public:
  const char* what() const noexcept override;
};

#endif //TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
