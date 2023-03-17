#include <iostream>
#include <stdlib.h>

using namespace std;
#define numRowCol 256

void createMatrix(double input[numRowCol][numRowCol]){
    double num = 1.0;
    for(int i = 0; i < numRowCol; i++){
        for(int j = 0; j < numRowCol; j++){
            input[i][j] = num;
            // cout << "\t" << input[i][j];
            num++;
        }
        // cout << endl;
    }
}
void transpose(double output[numRowCol][numRowCol], double input[numRowCol][numRowCol])
{
    for (int i = 0; i < numRowCol; i++) {
        for (int j = 0; j < numRowCol; j++) {
            output[j][i] = input[i][j];
            cout << "\t" << output[j][i];
        }
        cout << endl;
    }
    cout << "HIT!" << endl;
}

void blocked_transpose(double output[numRowCol][numRowCol], double input[numRowCol][numRowCol], int block_size){

    for (int i = 0; i < numRowCol; i = i + block_size) {
        for (int j = 0; j < numRowCol; j = j + block_size) {
            for (int n = 0; n < block_size; n++) {
                for (int m = 0; m < block_size; m++) {
                    output[j + m][i + n] = input[i + n][j + m];
                    cout << "\t" << output[j][i];
                }
                cout << endl;
            }
        }
    }
}

int main(){
    double input[numRowCol][numRowCol];
    double output[numRowCol][numRowCol];
    double output2[numRowCol][numRowCol];

    createMatrix(input);
    // transpose(output, input);
    blocked_transpose(output2, input, 64);

}
