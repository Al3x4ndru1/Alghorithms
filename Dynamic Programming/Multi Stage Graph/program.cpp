#include <iostream>

using namespace std;


int main(){
    int stages = 4; // number of stages
    int n = 8; // number of nodes
    int min;
    int Cost[9]; //  Array of cost that we will fill
    int Path[9]; // The path
    int d[9]; // Array that will store the next pass for each element
    int C[9][9]; // Matrix of cost


    Cost[n]=0; // Set the Cost for the last element with 0 because we already are at the last position

    for(int i = n-1;i>=1;i--){
        min = 32767;
        for(int k = i+1;k<=n;k++){
            
            if(C[i][k]!=0 && C[i][k]+Cost[k]<min){
                min = C[i][k] + Cost[k];
                d[i]=k;
            }
        }
        Cost[i]=min;
    }
    Path[1]=1; Path[stages]=n;
    for(int i=2;i<stages;i++){
        Path[i]=Path[d[i-1]];
    }
}