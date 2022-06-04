#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int hp = 1; //player health
//decrease player health
void decr_hp(int sig)
        {
                hp--;
		//if helath is 0 or somehow lower than
		//0 the pid is terminated
                if(hp <= 0)
                {
                        int id = getpid();
                        printf("enemy, %d, dead\n", id);
			exit(1);
                }
                printf("health lost. current health: %d\n", hp);
        }
	//incrase health
void incr_hp(int sig)
        {
                hp++;
		//if health is already 5 than no more health can be added
                if(hp >= 5)
                {
                        printf("health is at max\n");
			//exit(1);
                }
                printf("health increased, health is currently: %d\n", hp);
        }
	// prints out the id and current health
void print_hp(int sig)
        {
                int id = getpid();
                printf("process id: %d\n", id);
                printf("current health: %d\n", hp);

        }



int main() {
	//registers the handler and checks for errors
	if (signal(SIGUSR1, decr_hp) == SIG_ERR) {
              	printf("signal error\n");
        }

        if(signal(SIGUSR2, incr_hp) == SIG_ERR) {
               	printf("signal error\n");
        }

        if(signal(SIGINT, print_hp) == SIG_ERR) {
               	printf("signal error\n");
        }

	//runs the playerc in an infite loop
	//pauses indfintely until a signal from
	//game.c is recived
	for(;;) {
                pause();
	}
        return 0;

}


