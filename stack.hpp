#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <exception>
#include <string>

template <class T>

class Stack {
  private:
    class Node {
      private:
        T data;
        Node* next;
      public:
        Node();
        Node(const T&);

        T getData() const;
        Node* getNext() const;

        void setData(const T&);
        void setNext(Node*);
      };

    Node* anchor;

    void copyAll(const Stack<T>&);

    void deletAll();

  public:
    class Exception : public std::exception {
      private:

        std::string msg;

      public:

        explicit Exception(const char* message) : msg(message) { }

        explicit Exception(const std::string& message) : msg(message) { }

        virtual ~Exception() throw () { }

        virtual const char* what() const throw () {
          return msg.c_str();
          }
      };

    Stack();
    Stack(const Stack&);
    ~Stack();

    bool isEmpty() const;

    void push(const T&);

    T pop();

    T getTop() const;

    Stack& operator = (const Stack&);
  };

///Nodo
template <class T>
Stack<T>::Node::Node() : next(nullptr) { }

template <class T>
Stack<T>::Node::Node(const T& e) : data(e), next(nullptr) { }

template <class T>
T Stack<T>::Node::getData() const {
  return data;
  }

template <class T>
typename Stack<T>::Node* Stack<T>::Node::getNext() const {
  return next;
  }

template <class T>
void Stack<T>::Node::setData(const T& e) {
  data = e;
  }

template <class T>
void Stack<T>::Node::setNext(Node* n) {
  next = n;
  }

///Stack
template <class T>
void Stack<T>::copyAll(const Stack<T>& s) {
  Node* aux(s.anchor);
  Node* last(nullptr);
  Node* nuevoNodo;

  while(aux != nullptr) {
    nuevoNodo = new Node(aux->getData());

    if(last == nullptr) {
      anchor = nuevoNodo;
      }
    else {
      last->setNext(nuevoNodo);
      }
    last = nuevoNodo;
    aux = aux->getNext();
    }
  }

template <class T>
void Stack<T>::deletAll() {
  Stack::Node* aux;

  while(anchor != nullptr) {
    aux = anchor;
    anchor = anchor->getNext();

    delete aux;
    }
  }

template <class T>
Stack<T>::Stack() : anchor(nullptr) { }

template <class T>
Stack<T>::Stack(const Stack&) : anchor(nullptr) { }

template <class T>
Stack<T>::~Stack() {
  deletAll();
  }

template <class T>
bool Stack<T>::isEmpty() const {
  return anchor == nullptr;
  }

template <class T>
void Stack<T>::push(const T& e) {
  Node* aux(new Node(e));

  if(aux == nullptr) {
    throw Exception("Memoria no disponible, push");
    }

  aux->setNext(anchor);
  anchor = aux;
  }

template <class T>
T Stack<T>::pop() {
  if(isEmpty()) {
    throw Exception("Insuficiencia de datos, pop");
    }

  T result(anchor->getData());

  Node* aux(anchor);

  anchor = aux->getNext();

  delete aux;

  return result;
  }

template <class T>
T Stack<T>::getTop() const {
  if(isEmpty()) {
    throw Exception("Insuficiencia de datos, getTop");
    }

  return anchor->getData();
  }

template <class T>
Stack<T>& Stack<T>::operator = (const Stack& s) {
  copyAll(s);
  }

#endif // STACK_HPP_INCLUDED
