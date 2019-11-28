#include <iostream>
#include <fstream>
#include <math.h>

float const L = 1.0;
float const rho = 0.01;
float const ten = 40;
float const c = sqrt(ten/rho);

void inicializar(float* prevA, int Nx, float dx);
void p_avance(float* prevA, float* prevB, int Nx);
void avance(float* prevA, float* prevB, float* nuevo, int Nx);
std::ofstream outfile;

int main(int argv, char **argc){
    float dt = atof(argc[1]); //Paso temporal
    float tf = atof(argc[2]); //Tiempo final
    int Nt = tf/dt;
    float dx = c*dt;
    int Nx = 1+(L/dx);
	
	float* prevA = new float[Nx];
	float* prevB = new float[Nx];
	float* nuevo = new float[Nx];
	float t = 0;
	
	inicializar(prevA, Nx, dx);
	p_avance(prevA, prevB, Nx);
	
	outfile.open("onda.dat");
	
	outfile<< t << " ";
	for(int i=0;i<Nx;i++){
		outfile<< prevA[i] << " ";
	}
	outfile<<std::endl;
	
	t += dt;
	outfile<< t << " ";
	for(int i=0;i<Nx;i++){
		outfile<< prevB[i] << " ";
	}
	outfile<<std::endl;
	
	while(t<tf){
		t += dt;
		avance(prevA, prevB, nuevo, Nx);
		outfile<< t << " ";
		for(int i=0;i<Nx;i++){
			outfile<< nuevo[i] << " ";
		}
		outfile<<std::endl;
	}
	outfile.close();
	
	delete [] prevA;
	delete [] prevB;
	delete [] nuevo;
	
	return 0;
}

void inicializar(float* prevA, int Nx, float dx){
	for(int i=0;i<Nx;i++){
		prevA[i] = pow(10,-4)*sin((2.0*M_PI/L)*i*dx);
	}
}

void p_avance(float* prevA, float* prevB, int Nx){
	for(int i=1;i<Nx-1;i++){
		prevB[i]=0.5*(prevA[i+1]+prevA[i-1]);
	}
}

void avance(float* prevA, float* prevB, float* nuevo, int Nx){
	for(int i=1;i<Nx-1;i++){
		nuevo[i]=prevB[i+1]-prevA[i]+prevB[i-1];
	}
	for(int i=0;i<Nx;i++){
		prevA[i]=prevB[i];
	}
	for(int i=0;i<Nx;i++){
		prevB[i]=nuevo[i];
	}	
}