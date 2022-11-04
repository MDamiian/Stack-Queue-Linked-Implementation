#ifndef POSTFIJO_HPP_INCLUDED
#define POSTFIJO_HPP_INCLUDED

#include <string>
#include "queue.hpp"
#include "stack.hpp"

class Postfijo {
  private:
    Stack<char> myPila;
    Queue<char> infija;
    Queue<char> postfija;
    char myChar;
  public:
    void setPrefija(const std::string&);
    void convertPost();
    int priority(const char&);
    Queue<char> getPostfija();
  };

#endif // POSTFIJO_HPP_INCLUDED
