#include <iostream>
using namespace std;
template <class TYPE> class BST 
{
	TYPE val;
	BST<TYPE> *left,*right;
	public:
		BST<TYPE> (BST<TYPE> *left,TYPE val, BST<TYPE> *right)
		{
			this->left=left;
			this->val=val;
			this->right=right;
		}
		BST<TYPE>* insertVal(TYPE val)
		{
			BST<TYPE> *temp=this;
			if(!temp)	return new BST<TYPE>(NULL,val,NULL);
			if(temp->val>val)	temp->left=temp->left->insertVal(val);
			if(temp->val<val)	temp->right=temp->right->insertVal(val);
			return this;
		}
		TYPE findMin()
		{
			BST<TYPE> *temp=this;
			while(temp->left)	temp=temp->left;
			return temp->val; 
		}
		int findLevel(TYPE val,int level=0)
		{
			BST<TYPE> *temp=this;
			if(!temp)	return -99;
			if(temp->val==val)	return  level;
			if(temp->val>val)	return temp->left->findLevel(val,level+1);
			if(temp->val<val)	return temp->right->findLevel(val,level+1);
			return level;
		}
		BST<TYPE>* deleteVal(TYPE val)
		{
			BST<TYPE> *temp=this;
			if(!temp)	return temp;
			if(temp->val==val)
			{
				if(!temp->left&&!temp->right)	return NULL;
				if(!temp->left)	return temp->right;
				if(!temp->right)	return temp->left;
				temp->val=temp->right->findMin();
				temp->right=temp->right->deleteVal(temp->val);
				return  temp;
			}
			if(temp->val>val)	temp->left=temp->left->deleteVal(val);
			if(temp->val<val)	temp->right=temp->right->deleteVal(val);
			return this;
		}
		bool search(TYPE val)
		{
			if(!this)	return false;
			if(this->val==val)	return true;
			if(this->val<val&&this->right)	return this->right->search(val);
			if(this->val>val&&this->left)	return this->left->search(val);
			return false;
		}
		void inorder()
		{
			if(this->left)	this->left->inorder();
			cout<<this->val<<' ';
			if(this->right) this->right->inorder();
		}
		void preorder()
		{
			cout<<this->val<<endl;
			if(this->left)	this->left->preorder();
			if(this->right) this->right->preorder();
		}
		void postorder()
		{
			if(this->left)	this->left->postorder();
			if(this->right) this->right->postorder();
			cout<<this->val<<endl;
		}
		int countNodes()
		{
			if(!this)	return 0;
			return 1+this->right->countNodes()+this->left->countNodes();
		}
};
