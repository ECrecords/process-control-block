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
    short option;
    parent_proc pcb_arr[5];
    
    printf( "=================================================\n"
            "Process Creation Hierarchy\n"
            "\t1) Enter parameters\n"
            "\t2) Create a new child process\n"
            "\t3) Destroy all descendants of a process\n"
            "\t4) Quit program and free memory\n"
            "=================================================");

    while (1)
    {
        printf("\nEnter selection: ");
        scanf("%d", &option);
        
        if (option == 1)
        {
            /* code */
        } else if (option == 2)
        {
            /* code */
        } else if (option == 3)
        {
            /* code */
        } else if (option == 4)
        {
            break;
        } else
        {
            printf("INVALID OPTION");
        }
        
        
        
        
        
    }
    
    return 0;
}

