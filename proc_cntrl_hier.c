#include <stdlib.h>
#include <stdio.h>

struct list_struct
{
    /* data */
    int process_id;
    struct list_struct *link;
};

typedef struct list_struct list_type;

struct pcb_struct
{
    /* data */
    int parent;
    list_type *children;
};

typedef struct pcb_struct pcb_type;

void init_pcb_arr(pcb_type *pcb_arr, int *max_proc)
{
    printf("Enter maximum number of processes: ");
    scanf(" %d", max_proc);

    //pcb_type *probe;
    pcb_arr = (pcb_type*) malloc( (*max_proc) * sizeof(pcb_type));

    for (int i = 0; i < (*max_proc); i++)
    {
        //probe = pcb_arr+i;
        pcb_arr[i].parent = (i == 0) ?  0 : -1;
        pcb_arr[i].children = NULL;
    }

    printf("Process 0 was created as the top-level process\n");
    return;
}

void create_child(pcb_type *pcb_arr, int *max_proc)
{

}

int main(int argc, char const *argv[])
{
    char option;

    int max_proc;
    pcb_type *pcb_arr = NULL;
    
    
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
        scanf(" %c", &option);
        
        if (option == '1') {
            init_pcb_arr(pcb_arr, &max_proc);
        } else if (option == '2') {
            /* code */
        } else if (option == '3') {
            /* code */
        } else if (option == '4') {
            break;
        } else {
            printf("\nINVALID OPTION");
        }    
    }
    return 0;
}

