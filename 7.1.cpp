typedef struct tree_node{
	int item;
	struct tree_node* left;
	struct tree_ndoe* right;
	struct tree_ndoe* father;
}tree_node,*SplayTree;

void leftRotate(tree_node* x){
	tree_node* y;
	y=x->father;
	y->right=x->left;
	if(x->left!=NULL){
		X->left->father=y;
	}
	x->father=y->father;
	if(y->father!=NULL){
		if(y==y->father->left){
			x=y->father->left;
		}else{
			x=y->father->right;	
		}
	}
	y->father=x;
	x->left=y;
}

void rightRotate(tree_node* x){
	tree_node* y;
	y=x->father;
	y->left=x->right;
	if(x->right!=NULL){
		x->right->father=y;
	}
	x->fahter=y->father;
	if(y->father!=NULL){
		if(y==y->father->left){
			y->father->left=x;
		}else{
			y->father->right=x;
		}
	}
	y->father=x;
	x->right=y;
}

void splay(SplayTree &x,SplayTree &s){
	tree_node* p;
	while(x->father!=NULL){
		p=x->father;
		if(p->fahter==NULL){
			if(x==p->left){
				rightRotate(x);
			}else{
				leftRotate(x);
			}
			break;
		}
		if(x==p->left){
			if(p==p->father->left){
				rightRotate(x);	
				rightRotate(p);
			}else{
				rightRotate(x);
				leftRotate(p);
			}
		}else{
			if(p==p->father->left){
				leftRotate(x);
				rightRotate(p);
			}else{
				leftRotate(x);
				leftRotate(p);
			}
		}
	}
}
