#include "types.h"
#include "stat.h"
#include "user.h"
// #include "time.h"

int main()
{
    // clock_t begin = clock();
    int cbtAVG = 0,tatAVG = 0,wtAVG = 0;
    int cbtAVG1 = 0,tatAVG1 = 0,wtAVG1 = 0;
    int cbtAVG2 = 0,tatAVG2 = 0,wtAVG2 = 0;
    int cbtAVG3 = 0,tatAVG3 = 0,wtAVG3 = 0;
    int cbtAVG4 = 0,tatAVG4 = 0,wtAVG4 = 0;
    int cbtAVG5 = 0,tatAVG5 = 0,wtAVG5 = 0;
    int cbtAVG6 = 0,tatAVG6 = 0,wtAVG6 = 0;
    int my_priority=3;
    int *cbtS = malloc(30 * sizeof(int));
    int *tatS = malloc(30 * sizeof(int));
    int *wtS = malloc(30 * sizeof(int));
    int *pidS = malloc(30 * sizeof(int));
    int childcount =5;
    printf(1,"main %d ->%d\n",getpid(),my_priority);
    int my_pid = getpid();
    for (int cur_prio = 6 ; cur_prio > 0 ; cur_prio--)
    {
        for(int i=0;i<childcount;i++){
            if (getpid() == my_pid){
                if(!fork()){
                    // begin = clock();
                    my_priority = cur_prio;
                    setPriority(getpid(),cur_prio);
                    
                }
            }
        }
        // if (getpid() == my_pid)
        // printf(1,"finished making :%d\n",cur_prio);
    }
    if (getpid() != my_pid){
        for (int i = 0; i < 250 ; i++)
        {
            // printf(1,"%d \n",my_priority);
            printf(1,"/%d/ : /%d/\n",getpid(),i);
        }
    }
    else{
        int cbt,tat,wt,prio;
        // int pid[10];
        for (int i = 0 ; i < 30 ; i++)
        {
            pidS[i] = wait4(&cbt,&tat,&wt,&prio);
            if(prio == 1)
            {
                cbtAVG1 += cbt;
                tatAVG1 += tat;
                wtAVG1 += wt;
            }
            if(prio == 2)
            {
                cbtAVG2 += cbt;
                tatAVG2 += tat;
                wtAVG2 += wt;
            }
            if(prio == 3)
            {
                cbtAVG3 += cbt;
                tatAVG3 += tat;
                wtAVG3 += wt;
            }
            if(prio == 4)
            {
                cbtAVG4 += cbt;
                tatAVG4 += tat;
                wtAVG4 += wt;
            }
            if(prio == 5)
            {
                cbtAVG5 += cbt;
                tatAVG5 += tat;
                wtAVG5 += wt;
            }
            if(prio == 6)
            {
                cbtAVG6 += cbt;
                tatAVG6 += tat;
                wtAVG6 += wt;
            }
            cbtS[i] = cbt;
            tatS[i] = tat;
            wtS[i]  = wt;
        }
        for (int i = 0 ; i < 30 ; i++)
        {
            printf(1,"PID: %d\n",pidS[i]);
            printf(1,"CPU burst Time: %d\n",cbtS[i]);
            printf(1,"Turn around Time: %d\n",tatS[i]);
            printf(1,"waiting Time: %d\n\n\n",wtS[i]);
            cbtAVG += cbtS[i];
            tatAVG += tatS[i];
            wtAVG  += wtS[i];

        }
        printf(1,"priority 1 AVG:\n");
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG1/5);
        printf(1,"Turn around Time AVG: %d\n",tatAVG1/5);
        printf(1,"waiting Time AVG: %d\n\n",wtAVG1/5);

        printf(1,"priority 2 AVG:\n");
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG2/5);
        printf(1,"Turn around Time AVG: %d\n",tatAVG2/5);
        printf(1,"waiting Time AVG: %d\n\n",wtAVG2/5);

        printf(1,"priority 3 AVG:\n");
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG3/5);
        printf(1,"Turn around Time AVG: %d\n",tatAVG3/5);
        printf(1,"waiting Time AVG: %d\n\n",wtAVG3/5);

        printf(1,"priority 4 AVG:\n");
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG4/5);
        printf(1,"Turn around Time AVG: %d\n",tatAVG4/5);
        printf(1,"waiting Time AVG: %d\n\n",wtAVG4/5);

        printf(1,"priority 5 AVG:\n");
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG5/5);
        printf(1,"Turn around Time AVG: %d\n",tatAVG5/5);
        printf(1,"waiting Time AVG: %d\n\n",wtAVG5/5);

        printf(1,"priority 6 AVG:\n");
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG6/5);
        printf(1,"Turn around Time AVG: %d\n",tatAVG6/5);
        printf(1,"waiting Time AVG: %d\n\n",wtAVG6/5);


        printf(1,"\nCPU burst Time AVG: %d\n",cbtAVG/30);
        printf(1,"Turn around Time AVG: %d\n",tatAVG/30);
        printf(1,"waiting Time AVG: %d\n",wtAVG/30);
    }

    while (wait() != -1){}
    sleep(1);




    exit();
}