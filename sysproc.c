#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}
int
sys_wait2(void) {
  int *cbt, *tat, *wt;
  if (argptr(0, (void*)&cbt, sizeof(cbt)) < 0)
    return -1;
  if (argptr(1, (void*)&tat, sizeof(cbt)) < 0)
    return -1;
  if (argptr(2, (void*)&wt, sizeof(wt)) < 0)
    return -1;
  return wait2(cbt, tat, wt);
}
int
sys_wait3(void) {
  int *cbt, *tat, *wt , *q;
  if (argptr(0, (void*)&cbt, sizeof(cbt)) < 0)
    return -1;
  if (argptr(1, (void*)&tat, sizeof(cbt)) < 0)
    return -1;
  if (argptr(2, (void*)&wt, sizeof(wt)) < 0)
    return -1;
  if (argptr(3, (void*)&q, sizeof(q)) < 0)
    return -1;
  return wait3(cbt, tat, wt,q);
}
int
sys_wait4(void) {
  int *cbt, *tat, *wt , *priority;
  if (argptr(0, (void*)&cbt, sizeof(cbt)) < 0)
    return -1;
  if (argptr(1, (void*)&tat, sizeof(cbt)) < 0)
    return -1;
  if (argptr(2, (void*)&wt, sizeof(wt)) < 0)
    return -1;
  if (argptr(3, (void*)&priority, sizeof(priority)) < 0)
    return -1;
  return wait4(cbt, tat, wt,priority);
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
int 
sys_getParentID(void)
{
  return myproc()->parent->pid;
}

int  
sys_getChildren(void)
{
  // char * ch ;
  // if(argptr(0 , (void *)&ch , sizeof(char)*64) < 0){
  //   return -1;}
  
  return children (myproc()->pid);
}

int 
sys_getSyscallCounter(void)
{
  int n;
  if(argint(0, &n) < 0)
    return -1;
  return myproc()->sysCount[n-1];

}
int
sys_setPriority(void)
{
  int pid, pr;
    if(argint(0, &pid) < 0)
        return -1;
    if(argint(1, &pr) < 0)
        return -1;

    return ChangePriority(pid, pr);
  
}
int
sys_setQueue(void)
{
  int pid, queue;
    if(argint(0, &pid) < 0)
        return -1;
    if(argint(1, &queue) < 0)
        return -1;

    return ChangeQueue(pid, queue);
  
}

// int
// sys_safePrint(void){
//   int child_num;
//   int i;
//   if(argint(0, &child_num) < 0 ) 
//     return -1;
//   if(argint(1, &i) < 0 ) 
//     return -1;
  
//   return myPrint(child_num,i);
// }
int 
sys_changePolicy(void)
{
  int n;
  if(argint(0, &n) < 0)
    return -1;
  if(n == 0 || n == 1 || n == 2 || n == 3)
    Policy = n;
  else
  {
    cprintf("You can just choose 0 , 1 , 2 and 3");
  }

  return Policy;

}
int
sys_getQueue(void)
{
    int pid;
    if(argint(0, &pid) < 0)
        return -1;

    return findQueue(pid);
}