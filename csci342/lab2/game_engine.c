#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main() {
	int status;
        pid_t pid;
        pid_t retval;
	//j is used for storing id's in an array
	int j = 0;
	char buffer[16];
	//arr is used to store pids
	int arr[10];
	//overall size of the array
	int size = 0;
        for(;;) {
		//all choices are rest to 0
		int i = 0;
		int choice = 0;
		int counter = 0;
        	int input = 0;
		//resets the buffer to 0 with a max of 16 chracters
		memset(buffer, '\0', 16);
		memset(buffer, '\0', 16);
                printf("1: spawn player \n");
                printf("2: injury player \n");
                printf("3: heal player \n");
                printf("4: List player \n");
                printf("5: quit \n");
		//same as scanf but much cleaner
		fgets(buffer,16, stdin); 
		//converts ascii to int
		input = atoi(buffer);			

                switch(input)
                {
                        case 1:
                                if((retval = fork()) == 0)
                                {
					
                                        char *args[]={"player",NULL};
                                        execv("./player",args);
                                        exit(1);
                                }
                                printf("player spawend\n");
					size++;
					//loops through the array placing each id
					//in next open elment
					while(j < size){
						
						arr[j] = retval;
						printf("player id: %d\n", arr[j]);
						j++;
					}
                        	break;
                        case 2:
				//the counter is used to count the id's
				//in the array speificying which id is in what elm
				//while loops loops through array printing each id and health
				while(i < size){
				printf("options to select: %d\n",counter);
				kill(arr[i],SIGINT);
				i++;
				counter++;
				}
				printf("what player would you like to injury \n");
				fgets(buffer,16, stdin);
				choice = atoi(buffer);			
				kill(arr[choice],SIGUSR1);
				choice = 0;
				counter = 0;
                        	break;
                        case 3:
				while(i < size){
				printf("options to select: %d\n",counter);
				kill(arr[i],SIGINT);
				i++;
				counter++;
				}
				printf("what player would you like to heal \n");
				fgets(buffer,16, stdin);
				choice = atoi(buffer);			
				
				kill(arr[choice],SIGUSR2);
                        	break;
                        case 4:
				//while loops loops through array printing each id and health
				while(i < size){
				kill(arr[i],SIGINT);
				i++;
				}
                        	break;
                        case 5:
                       		exit(0);

                	default:
                        	printf("invalid input\n");
                		break;
        	}//end of switch
		//sleeps the program for one second to reprint menu
		sleep(1);
        }//end of loop
	
        return 0;

        }//end of main

	

