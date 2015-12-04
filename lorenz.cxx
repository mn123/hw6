#include <iostream>

using namespace std;

void func(double* const k, const double x, const double y, const double z, const int a, const int b, const double c);
	
int main(){

	double t=0, x=1, y=1, z=1, k1[3], k2[3], k3[3], k4[3]; //3-dim
	const int a=10, b=28;
	const double c=8.0/3, dt=0.001;
	const int tEnd=100, N=tEnd/dt;

	for(int i=0; i<N; i++){
		t += dt;

		func(k1,x,y,z,a,b,c);
		func(k2,x+dt/2*k1[0],y+dt/2*k1[1],z+dt/2*k1[2],a,b,c);
		func(k3,x+dt/2*k2[0],y+dt/2*k2[1],z+dt/2*k2[2],a,b,c);
		func(k4,x+dt*k3[0],y+dt/2*k3[1],z+dt/2*k3[2],a,b,c);

		x += dt/6*(k1[0]+2*k2[0]+2*k3[0]+k4[0]); 
		y += dt/6*(k1[1]+2*k2[1]+2*k3[1]+k4[1]); 
		z += dt/6*(k1[2]+2*k2[2]+2*k3[2]+k4[2]); 
	
		cout << t << "\t" << x << "\t" << y << "\t" << z << endl;
	}

	return 0;
}

void func(double* const k, const double x, const double y, const double z, const int a, const int b, const double c){
	k[0] = a*(y-x); // dx/dt
	k[1] = x*(b-z)-y; // dy/dt
	k[2] = x*y-c*z; // dz/dt
}
