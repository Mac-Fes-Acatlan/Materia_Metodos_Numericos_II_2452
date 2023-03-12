//Tarea 10
//Método de Newton
//Robles Yasumura Mauricio Azael

#include <stdio.h>
#include <math.h>

int i, j, k, l;

double vec[] = {0.0, 0.0};  //Punto inicial
double aux[] = {0.0, 0.0};  //Punto anterior
double nf[2];   //-f(x)
double jac[2][2];   //Jacobiano evaluado en el punto 
double aum[2][3];   //matriz aumentada
float err;  //error

int main()
{

    void jacobiana(double[]);
    void aumentada(double[]);
    double determinante(double[2][2]);
    void gauss_jordan(double[2][3]);
    void sigpunto(double[], double[2][3], double[]);
    void error(double[], double[]);
    int cont = 0;
    double det=0.0;

    printf("x(%d)=(%f, %f)\n", cont, vec[0], vec[1]);

    do      //se repite mientras el error sea mayor a 10E-6
    {
        cont++;
        printf("ITERACION %d:\n", cont);

        jacobiana(vec);     

        det=determinante(jac);

        if (det==0)     //si el determinante de la matriz jacobiana es 0, sale del loop
        {
            printf("El determinante de la matriz es 0 :(\n");
            break;
        }
        

        aumentada(vec);

        for (i = 0; i < 2; i++)     //se guardan los valores de la matriz jacobiana y -f(x) para formar la aumentada
        {
            for (j = 0; j < 2; j++)
            {
                aum[i][j] = jac[i][j];
            }
        }
        aum[0][2] = nf[0];
        aum[1][2] = nf[1];

        gauss_jordan(aum);

        for (i = 0; i < 2; i++) //se guarda el punto actual en el auxilar para calcular el error
        {
            aux[i] = vec[i];
        }

        sigpunto(vec, aum, nf);

        printf("\nx(%d)=(%f, %f)\n", cont, vec[0], vec[1]);

        error(vec, aux);

        printf("error: %f\n\n", err);

    } while (err > 10E-6);
}

void jacobiana(double vec[])    //evalua el punto en la matriz jacobiana
{
    jac[0][0] = 2 * cos(vec[0]) - 5;
    jac[0][1] = -sin(vec[1]);
    jac[1][0] = -2 * sin(vec[0]);
    jac[1][1] = -2.5 + cos(vec[1]);
}

void aumentada(double vec[])    //evalua f(x)
{
    nf[0] = -(2 * sin(vec[0])) + (5 * (vec[0])) - cos(vec[1]);
    nf[1] = -(2 * cos(vec[0])) + (2.5 * vec[1]) - sin(vec[1]);
}

double determinante(double a[2][2]) //calcula la determinante de la matriz jacobiana 
{
    double d;
    d = a[0][0] * a[1][1] - a[1][0] * a[0][1];
    return d;
}

void gauss_jordan(double a[2][3])   //resuelve el sistema de ecuaciones por Gauss-Jordan
{
    double temp;

    // Eliminación de Gauss
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 2; i++)
        {
            if (i != j)
            {
                temp = a[i][j] / a[j][j];
                for (k = 0; k < 2 + 1; k++)
                {
                    a[i][k] -= temp * a[j][k];
                }
            }
        }
    }

    // Eliminación de Gauss-Jordan
    for (i = 0; i < 2; i++)
    {
        temp = a[i][i];
        for (j = 0; j < 2 + 1; j++)
        {
            a[i][j] /= temp;
        }
    }
}

void sigpunto(double vec[], double aum[2][3], double nf[])  //calcula el siguiente punto 
{
    vec[0] = vec[0] + aum[0][2];
    vec[1] = vec[1] + aum[1][2];
}

void error(double vec[], double aux[])  //calcula el error
{
    err = sqrt(pow(vec[0] - aux[0], 2) + pow(vec[1] - aux[1], 2));
}