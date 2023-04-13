#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int signum) 
{		
		if (signum == SIGALRM){
		
		}
		
		
		if (signum == SIGUSR1){
		printf("Señal 1 recibida\n");
		}
		
		if (signum == SIGUSR2){
		printf("Señal 2 recibida\n");
		}
		


	}
	
	
	
	void signal_handler2(int signum) 
{		
		if (signum == SIGALRM){
		kill(pidP,SIGKILL);
		kill(pidR,SIGKILL);
		kill(pidM, SIGUSR1);
		}

	}



	int main() 
	{
        pid_t pidQ, pidV, pidR, pidP, pidM;
        int status;
        
        pidM=fork();
        
        if (pidM == 0){
			signal(SIGUSR1, signal_handler);
			signal(SIGUSR2, signal_handler);
				 
			pidQ = fork(); 
				
				    if (pidQ == 0) 
				    {	
					signal(SIGALRM,signal_handler);
				    	alarm(4);
				    	pause();
				    	kill(pidM, SIGUSR2);
					return 0;
				    }	
				    
				    	   
				pidV = fork();
				
				    if (pidV == 0) 
				    {
					pidR = fork();
						if (pidR == 0){
						signal(SIGALRM,signal_handler2);
						alarm(8);
						while (1){
						printf("MI id es: &i",getpid());
							
						} 
						
							pidP = fork();
							if (pidP == 0){
							
							while (1){
							printf("MI id es: &i",getpid());
							return 0;
								} 
							} 
						} 
						
					kill
				    } 

			    waitpid(pidQ, &status, 0);
			    waitpid(pidV, &status, 0);       
			    return 0;
		} 
}
