#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//cambiar de valor un espacio de la matriz --->>> listo
//imprimir matriz actualizada y bien
//armar algoritmo de espacios disponibles -----> casi listo problemas con 0,0
//armar items
//armar dados ataq, def
//armar ataque entre enemigos y jugador
//armar main
//caso inicial caso final
//guardar trayecto

#define B_H "━" //BOLD HORIZONTAL
#define B_V "┃" //BOLD VERTICAL
#define B_TL "┏"//BOLD TOP LEFT
#define B_TR "┓"//BOLD TOP RIGHT
#define sup "┏━1━┳━2━┳━3━┳━4━┳━5━┳━6━┳━7━┳━8━┳━9━┓"
#define LINE "━━━━━━━━━━━━━━━━━━━━━━━━━"//LINES
#define INTER "┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫"
#define INF "┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛"
#define B_BL "┗"//BOLD BOTTOM LEFT
#define B_BR "┛"//BOLD BOTTOM RIGHT



#define BN "\n" //BACKSLASH N

//variables universales

int vida;
int pocion;
int tesoros;


//definicion de funciones

int casillaOcupada(int *n){
	if(*n == 99){
		return 99;	
	}
	else if (*n==0){				
		return 0;
		}
}

int verifiCasillas(int fil, int col, int *matriz[]){
	
	if(col<8 & fil<9){
		if(casillaOcupada(&matriz[fil-1][col])==0){
			matriz[fil-1][col]=1;}
		if(casillaOcupada(&matriz[fil-1][col+1])==0){
			matriz[fil-1][col+1]=2;}
		if(casillaOcupada(&matriz[fil][col+1])==0){
			matriz[fil][col+1]=3;}
		if(casillaOcupada(&matriz[fil+1][col+1])==0){
			matriz[fil+1][col+1]=4;}
		if(casillaOcupada(&matriz[fil+1][col])==0){
			matriz[fil+1][col]=5;}
		if(casillaOcupada(&matriz[fil+1][col-1])==0){
			matriz[fil+1][col-1]=6;}
		if(casillaOcupada(&matriz[fil][col-1])==0){
			matriz[fil][col-1]=7;}
		if(casillaOcupada(&matriz[fil-1][col-1])==0){
			matriz[fil-1][col-1]=8;}


		
	}  	

	else if(fil==9 & col>0){
		if(casillaOcupada(&matriz[fil-1][col])==0){
			matriz[fil-1][col]=1;}
		if(casillaOcupada(&matriz[fil-1][col+1])==0){
			matriz[fil-1][col+1]=2;}
		if(casillaOcupada(&matriz[fil][col+1])==0){
			matriz[fil][col+1]=3;}
		if(casillaOcupada(&matriz[fil][col-1])==0){
			matriz[fil][col-1]=7;}
		if(casillaOcupada(&matriz[fil-1][col-1])==0){
			matriz[fil-1][col-1]=8;}

	}
	
	else if(col==8 & fil>0){
		if(casillaOcupada(&matriz[fil][col-1])==0){
			matriz[fil][col-1]=1;}
		if(casillaOcupada(&matriz[fil+1][col])==0){
			matriz[fil+1][col]=5;}
		if(casillaOcupada(&matriz[fil+1][col-1])==0){
			matriz[fil+1][col-1]=6;}
		if(casillaOcupada(&matriz[fil][col-1])==0){
			matriz[fil][col-1]=7;}
		if(casillaOcupada(&matriz[fil-1][col-1])==0){
			matriz[fil-1][col-1]=8;}
	}

	else if(col == 0 & fil>0){
		if(casillaOcupada(&matriz[fil-1][col])==0){
			matriz[fil-1][col]=1;}
		if(casillaOcupada(&matriz[fil-1][col+1])==0){
			matriz[fil-1][col+1]=2;}
		if(casillaOcupada(&matriz[fil][col+1])==0){
			matriz[fil][col+1]=3;}
		if(casillaOcupada(&matriz[fil+1][col+1])==0){
			matriz[fil+1][col+1]=4;}
		if(casillaOcupada(&matriz[fil+1][col])==0){
			matriz[fil+1][col]=5;}
		
	}

	else if(fil == 0 & col>0){
		if(casillaOcupada(&matriz[fil][col+1])==0){
			matriz[fil][col+1]=3;}
		if(casillaOcupada(&matriz[fil+1][col+1])==0){
			matriz[fil+1][col+1]=4;}
		if(casillaOcupada(&matriz[fil+1][col])==0){
			matriz[fil+1][col]=5;}
		if(casillaOcupada(&matriz[fil+1][col-1])==0){
			matriz[fil+1][col-1]=6;}
		if(casillaOcupada(&matriz[fil][col-1])==0){
			matriz[fil][col-1]=7;}
	
	}

	else if(fil==9 & col ==8){
		if(casillaOcupada(&matriz[fil-1][col])==0){
			matriz[fil-1][col]=1;}		
		if(casillaOcupada(&matriz[fil][col-1])==0){
			matriz[fil][col-1]=7;}
		if(casillaOcupada(&matriz[fil-1][col-1])==0){
			matriz[fil-1][col-1]=8;}

	}
	

	else if(fil==0 & col==0){
		if(casillaOcupada(&matriz[0][1])==0){
			printf("hola1" BN);
			matriz[0][1]=3;}
		if(casillaOcupada(&matriz[1][1])==0){
			printf("hola2" BN);
			matriz[1][1]=4;}
		if(casillaOcupada(&matriz[1][0])==0){
			matriz[1][0]=5;}
	}


return 0;}


