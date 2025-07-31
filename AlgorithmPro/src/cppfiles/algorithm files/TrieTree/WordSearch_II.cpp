

#include<string>
#include<vector>
#include<array>
namespace
{
    using std::vector;
    using std::string;
    class Solution {
    public:
        const int MAX = 3000001;
        vector<std::array<int, 26>> trie;
        vector<string> end;
        vector<int> pass;
        int cnt = 1;

        Solution() : cnt(1)
        {
            trie.assign(MAX, std::array<int, 26>{});
            end.resize(MAX, "");
            pass.resize(MAX, 0);
        }

        void clear()
        {
            std::fill(trie.begin(), trie.begin() + cnt, std::array<int, 26>{});
            for (int i = 0; i <= cnt; i++)
            {
                end[i] = "";
                pass[i] = 0;
            }
        }

        void build(vector<string>& words)
        {
            cnt = 1;
            for (string word : words)
            {
                int cur = 1;
                pass[cur]++;
                int path;
                for (int i = 0; i < word.size(); i++)
                {
                    path = word[i] - 'a';
                    if (trie[cur][path] == 0)
                    {
                        trie[cur][path] = ++cnt;
                    }

                    cur = trie[cur][path];
                    pass[cur]++;
                }
                end[cur] = word;
            }
        }

        int f(vector<string>& ans, vector<vector<char>>& board, int i, int j, int t)
        {
            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 0)
            {
                return 0;
            }
            
            int road = board[i][j] - 'a';
            t = trie[t][road];
            if (pass[t] == 0)
            {
                return 0;
            }

            char tmp = board[i][j];
            board[i][j] = 0;

            int fix = 0;
            if (end[t] != "")
            {
                ans.push_back(end[t]);
                fix++;
                end[t] = "";
            }

            fix += f(ans, board, i - 1, j, t);
            fix += f(ans, board, i + 1, j, t);
            fix += f(ans, board, i, j - 1, t);
            fix += f(ans, board, i, j + 1, t);

            board[i][j] = tmp;
            pass[t] -= fix;
            return fix;

        }

        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            vector<string> ans;
            build(words);
            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[0].size(); j++)
                {
                    f(ans, board, i, j, 1);
                }
            }

            clear();
            return ans;
        }
    };
}