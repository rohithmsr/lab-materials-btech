// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> getReverseMatrix(vector<vector<int>>& x){
    int n = x.size();
    
    vector<vector<int>> y(n, vector<int>(n));
    
    y[0][0] = x[1][1] * x[2][2] - x[1][2] * x[2][1];
	y[0][1] = -1 *(x[1][0] *x[2][2] - x[1][2] *x[2][0]);
	y[0][2] = x[1][0] *x[2][1] - x[1][1] *x[2][0];
	y[1][0] = -1 *(x[0][1] *x[2][2] - x[2][1] *x[0][2]);
	y[1][1] = x[0][0] *x[2][2] - x[0][2] *x[2][0];
	y[1][2] = -1 *(x[0][0] *x[2][1] - x[0][1] *x[2][0]);
	y[2][0] = x[0][1] * x[1][2] - x[0][2] *x[1][1];
	y[2][1] = -1 *(x[0][0] *x[1][2] - x[0][2] *x[1][0]);
	y[2][2] = x[0][0] *x[1][1] - x[0][1] *x[1][0];	
	
	long int det = x[0][0] * y[0][0] - x[0][1] * y[0][1] + x[0][2] * y[0][2];

	for (int i = 0; i < 3; i++)	//inverse of matrix 
	{
		for (int j = 0; j < 3; j++){
			y[i][j] = (y[i][j] / det) % 26;
		}
	}
    return y;
}

string getMultipliedText(vector<vector<int>>& keyMatrix, vector<int>& chunkMatrix, int n, int window){
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
    for(int i = 0; i < window; ++i){
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
    for(int i = 0; i < len; i += n){
        int window = 0;
        
        for(int j = 0; j < n; ++j){
            if(i + j >= n){
                break;
            }
            
            chunkMatrix[j] = toupper(message[i + j]) - 'A';
            window++;
        }
        
        res += getMultipliedText(keyMatrix, chunkMatrix, n, window);
    }
    
    return res;
}

string decrypt(string cipher, string key, int n){
    int len = cipher.size();
    string res = "";
    
    vector<vector<int>> keyMatrix(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            keyMatrix[i][j] = toupper(key[i * 3 + j]) - 'A';
        }
    }
    
    vector<vector<int>> inverseMatrix = getReverseMatrix(keyMatrix);
    
    vector<int> chunkMatrix(n, 'Q' - 'A');
    for(int i = 0; i < len; i += n){
        int window = 0;
        
        for(int j = 0; j < n; ++j){
            if(i + j >= n){
                break;
            }
            
            chunkMatrix[j] = toupper(cipher[i + j]) - 'A';
            window++;
        }
        
        res += getMultipliedText(inverseMatrix, chunkMatrix, n, window);
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
    
    string text = decrypt(cipher, key, n);
    cout << "Decrypted Text : " << text << endl;

    return 0;
}
