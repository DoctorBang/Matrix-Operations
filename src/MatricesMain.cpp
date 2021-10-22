#include "MatrixFunctions.h"
#include <string>


int main(){
  std::vector<std::vector<int>> a = {{1,2,3},{1,2,3}};
  std::vector<std::vector<int>> b = {{1,1}, {2,2}, {3,3}};
  std::cout << "About to multiply\n";
  std::vector<std::vector<int>> c = multiplyMatrices(a,b);
  printMatrix(c);
  return 0;
}
