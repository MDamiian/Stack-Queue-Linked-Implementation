#include "postfijo.hpp"

using namespace std;

void Postfijo::setPrefija(const string& myStr) {
  int sizeStr = myStr.length();
  for(int i(0); i < sizeStr; i++) {
    infija.enqueue(myStr[i]);
    }
  }

void Postfijo::convertPost() {
  while(!postfija.isEmpty()) {
    postfija.dequeue();
    }

  while(!infija.isEmpty()) {
    myChar = infija.dequeue();
    switch(myChar) {
      case '(':
        myPila.push(myChar);
        break;

      case ')':
        while(!myPila.isEmpty() and myPila.getTop() != '(') {
          postfija.enqueue(myPila.pop());
          }
        myPila.pop();
        break;

      case '+':
      case '-':
      case '*':
      case '/':
      case '^':

        if(myPila.isEmpty()) {
          myPila.push(myChar);
          break;
          }

        while(!myPila.isEmpty() and (priority(myChar) <= priority(myPila.getTop()))) {
          postfija.enqueue(myPila.pop());
          }
        myPila.push(myChar);
        break;

      default:
        postfija.enqueue(myChar);
        break;
      }
    }

  while(!myPila.isEmpty() and infija.isEmpty()) {
    postfija.enqueue(myPila.pop());
    }
  }

int Postfijo::priority(const char& a) {
  switch(a) {
    case '^':
      return 3;
      break;

    case '*':
    case '/':
      return 2;
      break;

    case '+':
    case '-':
      return 1;
      break;

    default:
      return 0;
      break;
    }
  }

Queue<char> Postfijo::getPostfija() {
  return postfija;
  }
