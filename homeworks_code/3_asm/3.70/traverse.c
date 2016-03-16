#include <stdio.h>

typedef struct ELE *tree_ptr;

struct ELE {
	tree_ptr left;
	tree_ptr right;
	long val;
};

long traverse(tree_ptr tp)
{
	long result = ((long) 1 << 63) - 1;

	if(tp) {
		long left = traverse(tp->left);
		long right = traverse(tp->right);

		long min = (left <= right ? left : right);
		min = (min <= tp->val ? min : tp->val);

		result =  min;
	}

	return result;
}
