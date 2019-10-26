#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "itemType.h"
#include "bag.h"

int main(void) {
	bag b = createBag();
	printf("%d\n", size(b));
	printf("%s", toBagString(b));
	add(b, 5);
	add(b, 7);
	add(b, 5);
	add(b, -3);
	printf("%d\n", size(b));
	char *string = toBagString(b);
	printf("%s", string);
	printf("%d\n", eraseOne(b, -3));
	printf("%s", toBagString(b));
	printf("%d\n", eraseOne(b, 5));
	printf("%s", toBagString(b));
	printf("Size: %d\n", size(b));
	printf("%d\n", eraseOne(b, 7));
	printf("%s", toBagString(b));
	emptyBag(b);
	add(b, 6);
	add(b, -2);
	add(b, 2);
	add(b, 5);
	printf("%s", toBagString(b));
	emptyBag(b);
	printf("%s", toBagString(b));
	add(b, 1);
	emptyBag(b);
	printf("%s", toBagString(b));
	add(b, 6);
	add(b, 6);
	add(b, 4);
	add(b, 5);
	add(b, 3);
	for(int i = 0; i < 6; i++)
		add(b, i * 2);
	printf("Item 4: %d\n", get(b, 4));
	printf("%s", toBagString(b));
	freeBag(b);
	return 0;
}