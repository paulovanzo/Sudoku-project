#include <iostream>
#include <algorithm>
#include <sstream>

#define EMPTY short(0)
#define SIZE 9

int check_square(short matrix[SIZE][SIZE],short line, short column){
	int count = 0;
	size_t squareX;
	size_t squareY;
        // we need to count how many times does the matrix[line][column] appear, so at least one of the elements in the square will be equal to it.
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
        // In these loops we are going to see through the lines and columns, from the first one to the last one element in the square.
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
    // TODO: implement this function.
	for(short i{0};i<SIZE;++i){
		for(short j{0};j<SIZE;++j){
			std::cout << b[i][j] << " ";
		}
		std::cout << "\n";
	}
}

bool is_valid( short b[SIZE][SIZE] )
{
    
	// TODO: implement this function.
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
	short board1[SIZE][SIZE]={
        { 1, 3, 4, 6, 7, 8, 5, 9, 2 },
        { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
        { 5, 9, 8, 3, 4, 2, 1, 6, 7 },
        { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
        { 4, 2, 6, 8, 5, 3, 9, 7, 1 },
        { 7, 1, 3, 4, 2, 9, 8, 5, 6 },
        { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
        { 2, 8, 7, 9, 1, 4, 6, 3, 5 },
        { 3, 4, 5, 2, 8, 6, 7, 1, 9 } };

    short board2[SIZE][SIZE]={
        { 1, 6, 2, 8, 5, 7, 4, 9, 3 },
        { 5, 3, 4, 1, 2, 9, 6, 7, 8 },
        { 7, 8, 9, 6, 4, 3, 5, 2, 1 },
        { 4, 7, 5, 3, 1, 2, 9, 8, 6 },
        { 9, 1, 3, 5, 8, 6, 7, 4, 2 },
        { 6, 2, 8, 7, 9, 4, 1, 3, 5 },
        { 3, 5, 6, 4, 7, 8, 2, 1, 9 },
        { 2, 4, 1, 9, 3, 5, 8, 6, 7 },
        { 8, 9, 7, 2, 6, 1, 3, 5, 4 } };

    short board3[SIZE][SIZE]={
        { 5, 3, 4, 6, 7, 8, 9, 1, 2 },
        { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
        { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
        { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
        { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
        { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
        { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
        { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
        { 3, 4, 5, 2, 8, 6, 1, 7, 9 } };

    short board4[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };


    // Problem
    short board5[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 5, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 3, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    // Problem
    short board6[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 19, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, -3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    // Problem
    short board7[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 0, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    // Problem
    short board8[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 3, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 6, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };
	

    std::cout << "Board: \n";
    print( board1 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board1 ) << std::endl;
    std::cout << "\n";

    std::cout << "Board: \n";
    print( board2 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board2 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board3 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board3 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board4 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board4 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board5 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board5 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board6 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board6 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board7 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board7 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board8 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board8 ) << std::endl;
    std::cout << "\n";
		
    short boards[SIZE][SIZE][SIZE];

    for(int i{0};i < 9;++i){
    
    
    }
    /* TODO: Make the code below work, instead of the ugly code above.

    int n_boards{8}; // Number of boards...
    
    for ( int i{0}; i < n_boards ; ++i )
    {
    	std::cin << boards[i];
        std::cout << "Board #" << (i+1) << ": \n";
        print( boards[i] );
        std::cout << "Is valid? " << std::boolalpha << is_valid( board[i] ) << std::endl;
        std::cout << "\n";
    }
	*/
    return 0;
}
