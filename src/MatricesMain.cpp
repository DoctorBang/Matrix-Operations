#include "MatrixFunctions.h"

int main(){
	char inputKey;
	/*
    *Initialized col and row1 to different variables so that 
    *loops that ask for them to be different sizes don't break.
    *Didn't leave them uninitilized because then they'll have 
    *random junk that just may or may not be equal.
    */
	int row = 0, col = 0, row1 = 1, col1 = 1, passVar;
	struct MatrixFunctions matrices;
	
	std::cout << "A) Multiply matrices. \n";
	std::cout << "B) Add matrices. \n";
	std::cout << "C) Subtract matrices.\n";
	std::cout << "Q) Quit. \n";
	std::cin.get(inputKey);

	switch(inputKey){
		case 'a':	//Section for multiplying matrices
		case 'A':{
			while(col != row1){
				std::cout << "Please enter the size of the matrix.\n";
				matrices.inputMatrixSize(&row, &col);
				std::cout << "Please enter the size of the second matrix.\n";
				matrices.inputMatrixSize(&row1, &col1);
				if(col != row1){					
					std::cout << "You cannot multiply these two matrices. ";
					std::cout << "The columns of the first matrix must be equal to the ";
					std::cout << "columns of the second matrix.\n";
				}
			}

			double matrix1[row][col] = {}, matrix2[row1][col1] = {}, finalMatrix[row][col1] = {};
 
			std::cout << "Please enter the values for each matrix:\n";
			std::cout << "Matrix 1: \n";
			matrices.matrixInput( (double*) matrix1, row, col);	//Cast the arrays to a double pointer in order to pass it by reference
			std::cout << "Matrix 2: \n";
			matrices.matrixInput( (double*) matrix2, row1, col1);

			if(row == 1)
				passVar = col1;
			else
				passVar = row;
			matrices.multiplyMatrices( (double*) finalMatrix, (double *)matrix1, (double *)matrix2, passVar, col);
			matrices.printMatrix( (double*) finalMatrix, row, col1);
			break;
		}
		case 'b':	//Section for adding matrices
		case 'B':{
			while(!col){
                std::cout << "Please enter the size of the matrices: \n";
                matrices.inputMatrixSize(&row, &col);
            }
			double matrix1[row][col] = {}, matrix2[row][col] = {};

            std::cout << "Please input the values in each matrix:\n";
            std::cout << "Matrix 1:\n";
			matrices.matrixInput((double*) matrix1, row, col);
			std::cout << "Matrix 2:\n";
			matrices.matrixInput((double*) matrix2, row, col);
			
			matrices.addMatrices((double*) matrix1, (double*) matrix2, row, col);
			matrices.printMatrix((double*) matrix1, row, col);
			break;
		}
		case 'c':
		case 'C':{
			while(!col){
                std::cout << "Please enter the size of the matrices: \n";
                matrices.inputMatrixSize(&row, &col);
            }
			double matrix1[row][col] = {}, matrix2[row][col] = {};

            std::cout << "Please input the values in each matrix:\n";
            std::cout << "Matrix 1:\n";
			matrices.matrixInput((double*) matrix1, row, col);
			std::cout << "Matrix 2:\n";
			matrices.matrixInput((double*) matrix2, row, col);
			
			matrices.subtractMatrices((double*) matrix1, (double*) matrix2, row, col);
			matrices.printMatrix((double*) matrix1, row, col);
			break;
		}
		default:
			std::cout << "Error occured\n";
	}

	return 0;
			

}
