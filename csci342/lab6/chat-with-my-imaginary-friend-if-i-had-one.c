#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdbool.h>

void recv()
{
size_t pagesize = getpagesize();
	int i;
	int fd = open("./chatlog.txt", O_RDONLY, S_IRUSR | S_IWUSR);
	char *chatlog = mmap(0,pagesize,PROT_READ, MAP_PRIVATE, fd,0);
	for(i = 0; i < pagesize; i++)
		{
					
			printf("%c",chatlog[i]);
		}
	printf("\n");
	munmap(chatlog, pagesize);
	close(fd);
		
}

void reply(char *m)
{
	//size_t pagesize = getpagesize();

	const char *text =m;
	size_t textsize = strlen(text) + 1;
	int fd = open("chatlog.txt", O_RDWR | O_CREAT, (mode_t)0600);
	lseek(fd, textsize-1, SEEK_SET);
	write(fd, "", 1);
	char *map = mmap(0, textsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	memcpy(map, text, strlen(text));
	msync(map, textsize, MS_SYNC);
	munmap(map, textsize);

}

void emp()
{
size_t pagesize = getpagesize();
	int i;
	int fd = open("./chatlog.txt", O_RDWR, S_IRUSR | S_IWUSR);
	char *chatlog = mmap(NULL,pagesize,PROT_READ |PROT_WRITE, MAP_SHARED, fd,0);
	for(i = 0; i < pagesize; i++)
		{
			chatlog[i] = 0;	
			printf("%c",chatlog[i]);
		}
	printf("\n");
	munmap(chatlog, pagesize);
	close(fd);
}		
int main()
{
	
	int friend = 1;
	char m[20];
	while(1)
	{
		switch(friend)
		{
			case 1:
				printf("you say:\n");
				scanf("%19s",&m);
				reply(m);
				friend = 2;
				break;
			case 2:	
				printf("friend says:\n");
				scanf("%19s",&m);
				reply(m);
				friend = 1;
				break;
		}
		printf("\n");
		printf("chat log: ");
		recv();
		emp();
		sleep(1);
	}	
}
