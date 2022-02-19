#include <stdlib.h>
#include <stdio.h>

struct child_proc
{
    /* data */
    int id;
    struct child_proc *sib_proc;
};


struct parent_proc
{
    /* data */
    int id;
    struct child_proc *ch_proc;
};

typedef struct child_proc child_proc;
typedef struct parent_proc parent_proc;

int main(int argc, char const *argv[])
{
    int exit_flag = 1;
    
    parent_proc pcb_arr[5];
    
    while (exit_flag)
    {
        
    }
    
    return 0;
}
