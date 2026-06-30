class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;

    bool searchHelper(string word, int i, TrieNode* node) {
        if (i == word.length()) {
            return node->isEnd;
        }

        char ch = word[i];

        if (ch == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->children[j] != nullptr) {
                    if (searchHelper(word, i + 1, node->children[j])) {
                        return true;
                    }
                }
            }
            return false;
        }
        else {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            return searchHelper(word, i + 1, node->children[index]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};