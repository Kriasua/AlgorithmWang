// 另一棵树的子树
// 给你两棵二叉树root和subRoot
// 检验root中是否包含和subRoot具有相同结构和节点值的子树
// 如果存在，返回true
// 否则，返回false
// 测试链接 : https://leetcode.cn/problems/subtree-of-another-tree/

#include<string>
#include<vector>
namespace
{
  

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    class Solution {
    public:
		std::vector<int> getNext(std::string& s2)
		{
			int n = s2.size();
			if (n == 1)
			{
				return { -1 };
			}

			if (n == 2)
			{
				return { -1,0 };
			}

			std::vector<int> next(n);
			for (int i = 2; i < n; i++)
			{
				int y = i - 1;
				while (y != 0)
				{
					if (s2[next[y]] == s2[i - 1])
					{
						break;
					}
					else
					{
						y = next[y];
					}
				}
				next[i] = next[y] + 1;
			}
			return next;

		}

		//给定字符串s1，s2。求s2是否是s1的字串。如果是的话返回起始位置，不是的话返回-1。
		int KMP(std::string& s1, std::string& s2)
		{
			int m = s1.size();
			int n = s2.size();
			std::vector<int> next = getNext(s2);

			int x = 0;
			int y = 0;
			while (x < m && y < n)
			{
				if (s1[x] == s2[y])
				{
					x++;
					y++;
				}
				else
				{
					if (y == 0)
					{
						x++;
					}
					else
					{
						y = next[y];
					}
				}
			}

			if (y != n)
			{
				return -1;
			}
			else
			{
				return x - n;
			}
		}

        void f(TreeNode* node, std::string& s)
        {
			if (node == nullptr)
			{
				s += "null,";
				return;
			}

			f(node->left, s);
			f(node->right, s);
			s += std::to_string(node->val);
			s += ',';
        }

        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            std::string s1;
            std::string s2;
			f(root, s1);
			f(subRoot, s2);
			return KMP(s1, s2) >= 0;
        }
    };
}