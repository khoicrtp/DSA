#include "Node.h"

Node* createNode(int data)
{
	Node* p = new Node;
	p->data = data;
	p->next = NULL;
	p->prev = NULL;

	return p;
}

int listSize(DoublyList ls)
{
	int count = 0;
	for (Node* p = ls.head; p; p = p->next) {
		count++;
	}

	return count;
}

void printList(DoublyList ls) {
	for (Node* p = ls.head; p; p = p->next)
	{
		cout << p->data << "  ";
	}
	cout << endl;
}

DoublyList* initList(int data)
{
	Node* p = createNode(data);
	DoublyList* ls = new DoublyList;

	ls->head = p;
	ls->tail = p;

	return ls;
}

void addHead(DoublyList* ls, int data)
{
	Node* p = createNode(data);
	if (ls->head == NULL)
	{
		ls->head = p;
		ls->tail = p;
	}

	else {
		p->next = ls->head;
		ls->head->prev = p;
		ls->head = p;
	}
}

void addTail(DoublyList* ls, int data) {
	Node* p = createNode(data);

	if (ls->head == NULL) {
		ls->head = p;
		ls->tail = p;
	}

	ls->tail->next = p;
	p->prev = ls->tail;
	ls->tail = p;
}

Node* nodeIth(DoublyList* ls, int n)
{
	Node* p = ls->head;
	for (int i = 0; i < n; i++)
	{
		if (!p)
		{
			return NULL;
		}
		p = p->next;
	}
	//cout << p->data;
	return p;
}

void addBeforeNode(DoublyList* ls, Node* o, int data)
{
	Node* temp = createNode(data);

	for (Node* p = ls->head; p; p = p->next)
	{
		if (p == o)
		{
			temp->prev = p->prev;
			temp->next = p;
			p->prev->next = temp;
			p->prev = temp;
		}
	}
}

void addAfterNode(DoublyList* ls, Node* o, int data)
{
	Node* temp = createNode(data);

	for (Node* p = ls->head; p; p = p->next)
	{
		if (p == o)
		{
			temp->next = p->next;
			temp->prev = p;
			p->next->prev = temp;
			p->next = temp;
		}
	}
}


void addBefore(DoublyList* ls, int data, int n) {
	if (listSize(*ls) <= n) {
		addTail(ls, data);
		return;
	}

	if (listSize(*ls) == 0) {
		addHead(ls, data);
		return;
	}

	Node* p1 = createNode(data);
	Node* p2 = nodeIth(ls, n);
	Node* temp = p2->prev;

	if (p2 == NULL) {
		cout << "Cant find " << n << " th node!" << endl;
		return;
	}

	temp->next = p1;
	p1->prev = temp;
	p1->next = p2;
	p2->prev = p1;
}

void addAfter(DoublyList* ls, int data, int n) {
	if (listSize(*ls) <= n) {
		addTail(ls, data);
		return;
	}

	if (listSize(*ls) == 0) {
		addHead(ls, data);
		return;
	}

	Node* p1 = createNode(data);
	Node* p2 = nodeIth(ls, n);
	Node* temp = p2->next;

	if (!p2) {
		cout << "Cant find " << n << " th node!" << endl;
		return;
	}

	p2->next = p1;
	p1->prev = p2;
	p1->next = temp;
	temp->prev = p1;
}

void removeHead(DoublyList* ls)
{
	Node* temp = ls->head;

	ls->head->prev = NULL;
	ls->head = ls->head->next;

	delete temp;
}

void removeTail(DoublyList* ls)
{
	Node* temp = ls->tail;

	ls->tail = ls->tail->prev;
	ls->tail->next = NULL;

	delete temp;
}

void removeFirstKey(DoublyList* ls, int key)
{
	for (Node* p = ls->head; p; p = p->next) {
		if (p->data == key) 
		{
			if (p == ls->head)
			{
				p->next->prev = NULL;
				ls->head = p->next;

				delete p;

				return;
			}

			if (p == ls->tail)
			{
				p->prev->next = NULL;
				ls->tail = p->prev;

				delete p;

				return;
			}

			Node* temp = p;
			p->prev->next = p->next;
			p->next->prev = p->prev;

			delete temp;

			return;
		}
	}
}

void printInvert(DoublyList ls)
{
	for (Node* p = ls.tail; p; p = p->prev)
	{
		cout << p->data << "  ";
	}
}