#include <iostream>
#include <fstream>
#include <math.h>

float const L = 100.0;
float const rho = 0.01;
float const ten = 100;
float const c = sqrt(ten/rho);



int main(int argv, char **argc){
    float dt = atof(argc[1]); //Paso temporal
    float tf = atof(argc[2]); //Tiempo final
    int Nt = tf/dt;
    float dx = c*dt;
    int Nx = L/dx;
    
    
    
    return 0;
}