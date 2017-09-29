/*
    11172 - Relational Operator
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){

    int T, a, b;

    cin >> T;

    while(T--){
        cin >> a >> b;
        if(a > b){
            printf(">\n");
        }
        else{
            if(a < b){
                printf("<\n");
            }
            else{
                printf("=\n");
            }
        }
    }

    return 0;
}