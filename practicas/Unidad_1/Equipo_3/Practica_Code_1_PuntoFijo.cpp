#include<stdio.h>
#include<math.h>
bool calcConv(double []);
void calcG(double [],double []);
double Error(double [],double []);
main()
{
    int k=1;
    double x[2]={0.2,0.35},x_aux[2]={0};
    do{
        printf("\nIteracion %d\n",k);
        if(calcConv(x)==false)
            return 0;
        else
        {
            calcG(x,x_aux);
            k++;
        }
    }while(Error(x,x_aux)>pow(10,-6));
    printf("\nSolucion:\nx(%d)=(%lf,%lf)",k,x_aux[0],x_aux[1]);
}
bool calcConv(double v[]){
    double a[2]={0};
    a[0]=abs(sqrt(5));
    a[1]=(sin(v[0])+4)/(sqrt(-16*pow(v[1],2)+8*v[1]*cos(v[1])+pow(sin(v[1]),2)));
    if(a[0]>1||a[1]>1)
    {
        printf("\nNo converge\n");
        return false;
    }
    else
    {
        printf("\nConverge\n");
        return true;
    }
}
void calcG(double v[],double v2[]){
    v2[0]=v[1]*sqrt(5);
    v2[1]=acos(4*v[1]-cos(v[1]));
    printf("\nSiguiente punto:\nx=(%lf,%lf)\n",v2[0],v2[1]);
}
double Error(double v[],double v2[]){
    return sqrt(pow(v2[0]-v[0],2)+pow(v2[1]-v[1],2));
}