int pasa(){
	int opcion;	
	do{
		printf("¿Qué desea hacer ahora?" BN);
		printf("Tomar poción: Opción 1" BN);
		printf("Intercambiar tesoros: Opción 2" BN);
		printf("Continuar: Opción 3" BN);
		scanf("%d",&opcion);
	}while(opcion > 3);
	return opcion;
}

int jugada(int a, int b){
	pasa();
	return 0;
}

int final(){
	return 0;}

/**int findInCasilla(int lvl, int nDado){
	switch(lvl){
		case 1:
			if(lvl==1)

			else if(lvl ==2)

			else if(lvl >= 3 & <=5)

			else if(lvl ==6)
		break;
		case 2:
			if(lvl==1)

			else if(lvl ==2)

			else if(lvl >=3 & <=5)

			else if(lvl ==6)
		break;
		case 3:
			if(lvl==1)

			else if(lvl ==2)

			else if(lvl ==3)

			else if(lvl ==4)

			else if(lvl ==5)

			else if(lvl ==6)
		break;
		case 4:
			if(lvl==1)

			else if(lvl ==2)

			else if(lvl ==3)

			else if(lvl ==4)

			else if(lvl ==5)

			else if(lvl ==6)
		break;
		case 5:
			if(lvl==1)

			else if(lvl ==2)

			else if(lvl ==3)

			else if(lvl ==4)

			else if(lvl ==5)

			else if(lvl ==6)
		break;
		case 6:
			if(lvl==1)

			else if(lvl ==2)

			else if(lvl ==3)

			else if(lvl ==4)

			else if(lvl ==5)

			else if(lvl ==6)
		break;
		case 7:
			if(lvl==1)

			else if(lvl ==2)

			else if(lvl ==3)

			else if(lvl ==4)

			else if(lvl ==5)

			else if(lvl ==6)
		break;
		case 8:
			if(lvl==1)

			else if(lvl ==2)

			else if(lvl ==3)

			else if(lvl ==4)

			else if(lvl ==5)

			else if(lvl ==6)
		break;
		case 9:
			if(lvl==1)

			else if(lvl ==2)

			else if(lvl ==3)

			else if(lvl ==4)

			else if(lvl ==5)

			else if(lvl ==6)
		break;
		case 10:
			if(lvl==1)

			else if(lvl ==2)

			else if(lvl ==3)

			else if(lvl ==4)

			else if(lvl ==5)

			else if(lvl ==6)
		break;
		case 11:

			break;


}	
 
}**/



