#include <iostream>

using namespace std;

void createMatrix(int &matrix){
    
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++){
            if(i==j){
                matrix[i][j] = 0;
            }else{
                matrix[i][j] = (int) rand() % 100;

            }
        }
    }
}


int main(){
    int matrix[4][4];
    createMatrix(matrix);

    return 0;
}