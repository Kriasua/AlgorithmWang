//Ç°×ºÊ÷
//https://leetcode.cn/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
#include<string>
namespace
{
	class Trie {
	public:
		Trie() {
			m_count = 1;
			m_trie.resize(MAX, std::vector<int>(26));
			pass.resize(MAX);
			end.resize(MAX);
		}

		void insert(std::string word) {
			int n = word.size();
			int curNode = 1;
			for (int i = 0; i < n; i++)
			{
				if (m_trie[curNode][word[i] - 'a'] == 0)
				{
					m_trie[curNode][word[i] - 'a'] = ++m_count;
				}
				curNode = m_trie[curNode][word[i] - 'a'];
				pass[curNode]++;
			}
			end[curNode]++;
		}

		bool search(std::string word) {
			int n = word.size();
			int curNode = 1;
			for (int i = 0; i < n; i++)
			{
				if (m_trie[curNode][word[i] - 'a'] == 0)
				{
					return false;
				}
				curNode = m_trie[curNode][word[i] - 'a'];
			}

			return end[curNode] != 0;
		}

		bool startsWith(std::string prefix) {
			int n = prefix.size();
			int curNode = 1;
			for (int i = 0; i < n; i++)
			{
				if (m_trie[curNode][prefix[i] - 'a'] == 0)
				{
					return false;
				}
				curNode = m_trie[curNode][prefix[i] - 'a'];
			}
			return true;
		}

	private:
		std::vector<std::vector<int>> m_trie;
		std::vector<int> pass;
		std::vector<int> end;
		int m_count;
		const int MAX = 150001;
	};
}