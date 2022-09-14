// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string getMultipliedText(vector<vector<int>>& keyMatrix, vector<int>& chunkMatrix, int n){
    vector<vector<int>> mult(n, vector<int>(1, 0));
    
    int r1 = n;
    int r2 = n;
    int c1 = n;
    int c2 = 1;
    
    for(int i = 0; i < r1; ++i)
        for(int j = 0; j < c2; ++j)
            for(int k = 0; k < c1; ++k)
            {
                mult[i][j] += keyMatrix[i][k] * chunkMatrix[k];
            }
            
    string res = "";
    for(int i = 0; i < n; ++i){
        res += (mult[i][0] % 26) + 'A';
    }
    return res;
}

string encrypt(string message, string key, int n){
    int len = message.size();
    string res = "";
    
    vector<vector<int>> keyMatrix(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            keyMatrix[i][j] = toupper(key[i * 3 + j]) - 'A';
        }
    }
    
    vector<int> chunkMatrix(n, 'Q' - 'A');
    string temp = "";
    for(int i = 0; i < len; i++){
        temp += message[i];
        chunkMatrix[i % n] = toupper(message[i]) - 'A';
        
        if(temp.size() == n){
            res += getMultipliedText(keyMatrix, chunkMatrix, n);
            
            temp = "";
        }
    }
    
    int remain = n - temp.size();
    if(remain != 0){
        res += getMultipliedText(keyMatrix, chunkMatrix, n);
        
        while(remain > 0){
            res.pop_back();
            --remain;
        }
    }
    
    return res;
}

int main() {
    int n = 3;
    
    string key;
    cout << "Key of size (3 x 3) : ";
    cin >> key;
    
    string message;
    cout << "Message : ";
    getline(cin >> ws, message, '\n');
    
    string cipher = encrypt(message, key, n);
    cout << "Encrypted Text : " << cipher << endl;

    return 0;
}
