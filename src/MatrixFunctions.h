#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H

#include <iostream>
#include <vector>

template<typename T>
std::vector<std::vector<T>> multiplyMatrices(
  std::vector<std::vector<T>> a, std::vector<std::vector<T>> b
    ){
  T sum = 0;
  std::vector<std::vector<T>> c;
  std::vector<T> temp;
  for(size_t i = 0; i < a.size(); ++i) {
    for(size_t j = 0; j < b[i].size(); ++j) {
      for(size_t k = 0; k < a[i].size(); ++k){
        sum += a[i][k] * b[k][j];
      }
      temp.push_back(sum);
      sum = 0;
    }
    c.push_back(temp);
    temp.clear();
  }
  return c;
} 

  template<typename T>
  std::vector<std::vector<T>> addMatrices(
      std::vector<std::vector<T>> a, std::vector<std::vector<T>> b
      ){
    
  }

    void subtractMatrices(double* finalMatrix, double* matrix, int col, int row){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                *((finalMatrix + i *row) +j) -= *((matrix +i *row) +j);
            }
        }

    }

    void inputMatrixSize(int* row, int* column){
        std::cout << "Rows: ";
        std::cin >> *row;
        std::cout << "Columns: ";
        std::cin >> *column;
    }

    void matrixInput(double* matrix, int rows, int columns){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                std::cout << "Matrix position (" << i + 1 << ")(" << j + 1 << ") ";
                std::cin >> *((matrix+i*columns) + j);
            }
        }
        std::cout << "\n";
    }
  
template<typename T>
void printMatrix(std::vector<std::vector<T>> n){
  for(auto i : n){
    for(auto j : i)
      std::cout << j << " ";
    std::cout << "\n";
  }
}

#endif
