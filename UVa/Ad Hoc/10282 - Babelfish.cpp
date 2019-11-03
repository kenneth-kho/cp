//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1223
//I use self-built AVL tree here, because why not :v
//Actually, you may use array and sort then do binary search or use STL map
#include<iostream>
#include<sstream>
using namespace std;

struct node{
	string KEY;
	int height;
	string answer;
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

struct node *newNode(string KEY,string answer){
	struct node *nNode = new node;
	nNode->KEY = KEY;
	nNode->left = nNode->right = NULL;
	nNode->height = 1;
	nNode->answer = answer;
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

struct node *insertValue(struct node *localRoot,string newKEY,string answer){
	if(localRoot == NULL)return newNode(newKEY,answer);
	if(localRoot->KEY < newKEY)localRoot->right = insertValue(localRoot->right,newKEY,answer);
	else if(localRoot->KEY > newKEY)localRoot->left = insertValue(localRoot->left,newKEY,answer);
	else return localRoot;
	return reBalance(localRoot);
}

string searchAnswer(struct node *localRoot,string KEY){
	if(localRoot == NULL)return "eh";
	if(localRoot->KEY < KEY)return searchAnswer(localRoot->right,KEY);
	else if(localRoot->KEY > KEY)return searchAnswer(localRoot->left,KEY);
	else return localRoot->answer;
}

int main(){
	struct node *root = NULL;
	string s,first,second;
	while(getline(cin,s),s!=""){
		istringstream in(s);
		in >> first >> second;
		root = insertValue(root,second,first);
	}while(cin>>s)cout<<searchAnswer(root,s)<<'\n';
}
