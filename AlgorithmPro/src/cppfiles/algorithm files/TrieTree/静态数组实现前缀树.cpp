#include<iostream>
#include<array>
#include<vector>
#include<climits>

namespace
{
	const int MAX = 150001;
	std::vector<int> pass ;
	std::vector<int> end ;
	std::vector<std::vector<int>> trie;
	int cnt = 1;

	void build()
	{
		cnt = 1;
	}

	void clear()
	{
		std::fill(pass.begin(), pass.end(),0);
		std::fill(end.begin(), end.end(), 0);
		for (auto& row : trie)
		{
			std::fill(row.begin(), row.end(), 0);
		}
	}
	void insert(std::string& word)
	{
		int node = 1;
		pass[1]++;
		for (int i = 0; i < word.size(); i++)
		{
			if (trie[node][word[i] - 'a'] == 0)
			{
				trie[node][word[i] - 'a'] = ++cnt;
			}
			node = trie[node][word[i] - 'a'];
			pass[node]++;
		}
		end[node]++;
	}

	bool search(std::string& word) 
	{
		int node = 1;
		for (int i = 0; i < word.size(); i++)
		{
			if (trie[node][word[i] - 'a'] == 0)
			{
				return false;
			}
			node = trie[node][word[i] - 'a'];
		}

		if (end[node] != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void erase(std::string& word)
	{
		if (!search(word))
		{
			return;
		}

		int node = 1;
		pass[node]--;
		int tmp;
		for (int i = 0; i < word.size(); i++)
		{
			if (--pass[trie[node][word[i] - 'a']] == 0)
			{
				trie[node][word[i] - 'a'] = 0;
				return;
			}
			node = trie[node][word[i] - 'a'];		
		}
		end[node]--;
	}

	int prefixNumber(std::string& word)
	{
		int node = 1;
		for (int i = 0; i < word.size(); i++)
		{
			if (trie[node][word[i] - 'a'] == 0)
			{
				return 0;
			}
			node = trie[node][word[i] - 'a'];
		}

		return pass[node];
	}

	int main()
	{
		pass.resize(MAX, 0);
		end.resize(MAX, 0);
		trie.resize(MAX, std::vector<int>(26, 0));
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		int times, op;
		std::string word;
		while (std::cin >> times) {
			build();
			for (int i = 0; i < times; i++)
			{
				std::cin >> op;
				std::cin >> word;
				if (op == 1)
				{
					insert(word);
				}
				else if (op == 2)
				{
					erase(word);
				}
				else if (op == 3)
				{
					bool isInTrie = search(word);
					if (isInTrie)
					{
						std::cout << "YES\n";
					}
					else
					{
						std::cout << "NO\n";
					}
				}
				else
				{
					std::cout << prefixNumber(word) << "\n";
				}
			}
			clear();
		}

	}

	
}

