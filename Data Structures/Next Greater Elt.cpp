// METHOD 2 : Process from start (new method but easy)

vector<long long> nextLargerElement(vector<long long> arr, int n){
      vector<long long> res(n, -1);
      stack<int> s;

      for(int i = 0; i < n; ++i){
          while(!s.empty() && arr[s.top()] <= arr[i]){
              res[s.top()] = arr[i];
              s.pop();
          }

          s.push(i);
      }

      return res;
  }

// METHOD 1 : Process from End

vector<long long> nextLargerElement(vector<long long> arr, int n){
      vector<long long> res(n, -1);
      stack<int> s;

      for(int i = n - 1; i >= 0; --i){
          while(!s.empty() && arr[s.top()] <= arr[i]){
              s.pop();
          }

          if(s.empty())
              res[i] = -1;
          else
              res[i] = arr[s.top()];

          s.push(i);
      }

      return res;
  }
