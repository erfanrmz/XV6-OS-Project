#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
    if (fork() > 0)
    {
        printf(1,"This is Process %d and parentID is %d\n",getpid(),getParentID());
    }
    else
    {
        sleep(100);
        printf(1,"This is Process %d and parentID is %d\n",getpid(),getParentID());
    }
    
    
    return 0;
}