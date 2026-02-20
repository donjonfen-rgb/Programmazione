#include <stdio.h>
#include <stdbool.h> //bool type and true false
#include <stdlib.h>

/*
comment often found here: //node.h | //forward declaration only
typedef struct t_node t_node;

struct t_node {
	int value;
	t_node *next;
};
this is a predeclaration or better Forward Typedef and avoid us to write struct node inside 
the actual declaration of the struct.
why ptr works with incomplete types: compiler doesn't need to know struct size to store it, 
because all ptrs have fixsize (eg 8bytes in 64bit-sys)
*/
typedef struct t_node
{
	int value;
	struct t_node *next; //ptr to the next on the list
} t_node;				/* design an alias for the struct, how is it difficult for the computer 
or program to always call a struct?*/

typedef struct
{
	t_node *head;
	t_node *tail;
	int size; // num of elements in the t_queue
} t_queue;
/*this is an anonymous struct, no tag names, since it doesn't refer to itself it doesn't need 
a tag (the name after struct).
thing that the first struct needs since 'struct t_node *next refers to itself' only name it gets 
comes from typedef alias which is t_queue, cannot call 'struct t_queue q;' cause it doesn't exist. 
Only 't_queue q' does. */
t_queue *create_t_queue();
int size(t_queue *t_queue);//when given a ptr to a q it'll return the siz
bool qise(t_queue *t_queue);// true or false
int peek(t_queue *t_queue, bool *status);/* return the value at the head of the t_queue, 
										if head is empty can't peek(?)*/
void ent_queue(t_queue *t_queue, int value);//
int det_queue(t_queue *t_queue, bool *status);
void destroy_t_queue (t_queue *t_queue);

t_queue *create_t_queue()
{
	t_queue *t_queue = malloc(sizeof(t_queue));
	t_queue->head = NULL;t_queue->tail = NULL;
	t_queue->size = 0;return t_queue;
}

int size(t_queue *t_queue){return t_queue->size;}

bool qise(t_queue *t_queue){return t_queue->size == 0;}//it'll return true if the size is 0

int peek(t_queue *t_queue, bool *status)
{
	if (qise(t_queue))
	{
		*status = false; 
		return 0;/*cannot return NULL cause you can't distinguish it from return 0*/
	}
	*status = true;
	return t_queue->head->value;//we take the value from what's in the head
}

void ent_queue(t_queue *t_queue, int value)
{
	t_node *newt_node = malloc(sizeof(t_node));if (!newt_node) return;
	newt_node->value = value;
	newt_node->next = NULL;
	//printf("%d\n",newt_node->value);
	if (qise(t_queue)){t_queue->head = newt_node; t_queue->tail = newt_node;}
	/*better control: if (t_queue->head==NULL){t_queue->head=newt_node;t_queue->tail=newt_node;}*/
	else{t_queue->tail->next = newt_node;//we take the next from tail which is a node
	t_queue->tail = newt_node;}
	t_queue->size++;
}

int det_queue(t_queue *t_queue, bool *status)
{
	int value = 0;
	if(qise(t_queue))
	{*status = false;return 0;}
	*status = true;
	value = t_queue->head->value;
	t_node *oldHead = t_queue->head;
	if (t_queue->size == 1){t_queue->head = NULL;t_queue->tail = NULL;}
	else
		t_queue->head = t_queue->head->next;
	free(oldHead);
	t_queue->size--;
	return value;
}

void destroy_t_queue (t_queue *t_queue)
{
	t_node *currentt_node = 0;
	currentt_node = t_queue->head;
	while(currentt_node != NULL)
	{
		t_node *tmp = currentt_node;
		currentt_node = currentt_node->next;
		free(tmp);
	}
	free(t_queue);
}

int main ()
{
	t_queue *q = create_t_queue();
	if(qise(q)) printf("Q is empty\n");
	ent_queue(q, 4);
	if(!qise(q)) printf("Q is not empty\n");
	ent_queue(q,5);ent_queue(q,6);
	printf("size of the t_queue is: %d\n",size(q));
	bool status = false;
	int value = 0;
	value = peek(q, &status);
	if(status) printf("peek success: %d\n",value);
	value = det_queue(q, &status);
	if(status) printf("det_queue success: %d\n",value);
	value = peek(q, &status);
	if(status) printf("peek success: %d\n",value);
	value = det_queue(q, &status);
	if(status) printf("det_queue success: %d\n",value);
	value = peek(q, &status);
	if(status) printf("peek success: %d\n",value);
	value = det_queue(q, &status);
	if(status) printf("det_queue success: %d\n",value);
	value = peek(q, &status);
	if(!status) printf("peek nonsuccess\n");
	value = det_queue(q, &status);
	if(!status) printf("det_queue nonsuccess\n");
	destroy_t_queue(q);
	if (qise(q)) printf("q destroyed: [%d]\n",qise(q));
	return 0;
}