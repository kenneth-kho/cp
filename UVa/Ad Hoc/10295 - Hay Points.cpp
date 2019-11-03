//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1236
//I use self-built AVL tree here, because why not :v
//Actually, you may use array and sort then do binary search or use STL map
#include<iostream>
using namespace std;

struct node{
	string KEY;
	int height;
	int price;
	struct node *left;
	struct node *right;
};

int max(int a, int b){
	return (a > b) ? a : b;
}

int getHeight(struct node *localRoot){
	return (localRoot == NULL) ? 0 : localRoot->height;
}

int getBalFactor(struct node *localRoot){
	return (localRoot == NULL) ? 0 : getHeight(localRoot->left)-getHeight(localRoot->right);
}

struct node *newNode(string KEY,int price){
	struct node *nNode = new node;
	nNode->KEY = KEY;
	nNode->left = nNode->right = NULL;
	nNode->height = 1;
	nNode->price = price;
	return nNode;
}

/*
 *			y	rightRotate->	x
 *		  /   \				   /  \
 *		x		c			 a		y
 *	  /  \						   /  \
 *  a      b	<-leftRotate	  b		c
 */
 
struct node *rightRotate(struct node *y){
	struct node *x = y->left;
	struct node *B = x->right;
	x->right = y;
	y->left = B;
	x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
	return x;
}

struct node *leftRotate(struct node *x){
	struct node *y = x->right;
	struct node *B = y->left;
	y->left = x;
	x->right = B;
	x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
	return y;
}

struct node *reBalance(struct node *localRoot){
	localRoot->height = max(getHeight(localRoot->left),getHeight(localRoot->right)) + 1;
	int bfactor = getBalFactor(localRoot);
	if(bfactor > 1 && getBalFactor(localRoot->left) < 0){
		localRoot->left = leftRotate(localRoot->left);
		return rightRotate(localRoot);
	}if(bfactor > 1 && getBalFactor(localRoot->left) >= 0){
		return rightRotate(localRoot);
	}if(bfactor < -1 && getBalFactor(localRoot->right) <= 0){
		return leftRotate(localRoot);
	}if(bfactor < -1 && getBalFactor(localRoot->right) > 0){
		localRoot->right = rightRotate(localRoot->right);
		return leftRotate(localRoot);
	}return localRoot;
}

struct node *insertValue(struct node *localRoot,string newKEY,int price){
	if(localRoot == NULL)return newNode(newKEY,price);
	if(localRoot->KEY < newKEY)localRoot->right = insertValue(localRoot->right,newKEY,price);
	else if(localRoot->KEY > newKEY)localRoot->left = insertValue(localRoot->left,newKEY,price);
	else return localRoot;
	return reBalance(localRoot);
}

int searchPrice(struct node *localRoot,string KEY){
	if(localRoot == NULL)return 0;
	if(localRoot->KEY < KEY)return searchPrice(localRoot->right,KEY);
	else if(localRoot->KEY > KEY)return searchPrice(localRoot->left,KEY);
	else return localRoot->price;
}

int main(){
	struct node *root = NULL;
	int n,m,a;long long sum;string s;
	cin>>n>>m;
	while(n--){
		cin>>s>>a;
		root = insertValue(root,s,a);
	}while(m--){sum=0;
		while(cin>>s,s!="."){
			sum+=searchPrice(root,s);
		}cout<<sum<<'\n';
	}
}
