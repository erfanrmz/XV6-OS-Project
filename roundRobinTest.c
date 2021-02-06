#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int x = getpid();
    int cbtAVG = 0,tatAVG = 0,wtAVG = 0;
    for (int i = 0 ; i < 10 ; i++)
    {
        if (x == getpid())
            fork();
        else
        {
            break;
        }
        
    }
    if (x == getpid())
    {
        int cbt,tat,wt;
        // int pid[10];
        for (int i = 0 ; i < 10 ; i++)
        {
            wait2(&cbt,&tat,&wt);
            cbtAVG += cbt;
            tatAVG += tat;
            wtAVG  += wt;
        }
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG/10);
        printf(1,"Turn around Time AVG: %d\n",tatAVG/10);
        printf(1,"waiting Time AVG: %d\n",wt/10);
    }
    else
    {
        for (int i = 0 ; i < 1000 ;i++)
        {
            printf(1,"pid:%d |i:%d\n",getpid,i);
        }
    }
    while(wait() != -1) { }
    sleep(1);
    exit();
    



}