

#define N 6
#define CNT 4

typedef struct {
	int idx;
	int x[N];
} a_struct;

typedef struct {
	int left;
	a_struct a[CNT];
	int right;
} b_struct;

void test(int i, b_struct *bp)
{
	int n = bp->left + bp->right;
	a_struct *ap = &bp->a[i];
	ap->x[ap->idx] = n;
}
	
