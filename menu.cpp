#include <iostream>
#include <string>

#include "menu.hpp"
#include "postfijo.hpp"
#include "stack.hpp"
#include "queue.hpp"

using namespace std;
void mainMenu::menu() {
  string myString;
  int myOption;
  char myChar;

  Queue<char> myCola;
  Stack<char> myPila;

  Postfijo conversion;
  Queue<char> myPostfija;

  do {
    system("cls");
    cout << "***Menu de opciones***" << endl << endl;

    cout << "**Pila**" << endl
         << "1)Vacia" << endl
         << "2)Empilar" << endl
         << "3)Desempilar" << endl
         << "4)Obtener tope" << endl<< endl;

    cout << "**Cola**" << endl
         << "5)Vacia" << endl
         << "6)Encolar" << endl
         << "7)Desencolar" << endl
         << "8)Obtener frente" << endl << endl;

    cout << "9)Convertir infija/postfija" << endl
         << "10)Salir" << endl
         << "Elige una opcion: ";

    cin >> myOption;
    cin.ignore();

    switch(myOption) {
      case 1:
        if(myPila.isEmpty()) {
          cout << "\nLa pila esta vacia" << endl;
          }
        else {
          cout << "\nLa pila no esta vacia" << endl;
          }
        system("pause");
        break;

      case 2:
        cout << "\nCaracter a empilar: ";
        cin >> myChar;
        myPila.push(myChar);
        system("pause");
        break;

      case 3:
        cout << endl;
        while(!myPila.isEmpty()) {
          cout << "Desempilando " << myPila.pop() << endl;
          }
        system("pause");
        break;

      case 4:
        cout << "\nTope: " << myPila.getTop() << endl;
        system("pause");
        break;

      case 5:
        if(myCola.isEmpty()) {
          cout << "\nLa cola esta vacia" << endl;
          }
        else {
          cout << "\nLa cola no esta vacia" << endl;
          }
        system("pause");
        break;

      case 6:
        cout << "\nCaracter a encolar: ";
        cin >> myChar;
        myCola.enqueue(myChar);
        system("pause");
        break;

      case 7:
        cout << endl;
        while(!myCola.isEmpty()) {
          cout << "Desencolando " << myCola.dequeue() << endl;
          }
        system("pause");
        break;

      case 8:
        cout << "\nFrente: " << myCola.getFront() << endl;
        system("pause");
        break;

      case 9:
        cout << "\nIntroduce una cadena en notacion infija: ";
        getline(cin, myString);

        conversion.setPrefija(myString);
        conversion.convertPost();
        myPostfija = conversion.getPostfija();

        cout << "Notacion postfija: ";

        while(!myPostfija.isEmpty()) {
          cout << myPostfija.dequeue();
          }
        cout << endl;
        system("pause");
        break;

      case 10:
        break;
      }
    }
  while(myOption != 10);
  }
