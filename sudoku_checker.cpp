#include <iostream>
#include <algorithm>
#include <sstream>

#define EMPTY short(0)
#define SIZE 9

struct boards{
        short board[SIZE][SIZE];
};

int check_square(short matrix[SIZE][SIZE],short line, short column){
	int count = 0;
	size_t squareX;
	size_t squareY;
        // we need to count how many times does the element matrix[row][column] appear, so at least one of the elements in the square will be equal to it.
        // here we pick the location of the square in the matrix.
        // These two variables (squareX and squareY) are useful to pick which square to check.
        if(line < 3){
                squareX = 0;
        }else{
                if(line > 5){
                        squareX = 2;
                }else{
                        squareX = 1;
                }
        }
        if(column < 3){
                squareY = 0;
        }else{
                if(column > 5){
                        squareY = 2;
                }else{
                        squareY = 1;
                }
        }
        // In these loops we are going to see through row and columns, from the first one to the last one element in the square.
        for(size_t i{squareX*3}; i < (squareX+1)*3; ++i){
                for(size_t j{squareY*3}; j < (squareY+1)*3; ++j){
                        if(matrix[line][column] == matrix[i][j])
                                count++;
                }
        }

        if(count == 1){
                //std::cout << "The square number " << (squareX*3) + squareY + 1 << " is correct." << std::endl;
                return 1;
        }else{
                //std::cout << "The square number " << (squareX*3) + squareY + 1 << " is incorrect." << std::endl;
                return 0;
	}
}

int check_column(short matrix[SIZE][SIZE], short line, short column){
	int count{0};
	//check_column and check_line functions are the same in terms of logic, but has differences in his parameters
	for( short i{0};i<SIZE;++i)
		if(matrix[line][column] == matrix[i][column])
			count++;

	if(count == 1)
		return 1;
	else
		return 0;
}

int check_line(short matrix[SIZE][SIZE], short line, short column){
	int count{0};
	
	for(short j{0};j<SIZE;++j)
		if(matrix[line][column] == matrix[line][j])
			count++;

	if(count == 1)
		return 1;
	else
		return 0;
}


void print( short b[SIZE][SIZE] )
{
	//classic for to print the matrix
	for(short i{0};i<SIZE;++i){
		for(short j{0};j<SIZE;++j){
			std::cout << b[i][j] << " ";
		}
		std::cout << "\n";
	}
}

bool is_valid( short b[SIZE][SIZE] )
{
    	for(short i{0};i<SIZE;++i){
		for(short j{0};j<SIZE;++j){
			if(check_column(b,i,j) == 1){
				if(check_line(b,i,j) == 1){
					if(check_square(b,i,j) == 1){
						//std::cout << "The number in index: " << i*SIZE + j << " is correct" << std::endl;
					}else{
						//std::cout << "The number in index " << i*SIZE + j << " has problems with his square" << std::endl;
						return false;
					}
				}else{
					//std::cout << "The number in index: " << i*SIZE + j << " has problems with his lines" << std::endl;
					return false;
				}
			}else{
				//std::cout << "The number in index: " << i*SIZE+j << " has problems with his column" << std::endl;
				return false;
			}
		}
	}	



	return true; 
}


int main(void)
{

    boards *boards_v = new boards[8];

    int n_boards{8}; // Number of boards...
    
    for ( int i{0}; i <= n_boards ; ++i )
    {
        // for to travel the matrix throw the struct
        for(int j{0}; j < 9; ++j){
                for(int k{0}; k < 9; ++k){
    	                std::cin >> boards_v[i].board[j][k];
                }
        }
        std::cout << "Board #" << (i+1) << ": \n";
        print( boards_v[i].board );
	auto valid = is_valid( boards_v[i].board );
        std::cout << "Is valid? " << std::boolalpha << valid << std::endl;
        std::cout << "\n";
    }

    return 0;
}
