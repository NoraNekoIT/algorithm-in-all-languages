#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(void *pa, void *pb, int size) {
	unsigned char tmp, *a = pa, *b = pb;
	while(size--) {
		tmp = *a;
		*a++ = *b;
		*b++ = tmp;
	}
}

void shuffle(void *p, int size, int n) {
	for(int i=n-1; i>1; --i) {
		// swap element at i with random element between 0 and i.
		swap(p + i*size, p + (rand()%(i+1))*size, size);
	}
}

int main(void) {
	srand(time(NULL));

	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	shuffle(arr, sizeof(int), 10);
	for(int i=0; i<10; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");

	struct person {
		char name[12];
		int age;
	};

	struct person *people = malloc(sizeof(struct person)*5);
	people[0] = (struct person){ .name = "jack", .age = 56 };
	people[1] = (struct person){ .name = "dan", .age = 12 };
	people[2] = (struct person){ .name = "lily", .age = 32 };
	people[3] = (struct person){ .name = "edward", .age = 2 };
	people[4] = (struct person){ .name = "james", .age = 10 };
	for(int i=0; i<5; ++i) {
		printf("%s is %d years old.\n", people[i].name, people[i].age);
	}
	puts("---");
	shuffle(people, sizeof(struct person), 5);
	for(int i=0; i<5; ++i) {
		printf("%s is %d years old.\n", people[i].name, people[i].age);
	}
}
