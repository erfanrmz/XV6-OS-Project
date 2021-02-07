#include "types.h"
#include "stat.h"
#include "user.h"
// #include "time.h"

int main()
{
    // clock_t begin = clock();
    int cbtAVG = 0,tatAVG = 0,wtAVG = 0;
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
        int cbt,tat,wt;
        // int pid[10];
        for (int i = 0 ; i < 30 ; i++)
        {
            pidS[i] = wait2(&cbt,&tat,&wt);
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
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG/30);
        printf(1,"Turn around Time AVG: %d\n",tatAVG/30);
        printf(1,"waiting Time AVG: %d\n",wtAVG/30);
    }

    while (wait() != -1){}
    sleep(1);




    exit();
}