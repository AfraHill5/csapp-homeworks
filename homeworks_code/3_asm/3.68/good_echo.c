#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 20

struct line {
	char contents[LEN];
	struct line *next;
	int length;
	int capacity;
};

struct line *new_line()
{
	struct line *line = malloc(sizeof(struct line));
	line->length = 0;
	line->capacity = LEN;

	return line;
}

struct line *store(char c, struct line *dest)
{
	if (dest->capacity == dest->length) {
		/* full of current line. make a new object to store current char */
		
		struct line *new_dest = new_line();
			
		new_dest->contents[new_dest->length] = c;
		new_dest->length += 1;
		
		dest->next = new_dest;
		dest = new_dest;
	} else if (dest->capacity > dest->length) {
		dest->contents[dest->length] = c;
		dest->length += 1;
	} else {
		; // Error.
	}

	return dest;
}	
	
void get(struct line *dest)
{

	int c;
	while (true) {
		c = getchar();
		if (c == EOF)
			break;
		
		dest = store(c, dest);

		if (c == '\n')
			break;
	}
}

void put_line(struct line *source)
{
	for (int i = 0; i < LEN; i++)
		printf("%c", source->contents[i]);
}

void put(struct line *source)
{
	while (true) {
		if (source)
			put_line(source);
		else
			break;

		if (source->next)
			source = source->next;
		else
			break;
	}
}

int good_echo()
{
	struct line *head = new_line();
	struct line *dest = head;

	get(dest);  // read from stdin, store into dest.
	put(head);

	return 0;
}


int main()
{
	good_echo();

	return 0;
}
