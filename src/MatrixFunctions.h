#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H

#include <iostream>

//Most of the functions are self explanatory.
struct MatrixFunctions{
    /*
    *The following funtion has issues for multiplying a 1x1 matrix with a 
    *larger matrix. If you need to multiply a 1x1 matrix, make sure to pass
    *the column for the second vector in the row place.
    */
    void multiplyMatrices(double* finalMatrix, double* matrix1, double* matrix2, int row, int col){
		/*
		*Matrices multiplied here
		*Good website to see how matrix multiplition is done:
		*https://www.mathsisfun.com/algebra/matrix-multiplying.html
		*/
		for(int i = 0; i < row; i++){
			for(int j = 0; j < row; j++){
				for(int k = 0; k < col; k++){
                    *((finalMatrix + i *row) + j) += *((matrix1 + i *col) +k) * *((matrix2 + k * row) + j);
				}
			}
		}
			
	}	

    void addMatrices(double* finalMatrix, double* matrix, int col, int row){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                *((finalMatrix + i *row) +j) += *((matrix +i *row) +j);
            }
        }

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

    void printMatrix(double* matrix, int rows, int columns){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                std::cout << *((matrix + i * columns) + j) << " ";
            }
            std::cout << "\n";
        }
    }
};
#endif