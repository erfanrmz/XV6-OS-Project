#include "types.h"
#include "stat.h"
#include "user.h"
#include "time.h"

int main()
{
    // clock_t begin = clock();
    int cbtAVG = 0,tatAVG = 0,wtAVG = 0;
    int my_priority=3;
    
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
        for (int i = 0; i < 25 ; i++)
        {
            printf(1,"%d \n",my_priority);
            //printf(1,"/%d/ \n",getpid());
        }
    }
    else{
        int cbt,tat,wt;
        // int pid[10];
        for (int i = 0 ; i < 25 ; i++)
        {
            // wait2(&cbt,&tat,&wt);
            cbtAVG += cbt;
            tatAVG += tat;
            wtAVG  += wt;
        }
        // printf(1,"CPU burst Time AVG: %d\n",cbtAVG/10);
        // printf(1,"Turn around Time AVG: %d\n",tatAVG/10);
        // printf(1,"waiting Time AVG: %d\n",wt/10);
    }
    // clock_t end = clock();
    // printf(1,"%d \n",(double)(end - begin) / CLOCKS_PER_SEC);
    // for (int i = 30; i > 0; i--)
    // {
    //     if (fork() == 0)
    //     {
    //         int child =i;

    //         setPriority(getpid(),(child/5));
    //         my_priority = (child/5);
    //         for (int j = 0; j < 25; j++)
    //         {
    //             printf(1,"%d \n",my_priority);
    //         }
    //         exit();
            
    //     }
        
    // }
    
    
    while (wait() != -1){}
    sleep(1);
    
    
    
    
    exit();
}