#include <stdio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>	

//Hay 'A' par de números consecutivos que suman B
//Al menos C son pares
//Hay exactamente D números primos
//Hay E pares de numeros seguidos en la secuencia que son son consecutivos


//Formato solución:
//arreglo de arreglos, donde estarán todo el conjunto de soluciones Soluciones[]
//Formato solucion array sol[5], con int a, int b, int c, int d, int d (valores que variarán), que se agregarán a Soluciones[].


/**Restricciones 
1. a b c d e

preguntar si son consecutivos (haciendo div conquista) los pares anteriores, si suman B, restar 1 a A, si A =0 dejar de buscar, si no, seguir buscando.

2.
Buscar pares en a b c d e, y si es menor a C descartar la solución, si es mayor o igual a C, guardar solución.

3. Buscar números que sean sólo divisibles por si mismos. Primero en el arreglo dígito por dígito. Luego todos los dígitos (divide y conquista).

4. Si E es mayor que 0, preguntar posición por posición si el número que le sigue es el consecutivo.   
**/

//Optimización: tomar la lista (conjunto solucion), y contabilizarla, si es par, dividir ese número a la mitad y extraer la solucíón que se encuentra allí. Si es impar, quitar 1, dividir en 2 y luego sumar 1.

/**¿Cómo hacerlo?
Se implementan 5 for's de 0-9, uno anidado sobre otro, en el último (o más interno), se deben aplicar las restricciones.
**/


//SEGUIDOS NUM+1
//CONSECUTIVOS A, B

int espar(int num){
//0 si
//1 no
if(num%2==0){
	return 0;}
else if(num%2 != 0)
	{return 1;}
}


int primo(int  num){
int resp;
int resto;
int result;

if (num ==2)
{
	return 1;
}

for (int i = 2; i < num; ++i){
	result = num/i;
	resto = num%i;

	//printf("%d dividido en %d es %d y su resto es: %d \n", num, i, result, resto);

	if (result<i && resto != 0)
	{
		resp = 1; //primo
		return resp;
	}
	else if (resto == 0)
	{
		resp = 0; //no primo
		return resp;
	}

}}

int restriccion1(int A, int B, int list[]){
int par=0;
if(A !=0){
	for (int i = 0; i < 5; ++i){
			if(i+1 != 6){
			int res = list[i]+list[i+1];
				if(res==B){
					par++;
				}}
		}
}
//printf("Cantidad de pares es %d\n", par);
if(par == A){
		return 1; //valido
}
else{ return 0;}
}

int restriccion2(int C, int list[]){
	int count;
	for (int i = 0; i < 5; ++i)
	{
		if(espar(list[i])==0){
			count++;
		}
	}
if (count >= C)
{
	return 1; //valida
}
else{return 0;}
}

int restriccion3(int D, int list[]){
	int count = 0;
	for (int i = 0; i < 5; ++i)
	{ //printf("en valor en %d es %d\n",i, list[i]);
		if(primo(list[i])==1){
			count++;
		}
	}
 //printf("el contador es %d\n", count);
if( count == D)
	return 1; //válida
else{return 0; //no valida
}
}

int restriccion4(int E, int list[]){
	int pares;
	for (int i = 0; i < 5; ++i)
	{
		int res = list[i+1]-1;
 //printf("el numero en %d y el siguiente menos 1 es %d\n",list[i], res); 
		if (list[i]==res)
		{
			pares++;
		}
	}

if(pares == E){
	return 1;}
else{return 0;}
}

void liberarMemoria (int ** matriz, int filas) {
    int i;
    for(i = 0; i < filas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main (){
int resp;
do{
	int A;
	int B;
	int C;
	int D;
	int E;

	printf("Ingrese valor de A\n");
	scanf("%d",&A);

	printf("Ingrese valor de B\n");
	scanf("%d",&B);

	printf("Ingrese valor de C\n");
	scanf("%d",&C);

	printf("Ingrese valor de D\n");
	scanf("%d",&D);

	printf("Ingrese valor de E\n");
	scanf("%d",&E);

	int *sol;

	int count = 0;

	int **lista = (int**)malloc(sizeof(int*)*100000);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				for (int m = 0; m < 10; ++m)
				{
					for (int n = 0; n < 10; ++n)
					{

						sol = (int *)malloc(sizeof(int)*5);
						sol[0] = i;
						sol[1] = j;
						sol[2] = k;
						sol[3] = m;
						sol[4] = n;
						if(restriccion1(A, B, sol)==1){
							//printf("Restriccion 2 es %d\n", restriccion2(C, sol));
							if(restriccion2(C, sol)==1){
								if(restriccion3(D, sol)==1){
									//printf("Restriccion 4 es %d\n", restriccion4(E, sol));
									if(restriccion4(E, sol)==1){
						printf("Una posible solucion es %d %d %d %d %d\n", sol[0], sol[1], sol[2], sol[3], sol[4]);
						printf("Restriccion 1 es %d\n", restriccion1(A, B, sol));
						printf("Restriccion 2 es %d\n", restriccion2(C, sol));
						printf("Restriccion 3 es %d\n", restriccion3(D, sol));
						printf("Restriccion 4 es %d\n", restriccion4(E, sol));
						//printf("EL contador es %d\n", count);
							lista[count] = sol;
							count++;}}}}

					}
				}
			}
		}
	}


//Hay 'A' par de números consecutivos que suman B
//Al menos C son pares
//Hay exactamente D números primos
//Hay E pares de numeros seguidos en la secuencia que son son consecutivos


printf("El CONTADOR es %d \n \n", count);
if(count != 0){
	printf("\n Hay A=%d numeros seguidos que suman B=%d\n", A, B);
	printf("Al menos C=%d numeros son pares\n", C);
	printf("Hay exactamente D=%d numeros primos\n", D);
	printf("Hay E=%d pares de numeros seguidos en la secuencia que son consecutivos\n", E);

	printf("La respuesta de restriccion4 es %d   ////0 no valida 1 si valida///\n", restriccion4(E, lista[(count/2)+1]));


	if (espar(count)==0){
	printf("El numero %d divido en dos mas 1 %d\n", count, (count/2)+1);
	printf("La solucion es %d %d %d %d %d\n", lista[(count/2)-1][0], lista[(count/2)-1][1], lista[(count/2)-1][2], lista[(count/2)-1][3], lista[(count/2)-1][4]);}
	else{
	printf("El numero %d divido en dos mas 1 %d\n", count, (count/2)+1);
	printf("La solucion es %d %d %d %d %d\n", lista[(count/2)+1][0], lista[(count/2)+1][1], lista[(count/2)+1][2], lista[(count/2)+1][3], lista[(count/2)+1][4]);	
	}
}
else{
	printf("No hay solucion\n");}

	liberarMemoria(lista, 100000);

/*
	printf("\n------------------------------------\n");
	printf("\n------------------------------------\n");
	int list[5];
	list[0]=9;
	list[1]=9;
	list[2]=7;
	list[3]=8;
	list[4]=1;
	int resp = restriccion1(A,B,list);
	if(resp == 0){
	printf("invalida\n");}
	else{
		printf("valida\n");}*/
printf("Desea intentar nuevamente?\n");
scanf("%d",&resp);

}while(resp==0);
	return 0;
}
