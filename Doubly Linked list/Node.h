#ifndef _NODE_H_
#define _NODE_H_

#include "Node.h"

#pragma once
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

struct DoublyList {
	Node* head = NULL;
	Node* tail = NULL;
};

Node* createNode(int data);
int listSize(DoublyList ls);
void printList(DoublyList ls);
DoublyList* initList(int data);
void addHead(DoublyList* ls, int data);
void addTail(DoublyList* ls, int data); 
Node* nodeIth(DoublyList* ls, int n);
void addBefore(DoublyList* ls, int data, int n);
void addAfter(DoublyList* ls, int data, int n);
void removeHead(DoublyList* ls);
void removeTail(DoublyList* ls);
void removeFirstKey(DoublyList* ls, int key);
void printInvert(DoublyList ls);
#endif // !_NODE_H_