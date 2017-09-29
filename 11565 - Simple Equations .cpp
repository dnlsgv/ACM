/*
    11565 - Simple Equations
    Busqueda completa    
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){

    int n, a, b, c;
    bool haySolucion;

    cin >> n;

    for(int i = 0; i < n; i++){
        haySolucion = false;
        cin >> a >> b >> c;

        for(int x = -100; x <= 100 && !haySolucion; x++){
            for(int y = -100; y <= 100 && !haySolucion; y++){
                for(int z = -100; z <= 100 && !haySolucion; z++){
                    if(x != y && x != z && y != z && (x+y+z) == a && (x*y*z) == b && (x*x+y*y+z*z) == c ){
                        haySolucion = true;
                        cout << x << " " << y << " " << z << endl;
                    }
                }
            }
        }
        if(haySolucion == false){
            cout << "No solution." << endl;
        }
    }
    
    return 0;
}