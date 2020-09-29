#ifndef CORE_CORE_EXCEPTION_H
#define CORE_CORE_EXCEPTION_H

#include <exception>

class CoreException: public std::exception {
 public:
  CoreException() = default;
  explicit CoreException(char const *_Message)
      : exception(_Message) {
  }

  CoreException(char const *_Message, int i)
      : exception(_Message, i) {
  }

  explicit CoreException(exception const &_Other)
      : exception(_Other) {
  }
};

#endif// CORE_CORE_EXCEPTION_H
