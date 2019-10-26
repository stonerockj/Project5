/* Project #3
 EGRE246 Fall 2019
 G. Arthur
 J. Stonerock */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "itemType.h"
#include "bag.h"

#define DEBUG false

struct node {
	itemType data;
	struct node* next;
};

struct bagType {
	unsigned int size;
	struct node* head;
};

bag createBag() {
	bag b = malloc(sizeof(struct bagType));
	b->size = 0;
	b->head = NULL;
	return b;
} // create a new bag

void freeBag(bag b) {
	emptyBag(b);
	free(b);
}  // deallocates a bag

void emptyBag(bag b) {
	if(b->head != NULL) {
		for(int i = 1; i <= b->size; i++) {
			struct node* traverser = b->head;
			for(int j = 0; j < b->size - i; j++)
				traverser = traverser->next;
			if(DEBUG) printf("Freeing %d\n", traverser->data);
			free(traverser);
		}
		b->size = 0;
		b->head = NULL;
	}
}                // emptys the bag
void bagCopy(bag b1,bag b2);    // copies b2 to b1, overwriting b1
int size(bag b) {
	return b->size;
}                   // returns the number of items in bag
int count(bag b,itemType x) {
	int count = 0;
	if(b->head == NULL) {
		return 0;
	} else {
		struct node *traverser = b->head;
		while(traverser->next != NULL) {
			if(traverser->data == x) count++;
		}
		return count;
	}
}    // returns number of items x in b
int eraseOne(bag b,itemType x) {
	int count = 0;
	if(b->head == NULL) {
		return 0;
	} else {
		struct node *traverser = b->head;
		if(traverser->data == x) {
			b->head = traverser->next;
			if(DEBUG) printf("Freeing 1st: %d\n", traverser->data);
			free(traverser);
			count++;
			if(b->head != NULL) traverser = b->head;
		}
		while(traverser->next != NULL) {
			if(traverser->next->data == x) {
				struct node *temporary = traverser->next;
				traverser->next = temporary->next;
				if(DEBUG) printf("Freeing: %d\n", temporary->data);
				free(temporary);
				count++;
			}
			if(traverser->next != NULL) traverser = traverser->next;
		}
		b->size -= count;
		return count;
	}
}     // erases the value x in b, returns # removed
void add(bag b,itemType item) {
	struct node *temporary = b->head;
	if(temporary == NULL) {
		struct node *newNode = malloc(sizeof(struct node));
		newNode->data = item;
		newNode->next = NULL;
		b->head = newNode;
	} else {
		while(temporary->next != NULL) {
			temporary = temporary->next;
		}
		struct node *newNode = malloc(sizeof(struct node));
		newNode->data = item;
		newNode->next = NULL;
		temporary->next = newNode;
	}
	b->size++;
}         // inserts value in bag
itemType get(bag b,int n) {
	struct node* traverser = b->head;
	for(int i = 0; i < n && i < b->size; i++)
		traverser = traverser->next;
	if(traverser != NULL) {
		return traverser->data;
	} else {
		printf("empty list\n");
		exit(-1);
	}
}     // returns item at n in b where 0 is first item
bool contains(bag b,itemType x) {
	bool con = false;
	struct node* traverser = b->head;
	while(traverser != NULL) {
		if(traverser->data == x) con = true;
		traverser = traverser->next;
	}
	return con;
}// returns true if x is in b, false otherwise

bool isEmpty(bag b) {
	if(b->size == 0) return true;
	return false;
}               // return true if bag is empty
bool equals(bag b1,bag b2);      // returns true if b1 == b2
char *toBagString(bag b) {
	char *returnString = malloc(b->size * 50);
	struct node* traverser = b->head;
	if(traverser==NULL) {
		return "{}\n";
	} else {
		strcat(returnString, "{");
		while(traverser != NULL) {
			strcat(returnString, toItemString(traverser->data));
			strcat(returnString, ",");
			traverser = traverser->next;
		}
		strcat(returnString, "\b}\n");
		return returnString;
	}
}