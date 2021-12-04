#include <iostream>

using namespace std;

int main()
{
    int w[3] = {5, 6, 8};
    int p[3] = {7, 6, 9};
    int P[15] = {0};

    P[0] = 0;
    for(int i=1; i<15; i++){
        P[i] = 0;
        for(int j=0; j<3; j++){
            if(i-w[j] >= 0){
                if(P[i-w[j]] + p[j] > P[i]){
                    P[i] = P[i-w[j]] + p[j];
                }
            }
        }
    }

    cout << "Capacity:Max Profit" << endl;
    for(int i=0; i<15; i++){
        cout << i << ": " << P[i] << endl;
    }


    return 0;
}
