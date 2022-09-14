#include <iostream>
#include <vector>

using namespace std;

class RailFence {
    int key;

public:
    RailFence(int key = 3){
        this->key = key;
    }
    
    string encrypt(string text){
        string cipher = "";
        
        int size = text.size();
        string holder(size, '-');
        
        vector<string> rail(key, holder);
     
        bool down = false;
        int row = 0;
        int col = 0;
     
        for (int i = 0; i < size; i++)
        {
            if (row == 0 || row == key - 1)
                down = !down;
     
            rail[row][col++] = text[i];
            
            down ? row++ : row--;
        }
     
        for (int i = 0; i < key; i++)
            for (int j = 0; j < size; j++)
                if (rail[i][j] != '-')
                    cipher.push_back(rail[i][j]);
    
        return cipher;
    }
    
    string decrypt(string cipher){
        string res = "";
        
        int size = cipher.size();
        string holder(size, '-');
        vector<string> rail(key, holder);
     
        bool down = true;
        int row = 0;
        int col = 0;
     
        for (int i = 0; i < size; i++)
        {
            if (row == 0)
                down = true;
            else if(row == key - 1)
                down = false;
     
            rail[row][col++] = '*';
            
            down ? row++ : row--;
        }
     
        int index = 0;
        for (int i = 0; i < key; i++){
            for (int j = 0; j < size; j++){
                if (rail[i][j] == '*' && index < size){
                    rail[i][j] = cipher[index++];
                }
            }
        }
        
        // cout << endl;
        // for(auto s : rail)
        //     cout << s << endl;
                    
        down = true;
        row = 0;
        col = 0;
        for (int i = 0; i < size; i++)
        {
            if (row == 0)
                down = true;
            else if(row == key - 1)
                down = false;
     
            if(rail[row][col] != '*')
                res += rail[row][col++];
            
            down ? row++ : row--;
        }
    
        return res;
    }
};

int main()
{
    int key;
    cout << "Enter key size : ";
    cin >> key;
    
    RailFence ac = RailFence(key);
    
    string msg;
    cout << "Message : ";
    getline(cin >> ws, msg, '\n');
    
    string cipher = ac.encrypt(msg);
    cout << "Encrypt : " << cipher << endl;
    cout << "Decrypt : " << ac.decrypt(cipher) << endl;

    return 0;
}
