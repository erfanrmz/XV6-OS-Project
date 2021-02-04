#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    
    int childcount =2;
    int my_pid = getpid();
    for (int cur_prio = 3 ; cur_prio > 0 ; cur_prio--)
    {
        for(int i=0;i<childcount;i++){
            if (getpid() == my_pid){
                if(fork()){
                    setPriority(cur_prio);
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf(1,"%d->%d \n",getpid(),i);
        // safePrint(getpid(),i);
    }
    // for (int i = 0; i < 20; i++)
    // {
    //     if (fork() == 0)
    //     {
    //         int child =i;
    //         setPriority((child/5)+1);
    //         for (int j = 0; j < 25; j++)
    //         {
    //             printf(1,"\n %d->%d \n",getpid(),j);
    //         }
    //         exit();
            
    //     }
        
    // }
    
    
    while (wait() != -1){}
    sleep(1);
    
    
    
    
    exit();
}