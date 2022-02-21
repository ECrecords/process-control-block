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
} *pcb_arr;

typedef struct pcb_struct pcb_type;

void
print_hierarchy (int *max_proc)
{
  list_type *current_child;

  printf ("\nProcess hierarchy:\n");
  for (int i = 0; i < *max_proc; i++)
    {
      if (pcb_arr[i].parent != -1 && pcb_arr[i].children != NULL)
	{
	  current_child = pcb_arr[i].children;
	  while (current_child != NULL)
	    {
	      printf ("\tProcess %d is the parent of Process %d.\n", i,
		      current_child->process_id);
	      current_child = current_child->link;
	    }
	}
    }
}

void
init_pcb_arr (int *max_proc)
{

  printf ("Enter maximum number of processes: ");
  scanf (" %d", max_proc);

  pcb_type *temp = (pcb_type *) malloc ((*max_proc) * sizeof (pcb_type));

  for (int i = 0; i < (*max_proc); i++)
    {
      temp[i].parent = (i == 0) ? 0 : -1;
      temp[i].children = NULL;
    }

  pcb_arr = temp;
  printf ("Process 0 was created as the top-level process\n");
}

void
create_child (int *max_proc)
{
  int p;
  int q = 0;
  list_type *child_process;
  list_type *current_child;

  printf ("\nEnter the parent process index: ");
  scanf (" %d", &p);

  while ((q < (*max_proc)) && (pcb_arr[q].parent != -1))
    {
      q++;
    }
  if (q == (*max_proc))
    {
      printf ("Out of processes!\n");
      return;
    }

  child_process = (list_type *) malloc (sizeof (list_type));
  (*child_process).process_id = q;
  (*child_process).link = NULL;

  if (pcb_arr[p].children == NULL)
    {
      pcb_arr[p].children = child_process;
    }
  else
    {
      current_child = pcb_arr[p].children;
      while (current_child->link != NULL)
	{
	  current_child = current_child->link;
	}
      current_child->link = child_process;
    }

  pcb_arr[child_process->process_id].parent = p;
  printf ("\nProcess %d was created as a child of Process %d\n", q, p);
  print_hierarchy (max_proc);
}


void
destroy_descendants_h (int *max_proc)
{
  int p;
  printf ("\nEnter the parent process whose descendants are to be destroyed: ");
  scanf (" %d", &p);
  destroy_descendants (pcb_arr[p].children);
  pcb_arr[p].children = NULL;
  print_hierarchy (max_proc);
}

void
destroy_descendants (list_type * node)
{
  int q;

  if (node == NULL)
    {
      free (node);
      return;
    }
  else
    {
      destroy_descendants (node->link);
      q = node->process_id;
      destroy_descendants (pcb_arr[q].children);
      printf ("\nProcess %d was destroyed", q);
      free (node);
      pcb_arr[q].parent = -1;
      node = NULL;
    }


}

void
free_program (int *max_proc)
{
  for (int i = 0; i < *max_proc; i++)
    {
      destroy_descendants (pcb_arr[i].children);
    }

}

int
main (int argc, char const *argv[])
{
  char option;

  int max_proc;

  printf ("=================================================\n"
	  "Process Creation Hierarchy\n"
	  "\t1) Enter parameters\n"
	  "\t2) Create a new child process\n"
	  "\t3) Destroy all descendants of a process\n"
	  "\t4) Quit program and free memory\n"
	  "=================================================");

  while (1)
    {
      printf ("\nEnter selection: ");
      scanf (" %c", &option);

      if (option == '1')
	{
	  init_pcb_arr (&max_proc);
	}
      else if (option == '2')
	{
	  create_child (&max_proc);
	}
      else if (option == '3')
	{
	  destroy_descendants_h (&max_proc);
	}
      else if (option == '4')
	{
	  free_program (&max_proc);
	  printf ("\nQuitting program...\n");
	  break;
	}
      else
	{
	  printf ("\nINVALID OPTION");
	}
    }
  return 0;
}
