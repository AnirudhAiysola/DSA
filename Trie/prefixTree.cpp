class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool endWord = false;
};
class Trie
{
public:
    TrieNode root;
    Trie()
    {
    }
    void insert(string word)
    {
        TrieNode *curr = &root;
        for (auto it : word)
        {
            if (!curr->children.count(it))
            {
                curr->children[it] = new TrieNode();
            }
            curr = curr->children[it];
        }
        curr->endWord = true;
    }

    bool search(string word)
    {
        TrieNode *curr = &root;
        for (auto it : word)
        {
            if (!curr->children.count(it))
            {
                return false;
            }
            curr = curr->children[it];
        }
        return curr->endWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = &root;
        for (auto it : prefix)
        {
            if (!curr->children.count(it))
            {
                return false;
            }
            curr = curr->children[it];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */