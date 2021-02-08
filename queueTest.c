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
    int *cbtS1 = malloc(10 * sizeof(int));
    int *tatS1 = malloc(10 * sizeof(int));
    int *wtS1 = malloc(10 * sizeof(int));
    int *pidS1 = malloc(10 * sizeof(int));
    int *cbtS2 = malloc(10 * sizeof(int));
    int *tatS2 = malloc(10 * sizeof(int));
    int *wtS2 = malloc(10 * sizeof(int));
    int *pidS2 = malloc(10 * sizeof(int));
    int *cbtS3 = malloc(10 * sizeof(int));
    int *tatS3 = malloc(10 * sizeof(int));
    int *wtS3 = malloc(10 * sizeof(int));
    int *pidS3 = malloc(10 * sizeof(int));
    int *cbtS4 = malloc(10 * sizeof(int));
    int *tatS4 = malloc(10 * sizeof(int));
    int *wtS4 = malloc(10 * sizeof(int));
    int *pidS4 = malloc(10 * sizeof(int));
    // int *pidS = malloc(40 * sizeof(int));
    // int *queueS = malloc(40 * sizeof(int));
    // int No = 0;
    int my_pid = getpid();
    for (int queue = 0 ; queue < 4 ; queue++)
    {
        for(int i=0;i < 10 ; i++){
            if (getpid() == my_pid){
                if(!fork()){
                    setQueue(getpid(),queue);
                    if(queue == 2 || queue == 1)
                    {
                        setPriority(getpid(),(i%6)+1);
                    }

                }
            }
        }
        // if (getpid() == my_pid)
        // printf(1,"finished making :%d\n",cur_prio);
    }
    if (getpid() != my_pid){
        // pidS[No] = getpid();
        // queueS[No] = getQueue(getpid());
        // No++;
        // printf(1,"%d    %d\n\n",getpid(),getQueue(getpid()));
        for (int i = 0; i < 200 ; i++)
        {

            printf(1,"pid :%d | i:%d\n",getpid(),i);
        }
    }
    else{
        int cbt,tat,wt,q;
        int queue0 = 0;
        int queue1 = 0;
        int queue2 = 0;
        int queue3 = 0;
        for (int i = 0 ; i < 40 ; i++)
        {
            int pidW;
            pidW = wait3(&cbt,&tat,&wt,&q);
            // for (int j = 0 ; j < 40 ; j++)
            //     if(pidS[j] == pidW)
            //     {
            //         q = queueS[j];
            //         break;
            //     }
            if (q == 0)
            {
                
                pidS1[queue0] = pidW;
                cbtS1[queue0] = cbt;
                tatS1[queue0] = tat;
                wtS1[queue0]  = wt;
                queue0++;

            }
            else if (q == 1)
            {
                pidS2[queue1] = pidW;
                cbtS2[queue1] = cbt;
                tatS2[queue1] = tat;
                wtS2[queue1]  = wt;
                queue1++;
                
            }
            else if (q == 2)
            {
                pidS3[queue2] = pidW;
                cbtS3[queue2] = cbt;
                tatS3[queue2] = tat;
                wtS3[queue2]  = wt;
                queue2++;
                
            }
            else if (q == 3)
            {
                pidS4[queue3] = pidW;
                cbtS4[queue3] = cbt;
                tatS4[queue3] = tat;
                wtS4[queue3]  = wt;
                queue3++;
                
            }

        }
        
        for (int i = 0 ; i < 10 ; i++)
        {
            printf(1,"Queue 1\n");
            printf(1,"PID: %d\n",pidS1[i]);
            printf(1,"CPU burst Time: %d\n",cbtS1[i]);
            printf(1,"Turn around Time: %d\n",tatS1[i]);
            printf(1,"waiting Time: %d\n\n\n",wtS1[i]);
            cbtAVG1 += cbtS1[i];
            tatAVG1 += tatS1[i];
            wtAVG1  += wtS1[i];
            cbtAVG += cbtS1[i];
            tatAVG += tatS1[i];
            wtAVG  += wtS1[i];

        }
        for (int i = 0 ; i < 10 ; i++)
        {
            printf(1,"Queue 2\n");
            printf(1,"PID: %d\n",pidS2[i]);
            printf(1,"CPU burst Time: %d\n",cbtS2[i]);
            printf(1,"Turn around Time: %d\n",tatS2[i]);
            printf(1,"waiting Time: %d\n\n\n",wtS2[i]);
            cbtAVG2 += cbtS2[i];
            tatAVG2 += tatS2[i];
            wtAVG2  += wtS2[i];
            cbtAVG += cbtS2[i];
            tatAVG += tatS2[i];
            wtAVG  += wtS2[i];

        }
        for (int i = 0 ; i < 10 ; i++)
        {
            printf(1,"Queue 3\n");
            printf(1,"PID: %d\n",pidS3[i]);
            printf(1,"CPU burst Time: %d\n",cbtS3[i]);
            printf(1,"Turn around Time: %d\n",tatS3[i]);
            printf(1,"waiting Time: %d\n\n\n",wtS3[i]);
            cbtAVG3 += cbtS3[i];
            tatAVG3 += tatS3[i];
            wtAVG3  += wtS3[i];
            cbtAVG += cbtS3[i];
            tatAVG += tatS3[i];
            wtAVG  += wtS3[i];

        }
        for (int i = 0 ; i < 10 ; i++)
        {
            printf(1,"Queue 4\n");
            printf(1,"PID: %d\n",pidS4[i]);
            printf(1,"CPU burst Time: %d\n",cbtS4[i]);
            printf(1,"Turn around Time: %d\n",tatS4[i]);
            printf(1,"waiting Time: %d\n\n\n",wtS4[i]);
            cbtAVG4 += cbtS4[i];
            tatAVG4 += tatS4[i];
            wtAVG4  += wtS4[i];
            cbtAVG += cbtS4[i];
            tatAVG += tatS4[i];
            wtAVG  += wtS4[i];

        }
        printf(1,"AVG of Queue 1\n");
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG1/10);
        printf(1,"Turn around Time AVG: %d\n",tatAVG1/10);
        printf(1,"waiting Time AVG: %d\n\n",wtAVG1/10);

        printf(1,"AVG of Queue 2\n");
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG2/10);
        printf(1,"Turn around Time AVG: %d\n",tatAVG2/10);
        printf(1,"waiting Time AVG: %d\n\n",wtAVG2/10);

        printf(1,"AVG of Queue 3\n");
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG3/10);
        printf(1,"Turn around Time AVG: %d\n",tatAVG3/10);
        printf(1,"waiting Time AVG: %d\n\n",wtAVG3/10);

        printf(1,"AVG of Queue 4\n");
        printf(1,"CPU burst Time AVG: %d\n",cbtAVG4/10);
        printf(1,"Turn around Time AVG: %d\n",tatAVG4/10);
        printf(1,"waiting Time AVG: %d\n\n",wtAVG4/10);



        printf(1,"CPU burst Time AVG: %d\n",cbtAVG/40);
        printf(1,"Turn around Time AVG: %d\n",tatAVG/40);
        printf(1,"waiting Time AVG: %d\n",wtAVG/40);

        // for (int i = 0 ; i < 40 ; i++)
        // {
        //     printf(1,"%d     %d\n",pidS[i],queueS[i]);
        // }
    }

    while (wait() != -1){}
    sleep(1);




    exit();
}