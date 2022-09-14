/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

// Moodle
// Brute attack in caeser

using namespace std;

class Affine {
    int m;
    int a;
    int b;
    int a_inv;

private:
    int findInverse(){
        for(int i = 25; i >= 0; --i){
            int flag = (a * i) % m;
            
            if(flag == 1){
                return i;
            }
        }
        
        return 1;
    }
    
public:
    Affine(int a, int b, int m = 26){
        this->a = a;
        this->b = b;
        this->m = m;
        
        this->a_inv = findInverse();
    }
    
    string encrypt(string str){
        string cipher = "";
        
        for(char c : str){
            if(isalpha(c)){
                char base = 'A';
                cipher += ((a * (c - base) + b) % 26) + base;
            }
            else{
                cipher += c;
            }
        }
        
        return cipher;
    }
    
    string decrypt(string str){
        string text = "";
        
        for(char c : str){
            if(isalpha(c)){
                char base = 'A';
                text += (char) (((a_inv * ((c + base - b)) % 26)) + base);
            }
            else{
                text += c;
            }
        }
        
        return text;
    }
};

int main()
{
    Affine ac = Affine(17, 20, 26);
    
    string msg;
    cout << "Message : ";
    getline(cin, msg, '\n');
    
    string cipher = ac.encrypt(msg);
    cout << "Encrypt : " << cipher << endl;
    cout << "Decrypt : " << ac.decrypt(cipher) << endl;

    return 0;
}
