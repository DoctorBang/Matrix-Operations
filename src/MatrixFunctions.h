#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H

#include <iostream>
#include <vector>
#include <initializer_list>

#define MATRIX(X) std::vector<std::vector<X>>
#define LIST(X) std::initializer_list<std::initializer_list<X>>

template<typename T>
struct Matrix {
public:
  MATRIX(T) m;

  Matrix() = default;

  Matrix(LIST(T) list){
    std::vector<T> temp;
    for(auto i : list){
      for(auto j : i){
        temp.push_back(j);
      }
      m.push_back(temp);
      temp.clear();
    }
  }

  friend Matrix<T> operator*(Matrix<T> a, Matrix<T> b){
    T sum = 0;
    Matrix<T> c;
    std::vector<T> temp;
    for(size_t i = 0; i < a.m.size(); ++i) {
      for(size_t j = 0; j < b.m[0].size(); ++j) {
        for(size_t k = 0; k < a.m[0].size(); ++k){
          sum += a.m[i][k] * b.m[k][j];
        }
        temp.push_back(sum);
        sum = 0;
      }
      c.m.push_back(temp);
      temp.clear();
    }
    return c;
  } 

  friend Matrix<T> operator+(Matrix<T> a, Matrix<T> b){
    Matrix<T> c;
    std::vector<T> temp;
    for(size_t i = 0; i < a.m.size(); ++i){
      for(size_t j = 0; j < a.m[i].size(); ++j){
        temp.push_back(a.m[i][j] + b.m[i][j]); 
      }
      c.m.push_back(temp);
      temp.clear();
    }
    return c;
  }

  friend Matrix<T> operator-(Matrix<T> a, Matrix<T> b){
    Matrix<T> c;
    std::vector<T> temp;
    for(size_t i = 0; i < a.m.size(); ++i){
      for(size_t j = 0; j < a.m[i].size(); ++j){
        temp.push_back(a.m[i][j] - b.m[i][j]); 
      }
      c.m.push_back(temp);
      temp.clear();
    }
    return c;
  }
  friend std::ostream& operator<<(std::ostream &output, Matrix<T> &mat){
    for(auto i : mat.m){
	for(auto j : i){
	    output << j << " ";	
	}
	output << "\n";
    }	
    return output;
  }

  void input(){
    size_t row, col;
    std::cout << "Enter the row size: ";
    std::cin >> row;
    std::cout << "Enter the column size: ";
    std::cin >> col;
    T val;
    std::vector<T> temp;
    for(size_t i = 0; i < row; ++i){
      for(size_t j = 0; j < col; ++j){
        std::cin >> val;
        temp.push_back(val);
      }
      this->m.push_back(temp);
      temp.clear();
    }
  }
};
#endif
