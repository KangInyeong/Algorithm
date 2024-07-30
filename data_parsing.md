# typedef
a keyword that is used to provide existing data types with a new name

## Example of `typedef`

```C
#include <stdio.h>
#include <stdint.h>

typedef long long lnln;
typedef uint8_t fpt;

int main() {

    lnln bigNum = 123123123;
    fpt numbers  = 255;

    printf("%lld\n", bigNum);
    printf("%hhu\n", numbers);
    
    return 0;
}
```

# struct

```
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}Point;

int main() {

    Point p1; //without initialization
    Point p2 = { 5, 7 }; // members in order
    Point p3 = { .x = 3, .y = 4 }; // designated initializer
    Point p4 = { .y = 10, .x = 2 }; // out of order
    Point p5 = { .x = 1 }; //other members are initialized with 0
    
    return 0;
}

#include <stdio.h>

typedef unsigned long int ULONG;

int main() {
    
    ULONG largeNumber = 1000000;
    
    printf("The number is: %lu\n", largeNumber);
    
    return 0;
}

#include <stdio.h>

struct date{
    int day;
    int month;
    int year;
    char title[20];
};

int main() {

    struct date birthDay;

    printf("Enter title of date: ");
    scanf("%s", birthDay.title);
    printf("Enter day of %s: ", birthDay.title);
    scanf("%d", &birthDay.day);
    printf("Enter month of %s: ", birthDay.title);
    scanf("%d", &birthDay.month);
    printf("Enter year of %s: ", birthDay.title);
    scanf("%d", &birthDay.year);

    printf("%s : %d-%d-%d", birthDay.title, birthDay.day, birthDay.month, birthDay.year);

    return 0;
}
```

# union

```
#include <stdio.h>
#include <stdint.h>

typedef union _ABC_{
    uint32_t a;
    uint8_t b[4];
} ABC;

int main() {

    ABC data;
    data.a = 0x1234ABCD;
    
    return 0;
}
```

# SEAGATE datasheet

```c
#include <stdio.h>
#include <stdint.h>

int main() {

	uint8_t buf[6] = { 0x08, 0xF2, 0x34, 0x56, 0x20, 0x1C };

#pragma pack(1)

	union Node {
		uint8_t ori[6];

		struct {
			uint8_t opcode;

			uint8_t lba_part1 : 5;
			uint8_t reserved : 3;
			
			uint8_t lba_part2;
			uint8_t lba_part3;

			uint8_t length;
			uint8_t control;
		}field;
	}node;

	memcpy(node.ori, buf, 6);

	uint32_t lba = 0x0;
	lba |= (node.field.lba_part1 << 16);
	lba |= (node.field.lba_part2 << 8);
	lba |= (node.field.lba_part3 << 0);

	printf("OPCODE : ox%02X\n", node.field.opcode);
	printf("Reserved : 0x%02X\n", node.field.reserved);
	printf("LBA : 0x%X\n", lba);
	printf("Length : 0x%02X\n", node.field.length);
	printf("Control : 0x%02X\n", node.field.control);

	return 0;
}
```
