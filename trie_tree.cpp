
// Example program for basic Trie Tree

#include <iostream>
#include <unordered_map>

using namespace std;


// Node class for Trie Tree
class TrieNode
{
public:
    unordered_map<char, TrieNode*> umap;
    bool isCompleteWord; 
    char ch;

    // Default constructor
    TrieNode()
    {
        ch = '*';
        isCompleteWord = false;
        umap['*'] = NULL;
    }

    // Parameterized constructor
    TrieNode(char chr)
    {
        ch = chr;
        isCompleteWord = false;
        umap['*'] = NULL;
    }

    // Function to check if given char is accessible via current node
    bool contains(char ch)
    {
        return umap.find(ch) != umap.end();
    }
};


// Function to insert a word into trie tree
TrieNode* insertIntoTrieTree(TrieNode *root, const string word)
{
    const int n = word.length();

    // Base case
    if (n == 0)
    {
        return root;
    }

    TrieNode *temp;
    temp = root;

    // Iterate over every char of given word
    int i = 0;
    while(i < n)
    {
        // If curr char is not in trie tree continuation, add it
        if (!temp->contains(word[i]))
        {
            temp->umap[word[i]] = new TrieNode(word[i]);
        }
        
        // If curr char is last we mark the node as word-done
        if (i == n-1)
        {
            
            temp->isCompleteWord = true;
            break;
        }

        // Move to next node
        temp = temp->umap[word[i]];

        // Move to next char
        i++;
    }

    // Return the root node of trie tree - optional
    return root;
}


// Function for preorder traversal of trie tree
void display_preorder(TrieNode *root)
{
    if (root != NULL)
    {
        cout<<root->ch<<" ";
        
        for (auto it = root->umap.begin(); it != root->umap.end(); it++)
        {
            display_preorder(it->second);
        }
    }
}


// Function to check if given word is in trie tree or not
bool isInTrieTree(TrieNode *root, const string word)
{
    const int n = word.length();
    int i = 0;
    while (root!=NULL && i < n)
    {
        if (i == n-1)
        {
            return root->isCompleteWord;
        }
        if (!root->contains(word[i]))
        {
            return false;
        }
        else
        {
            root = root->umap[word[i]];
            i += 1;
        }
        
    }
    return false;
}

int main()
{
    // Root Node of our Trie Tree
    TrieNode *root = new TrieNode();

    // List of words for which Trie Tree needs to be made
    const string words[] = {
        "cat",
        "car",
        "card",
        "cards",
        "cats",
        "human",
        "humans"
    };

    // Number of words in above list
    const int n = 7;

    // Add each word to trie tree
    for (int i=0; i<n; i++)
    {
        root = insertIntoTrieTree(root, words[i]);
    }

    // Checking
    cout<<"character:"<<isInTrieTree(root, "character")<<endl;
    cout<<"cat:"<<isInTrieTree(root, "cat")<<endl;
    cout<<"cats:"<<isInTrieTree(root, "cats")<<endl;
    cout<<"human:"<<isInTrieTree(root, "human")<<endl;
    cout<<"humans:"<<isInTrieTree(root, "humans")<<endl;

    // Display preorder traversal
    display_preorder(root);

    return 0;
}