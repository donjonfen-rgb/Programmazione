#include "push_swap.h"

// Find the node that starts the Longest Increasing Subsequence (LIS)
t_node *find_lis_starter(t_node *head)
{
    t_node *curr, *start, *best_start = NULL;
    int max_len = 0, curr_len, i = 0, best_idx = 0, idx = 0;
    t_node *runner, *prev, *tmp;
    int last_val;
    int total_len = 0;
    for (tmp = head; tmp; tmp = tmp->next)
        total_len++;
    for (start = head; start; start = start->next, idx++) {
        curr_len = 1;
        last_val = start->value;
        runner = start->next;
        while (runner) {
            if (runner->value > last_val) {
                curr_len++;
                last_val = runner->value;
            }
            runner = runner->next;
        }
        if (curr_len > max_len) {
            max_len = curr_len;
            best_start = start;
            best_idx = idx;
        }
        if (total_len - idx <= max_len)
            break;
    }
    return best_start;
}

// Helper to get list length
int list_len(t_node *head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Helper to get node at index
static t_node *node_at(t_node *head, int idx) {
    while (idx-- && head)
        head = head->next;
    return head;
}

// Compute LIS lengths for each node
void lis_lengths(t_node *head, int *dp) {
    int n = list_len(head);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (node_at(head, j)->value < node_at(head, i)->value && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }
}

// Return LIS value (length)
int lis_value(t_node *head) {
    int n = list_len(head), max = 0;
    int dp[1024]; // adjust size as needed
    lis_lengths(head, dp);
    for (int i = 0; i < n; i++)
        if (dp[i] > max)
            max = dp[i];
    return max;
}
//######################################################################################

/*per trovare il lis il metodo del longest che cosa mi dovra' tornare?
 int del valore o id? da ritrovare o direttamente il node?*/

t_node *whereislisa(t_queue q)
{
	int blis;
	int jalisse;
	t_node *k;

	k = q.head;
	/*cercare il lis.
	scorrere la lista a partire da head.
	conservare il valore ottenuto per futuro paragone e il nodo di riferimento
	aggiornare il punto di partenza e avanzare*/
	blis = 0;
	while (blis <= (q.size - runthrough(k,q)) && k != q.tail)//sinonimo di k.next !=NULL
	{
		if (k->next->value > k->value)
			blis++;
		if (k->next)
			k = k->next;

		if (blis < jalisse)//best lis so far check to compare to the one just run
			blis = jalisse;
	}
	return ;
}

int runthrough(t_node *n, t_queue q)
{
	//scorrere la lista e calcolare la len dei rimamenti. scorrere la lista, questa e la len.
	//sia q.size-counter
	t_node *k;
	int i;

	k = q.head;
	i = 0;
	while (n->value != k->value)
	{
		k = k->next;
		i++;
	}
	return (i);
}
