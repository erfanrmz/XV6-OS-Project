#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
     int my_priority=3;
    
    int childcount =5;
    printf(1,"main %d ->%d\n",getpid(),my_priority);
    int my_pid = getpid();
    for (int cur_prio = 6 ; cur_prio > 0 ; cur_prio--)
    {
        for(int i=0;i<childcount;i++){
            if (getpid() == my_pid){
                if(!fork()){
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