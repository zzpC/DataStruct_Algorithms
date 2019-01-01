#include <stdlib.h>
#include <stdio.h>

typedef struct tree_node{
	int item;
	int size;
	struct tree_node* left;
	struct tree_node* right;
	struct tree_node* father;
}tree_node,*SplayTree;

void leftRotate(struct tree_node* x){
	struct tree_node* y;
	y=x->father;
	y->right=x->left;
	if(x->left!=NULL){
		x->left->father=y;
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

void rightRotate(struct tree_node* x){
	struct tree_node* y;
	y=x->father;
	y->left=x->right;
	if(x->right!=NULL){
		x->right->father=y;
	}
	x->father=y->father;
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

void splay(SplayTree *x1,SplayTree *s1){
	SplayTree x=*x1;
	SplayTree s=*s1;
	struct tree_node* p;
	while(x->father!=NULL){
		p=x->father;
		if(p->father==NULL){
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
	*x=*s;
}

tree_node* findK(int k,SplayTree *s){
	int l;
	int r;
	struct tree_node* p=*s;
	while(p){
		l=0;
		r=0;
		if(p->left){
			l=(p->left)->size;
		}
		if(p->right){
			r=(p->right)->size;
		}
		if(k<l){
			p=p->left;
		}else if(k==l+1){
			break;
		}else{
			k=k-l-1;
			p=p->right;
		}
	}
	if(p){
		splay(&p,s);
	}
	return p;
}

void delLMin(int min,SplayTree *s1){
	struct tree_node * s=*s1;

	struct tree_node *p=s;
	struct tree_node *q;
	while(p){
		if(min<p->item){
			q=p;
			p=p->left;
		}else{
			p=p->right;
		}
	}
	if(!q){
		//freeNodes(s);
		s=NULL;
		return;
	}else{
		splay(&q,&s);
		if(q->left){
			q->size-=q->left->size;
			//freeNodes(q->left);
		}
		q->left=NULL;
	}
}



int SearchBST(int x,struct tree_node*  s,struct tree_node* f,SplayTree *p1){
	SplayTree p=*p1;
	if(s==NULL){
		p=f;
		return 0;
	}
	if(x==s->item){
		p=s;
		return 1;
	}else if(x<s->item){
		return SearchBST(x,s->left,s,&p);
	}else{
		return SearchBST(x,s->right,s,&p);
	}
}

SplayTree insertBSTree(int x,SplayTree * s1){
	SplayTree s=*s1;
	SplayTree p;
	struct tree_node* t;
	if(!SearchBST(x,s,NULL,&p)){
		t=(SplayTree)malloc(sizeof(struct tree_node));
		t->item=x;
		t->left=t->right=NULL;
		t->father=p;
		if(!p){
			s=t;
		}else if(x<p->item){
			p->left=t;
		}else{
			p->right=t;
		}
		return  t;
	}else{
		return NULL;
	}
}

void insert(int x,SplayTree *s1){	SplayTree s=*s1;
	struct tree_node* p;
	insertBSTree(x,&s);
	if(p){
		splay(&p,&s);
	}
}



int main(){
	int n;
	int min;
	int delta=0;
	int num;
	char opr;
	SplayTree root=NULL;
	scanf("%d%d",&n,&min);
	for(int i=0;i<n;i++){
		scanf("%c%d",&opr,&num);
		switch(opr){
			case 'I':
				if(num>=min){
					insert(num-delta,&root);
				}
				break;
			case 'A':
				delta+=num;
				break;
			case 'S':
				delta-=num;
				delLMin(min-delta-1,&root);
				break;
			case 'F':if(!root||num>root->size){
				 	printf("-1\n");
				 }else{
				 	findK(root->size-num+1,&root);
					printf("%d\n",root->item+delta);
				 }
				 break;
		}
	}
	return 0;
}



