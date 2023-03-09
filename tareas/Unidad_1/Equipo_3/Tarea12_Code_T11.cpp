#include<stdio.h>
#include<math.h>
void calcJacobiana(double [][2],double []);
double det(double [][2]);
void gauss_jordan(double [][3],double []);
void matrizAumentada(double [][2],double [][3],double []);
void nuevoPunto(double [],double [],double []);
double Error(double [],double []);
main()
{
    int i=1;
    double J[2][2]={0},mA[2][3]={0},f[2]={0},x[2]={1,1},x_aux[2]={0},y[2]={0},er=0;
    printf("\nTarea 11:\n");
    do{
        printf("\nIteracion %d\n",i);
        calcJacobiana(J,x);
        if(det(J)!=0)
            printf("\nConverge\n");
        else
            printf("\nNo converge\n");
        f[0]=sin(x[0])-pow(x[1],2);
        f[1]=pow(x[0],2)+(x[0]*x[1])+pow(x[1],2)-3;
        matrizAumentada(J,mA,f);
        gauss_jordan(mA,y);
        nuevoPunto(x,x_aux,y);
        printf("\nx(%d)=(%lf,%lf)",i,x[0],x[1]);
        i++;
        er=Error(x,x_aux);
        printf("\nError = %lf\n\n",er);
    }while(er>pow(10,-6));
}
void calcJacobiana(double M[][2],double v[])
{
    M[0][0]=cos(v[0]);
    M[0][1]=(-2)*(v[1]);
    M[1][0]=(2*(v[0]))+v[1];
    M[1][1]=v[0]+(2*(v[1]));
}
double det(double M[][2]){
    return (M[0][0]*M[1][1])-(M[0][1]*M[1][0]);
}
void gauss_jordan(double M[][3],double y[]){
    double may;
    int ind;
    double aux;
    double pivote;
    for(int k=0;k<2;k++){
        may=abs(M[k][k]);
        ind=k;
        for(int l=k+1;l<2;l++){
            if(may<abs(M[l][k])){
                may=abs(M[l][k]);
                ind=l;
            }
        }
        if(k!=ind){
            for(int i=0;i<2+1;i++){
                aux=M[k][i];
                M[k][i]=M[ind][i];
                M[ind][i]=aux;
            }
            
        }
        if(M[k][k]==0){
            printf("No tiene solucion");
            break;
        }
        else{
            for(int i=0;i<2;i++){
                if(i!=k){
                    pivote=-M[i][k];
                    for(int j=k;j<2+1;j++){
                        M[i][j]=M[i][j]+pivote*M[k][j]/M[k][k];
                    }
                }
                else{
                    pivote=M[k][k];
                    for(int j=k;j<2+1;j++){
                        M[i][j]=M[i][j]/pivote;
                    }
                }
            }
        }
    }
    printf("\nSolucion:\n");
    for(int i=0;i<2;i++){
        printf("y%d=%lf\t",i+1,M[i][2]);
        y[i]=M[i][2];
    }
    putchar('\n');
}
void matrizAumentada(double J[][2],double mA[][3],double f[]){
    int i,j;
    printf("Jacobiana:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("\t%lf",J[i][j]);
        }
        putchar('\n');
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if(j==2)
                mA[i][j]=-f[i];
            else
                mA[i][j]=J[i][j];
        }
    }
    printf("Matriz Aumentada:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\t%lf",mA[i][j]);
        }
        putchar('\n');
    }
}
void nuevoPunto(double v1[],double v2[],double v3[]){
    int i;
    for ( i = 0; i < 2; i++)
    {
        v2[i]=v1[i];
        v1[i]=v2[i]+v3[i];
    }
}
double Error(double v1[],double v2[]){
    return sqrt(pow(v1[0]-v2[0],2)+pow(v1[1]-v2[1],2));
}