#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int buffer=0;


void*hiloB() {

	while (1) {
		if (buffer!=0) {
			if (buffer<0) {
				pthread_exit(NULL);
			} //end if
			else {
				buffer=buffer*buffer;
				printf("El cuadrado del numero es: %i",buffer);
				buffer=0;
			
			} //end else
		} //end if
		
	} 
	
} 




int main () {
	pthread_t hiloB;
	int B = pthread_create(&hiloB,NULL,hiloB,NULL);
     
     while(1){
     
     	if (buffer == 0){
     		
     		printf("Escriba un numero: ");
     		scanf("%i",&buffer);
     		
     	}
     
     }
  
    return 0;
} //end main
