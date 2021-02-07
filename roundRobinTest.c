#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    int x = getpid();
    int cbtAVG = 0,tatAVG = 0,wtAVG = 0;
    int *cbtS = malloc(10 * sizeof(int));
    int *tatS = malloc(10 * sizeof(int));
    int *wtS = malloc(10 * sizeof(int));
    int *pidS = malloc(10 * sizeof(int));
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
        int cbt=0,tat=0,wt=0;
        // int pid[10];
        for (int i = 0 ; i < 10 ; i++)
        {
            pidS[i] = wait2(&cbt,&tat,&wt);
            cbtS[i] = cbt;
            tatS[i] = tat;
            wtS[i]  = wt;

        }
        for (int i = 0 ; i < 10 ; i++)
        {
            printf(1,"PID: %d\n",pidS[i]);
            printf(1,"CPU burst Time: %d\n",cbtS[i]);
            printf(1,"Turn around Time: %d\n",tatS[i]);
            printf(1,"waiting Time: %d\n\n\n",wtS[i]);
            cbtAVG += cbtS[i];
            tatAVG += tatS[i];
            wtAVG  += wtS[i];

        }
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG/10);
        printf(1,"Turn around Time AVG: %d\n",tatAVG/10);
        printf(1,"waiting Time AVG: %d\n",wtAVG/10);
    }
    else
    {
        for (int i = 0 ; i < 1000 ;i++)
        {
            printf(1,"pid:%d |i:%d\n",getpid(),i);
        }
    }
    while(wait() != -1) { }
    sleep(1);
    exit();
    



}