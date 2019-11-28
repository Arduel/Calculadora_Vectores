#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define MAX 3

void Menu(int &a);
void Imp(int *ptr_v, char l);
void Imp(float *ptr_v, char l);
void Leer(int *ptr_v, char l);
void Suma(int *ptr_a, int *ptr_b, int *ptr_c);
void Resta(int *ptr_a, int *ptr_b, int *ptr_c);
void pPunto(int *ptr_a, int *ptr_b, int &r);
void pEsc(int *ptr_a, int *ptr_b, int *ptr_c, int &r);
void Norma(int *ptr_a, float &r);
void vUni(int *ptr_a, float *ptr_c);
void det(int *ptr_a, int *ptr_b, int val, int &ret);
void Rep(char &re);
void cleV(int *ptr_n);
void cleV(float *ptr_n);
void cle(int &ptr_n);
void cle(float &ptr_n);
 
int main(void){
	int A[MAX], B[MAX], C[MAX], *pA, *pB, *pC, pR, opt, cas = 7;
 	float pr, *pc, CF[MAX];
 	char rep;
	pA = &A[0];
	pB = &B[0];
	pC = &C[0];
 	pc = &CF[0];
 
 	do{   
        rep = ' ';
        
	    do{  
		Menu(opt);
	        if(opt < 1 || opt > cas){
	            printf("\n*** Opcion incorrecta, intente de nuevo ***\n");
	            cle(opt);
	        }
	    }while(opt < 1 || opt > cas);
    
	    if(opt != cas){
	        switch(opt){
		        case 1:
			        printf("\n\n---SUMA DE VECTORES-----------------------\n");
			        Leer(pA, 'A');
			        Leer(pB, 'B');
			        Suma(pA, pB, pC);
					printf("\n\n---RESULTADO------------------------------\n");
			        Imp(pC, 'R');
		        break;
		        
		        case 2:
			        printf("\n\n---RESTA DE VECTORES----------------------\n");
			        Leer(pA, 'A');
			        Leer(pB, 'B');
			        Resta(pA, pB, pC);
			 		printf("\n\n---RESULTADO------------------------------\n");
			        Imp(pC, 'R');
		        break;
		        
		        case 3:
			        printf("\n\n---PRODUCTO PUNTO-------------------------\n");
			        Leer(pA, 'A');
			        Leer(pB, 'B');
			        pPunto(pA, pB, pR);
			        printf("\nEl producto punto de los vectores A y B es: %d", pR);
		        break;
		        
		        case 4:
			        printf("\n\n---PRODUCTO ESCALAR-----------------------\n");
			        Leer(pA, 'A');
			        Leer(pB, 'B');
			        pEsc(pA, pB, pC, pR);
			        printf("\nEl producto escalar de los vectores A y B es:\n");
			        Imp(pC, 'R');
		        break;       
		        
		        case 5:  printf("\n\n---NORMA----------------------------------\n");
			        Leer(pA, 'A');
			        Norma(pA, pr);
			        printf("\nLa norma del vector A es: %0.3f", pr);
		        break;
		     
		        case 6:
			        printf("\n\n---VECTOR UNITARIO------------------------\n");
			        Leer(pA, 'A');
			        vUni(pA, pc);               
					printf("\n\n---RESULTADO------------------------------\n");               
					Imp(pc, 'R');
		        break;
		    }    
	    Rep(rep);
	            if(rep == 's' || rep == 'S'){
	                cleV(pA);
	                cleV(pB);
	                cleV(pC);
	                cleV(pc);
	                cle(pR);
	                cle(pr);
	                printf("\n\n");
	            }
	    }
	}while(rep == 's' || rep == 'S');
}

void Menu(int &a){
	printf("----------CALCULADORA DE VECTORES------------\n");
	printf("1. Suma\n");
	printf("2. Resta\n");
	printf("3. Producto punto\n");
	printf("4. Producto escalar\n");
	printf("5. Norma\n");
	printf("6. Vector unitario\n");
	printf("7. Salir\n");
	printf("Seleccione una opcion: ");
	scanf("%d", &a);
}

void Imp(int *ptr_v, char l){
    for(int i = 0; i<MAX; i++){
        printf("\nVec_%c[%d]: %d\n", l, i, *(ptr_v + i));
    }
}

void Imp(float *ptr_v, char l){
    for(int i = 0; i<MAX; i++){
        printf("\nVec_%c[%d]: %.3f\n", l, i, *(ptr_v + i));
    }
}

void Leer(int *ptr_v, char l){
	 printf("\n------------------------------------------\n");
	 printf("Leyendo valores del vector %c: \n",l);
		 for(int i = 0; i<MAX ; i++){
	    	printf("\nIntroduce el valor de Vec_%c[%d]: ",l ,i);
		   	scanf("%d",ptr_v + i);
		 }	
}

void Suma(int *ptr_a, int *ptr_b, int*ptr_c){
	for(int i = 0; i<MAX; i++){
		*(ptr_c + i) = *(ptr_a + i) + *(ptr_b + i);
	}
}

void Resta(int *ptr_a, int *ptr_b, int*ptr_c){
	for(int i = 0; i<MAX; i++){
		*(ptr_c + i) = *(ptr_a + i) - *(ptr_b + i);
	}
}

void pPunto(int *ptr_a, int *ptr_b, int &r){
    for(int i = 0; i<MAX; i++){
        r += (*(ptr_a + i)) * (*(ptr_b + i));
    }
}

void pEsc(int *ptr_a, int *ptr_b, int *ptr_c, int &r){
    for(int i = 0; i<MAX; i++){
        det(ptr_a, ptr_b, i, r);
        *(ptr_c + i) = r;
    }
}

void Norma(int *ptr_a, float &r){
    r = 0;
    for(int i = 0; i<MAX; i++){
        r += pow(*(ptr_a + i),2);
    }
    r = sqrt(r);
}

void vUni(int *ptr_a, float *ptr_c){
    float pT;
    Norma(ptr_a, pT);
    for(int i = 0; i<MAX; i++){
        *(ptr_c + i) = *(ptr_a + i) / pT;
    }
}

void det(int *ptr_a, int *ptr_b, int val, int &ret){
int Mat[2][2], x = 0, y = 0;
    for(int i = 0; i<2 ; i++){
        for(int j = 0; j<MAX; j++){
            if(i == 0 && j != val){
                Mat[x][y] = *(ptr_a + j);
                y++;
                if(y >= 2){
                    x++;
                    y = 0;
                }
            }
            if(i == 1 && j != val){
                Mat[x][y] = *(ptr_b + j);
                y++;
            }
        }
    }
    
ret = ((Mat[0][0])*(Mat[1][1])) - ((Mat[0][1])*(Mat[1][0]));
}

void Rep(char &re){
    printf("\n\n    [S] [N]\nDesea hacer otra operacion: ");
    scanf("%s", &re);
}

void cleV(int *ptr_n){
    for(int i = 0; i<MAX; i++){
        *(ptr_n + i) = 0;
    }
}

void cle(int &ptr_n){
    ptr_n = 0;
}

void cleV(float *ptr_n){
    for(int i = 0; i<MAX; i++){
        *(ptr_n + i) = 0;
    }
}

void cle(float &ptr_n){
    ptr_n = 0;
}
