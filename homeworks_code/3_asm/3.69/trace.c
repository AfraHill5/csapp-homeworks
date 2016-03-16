typedef struct ELE *tree_ptr;

struct ELE {
	tree_ptr left;
	tree_ptr right;
	long val;
};

/*
long trace_rec(tree_ptr tp)
{
	if(tp) {
		if(tp->left)
			return trace(tp->left);
		else
			return tp->val;
	} else {
		; // Error.
	}
}
*/

long trace_iter(tree_ptr tp)
{
	long result = 0;
	
	while(tp) {
		result = tp->val;
		tp = tp->left;
	}

	/*
	while(tp) {
		if(!tp->left)
			return tp->val;
		else
			tp = tp->left;
	}
	*/

	return result;
}

	
