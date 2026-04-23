*This project has been created as part of the 42 curriculum by ggaritta.*
update
still need to check qops for different movements;

TO DO
/*
- metodo per contenere/individuare i nodi della lis nello stack a.
- prendere possibilmente l'ultima lis piu' lunga trovata se doppioni a meno che non si voglia considerare lo spread di valore tra primo e ultimo elemento della lis.
- Quindi serve un metodo per la corsa a ritroso
*/
/*
how to save one lis which cost is less to move the other stuff into the stackb, create one f() that cleans the status and saves the true lis status on those others unless we just do the first one -> implemented a ptr on Q that will grab the max last value

gg: find minvals lis : the literally +1 search lis,

true lis algo searches for each node and takes into consideration the next one
*/


operations between linked lists
	https://www.youtube.com/watch?v=YjxKYxpf51E
grokking pfd and other valuable pdfs 
	https://github.com/swadhinsekhar/books/tree/master
push swap explainer
	https://www.youtube.com/watch?v=wRvipSG4Mmk
visualizer diff
	https://github.com/kurval/42-push_swap?tab=readme-ov-file
	https://www.toptal.com/developers/sorting-algorithms/bubble-sort
	
LIS best explainauh
	https://www.youtube.com/watch?v=E6us4nmXTHs

chunk maybe explained
	https://github.com/kurval/42-push_swap
	

	set int min and max as max values
	abs?
	costs?
- take > list of ints; 
- display sequence of instruction \n instruction
- if no param 
	are specified program must-n display anything, return to prompt
- errors handled "some arguments not being integers, some arguments
exceeding the integer limits, and/or the presence of duplicates." followed by ending with\n
100% moves limits > 100 nums 700 ops
					500 nums 5500 ops

EX {$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error}
EX2 {$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>}



## checker
h, c
makefile bonus rule
the checker as the bonus program has to read the prompt given by the Manda and execute those moves
- case of error, you must display "Error" followed by a ’\n’ on the standard error. 
Errors might be: 
	- args are not integers,
	- args are bigger than integer' -already managed-, 
	- there are duplicates, 
	- an instruction doesn’t exist and/or is incorrectly formatted.


#description
Functions stack and rotate in perfect symmetry
Order emerges from chaos with minimal moves
Rules strict: push, swap, rotate—nothing more

Two stacks, A and B, dance in algorithmic flow
Heaps of numbers reduced with clever strategy
Instructions optimized, every step must count
Sorting under pressure, efficiency is king

Push_swap: a test of logic, not brute force
Reducing operations is the ultimate goal
Optimal sequences crafted through thought and trial
Juggling integers with precision and care
Every move calculated, no randomness allowed
Complexity hidden behind simple commands
Training the mind to think like a machine

I leveraged patterns, chunking, and clever splits
Using every trick to beat the evaluator
Sometimes… yeah, I used AI or some shit
End result: clean, fast, and (mostly) understood

Debugged, refined, and pushed to completion

Algorithms sharpened through iteration
Intuition meets computation in every line




HOW TO FIND THE COSTS
what to use? idx? 
might be the good one since we have to get the pos of it anyway? <-just said two diff things in here, CAREFUL
= if idx is available at every move it will have to be updated.
= if you use the function every time you get to find the node you're looking for (MUST IMPLEMENT PIKMIN AND POKMON)
	need a position and calculate the diff between the values, which spread is shorter? 
	formula(?) = run the whole stack node by node: for each a calculate the spread + the moves needed to execute. nit's not a real addition cause that's dogshit result. they've got to be different values. if you find something less costly that is your new move GianTirchio(t_stacks s). 


# My Garbage
---
## worked on the final LIS behaviour. it should be fine now

