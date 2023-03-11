//Tarea 7
//Método del punto fijo
//Robles Yasumura Mauricio Azael


#include <stdio.h>
#include <math.h>

int main() {
	int convergencia(float[],float[]);
	float * iteracion(float[]);
	float error(float[],float[]);
	float verror;
	
	float vec_ite[]= {0.1,0.1,-0.1};	//arreglo para guardar los valores de x(k)
	float vec_aux[]= {0.0,0.0,0.0};		//arreglo para guardar los valores de x(k-1)
	float mat[3][10];	//matriz para guardar todos los valores que se obtengan
	int i,j,k=0,conv=1;	//boolean para comprobar si converge
	float *p;	//puntero para obtener un array de la funcion iteracion

	do {
		conv=convergencia(vec_ite,vec_aux);	//se llama a la funcion convergencia
		
		if(conv==0){	//si no converge se termina el programa
			printf("no converge:(");
			break;
		}

		for (i = 0; i < 3; i++){	//se llena la matriz con los valores actuales del vector
			mat[i][k]=vec_ite[i];
		}
		
		p=iteracion(vec_ite);	

		for(i=0;i<3;i++){	//se copia el vector iterador en el vector auxiliar
			vec_aux[i]=vec_ite[i];
		}
		for(i=0;i<3;i++){	//se guardan los nuevos valores del vector iterador
			vec_ite[i]=*(p+i);
		}

		k++;	//contador de iteraciones

		verror=error(vec_ite,vec_aux);	//se obtiene el error desde la funcion error
		
		printf("error iteracion %d es %f\n",k,verror);

	}while(conv==1 && verror>10E-6);

	
	for ( j = 0; j < k; j++){
		printf("\nvalores en la iteracion %d: (%f, %0.12f, %f)\n",j+1,mat[0][j],mat[1][j],mat[2][j]);
	}
	
	
}

int convergencia(float vec_ite[],float vec_aux[]) {
	double aux,aux2,aux3;
	aux=fabs(vec_ite[0]/(9.0f*(sqrt(pow(vec_ite[0],2)+sin(vec_ite[2])+1.06f)))) + fabs((exp((-vec_ite[0])*(vec_ite[1]))/20.0f));
	aux2=fabs((-vec_ite[2]/3.0f)*sin(vec_ite[1]*vec_ite[2])) + fabs((vec_ite[0])*exp((-vec_ite[0])*(vec_ite[1]))/20.0f);
	aux3=fabs((-vec_ite[1]/3.0f)*sin(vec_ite[1]*vec_ite[2])) + fabs(cos(vec_ite[2])/(18.0f*(sqrt(pow(vec_ite[0],2)+sin(vec_ite[2])+1.06f))));

	if(aux<1.0 && aux2<1.0 && aux3<1.0) {
		return 1;
	}else{
		return 0;
	}
}

float * iteracion(float vec_ite[]) {
	static float vec_aux[3];

	vec_aux[0]=(cos(vec_ite[1]*vec_ite[2])/3)+(1.0f/6);
	vec_aux[1]=(1.0f/9.0f)*sqrt(pow(vec_ite[0],2)+sin(vec_ite[2])+1.06f)-0.1f;
	vec_aux[2]=(-1.0f/20.0f)*(exp(-vec_ite[0]*vec_ite[1])+((10.0f*M_PI-3)/3));
	return vec_aux;
}

float error(float vec_ite[],float vec_aux[]) {
	float aux;
	aux=sqrt(pow(vec_ite[0]-vec_aux[0],2)+pow(vec_ite[1]-vec_aux[1],2)+pow(vec_ite[2]-vec_aux[2],2));
	return aux;
}
