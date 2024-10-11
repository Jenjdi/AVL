//#include<iostream>
//#include<assert.h>
//using namespace std;
//template<typename t>
//struct avlnode
//{
//	avlnode<t>* _left;
//	avlnode<t>* _right;
//	avlnode<t>* _parent;
//	t _val;
//	int _bf;
//	avlnode(t key)
//		:_left(nullptr),
//		_right(nullptr),
//		_parent(nullptr),
//		_val(key),
//		_bf(0)
//	{};
//};
//template<typename t>
//class avltree
//{
//public:
//	typedef avlnode<t> node;
//	bool insert(const t& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new node(key);
//			return true;
//		}
//		node* parent = nullptr;
//		node* cur = _root;
//		while (cur)
//		{
//			if (cur->_val < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_val > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		cur = new node(key);
//		if (parent->_val < key) {
//			parent->_right = cur;
//		}
//		else
//		{
//			parent->_left = cur;
//		}
//		cur->_parent = parent;
//		while (parent)
//		{
//			if (cur == parent->_left)
//			{
//				parent->_bf--;
//			}
//			else
//			{
//				parent->_bf++;
//			}
//			if (parent->_bf==0)
//			{
//				break;
//			}
//			else if (parent->_bf==1||parent->_bf==-1)
//			{
//				cur = parent;
//				parent = parent->_parent;
//			}
//			else if(parent->_bf==-2||parent->_bf==2)
//			{
//				if (parent->_bf == -2 && cur->_bf == -1)
//				{
//					rotate_right(parent);
//				}
//				else if (parent->_bf==2&&cur->_bf==1)
//				{
//					rotate_left(parent);
//				}
//				else if(parent->_bf==-2&&cur->_bf==1)
//				{
//					rotate_left_right(parent);
//				}
//				else if (parent->_bf==2&&cur->_bf==-1)
//				{
//					rotate_right_left(parent);
//				}
//			}
//			else
//			{
//				assert(false);
//			}
//		}
//		return true;
//	}
//	void rotate_left(node* cur)
//	{
//		node* subR = cur->_right;
//		node* subRL = subR->_left;
//		cur->_right = subRL;//当subLR为空时cur->right直接指向空
//		if (subRL)
//		{
//			
//			subRL->_parent = cur;
//		}
//		node* pcur = cur->_parent;
//		subR->_left = cur;
//		cur->_parent = subR;
//		if (cur == _root)
//		{
//			_root = subR;
//			subR->_parent = nullptr;
//		}
//		else
//		{
//			if (subR == pcur->_left)
//			{
//				pcur->_left = subR;
//			}
//			else
//			{
//				pcur->_right = subR;
//			}
//		}
//		cur->_bf = subR->_bf = 0;
//	}
//	
//	void rotate_right(node* parent)
//	{
//		node* subL = parent->_left;
//		node* subLR = subL->_right;
//		parent->_left = subLR;
//		if (subLR) {
//			subLR->_parent = parent;
//		}
//		node* ppNode = parent->_parent;
//		subL->_right = parent;
//		parent->_parent = subL;
//		if (_root == parent) {
//			_root = subL;
//			subL->_parent = nullptr;
//		}
//		else {
//			if (ppNode->_left == parent) {
//				ppNode->_left = subL;
//			}
//			else {
//				ppNode->_right = subL;
//			}
//			subL->_parent = ppNode;
//		}
//		//更新平衡因子
//		subL->_bf = parent->_bf = 0;
//	}
//	void rotate_left_right(node* parent) {
//		//要在单旋之前记录一下，因为单旋之后平衡因子会变
//		node* subL = parent->_left;
//		node* subLR = subL->_right;
//		int bf = subLR->_bf;//记录一下subLR的平衡因子
//		rotate_left(parent->_left);//先最左边进行一个左旋
//		rotate_right(parent);//再对自己进行一个右旋转
//		//如何区分三种情况的平衡因子更新呢？
//
//		subLR->_bf = 0;//一定要画图！三种情况的subLR最终都是0
//		if (bf == 1) {
//			//情况1
//			parent->_bf = 0;
//			subL->_bf = -1;
//		}
//		else if (bf == -1) {
//			//情况2
//			parent->_bf = 1;
//			subL->_bf = 0;
//		}
//		else if (bf == 0) {
//			//情况3
//			parent->_bf = 0;
//			subL->_bf = 0;
//		}
//		else assert(false);
//	}
//	void rotate_right_left(node* parent) {
//		node* subR = parent->_right;
//		node* subRL = subR->_left;
//		int bf = subRL->_bf;
//		rotate_right(parent->_right);
//		rotate_left(parent);
//		subRL->_bf = 0;
//		if (bf == 1) {
//			subR->_bf = 0;
//			parent->_bf = -1;
//		}
//		else if (bf == -1) {
//			subR->_bf = 1;
//			parent->_bf = 0;
//		}
//		else if (bf == 0) {
//			subR->_bf = 0;
//			parent->_bf = 0;
//		}
//		else assert(false);
//	}
//	node* find(const t& key)
//	{
//		node* cur = _root;
//		while (cur) {
//			if (cur->_val > key) {
//				cur = cur->_left;
//			}
//			else if (cur->_val<key)
//			{
//				cur = cur->_right;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//		return nullptr;
//	}
//	bool erase(const t& key) 
//	{
//		if (find(key) == nullptr)
//		{
//			return false;
//		}
//		node* cur = find(key);
//
//	}
//	void inorder() {
//		_inorder(_root);
//	}
//private:
//	node* _root=nullptr;
//	void _inorder(node* root) {
//		if (root == nullptr) {
//			return;
//		}
//		_inorder(root->_left);
//		cout << root->_val<<" ";
//		_inorder(root->_right);
//	}
//};
//
#include<iostream>
#include<assert.h>
using namespace std;
template<typename Val>
struct AVLnode
{
	AVLnode* _left;
	AVLnode* _right;
	AVLnode* _parent;
	Val _val;
	int _bf;
	AVLnode(Val val)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_val(val),
		_bf(0) {};
};
template<typename T>
class AVL
{
public:
	typedef AVLnode<T> Node;
	bool insert(T val)
	{
		if (_root == nullptr)
		{
			_root->_val = val;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_val < val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_val > val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(val);
		if (cur->_val < parent->_val)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					rightrotate(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					leftrotate(parent);
				}
				else if (parent->_bf == -2 && cur->_bf = 1)
				{
					left_right_rotate(parent);
				}
				else if (parent->_bf == 2 && cur->_bf = -1)
				{
					right_left_rotate(parent);
				}
			}
		}
		return true;
	}
		
	void leftrotate(Node * parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_left = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		Node* pparent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (subR == pparent->_left)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_parent = subR;
			}
			subR->_parent = pparent;
		}
		subR->_bf = parent->_bf = 0;
	}
	void rightrotate(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		Node* pparent = parent->_parent;
		subL->_left = parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (subL == pparent->_left)
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}
		parent->_bf = subL->_bf = 0;
	}
	void left_right_rotate(Node* parent)
	{
		while (parent)
		{
			leftrotate(parent->_left);
			rightrotate(parent);
			parent = parent->_parent;
		}
	}
	
	
private:
	Node* _root = nullptr;
};

