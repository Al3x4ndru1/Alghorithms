#include <iostream>

using namespace std;

int main()
{
    int P[5] ={0,1,2,5,6}; // We have to add 0 for P and for wt
    int wt[5] ={0,2,3,4,5};
    int n=4,m=8;
    int K[5][9]; // 5 is for number of objects (rows) and 9 is for number of the capacity (colums)
    int j;
    int i;

    for(i=0;i<n;i++){
        for(j=0;j<m;m++){

            if(i==0 || j==0){
                K[i][j] = 0;
            }

            else{ 
            
                if(wt[i]<j){ // if the weight of the object i is less the j ?
                    K[i][j] = max(K[i-1][j],K[i-1][j - wt[i]] + P[i]);
                }
                else{
                    K[i][j] = K[i-1][j]; 
                }
            }
        }
    }
    cout<< K[n][j]; // This is the optimal cost


    // If we want to know the object:
    i=n;
    j=m;
    while(i>0 && j>0){
        if(K[i][j]==K[i-1][j]){
            cout <<i<<" =0"<<endl;
            i--;
        }else{
            cout<<i<< " = 1"<<endl;
            i--;
            j=j-wt[i];
        }
    }

}


//TODO: Formula for the second if:
// The first time when the second conditon will be true in this case is when i=1 and j=2, so:
// K[1][2] = max(K[i-1][j], ,K[i-1][j - wt[i]] + P[i])
// K[1][2] = max(0, K[1-1][2- wt[i]]+ 1 )
// K[1][2] = max(0, K[1-1][2-2] + 1 )
// K[1][2] = max(0, 1)
// K[1][2] = 1