#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>




#define size 3

void printboard(char*[][size]);
bool gameOver(char*[][size], int);
void printResults();

void* player1(void*);
void* player2(void*);
int main(int argc, char** argv) {
	   
	struct threadInfo{
                char* board [size][size];
                int len;
                int curPlayer;
                bool gameOver;
        };
	
	struct threadInfo info;
	        int row;
		int col;
		board[row][col];	

	//create a way to place X and O using rand gen
	
        printboard(info.board);

        pthread_t id1;
        pthread_t id2;

        int err = pthread_create(&id1, NULL, player1, &info);

        if(err != 0) {
                printf("Error creating pthread\n");
                return 1;
        }

        if (pthread_detach(id1) !=0 ) {
                printf("Error detaching player1'\n");
                return 1;
        }
                err = pthread_create(&id2, NULL, player2, &info);

        if(err !=0) {
                printf("Error creating pthread\n");
                return 1;
        }

        while(1) {
                if (gameOver(info.board, info.len)) {
                        printResults();
                        return 0;
                }
        }
}
        void* player1(void* arg) {
		struct threadInfo{
                	char* board[size][size];
                	int len;
                	int curPlayer;
                	bool gameOver;
        	};
                printf("player1\n");

                struct threadInfo* info = (struct threadInfo*) arg;
                while(!info->gameOver) {
                        while(info->curPlayer != '1') {
                                sleep(2);
                        }


                        info->curPlayer =2;
                }
}
       void* player2(void* arg) {
                struct threadInfo{
                        char* board[size][size];
                        int len;
                        int curPlayer;
                        bool gameOver;
                };
                printf("player2\n");

                struct threadInfo* info = (struct threadInfo*) arg;
}


void printboard(char* board[][size]) {
        int i = 0;
	int j = 0;
	char x = 'x';
	for(;i < 3; i++) {
        printf("[");//use %c
		for(;j < 3; j++) {
                	printf("%c ", board[i][j]);
        	}
        	printf("%c]\n", board[i][j]);
		//printf("\n");
	}
}	

bool gameOver(char* board[][size], int len) {

}

void printResults() {
}
