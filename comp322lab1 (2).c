/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/* Define structures and global variables*/
	int n;  //number of processes 
	
	struct tree_node{
		int  process;
		struct tree_node *link;
		};
		 
		 typedef struct tree_node linkedListType;
		 
		 struct node{
		 int parent;
		 linkedListType *children;
		 } *PCB = NULL;
		 
		typedef struct node pcb_type;
/***************************************************************/

void enter_param() {

	printf("Enter maximum number of process: ");
	scanf("%d", &n);
	
	PCB = (pcb_type *) malloc(n * sizeof(pcb_type));
	PCB[0].parent=0;
	PCB[0].children=NULL;
	
	/* for-loop to intitialize all other indices' parent to -1 */
	for(int i =1;i< n;i++){
	PCB[i].parent= -1;
	PCB[i].children = NULL;
	}
	return;
    }; /* end of procedure */
  
  void print_processes() {
	printf("print processes!");
/* declare local vars */
	linkedListType *next;
	for(int i=0;i<n;i++){
		if(PCB[i].parent!=-1 && PCB[i].children!=NULL){
		printf("PCB[%d] is parent of",i);
		next=PCB[i].children;
		while(next!=NULL){
			printf( "PCB[%d]", next-> process);
			next= next->link;
		}
		printf("\n");
		}
	}
	return;
    };
		


/* for each PCB index i from 0 up to (but not including) maximum 
number*/
/* check if PCB[i] has a parent and children */
/* print message about children of the 
current PCB[i] */
/* intilize variable to head of list of 
children */
/* while the end of the linked list of 
children is not reached */ 
/* print message about current child 
process index */
/* move to next node in linked list */
 /* while */
/* print newline */
/* if */
 /* for */
 /* end of procedure */
/***************************************************************/
/***************************************************************/
void create() {
	printf("create a process");
	/* define local vars */
	linkedListType *newchild, *next;
	int p, q=0;
	printf("Enter the parent process index: ");
	scanf("%d", &p);
	
	/* search for first available index q without a parent in a while 
loop */
	while(PCB[q].parent!=-1){
	q++;
	}
	
	newchild=(linkedListType *) malloc(sizeof(linkedListType));
	newchild->process= q; //to calculate new child index
	newchild->link= NULL;
	
	PCB[q].parent=p;
	PCB[q].children=NULL;
	
		if(PCB[p].children==NULL){
		 PCB[p].children= newchild;
		 }
		 else{ //traverse the linkelist and add it at the end
		 next=PCB[p].children;
	 while(next->link!=NULL){
	     next =next->link;
	 }
	 next->link=newchild;
		 }
			print_processes();
/* create a new link containing the child's index q and append the 
link to the end of the linked list of PCB[p] */
/* call procedure to print current hierachy of processes */
	return;
	} /* end of procedure */
/***************************************************************/
void destroy_recursion(linkedListType *node) {
/* declare local vars */
	int q;
	if(node==NULL){
	return;
	}
	else{
		destroy_recursion( node->link);
		q= node-> process;
		destroy_recursion(PCB[q].children);
		
		free(node);
		PCB[q].parent= -1;
		node=NULL;
	}
	return;
}
/* check if end of linked list--if so return */
/* else call self on next node in linked list */
/* set variable q to current node's process index field 
	
/* call self on children of PCB[q] */ 
/* free memory of paramter */
/* reset parent of PCB[q] to -1 */
/* set paramter to NULL */
 /* end of else */

 /* end of procedure */
/***************************************************************/
void destroy() {
	printf("Destroy a processes and its children");
	int p;
	printf("Enter the process whose descidents  are to be destroy");
	scanf("%d", &p);
	destroy_recursion(PCB[p].children);
	PCB[p].children=NULL;
	print_processes();
	return;
	}
	
/* declare local vars */
/* prompt for process index p */
/* call recursive procedure to destroy children of PCB[p] */
/* reset children of PCB[p] to NULL */
/* call procedure to print current hierarchy of processes */

 /* end of procedure */
/***************************************************************/
void garbage_collection() {
	 /*check if PCB is non null)
/* check if children of PCB[0] is not null */
	if(PCB!=NULL){
	    if(PCB[0].children!=NULL){
		/* call recursive procedure to destroy 
		children of PCB[0] */
		destroy_recursion(PCB[0].children);
	    }
		/* free memory of PCB */
		free(PCB);
	}
	
	return;
	}


 /* if */

 /* if */

 /* end of procedure */
/***************************************************************/
int main() {
	int choice=0;
		while(choice!=4){
		
		printf("\n simulate PCB: \n");
		printf("----------------\n");
		
		printf("1) Enter Paramaters\n"); 
		printf("2) Create a new child process\n"); 
		printf("3) Destory all the descendants of a processs\n"); 
		printf("4) Free memory and quit\n"); 
		
		printf("\n Enter selection:");
		scanf("%d",&choice);
		
		switch(choice){
		    case 1: enter_param();break;
		    case 2: create();break;
		    case 3: destroy();break;
		    case 4: garbage_collection();break;
		    default: printf("invalid option\n"); break;
		}
	}
	return 1;
}
/* declare local vars */
/* while user has not chosen to quit */
/* print menu of options */
/* prompt for menu selection */
/* call appropriate procedure based on choice--use switch 
statement or series of if, else if, else statements */
 /* while loop */
  /* indicates success */
 /* end of procedure */
