#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUF 1024
int main()
{
	int counter = 0;
	int fd;
	char *myfifo = "/tmp/myfifo";
	char buf[MAX_BUF];
	fd = open(myfifo, O_RDWR);

	while(read(fd, buf, MAX_BUF)){
		printf("Writer: %s\n",buf);
		counter++;
		if(counter == 10) break;
	}
	close(fd);
	return 0;
}