int tesoro(int a, int b){ 
	return 0;
	}

int dado(){	
  int n;
  srand (time(NULL));
  n = 1 + rand()%7;
  return n; 
}

int enemigo(int tipo, int ataq, int def){
	return 0;}

int casillaInfo(int dadosDef, int dadosAtaq, int pocio, int teso, int vida, int items){
  
  printf(B_TL LINE B_TR"\n");
  printf(B_V "Cantidad de pociones: %d  " B_V BN, pocio);
  printf(B_V "Puntos de vida: %d        " B_V BN, vida);
  printf(B_V "Dados de ataque: %d       " B_V BN, dadosAtaq); 
  printf(B_V "Dados de defensa: %d      " B_V BN, dadosDef);
  printf(B_V "Cantidad de Tesoros: %d   " B_V BN, teso); 
  //printf(B_V "Items acumulados: " B_V BN , items);
  printf(B_BL LINE B_BR"\n");
  return 0;
}
	
int tablero(int *arreglo[]){
  
  printf(sup BN B_V);
  
for(int fil = 0; fil<10; fil++){
  
  for(int col=0; col<9; col++){
  	if(arreglo[fil][col] == 0)
		{printf("   " B_V);}
  	else{printf(" %d " B_V, arreglo[fil][col]);}
	}	
  if(fil<9){
  	printf(BN INTER BN B_V);}
  else{
	printf(BN INF BN);}
  }

return 0;

}


int ingresarJugada(){
  int FilaJugada;
  int ColumJugada;

  printf("Ingrese fila del bloque" BN);
  scanf("%d",&FilaJugada);
  printf("Ingresa columna del bloque" BN);
  scanf("%d",&ColumJugada);
  return 0;
}


int main(){
 setlocale(LC_ALL, "");

 int ** matriz = (int **) malloc(sizeof(int*)*9);
 for(int i=0; i<10; i++){
 matriz[i] = (int *) malloc(sizeof(int)*9);} //[fil=max8][col=max=9]



//Probando

verifiCasillas(0,0, matriz);

tablero(matriz);



return 0;}
/*
Turno
Primero elegir posición
Tirar dado de casilla (nunca se acaba hasta que se muera)
Qué se encuentra en el dado
El dado puede contener: 
tesoro, se suma (cont: tesoros)
poción, se suma (cont: pociones)
Enemigo, pelear (estructura pelea dados)
Espacio, no pasa nada

Además se puede beber pociones (tirar la menu) (si hay barra completa, error)
cambiar tesoros por items 

Elegir siguiente casilla.


Pociones:

Si no tiene no mostrar (if)
Debe aparecer opción "Beber o continuar" (prinf, scanf, if)


Dados:

Existen

Dados de casilla:
Cambia por nivel (switch)
Se debe mostrar lo que aparece de ese dado por casilla. Número dado = "Encontraste una poción (u otro)"

Dados de Ataque (Estructuras)

Dados de Defensa (Estructuras)

Sólo uno de cada uno al principio


-Tesoros:
Si no tiene no mostrar opción de intercambiar tesoros (if not)

Si es que tiene:
Mostrar tabla con cada uno de los tesoros, costos
inhabilitar si es que no tiene disponible para uno (if/switch)



-Se debe mostrar por pantalla
Tablero
Cantidad de:
Dados de ataque
Dados de Defensa
Puntos de Salud
Tesoros Recolectados
Pociones
Ítems Equipados


Jefes

Cambian por nivel (switch)

Jefe final
9 dados de ataque
9 dados de defensa

 */