/*basic comprehensive function that will incorporate all the behaviours of 
lis backbone struct until you find the reps to detach it to.
2 arr: both of them will be long as the number inputted, 
one for each index find the lis required, second will not have the first 
elements being that it will not have a subnumb to get to*/
// int	*lisength;
// int	*lidljumps;
// lisength = ft_helloitsmecalloc(q.size, sizeof(int), 1);//lis could be added to the struct
// lidljumps = ft_helloitsmecalloc(q.size, sizeof(int), '\0');//also the jumps number
void	theTamingoftheShrewLisa(t_queue q)
{
	t_node	*k;
	t_node	*rk;
	t_node	*rrk;

	k = q.head->next;//<- should i start from the next since case 0 is lisength set to 1(costant) and lidljumps is null since it's on the first index;
	rk = q.head;
	while(k->idx < q.size)//check size and elaborate if normal cases then ... /
	{
		rk = q.head;
		while(rk != k)//i have to reset one of these two bitches counters
		{/*everytime you check for a number you add the index at that number to said subsequence index, cause its its previous subsequence element also it has to be checked if at said index, the new number which is less than I -> enters and if the val at that index is > or < than the new val if then switch val. YOU ALWAYS CHOOSE THE LOWER VAL*/
			//if (!(k->idsubseq)) wrong case.
			//first index should be empty cause it can't jump to nowhere else, but since empty is not acceptable i need to find a way out.
				//k->idsubseq = rk;
				/*i should check each node and by each step increment the value of lis, then also check if the subsequent nodes till k are less than in reverse until the rk is higher*/
			if (rk->sval < k->sval && rk->lis+1 >= k->lis)
			{
				if (k->idsubseq->sval > rk->sval)
				{
					k->lis = rk->lis+1;
					k->idsubseq = rk;
				}
			}
			//if ((rk->sval < k->idsubseq->sval) && (rk->sval > k->idsubseq->idsubseq->sval))/*how to find the id of the previous subseq? should you use the same as the next?(t_node *acquisire il nodo della subsequenza invece che l'index siccome siamo con i nodi demente)*/
			rk = rk->next;
		}
		k = k->next;
	}
}
---
/*basic comprehensive function that will incorporate all the behaviours of 
lis backbone struct until you find the reps to detach it to.
2 arr: both of them will be long as the number inputted, 
one for each index find the lis required, second will not have the first 
elements being that it will not have a subnumb to get to*/
// int	*lisength;
// int	*lidljumps;
// lisength = ft_helloitsmecalloc(q.size, sizeof(int), 1);//lis could be added to the struct
// lidljumps = ft_helloitsmecalloc(q.size, sizeof(int), '\0');//also the jumps number
void	theTamingoftheShrewLisa(t_queue q)
{
	t_node	*k;
	t_node	*rk;

	k = q.head->next;//<- should i start from the next since case 0 is lisength set to 1(costant) and lidljumps is null since it's on the first index;
	rk = q.head;
	while(k->idx < q.size)//check size and elaborate if normal cases then ... /
	{
		rk = q.head;
		while(rk != k)//i have to reset one of these two bitches counters
		{/*everytime you check for a number you add the index at that number to said subsequence index, cause its its previous subsequence element also it has to be checked if at said index, the new number which is less than I -> enters and if the val at that index is > or < than the new val if then switch val. YOU ALWAYS CHOOSE THE LOWER VAL*/
			//if (!(k->idsubseq)) wrong case.
			//first index should be empty cause it can't jump to nowhere else, but since empty is not acceptable i need to find a way out.
				//k->idsubseq = rk;
				/*i should check each node and by each step increment the value of lis, then also check if the subsequent nodes till k are less than in reverse until the rk is higher*/
			if (rk->sval < k->sval && rk->lis+1 >= k->lis)
			{
				if (k->idsubseq == NULL || rk->sval < k->idsubseq->sval)
				{
					k->lis = rk->lis+1;
					k->idsubseq = rk;
				}
			}
			//if ((rk->sval < k->idsubseq->sval) && (rk->sval > k->idsubseq->idsubseq->sval))/*how to find the id of the previous subseq? should you use the same as the next?(t_node *acquisire il nodo della subsequenza invece che l'index siccome siamo con i nodi demente)*/
			rk = rk->next;
		}
		k = k->next;
	}
	
}
---
// lisength[j]++;
//(*(lisength + i))++; this also increases the value stored at that index
//(*lisength)++; this also increases the value at current ptr pos given that you move by ptr instead of counter but it would be more diff to reset the pos;

fine LIS
---

## CHUNK

The mathematical intuition
For a random permutation of n elements, the optimal chunk size minimizes:
total ≈ (n / chunk_size) × n  +  insertions × (chunk_size / 4)

The first term is phase 1 scanning cost. The second term approximates phase 2 rotation cost — within a chunk of size s, an element is on average s/4 positions from where greedy wants it.

Setting the derivative to zero and solving for chunk_size gives:
chunk_size = 2 × sqrt(n)
For n=500 this gives 2 × sqrt(500) ≈ 44. For n=100 this gives 2 × sqrt(100) = 20. These match the empirical sweet spots the community has found, which validates the reasoning.

The formula to use? why? we need it stupeed

	int	calculate_chunk_size(int n)
	{
		int size;

		size = 2 * ft_sqrt(n);
		if (size < 5)
			size = 5;
		return (size);
	}

	int	ft_sqrt(int n)
	{
		int i;

		i = 1;
		while (i * i <= n)
			i++;
		return (i - 1);
	}

