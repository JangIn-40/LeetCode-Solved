class Solution {
public:
struct Trie 
{
    string name{};
    int count{};
    unordered_map<char, Trie*> child;
    string word{};
};

void asdf(vector<vector<char>>& board, int y, int x, Trie* curnode, vector<string>& answer, vector<Trie*>& vec) 
{
    char c{board[y][x]};
    if (!c || !curnode->child[c] || !curnode->count)
    {
        return;
    }
    curnode = curnode->child[c];
    vec.push_back(curnode);
    board[y][x] = 0;
    if (!curnode->word.empty()) 
    {
        answer.push_back(curnode->word);
        curnode->word.clear();
        for (auto& e : vec) 
        {
            e->count--;
        }
    }
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,-1,1};
    for (int i{}; i < 4; i++) 
    {
        if (y + dy[i] >= 0 && y + dy[i] < board.size() && x + dx[i] >= 0 && x + dx[i] < board[0].size())
        {
            asdf(board, y + dy[i], x + dx[i], curnode, answer, vec);
        }
    }
    board[y][x] = c;
    vec.pop_back();
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
{
    vector<string> answer;
    Trie* root = new Trie;
    for (auto e : words) 
    {
        Trie* curnode = root;
        curnode->name = "root";
        for (auto f : e) 
        {
            if (!curnode->child[f]) 
            {
                curnode->child[f] = new Trie;
                curnode->child[f]->name = f;
            }
            curnode->count++;
            curnode = curnode->child[f];
        }
        curnode->count++;
        curnode->word = e;
    }

    for (int i{}; i < board.size(); i++) 
    {
        for (int j{}; j < board[i].size(); j++) 
        {
            vector<Trie*> vec;
            asdf(board, i, j, root, answer, vec);
        }
    }
    return answer;
}
};