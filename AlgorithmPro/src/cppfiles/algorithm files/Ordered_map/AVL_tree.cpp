#include<algorithm>
#include<stack>
namespace 
{
	struct AVLNode
	{
		int key;
		int height = 1;
		AVLNode* left = nullptr;
		AVLNode* right = nullptr;
		int count = 1;
		int size = 1;

		AVLNode(int k) : key(k){}
	};

	struct NodePath
	{
		AVLNode* node = nullptr;
		int direction;

		NodePath(int d, AVLNode* n) : direction(d),node(n){}
	};


	class AVL
	{
	public:
		AVLNode* head = nullptr;

		void add(int k)
		{
			if (head == nullptr)
			{
				head = new AVLNode(k);
				return;
			}

			std::stack<NodePath> paths;
			AVLNode* cur = head;
			while (cur != nullptr)
			{
				if (k > cur->key)
				{
					paths.push({ 1, cur });
					cur = cur->right;
				}
				else if (k < cur->key)
				{
					paths.push({ 0, cur });
					cur = cur->left;
				}
				else
				{
					cur->count++;
					while (!paths.empty())
					{
						NodePath path = paths.top();
						paths.pop();
						up(path.node);
					}
					return;
				}
			}

			AVLNode* newNode = new AVLNode(k);
			cur = newNode;
			while (!paths.empty())
			{
				NodePath path = paths.top();
				paths.pop();
				cur = maintain(cur);
				if (path.direction == 0)
				{
					path.node->left = cur;
				}
				else
				{
					path.node->right = cur;
				}
				cur = path.node;
			}
			head = maintain(cur);
		}

		AVLNode* find(int k)
		{
			AVLNode* cur = head;
			while (cur != nullptr)
			{
				if (k > cur->key)
				{
					cur = cur->right;
				}
				else if(k < cur->key)
				{
					cur = cur->left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		void remove(int k)
		{

		}

		AVLNode* maintain(AVLNode* node)
		{
			up(node);
			int lh = node->left ? node->left->height : 0;
			int rh = node->right ? node->right->height : 0;

			if ((lh - rh) >= 2)
			{
				//确定是L型违规
				//然后再判断是LL还是LR
				int llh = node->left->left ? node->left->left->height : 0;
				int lrh = node->left->right ? node->left->right->height : 0;
				if (llh >= lrh)
				{
					//LL型
					return rightRotate(node);
				}
				else
				{
					//LR型
					AVLNode* left = node->left;
					node->left = leftRotate(left);
					return rightRotate(node);
				}
			}
			else if ((rh - lh) >= 2)
			{
				//确定是R型违规
				//然后再判断是RR还是RL
				int rrh = node->right->right ? node->right->right->height : 0;
				int rlh = node->right->left ? node->right->left->height : 0;
				if (rrh >= rlh)
				{
					//RR型
					return leftRotate(node);
				}
				else
				{
					//RL型
					AVLNode* right = node->right;
					node->right = rightRotate(right);
					return leftRotate(node);
				}
			}
			else
			{
				return node;
			}
		}

		void up(AVLNode* node)
		{
			int lh = node->left ? node->left->height : 0;
			int rh = node->right ? node->right->height : 0;
			int ls = node->left ? node->left->size : 0;
			int rs = node->right ? node->right->size : 0;
			node->height = std::max(lh, rh) + 1;
			node->size = ls + rs + node->count;
		}

		AVLNode* leftRotate(AVLNode* node)
		{
			AVLNode* right = node->right;
			node->right = right->left;
			right->left = node;
			up(node);
			up(right);
			return right;
		}

		AVLNode* rightRotate(AVLNode* node)
		{
			AVLNode* left = node->left;
			node->left = left->right;
			left->right = node;
			up(node);
			up(left);
			return left;
		}
	

	};
}