The number of chunks then falls out naturally:
int	num_chunks = (n + chunk_size - 1) / chunk_size;
The + chunk_size - 1 before dividing is ceiling division — it ensures the last chunk is not silently dropped when n is not perfectly divisible by chunk_size.

int     chunk_start(int i, int chunk_size)
{
    return (i * chunk_size);
}

int     chunk_end(int i, int chunk_size, int n)
{
    int end;

    end = (i + 1) * chunk_size - 1;
    if (end >= n)
        end = n - 1;
    return (end);
}

int     chunk_mid(int i, int chunk_size) // is this enough when i need to check the midchunk value?
{
    return (i * chunk_size + chunk_size / 2);
}

//individuare il chunk when you run through the stack
int     which_chunk(int rank, int chunk_size)
{
    return (rank / chunk_size);//this is not the index, maybe sval right? yep!
}

int     belongs_to_chunk(int rank, int chunk_index, int chunk_size, int n) i can do you one better (t_node *k, t_queue q )//is this even useful? if i find which chunk the node is not from i know which one to enter right?
{
    return (rank >= chunk_start(chunk_index, chunk_size)
        && rank <= chunk_end(chunk_index, chunk_size, n));
}


**The rules expressed as decisions at each step**

During each chunk pass you are rotating through `a`. At every step you look at the top of `a` and make one of three decisions:
```
is top of a a skeleton element (in_lis == 1)?
    → ra, it never moves

is top of a a non-skeleton element belonging to the current chunk?
    → pb
    → is its rank >= chunk_mid?
           yes → rb   (sink it, upper half goes deeper)
           no  → nothing (lower half stays on top)

is top of a a non-skeleton element belonging to a future chunk?
    → ra, its turn has not come
```

You repeat this until every element of the current chunk has been pushed. You know you are done with a chunk when the count of pushed elements equals the number of non-skeleton elements whose rank falls within that chunk's boundaries. Track this count explicitly — do not rely on scanning `a` and finding nothing, because skeleton elements might be the only things left on top and you would loop forever.

---

**Tracking progress cleanly**

Before starting the chunk phase, count how many non-skeleton elements belong to each chunk. Store this in a small array:
```
chunk_counts[i] = number of non-skeleton elements with rank in chunk i's range
```

You compute this once in O(n) by walking your node list before touching the stacks. Then during phase 1, decrement `chunk_counts[current_chunk]` each time you `pb`. When it hits zero, advance to the next chunk. This gives you a clean termination condition with no risk of infinite rotation.

---

il nostro chunk funziona come un counter. non usiamo gli indici per sfizio. 
	adesso, effettuato un push currentchunkcounter++ fino al raggiungimento di currentchunkrange.
	una volta raggiunto si moltiplica i per il chunksize... o si aggiorna chunkrange+= chunksize e incrementa la i++; cosi' da arrivare fino a maxchunks, controllo del l'ultimo step: if currentchucnkrange > maggiore degli elementi presenti negli stacks totsize = (s.a.size+s.b.size).

//se il range dovra' essere il chunk range come valore massimo del chunk di ppartenenza non sara' dunque
	chrange 40
	maxchunk 5
	come differire se un numero andra' considerato top or bottom of the bstack

## AVOIDMELISA how to avoid the lis elements from being counted in chunk algo

	if you find lis you can ++ whatever you need and go to the next one
	or for each element in said chunk range you can +1 
	you can jump lis elements and look for the next one
	or? is there another method i can use?





