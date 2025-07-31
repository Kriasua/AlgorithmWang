/*
С͵�ַ�����һ���µĿ����Եĵ������������ֻ��һ����ڣ����ǳ�֮Ϊ root ��

���� root ֮�⣬ÿ����������ֻ��һ��������������֮������һ�����֮�󣬴�����С͵��ʶ��
������ط������з��ݵ�����������һ�ö��������� ��� ����ֱ�������ķ�����ͬһ�����ϱ���� ��
���ݽ��Զ�������

������������ root ������ �ڲ���������������� ��С͵�ܹ���ȡ����߽�� ��*/
#include<cmath>
#include<algorithm>
#include "pch.h"

namespace 
{
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:

        int yes;
        int no;

        void f(TreeNode* root)
        {
            if (root == nullptr)
            {
                yes = 0;
                no = 0;
            }
            else {
                int y = root->val;
                int n = 0;
                rob(root->left);
                y += no;
                n += std::max(yes, no);
                rob(root->right);
                y += no;
                n += std::max(yes, no);

                yes = y;
                no = n;
            }
        }
        int rob(TreeNode* root) {

            f(root);

            return std::max(yes, no);

        }
    };
}