#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int childpid=-1;
void create_process(char *jar_path)
{
	int i;
        childpid = fork();
	if (childpid == 0){
		//child process
                
		char * execv_str[] = {"java", "-jar",jar_path,NULL};
		if (execv("/usr/local/openjdk-8/bin/java",execv_str) <0 ){
			perror("error on exec");
			exit(0);
		}
	}else{
		//parent process
		wait(&childpid);
		printf("execv done\n\n");
    }
}

void stop_java()
{
    printf("capture a SIGALRM signal, child id =%d\n",childpid);
    if(childpid !=-1) {
    	kill(childpid, 9);
        childpid = -1;
    }
}
void start_java()
{
    //char* path="./amazon-vendor-service/amazon-vendor-service/fw-amazon-api/target/fw-amazon-api-1.0.0.jar";
    char* path="./amazon-vendor-service/amazon-vendor-service/fw-amazon-api/target/fw-amazon-api-1.0.0.jar";
    printf("jar_path is %s\n",path);
    create_process(path);
}

int main(int argc, char* argv[])
{
    signal(10,start_java);
    signal(12,stop_java);

    while(1) {sleep(5);printf("heart beat...\n");}

} 
