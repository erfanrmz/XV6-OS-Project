#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int cbt,tat,wt;
    if (fork() > 0)
    {
        wait2(&cbt,&tat,&wt);
        printf(1,"CPU burst time : %d\n",cbt);
        printf(1,"Turn around time : %d\n",tat);
        printf(1,"waiting time : %d\n",wt);
    }
    else
    {
        sleep(100);
        for (int i = 0 ; i < 100 ; i++)
        {
            printf(1,"pid:%d i:%d\n",getpid,i);
        }
    }
    
    while(wait() != -1) { }
    sleep(1);
    exit();
    
    return 0;
}