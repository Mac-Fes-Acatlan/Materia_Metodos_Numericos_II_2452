#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define TOL 1e-6

double g1(double x1, double x2, double x3){
	return (cos(x2*x3) + 0.5)/3;
}

double g2(double x1, double x2, double x3){
	return ((sqrt(pow(x1, 2)+sin(x3)+1.06))/9) - 0.1;
}

double g3(double x1, double x2, double x3){
	return (-exp(-x1*x2)-(10*M_PI - 3)/3)/20;
}
bool convergence(double x0, double y0, double x30){
    double dx1ldx1 = 0;
    double dx2lx1 = (1.0 / 9.0) * (x0 / sqrt(x0 * x0 + sin(x30) + 1.06));
    double dx3lx1 = (1.0 / 20.0) * exp(-x0 * y0);
    bool firstconvergence = (fabs(dx1ldx1) + fabs(dx2lx1) + fabs(dx3lx1))<1;
    
    double dx1ldx2 = (x30/3)*sin(y0-x30);
    double dx2lx2 = 0;
    double dx3lx2 = (-1.0/20.0)*exp(-x0*y0);
    bool secondconvergence = (fabs(dx1ldx2) + fabs(dx2lx2) + fabs(dx3lx2))<1;

    double dx1ldx3 = (y0/3)*sin(y0*x30);
    double dx2lx3 = (1.0/18.0*sqrt((x0*x0) + sin(x30) + 1.06))*cos(x30);
    double dx3lx3 = 0;
    bool thirdconvergence = (fabs(dx1ldx3) + fabs(dx2lx3) + fabs(dx3lx3))<1;
    bool isconvergent = firstconvergence && secondconvergence && thirdconvergence;
    return isconvergent;
}

int main(){
	double x1 = 0.1, x2 = 0.1, x3 = -0.1;
	double x1_new, x2_new, x3_new;
	double error = INFINITY;
	int iter = 0;
	
	while (error>TOL){
        bool isconvergent = convergence(x1,x2,x3);
        if(!isconvergent)
        {
            printf("El metodo diverge cuando x1=%f , x2=%f, x3=%f",x1,x2,x3);
            return;
        }
		x1_new=g1(x1, x2, x3);
		x2_new=g2(x1, x2, x3);
		x3_new=g3(x1, x2, x3);
		error = sqrt(pow(x1_new - x1, 2)+pow(x2_new - x2, 2)+pow(x3_new - x3, 2));
		
		x1=x1_new;
		x2=x2_new;
		x3=x3_new;
		iter++;
		printf("iter %d: x1 = %lf, x2 = %lf, x3 = %lf, error = %lf\n", iter, x1, x2, x3, error);
		
	}
	printf("Solucion encontrada despues de %d iteraciones; \n", iter);
	printf("x1 = %lf, x2 = %lf, x3 = %lf\n", x1, x2, x3);
	return 0;
}
