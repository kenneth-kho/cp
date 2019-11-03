//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=358
//I use self-built AVL tree here, because why not :v
//Actually, you may use array and sort or use STL map
#include<iostream>
using namespace std;

struct node{
	string KEY;
	int height;
	int index;
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

struct node *newNode(string KEY,int index){
	struct node *nNode = new node;
	nNode->KEY = KEY;
	nNode->left = nNode->right = NULL;
	nNode->height = 1;
	nNode->index = index;
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

struct node *insertValue(struct node *localRoot,string newKEY,int index){
	if(localRoot == NULL)return newNode(newKEY,index);
	if(localRoot->KEY < newKEY)localRoot->right = insertValue(localRoot->right,newKEY,index);
	else if(localRoot->KEY > newKEY)localRoot->left = insertValue(localRoot->left,newKEY,index);
	else return localRoot;
	return reBalance(localRoot);
}

int searchIndex(struct node *localRoot,string KEY){
	if(localRoot == NULL)return 0;
	if(localRoot->KEY < KEY)return searchIndex(localRoot->right,KEY);
	else if(localRoot->KEY > KEY)return searchIndex(localRoot->left,KEY);
	else return localRoot->index;
}

int main(){
	struct node *root = NULL;
	int index=1;string s;
	for(char i='a';i<='z';i++){
		s="";s+=i;
		root=insertValue(root,s,index++);
	}for(char i='a';i<='z';i++){
		for(char j=i+1;j<='z';j++){
			s="";s+=i;s+=j;
			root=insertValue(root,s,index++);
		}
	}for(char i='a';i<='z';i++){
		for(char j=i+1;j<='z';j++){
			for(char k=j+1;k<='z';k++){
				s="";s+=i;s+=j;s+=k;
				root=insertValue(root,s,index++);
			}
		}
	}for(char i='a';i<='z';i++){
		for(char j=i+1;j<='z';j++){
			for(char k=j+1;k<='z';k++){
				for(char l=k+1;l<='z';l++){
					s="";s+=i;s+=j;s+=k;s+=l;
					root=insertValue(root,s,index++);
				}
			}
		}
	}for(char i='a';i<='z';i++){
		for(char j=i+1;j<='z';j++){
			for(char k=j+1;k<='z';k++){
				for(char l=k+1;l<='z';l++){
					for(char m=l+1;m<='z';m++){
						s="";s+=i;s+=j;s+=k;s+=l;s+=m;
						root=insertValue(root,s,index++);
					}
				}
			}
		}
	}while(cin>>s)cout<<searchIndex(root,s)<<'\n';
}
