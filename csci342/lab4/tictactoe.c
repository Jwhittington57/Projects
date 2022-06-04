#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>


/*must figure out where dashs are printing in array
 *limit the row and col selections to dashes only
 *X and O are being placed plaaces I cannot see them
	techinclly the board is being filled up
 */

#define ROWS 3
#define COLS 7
#define NUMTHRDS 2

void printboard(char*[ROWS][COLS]);
bool gameOver(char*[][COLS]);
void printResults();

void* player1(void*);
void* player2(void*);
int main(int argc, char** argv) {
	   
	struct threadInfo{
                char* board [ROWS][COLS];
                int len;
                int curPlayer;
                bool gameOver;
        };
	
	struct threadInfo info;
		info.curPlayer =1;
		info.gameOver = false;
		
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
                if (gameOver(info.board)) {
                        printResults();
                        return 0;
                }
        }
}
        void* player1(void* arg) {
		printf("player1\n");
		
                struct threadInfo{
                        char* board[ROWS][COLS];
                        int len;
                        int curPlayer;
                        bool gameOver;
                };
		
		struct threadInfo* info = (struct threadInfo*) arg;
	
		int lower = -1; 
		int upper = 1;
		int row = (rand() % (upper - lower + 1));
		int col = (rand() %7)*2 +1;
		while(!info->gameOver)
		{
			while(info->curPlayer!=1)
			{
				//sleep(2);
			}
		while(info ->board[row][col] !=(char*) '-')
		{
			 row = (rand() % (upper - lower + 1));
			 col = (rand() % 7)*2 +1;
		}	
		
		if(info ->board[row][col] =(char*) '-')
		{
			info ->board[row][col] =(char*) 'X';
		}
			info->curPlayer = 2;
	}
}	


        void* player2(void* arg) {
		printf("player2\n");
		
                struct threadInfo{
                        char* board[ROWS][COLS];
                        int len;
                        int curPlayer;
                        bool gameOver;
                };
		
		struct threadInfo* info = (struct threadInfo*) arg;
		
		int lower = -1; 
		int upper = 1;
		int row;
		int col;
		while(!info->gameOver)
		{
			while(info->curPlayer!=2)
			{
				//sleep(2);
			}
		
		while(info ->board[row][col] !=(char*) '-')
		{
			 row = (rand() % (upper - lower + 1)) +lower;
			col = (rand() %5)*2 +1;
		}
		
		if(info ->board[row][col] =(char*) '-')
		{
			info->board[row][col] =(char*) 'O';
		}
		info->curPlayer = 1;
	}
}
void printboard(char* board[ROWS][COLS]) {
	int row;
	int col;
	for(row = 0; row < 3; row++) {
		for(col = 0;col < 7; col = col + 2) {
			board[row][col] = (char*)'|';
			
        	}
	}
	
	for(row = 0; row < 3; row++) {
		for(col = 1;col < 7; col = col + 2) {
		
			board[row][col] = (char*)'-';
		}
	}
	for(row = 0; row < 3; row++) {
		for(col = 0;col < 7; col++) {
		printf("%c", board[row][col] );
		}
		printf("\n");
	}
		printf("\n");
}	

bool gameOver(char* board[][COLS]) {
	int i;
	int j;
	for(i = 0; i < 3; i++) {
		for(j = 0;j < 7; j++ ) {
			if(board[i][j] !=(char*) '-')
			{
					
			printboard(board);
			}
		}
	}
	for(i = 0; i < 3; i++) {
		for(j = 0;j < 7; j++ ) {
			if(board[i][j] =(char*) '-')
			{
				return false;
			}
		}
	}
	return true;
}

void printResults() {

}


