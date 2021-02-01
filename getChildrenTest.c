#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    // char *ch =(char *)malloc(sizeof(char)*64);
    // char *ch =(char *)malloc(sizeof(char)*64);
    // printf(1,"fufufufu %p\n",ch);
    // int * y =getChildren(ch);
    int q[64];
    // char final[64];
    int s,counter=0;
    int childcount =4;
    int my_pid = getpid();
    for(int i=0;i<childcount;i++){
          fork();
    }
    int x=getpid();
    if (x == my_pid){
        int z =getChildren();
        while (z/100 != 0)
        {
            s = z % 100;
            q[counter] =s;
            counter ++;
            z = z/100;
        }
        q[counter] =z;
        
        printf(1,"This process %d and children are :",x);
        for (int i =-1 ;i < counter;i++)
        {
            printf(1,"%d /",q[i+1]);
            // final[(i+1)*2]=q[i+1];
            // final[(i+1)*2 + 1] = '/';
            // final[i+1]=q[i+1] + '0';
            // printf(1,"%c\n",final[i+1]);
        }
        

        // printf(1,"%d\n",y);
    }
    while (wait() != -1){}
    sleep(1);
    
    
    
    
    exit();
}