/*In push_swap, chunking is a heuristic strategy, not a mathematically “proven best” rule. The common guideline of using a chunk size ≈ 2 × √n comes from balancing two competing costs:

1. What chunking is trying to optimize

When you split the input into chunks, you’re trying to:

Minimize rotations in stack A (to find elements in the current chunk)
Keep stack B organized enough so pushing back to A is efficient

So the chunk size affects:

How far you scan in A → cost grows with chunk size
How messy B becomes → cost grows if chunks are too large
2. Why √n shows up

The √n pattern appears in many algorithms where you balance two linear costs.

Think of it like this:

If you use k chunks, each chunk has size ≈ n/k
Total cost roughly behaves like:
Cost ≈ (cost to find elements) + (cost to manage chunks)
     ≈ n * (n/k) + n * k
First term: scanning A (larger chunks → more scanning)
Second term: managing chunks / pushing back (more chunks → more overhead)

To minimize:

n²/k + n*k

Take the minimum → happens around:

k ≈ √n

So:

Number of chunks ≈ √n
Chunk size ≈ n / √n = √n
3. Why multiply by 2?

The “2 × √n” is a practical tuning, not theory:

Pure √n chunks are often too tight
You spend too much time rotating A to find exact elements
Doubling the chunk size:
Gives more flexibility (you accept a wider range of values)
Reduces rotations in A
Slightly increases disorder in B, but that’s easier to fix

So it's a trade-off tweak:

√n → theoretically balanced
2√n → empirically faster in push_swap constraints
4. Intuition in plain terms
Too small chunks → too many passes, lots of overhead
Too big chunks → B becomes chaotic, costly to rebuild
√n → balance point
2√n → same balance, but biased toward fewer rotations (which are expensive in push_swap)
5. Important: it's not universal

Top implementations often tweak this:

Small inputs (≤100): smaller chunks
Large inputs (500): 1.5√n, 2√n, or even adaptive ranges
Some don’t use chunks at all (radix sort instead)
Bottom line

The 2 × √n rule works well because:

√n comes from minimizing two opposing linear costs
×2 is an empirical adjustment to reduce rotations and improve real-world performance

If you want, I can show you:

how this compares to radix (which often beats chunking), or
how to implement an optimal chunk strategy step-by-step.*/



---
funzione inutile
/*impostare una funzione che pusha a B funzione struttura per howmuchisnextchunk*/
t_stacks chunkamiphase2(t_stacks s, void (*f)(int) )
{
	// check if cost is less from next rotation ort_node* quattrosaldinchunk(t_queue q, int churro)
{
	//throguh nextrot and prevrot withing the current chunk and not intoLisa
	if (nrnktp(q,churro) <= prnktp(q,churro))
		return (&rr);
	return (&rb);
} prev rotation;
	int currentchonker;
	int currentchonkersize;
	int spitme;
	int i;
	int nelementsinA;
	int maxchunk;
	//currentchonker = sizeChunkchocolatechipcookie();
	nelementsinA = s.a.size - s.a.lis->valis;
	maxchunk = (nelementsinA + currentchonkersize - 1) / currentchonkersize;
	i=1;
	while (i < maxchunk)
	{
		currentchonker = i * currentchonkersize;
		if (currentchonker > (s.a.size + s.b.size))
			currentchonker = (s.a.size + s.b.size);
		if (s.a.head->sval >= currentchonkersize / 2)//midchunk
			pb();
		else
			if (checkfutureknottopushinb() == &rrr)
				rrr();
		i++;
	}
}

// t_stacks	ft_createStacks()
// {
// 	t_stacks s;
// 	s.a = createQ();
// 	if (!s.a)
// 		ft_callmeanerror(51);
// 	s.b = createQ();
// 	if (!s.b)
// 	{
// 		free(s.a);
// 		ft_callmeanerror(52);
// 	}
// 	return (s);
// }
// t_stacks ft_createStacks()
// {
// 	return ((t_stacks){createQ(), createQ()});
// }
// t_queue	*createQ()
// {
// 	t_queue *q;
// 	q = malloc(sizeof(t_queue));
// 	if (!q)
// 		return (NULL);
// 	q->head = NULL;
// 	q->tail = NULL;
// 	q->size = 0;
// 	return (q);
// }

// int decappler(t_queue q)
// {
// 	int oVal;
// 	t_node *oNod;
// 	oVal = 0;
// 	if (q.head == NULL)
// 		return false;
// 	oNod = q.head;
// 	oVal = oNod->value;
// 	q.head = q.head->next;
// 	free(oNod);
// 	q.size--;
// 	return (oVal);
// }
/*alla fine della liberazione bis
- cos'e' il max costo totale???
*/


---












Concetti Halal e Habibi 
Halal: Cibo preparato rispettando le regole islamiche, garantendo la carne priva di sangue e non contaminata da derivati del maiale.
Habibi/Habibti: Termine arabo affettuoso, spesso utilizzato nei nomi dei ristoranti per indicare accoglienza e cucina tradizionale

Termini simili a Halal (Permesso/Conformità) 
Tayyib: Si riferisce a cibo puro, sano, di alta qualità e salutare. Spesso usato insieme a "halal" (halal tayyib) per indicare non solo la leceità religiosa, ma anche la qualità etica e nutrizionale.
Dhabiha (o Zabiha): Indica specificamente la carne macellata secondo il rito islamico, garantendo che sia halal.
Kosher (o Kasher): Termine ebraico per il cibo conforme alle regole alimentari ebraiche. Sebbene le religioni siano diverse, il concetto di "cibo lecito e controllato" è analogo a quello halal.
Mashbooh: Indica un cibo "dubbio" o sospetto, che non è chiaramente halal né chiaramente haram, spesso a causa di ingredienti incerti nei cibi processati.
Haram: L'opposto di halal; significa proibito, illecito. 

