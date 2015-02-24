
struct node {
	int object;
	struct node* next;
};

/**
 * constructor
 */
struct node* createNode(int object);

/**
 * Destructor
 */
void freeNode(struct node* node);
