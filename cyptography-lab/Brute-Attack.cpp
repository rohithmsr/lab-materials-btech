#include <iostream>
#include <string>

using namespace std;

unsigned long long n_attempt = 0;

bool permute(string full, string password, string temp, int k, int n)
{
    if (k == 0)
    {
        n_attempt++;
        
        if(temp == password){
            cout << "Cracked The Password Successfully......." << endl;
            cout << "Password :" << temp << '\n' ;
            cout << "Found it at attempt #" << n_attempt << endl;
            
            return true;
        }
        
        return false;
    }
 
    for (int i = 0; i < n; i++)
    {
        if(permute(full, password, temp + full[i], k - 1, n))
            return true;
    }
    
    return false;
}

int main(){
    string username, pword;
    cout << "Enter Username: ";
    cin >> username ;
    
    int k;
    cout << "Enter the password size : ";
    cin >> k;
    
    cout << "Enter Password : ";
    cin >> pword ;
    
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+={}:><?/.,;[]`~" ;
    int n = alphabet.size();
    
    permute(alphabet, pword, "", k, n);
}
