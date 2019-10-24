#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "itemType.h"
#include "bag.h"

int main(void) {
	bag b = createBag();
	printf("%d\n", size(b));
	printf("%s\n", toBagString(b));
	add(b, 5);
	add(b, 7);
	add(b, 5);
	add(b, -3);
	printf("%d\n", size(b));
	char *string = toBagString(b);
	printf("%s", string);
	printf("%d\n", eraseOne(b, 7));
	return 0;
}