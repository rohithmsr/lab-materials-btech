// https://www.codingninjas.com/codestudio/problems/implement-trie_1387095

struct Node {
    Node* links[26];
    bool isWord = false;
    int cw = 0;
    int cp = 0;
    
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void setWord(){
        isWord = true;
        ++cw;
    }
    
    int getWords(){
        return cw;
    }
    
    void deleteWord(){
        --cw;
        if(cw == 0)
            isWord = false;
    }
    
    int getPrefixWords(){
        return cp;
    }
    
    void increasePrefix(){
        ++cp;
    }
    
    void decreasePrefix(){
        --cp;
    }
};

class Trie{
    Node* root;
    
    bool search(string word) {
        Node* curr = root;
        
        for(int i = 0; i < word.size(); ++i){
            if(!curr->containsKey(word[i])){
                return false;
            }
            curr = curr->get(word[i]);
        }
        
        return curr->getWords() > 0;
    }
    
public:
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* curr = root;
        
        for(int i = 0; i < word.size(); ++i){
            if(!curr->containsKey(word[i])){
                curr->put(word[i], new Node());
            }
            
            curr = curr->get(word[i]);
            curr->increasePrefix();
        }
        
        curr->setWord();
    }

    int countWordsEqualTo(string &word){
        Node* curr = root;
        
        for(int i = 0; i < word.size(); ++i){
            if(!curr->containsKey(word[i])){
                return 0;
            }
            
            curr = curr->get(word[i]);
        }
        
        return curr->getWords();
    }

    int countWordsStartingWith(string &word){
        Node* curr = root;
        
        for(int i = 0; i < word.size(); ++i){
            if(!curr->containsKey(word[i])){
                return 0;
            }
            
            curr = curr->get(word[i]);
        }
        
        return curr->getPrefixWords();
    }

    void erase(string &word){
        Node* curr = root;
        
        if(!search(word))
            return;
        
        for(int i = 0; i < word.size(); ++i){
            if(!curr->containsKey(word[i])){
                return;
            }
            
            curr = curr->get(word[i]);
            curr->decreasePrefix();
        }
        
        curr->deleteWord();
    }
};