Azioni e Tecniche di Cucina
Bismillah: La formula ("Nel nome di Dio") che deve essere pronunciata prima della macellazione o del consumo del pasto per renderlo lecito.
Sgozzamento: La tecnica specifica di macellazione rituale prevista sia dall'halal che dal kosher per drenare il sangue.
Shechita: Il termine ebraico specifico per la macellazione rituale kosher.
Kasherizzare: L'azione di rendere kosher un alimento o una cucina, spesso tramite lavaggio o esposizione al calore

**How this connects to greedy**

The chunk size directly determines the average `rb`/`rrb` cost greedy pays per insertion. Within a chunk of size s, an element is on average s/4 rotations from the top of `b` after the midpoint rule is applied. So:
```
average b-side rotation cost per insertion ≈ chunk_size / 4

---
## Griddy
	GREEDY real - find the smallest bigger node in a to push the node from b to.
		so it has to be bigger than bsval and the smallest of the bunch in that interval, so it will come out as the next in the succession.
		since this also should be in a while looking for the cost as the && result
	
	
	Chunked greedy
		depending on the a.head but it will not matter cause we will have big numbers at the start ot the 

	- what if only smaller numbers remain in the stack B than in A find smallest in A and start pushing smaller ones
	- same as biggest numbers, find smallest and pushA then rotate

	cercare max num
	possible behaviour: 
		since chunk puts BIG nums on the edges.
		(WRONG bring maxA to top') Then calculate costs of next node to push, which could be bigger in which case ra, pa, otherwise pa
	vedere se il valore sia piu o meno costoso di e del successivo sia da pushare vicino a minA o maxA

	run the whole cost circus for the > and < value that costs less for each node, store that node and recalciulate

	showdown a 4 min and max from next and prev in tot,

for each node calculate which one of them is the cheapest, to do that for all the stack and find out

Q: how to find out the best number for that node to be pushed next to????

look for the smallest difference between the nodes, which will identify/spot/pinpoint the behaviour of its location, be it that node's prev or next.

//behaviour again
	pushare i greatest nums, which will be the first ones available
		spot which ones in couples have the lowest number of moves needed to reach the exchange. 
			remember each from the stacks the coordinated couple. be able to consider the diff if direction is same

if s.b.head is biggest in s.a pa, then check for it's closest and while running it after having calculated its cost to push switch it only when you find a cheaper one which in perspective will always be the closest to that nodesval!! 

how to get the usual rotation needed info back?

solved a non-issue about the: 2 - 480; get the lowest between the two a-b and n -Mk + mk;
prendere sempre il valore maggiore e fare differenza tra esso e la sizeN aggiungendo il minore tra i due numeri

### before the push
'''
after found the strat to go to top of both stacks i need to find the behaviour of the push:
	- is it a num bigger or lower,
		if it s lower then just PA,
		also if it s the biggest and the smallest then PA
		if the bk diff 
	FIND IF THE BK IS BIGGER AND THAT IS THE REASON OF THE MINDIFF OR DOES IT COME FROM N - B+A CALCULI
		in which case:
			if n has been involved
				n-b+a
				if b > a do another rotation if RA case or one less if RRA 
				if b < a come on top and just push if RA one less if RRA
				8 cases total based on which one is greater, internal or external values and if it comes from prev or next rotations
'''
----
how to initialize a pointer to a struct
	Short answer: almost — but not quite the way you wrote it.
	✅ Correct way
	If you have a pointer:
	struct s_coord *zd = {0};  // ❌ not correct
	This is invalid, because {0} is for struct initialization, not for pointers.
	✔️ What you should do instead
	1. Initialize a pointer to NULL
	struct s_coord *zd = NULL;
	2. Allocate and zero-initialize
	If you actually want a usable struct:
	struct s_coord *zd = malloc(sizeof(struct s_coord));
	if (zd)
		*zd = (struct s_coord){0};
	Or cleaner:
	struct s_coord *zd = calloc(1, sizeof(struct s_coord));
	🧠 If you meant a struct (not a pointer)
	Then yes — this is perfectly valid:
	struct s_coord zd = {0};
	This sets:
	all pointers → NULL
	all ints → 0
	all fields → zeroed
	⚠️ Summary
	Case	Correct initialization
	struct variable	struct s_coord zd = {0}; ✅
	pointer only	struct s_coord *zd = NULL; ✅
	allocated + zeroed	calloc(...) or assign {0} after malloc ✅
----






