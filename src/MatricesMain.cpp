#include "MatrixFunctions.h"

void print_menu(){
  std::cout << "0: Multiply\n" 
    << "1: Add\n"
    << "2: Subtract\n";
}

int main(){
  Matrix<double> a,b,c;
  print_menu();
  int input;
  std::cin >> input;
  
  switch(input){
  case 0:
    std::cout << "Enter matrix 1\n";
    a.input();
    std::cout << "Enter matrix 2\n";
    b.input();
    a.print();
    b.print();
    c = a * b;
    c.print();
    break;
  case 1:
    std::cout << "Enter matrix 1\n";
    a.input();
    std::cout << "Enter matrix 2\n";
    b.input();
    c = a + b;
    c.print();
    break;
  case 2:
    std::cout << "Enter matrix 1\n";
    a.input();
    std::cout << "Enter matrix 2\n";
    b.input();
    c = a - b;
    c.print();
    break;
  default:
    std::cout << "Menu option incorrect\n";
  }

  return 0;
}
