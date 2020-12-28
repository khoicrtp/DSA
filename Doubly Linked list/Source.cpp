#include "Node.h"

int main()
{
	DoublyList* ls=initList(1);

	addHead(ls, 0);
	addTail(ls, 3);
	addBefore(ls, 2, 2);
	addAfter(ls, 1, 2);

	removeHead(ls);
	removeTail(ls);

	addHead(ls, 0);
	removeFirstKey(ls,1);

	printList(*ls);
	printInvert(*ls);
	return 0;
}