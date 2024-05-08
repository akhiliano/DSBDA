#include <bits/stdc++.h>
using namespace std;

int main() {
   
    cout<<"enter the string : "<<endl;
    string str;
    cin>>str;
    std::cout << "Original string: " << str << "\n";

    std::cout << "After AND with 127:\n";
    for (int i = 0; str[i] != '\0'; ++i) {
        char andResult = str[i] & 127;
        std::cout << andResult;
    }
    std::cout << "\n";

    std::cout << "After XOR with 127:\n";
      for (int i = 0; str[i] != '\0'; ++i) {
        char xorResult = (str[i] ^ 127);
       std::cout << xorResult;
    }
  
    std::cout << "\n";

    std::cout << "After OR with 127:\n";
    for (int i = 0; str[i] != '\0'; ++i) {
        char orResult = str[i] | 127;
        std::cout << orResult;
    }
    
    std::cout << "\n";

  

    return 0;
}
