#include "MatrixFunctions.h"

void print_menu(){
    std::cout << "0: Multiply\n" 
      << "1: Add\n"
      << "2: Subtract\n";
}

void get_in(Matrix<double>& a, Matrix<double>& b) {
    std::cout << "Enter matrix 1\n";
    a.input();
    std::cout << "Enter matrix 2\n";
    b.input();
}

int main(){
    Matrix<double> a,b;
    print_menu();
    int input;
    std::cin >> input;
  
    switch(input){
    case 0:
        get_in(a,b);
        std::cout << a*b;
        break;
    case 1:
        get_in(a,b);
        std::cout << a + b;
        break;
    case 2:
        get_in(a,b);  
        std::cout << a - b;
        break;
    default:
        std::cout << "Menu option incorrect\n";
    }
    return 0;
}
