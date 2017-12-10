#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	int i = 0, fd;
	char input[50];
	char* myfifo = "/tmp/myfifo";
	mkfifo(myfifo, 0666);
	fd = open(myfifo, O_WRONLY);
	while(i<10){
		fgets(input, 51, stdin);
		write(fd, input, sizeof(input));
		i++;
	}
	close(fd);
	unlink(myfifo);
	return 0;
}