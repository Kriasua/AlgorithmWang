//
#include<string>
#include<vector>
#include <sstream>
#include <iostream>
#include<array>
#include "pch.h"
namespace
{
    const int MAX = 10001;
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    class Codec {
    public:
        std::vector<std::string> split(const std::string& s, char delimiter) {
            std::vector<std::string> tokens;
            std::string token;
            std::istringstream tokenStream(s);

            while (std::getline(tokenStream, token, delimiter)) {
                tokens.push_back(token);
            }

            return tokens;
        }

        void s(TreeNode* root, std::string& ans)
        {
            if (root == nullptr)
            {
                ans.append("#,");
                return;
            }

            std::string str = std::to_string(root->val);
            ans.append(str + ",");

            s(root->left, ans);
            s(root->right, ans);

        }

        std::string serialize(TreeNode* root) {
            std::string ans;
            s(root,ans);
            return ans;
        }

        int cnt = 0;

        TreeNode* d(std::vector<std::string>& str)
        {
            std::string cur = str[cnt++];
            if (cur == "#")
            {
                return nullptr;
            }

            TreeNode* head = new TreeNode(std::stoi(cur));
            head->left = d(str);
            head->right = d(str);
            return head;
        }

        TreeNode* deserialize(std::string data) {
            char delimiter = ',';
            std::vector<std::string> ans = split(data, delimiter);
            cnt = 0;
            return d(ans);
        }
    };

    class Codec2 {
    private:
        std::array<TreeNode*, MAX> queue;
        int l, r;
        int size;
    public:
        
        std::vector<std::string> split(const std::string& s, char delimiter) {
            std::vector<std::string> tokens;
            std::string token;
            std::istringstream tokenStream(s);
            while (std::getline(tokenStream, token, delimiter)) {
                tokens.push_back(token);
            }
            return tokens;
        }
       

        std::string serialize(TreeNode* root) {
            std::string ans;
            if (root == nullptr)
            {
                return ans;
            }
            
            l = r = 0;
            queue[r++] = root;
            ans.append(std::to_string(root->val) + ",");
            while (l < r)
            {
                if (queue[l]->left != nullptr)
                {
                    queue[r++] = queue[l]->left;
                    ans.append(std::to_string(queue[l]->left->val) + ",");
                }
                else
                {
                    ans.append("#,");
                }

                if (queue[l]->right != nullptr)
                {
                    queue[r++] = queue[l]->right;
                    ans.append(std::to_string(queue[l]->right->val) + ",");
                }
                else
                {
                    ans.append("#,");
                }
                l++;     
                
            }
            return ans;
        }

        TreeNode* generate(std::string str)
        {
            return str == "#" ? nullptr : new TreeNode(std::stoi(str));
        }

        TreeNode* deserialize(std::string data) {
            if (data == "")
            {
                return nullptr;
            }

            int index = 0;
            l = r = 0;

            char delimiter = ',';
            std::vector<std::string> ans = split(data, delimiter);
           

            TreeNode* root = new TreeNode(std::stoi(ans[index++]));
            queue[r++] = root;

            while (l < r)
            {
                TreeNode* cur = queue[l++];
                cur->left = generate(ans[index++]);
                cur->right = generate(ans[index++]);

                if (cur->left != nullptr)
                {
                    queue[r++] = cur->left;
                }

                if (cur->right != nullptr)
                {
                    queue[r++] = cur->right;
                }
            }

            return root;
           
            
        }
    };

	class Codec3 {
	public:
        int str2int(std::string str)
        {
            int ans = 0;
            int a = 1;
            if (str[0] == '-')
            {
                for (int i = str.size() - 1; i >= 1; i--)
                {
                    ans += (str[i] - '0') * a;
                    a *= 10;
                }

                return -ans;
            }
            else
            {
				for (int i = str.size() - 1; i >= 0; i--)
				{
					ans += (str[i] - '0') * a;
					a *= 10;
				}
                return ans;
            }
        }


        void f1(std::string& ans, TreeNode* node)
        {
            if (node == nullptr)
            {
                ans += "#,";
                return;
            }

            std::string str = std::to_string(node->val);
            ans += str;
            ans += ",";

            f1(ans, node->left);
            f1(ans, node->right);
        }

		std::string serialize(TreeNode* root) {
            std::string ans;
            f1(ans, root);
            return ans;
		}

        
        TreeNode* f2(std::vector<int>& arr, int& pos)
        {
            if (pos == arr.size())
            {
                return nullptr;
            }

            if (arr[pos] == INT_MAX)
            {
                return nullptr;
            }

            TreeNode* node = new TreeNode(arr[pos]);
            pos++;
            node->left = f2(arr, pos);
            pos++;
            node->right = f2(arr, pos);
            return node;
        }

		TreeNode* deserialize(std::string data) {
            std::vector<int> arr;
            int i = 0;
            for (; i < data.size(); i++)
            {
                std::string tmp= "";
                while (data[i] != ',')
                {
                    tmp += data[i];
                    i++;
                }
                if (tmp == "#")
                {
                    arr.push_back(INT_MAX);
                }
                else
                {
                    arr.push_back(str2int(tmp));
                }
            }

            int pos = 0;

            return f2(arr, pos);

		}
	};
}