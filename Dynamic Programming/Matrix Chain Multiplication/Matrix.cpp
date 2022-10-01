#include <iostream>
using namespace std;

int main()
{   
    int n = 5;                 // Number of matrices
    int P[] = {5, 4, 6, 2, 7}; // Array which have the dimensions A1(5x4) A2(4x6) A3(6x2) A4(2x7)
    int S[5][5] = {0};         // Matrice pentru a tine minte cum le multiplicam
    int m[5][5] = {0};         // Matrice pentru cost
    int j, min, q;

    for (int d = 1; d < n - 1; d++)
    { // d is for the distancce between the first and the last
      //  matrices that will be multiplied in this stage
        for (int i = 1; i < n - d; i++)
        {
            j = i + d;
            min = 32767; // max value for int
            for (int k = i; k <= j-1; k++)
            {

                q = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];

                if (q < min)
                {
                    min = q;
                    S[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }

    cout << m[1][n - 1] << endl;
    cout << S[1][n - 1] << endl;
}

// TODO: The S matrix will keep in mind how to multiply the matrixand the m is the cost