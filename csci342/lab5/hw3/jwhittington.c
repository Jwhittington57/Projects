/*diator.c
 *
 *  * Joshua whittington
 *   ****************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sem_helper.h"
#include "sem_helper.c"
int main(int argc, char* argv[])
{
        int semid;
        int gladiator_id;
        int arena_len;
        int index;
        int pos;
	int player;
	int front;
	int back;
        if (argc != 4) 
	{
                printf("usage: %s semid gladiator_id arena_len\n", argv[0]);
                return 0;
        }

        semid = atoi(argv[1]);
        gladiator_id = atoi(argv[2]);
        arena_len = atoi(argv[3]);

        /* Battle */
	player = gladiator_id;
 	for(index = 0; index < arena_len * arena_len;index++)
        {
                if(gladiator_id = getSemaphore(semid, index))
                {
                        pos = index;
			back = pos;
			front = pos;
		}
		if(gladiator_id == player)
		{
			while(1)
			{
				if(semid != player)
				{
					if(front >= arena_len *arena_len - 1)
						{
						while(1)
						{	
							--back;
							setSemaphore(semid,back,gladiator_id);
							sleep(1);
							if(front >= arena_len *arena_len - 1 && back == 0)
								{
									printf("mission succseful\n");
									exit(0);
								}
						}
						}	
					front++;
					setSemaphore(semid,front,gladiator_id);
					sleep(1);
				}
				if (back == 0 && front == 0)
				{
					printf("mission failed we'll get em next time\n");
					exit(0);
				}
				 
							if(front >= arena_len *arena_len - 1 && back == 0)
								{
									printf("mission succseful\n");
									exit(0);
								}
			}
                
		}
		
	}
	return 0;
}

//  END OF FILE
