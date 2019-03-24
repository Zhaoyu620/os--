#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    pid_t p1,p2,p3,p4,p5;
    while((p1=fork()) == -1)
	sleep(1);
    if(!p1)
    {
        while((p2=fork()) == -1)
		sleep(1);
        if(!p2)
        {
            while ((p4=fork())==-1);
            if (!p4)
            {
                while(1)
                {
                    printf("p4: pid %d, ppid %d\n",getpid(),getppid());
                    sleep(1);
                }
            }
            else
            {
                while ((p5=fork())==-1)
			sleep(1);

                if (!p5)
                {
                    while(1)
                    {
                        printf("p5: pid %d, ppid %d\n",getpid(),getppid());
                        sleep(1);
                    }

                }

            }

            while(1)
            {
                printf("p2: pid %d,ppid %d\n",getpid(),getppid());
                sleep(1);
		exit(0);
            }
	    while(1)
        {
            printf("p1: pid %d, ppid %d\n",getpid(),getppid());
            sleep(0.1);
        }
        }
        else
        {
            sleep(1);
        }

        
    }
    else
    {
        while ((p3=fork())==-1)
			sleep(1);

                if (!p3)
                {
                    while(1)
                    {
                        printf("p3:pid %d, ppid %d.\n",getpid(),getppid());
                        sleep(1);
                    }

                }
    }

    return 0;
}
