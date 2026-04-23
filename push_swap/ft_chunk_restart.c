#include "push_swap.h"

//new start
finche lo stackA non e fatto solo di lis
	controlla il primo nodo entro il range e se maggiore o minore del mid;
		is q.head the best knot to push?
			yes: check push it accordingly pb,
				then calculate if you need to do a ra
		invece che questo cerca semplicemente ogni volta, se coincide tanto meglio.

			no: find it and 
	se maggiore effettua il pushb
		controlla se il prossimo nodo con stessa rotazione in questo caso >mid sia minore del numero appena pushato,
			in quel caso fagli raggiungere il topA e pushalo poi devi rotarebx2
				prova a cercare se il successivo sia ancora minore(creare flag) etc... ?forse da implementare
	se minore



cercare il nodo
portarlo su, check <> midchunk
	pusharlo
	verificare next node to push is also < oldnodejustpushed(stackb.head)
		yes push b
			repeat another time also if you need 
			look for next cheaper knot to push and check if also is >< and also oldk >< justfoundknot
			HOW TO SAVE THE "MOVEMENT" NEEDED TO CHECK THE DIRECTION WITH NEXT KNOT FOUND?
portarlo su
SE GIA CI SONO RIPETIZIONI E POSSIBILE CHE TUTTO QUESTO NON SERVA

if k < midchunk
	pushb
	if nextknot < midchunk and <justpushednode 
		//acquisire valore per ogni di questa funzione per controllare con piu facilita dopo? come acquisire altrimenti il valore ? flag?
		pullmeup and pushb 





OTHERWISE SANS PREDICTION

check cheaper node in range and direction to be pushed to,
check and pull it up might be better
	so push it correctly and repeat
	just check if before rb the next node also needs a ra, so the next node to push will also be from a ra loop and do those together


bool nextktopushsmallerthanbhead(t_node *nextkfound, t_node *b.head)
{
	if (k < b.head)
		checkif nextnode is also less than midchunk and less than k instead
	else


}