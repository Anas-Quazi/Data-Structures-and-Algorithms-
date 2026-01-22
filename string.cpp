#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

bool validPalindrome(std :: string str) {
    std :: string new_str = "";

    if(new_str.empty()) {
        return true;
    }
    else { 

        for(char ch : str) {
        new_str += std :: tolower(ch);
        }

        for(int i=0;i<new_str.length();) {

            if(!((new_str[i] >= 'a' && new_str[i] <= 'z') || (new_str[i] >= '0' && new_str[i] <= '9'))) {
            new_str.erase(i,1);
            }
            else {
            i++;
            }
        }

    std :: cout << new_str << "\n";

    std ::string rev_str = new_str;

    reverse(rev_str.begin(), rev_str.end());
    std ::cout << rev_str << std ::endl;

    if(rev_str == new_str) return true;
    else return false;
    }

}



void remove_all_Occurance(std :: string str) {
    std :: string part = "abc";
    int len = part.length();

    int i=0;
    while(i<str.length()) {
        
        if(str.find(part) < str.length()) {
            int x = str.find(part);
            str.erase(x,len);
        }

        i++;
    }

    std :: cout << str << std :: endl;
    
} 

//* function to check equality of both frequency arrays
bool isFreqSame(int freq[],int windFreq[]) {
    for(int i=0;i<26;i++) {
        if(freq[i]!=windFreq[i]) {
            return false;
        }
    }
    return true;
}

//* is there substring permutation in given string
bool permutationString(std :: string str) {
    std :: string sub_str = "aabc";

    int freq[26] = {0};
    int windFreq[26] = {0};

    //^ calculating freq for sub-string
    for(char ch : sub_str) {
        freq[ch - 'a']++; //^ a->0 , b->1 ... z->25 (the sum of all frequencies will help for permutations) 
    }

    int windSize = sub_str.length();

    //^ initial windowFreq
    for(int i=0;i<sub_str.length();i++) {
        windFreq[str[i]-'a']++;
    }
    if(isFreqSame(freq,windFreq)) return true;

    //^ if not then slide the window
    for(int i=windSize;i<str.length();i++) {
        windFreq[str[i-windSize] - 'a']--; //! remove left most
        windFreq[str[i] - 'a']++; //! add right most

        if(isFreqSame(freq,windFreq)) return true;
    }
    return false;
}

// * max sum in array using slinding window


//* reverse words in string ( leetcode 151)
void reverseWord(std :: string str) {

    //& Muhammad Anas Razvi -----> Razvi Anas Muhammad

    int n = str.length();
    //^ reverse whole string (two pointer approach)
    int st=0,end=str.length()-1;
    while(st<end) {
        std :: swap(str[st],str[end]);
        st++; end--;
    }

    std :: cout << "reverse string :   " << str << "\n word:    ";

    std :: string ans = "";
    //^ string reverse done, now reverse single words one by one
    //! work on linear time complexity bcoz we use same iterator(i) in both loop
    for(int i=0;i<n;i++) {
        std :: string word = "";
        while(i<n && str[i]!=' ') {
            word += str[i];
            i++;
        }
        std :: reverse(word.begin(),word.end());
        if(word.length()>0) {
            ans += " " + word;
        }
    }
    ans.erase(0,1);


    std :: cout << "\nstring after reversing the words:   " << ans;

} 

int compress(std :: vector<char> carr) {

    //~ first run a loop, start from 1st idx then check if next some values are same as that element? if yes then count frequency and store it in answer vector with that character then move to next

    //& ["a","a","b","b","c","c","c"]

    int n = carr.size();
    int idx = 0;
    std :: vector<char> ans;
    for(int i=0;i<n;i++) {
            char ch = carr[i];
            int freq = 0;
        
            while(i<n && carr[i]==ch) {
                freq++;i++;
            }
        
            if(freq==1) {
                carr[idx++] = ch; 
            }
            else {
                carr[idx++] = ch;
                std :: string s = std :: to_string(freq);

                for(char digit : s) {
                    carr[idx++] = digit;
                }
            }
            i--;
     }

    std :: cout << "compressed array : \n";
    for(char ch : carr) {
        std :: cout << ch << " ";
    }

    carr.resize(idx);

    return idx;
}



int main() {

    // // charcter array (used to store string)
    // char str[] = {'A', 'N', 'A', 'S', '\0'}; // NULL value \0

    // int arr[] = {1, 8, 7};

    // char str2[] = "Razvi"; // string literals (can't change)

    // std ::cout << str << std ::endl; // character converted into single string

    // // length function
    // std ::cout << strlen(str) << std ::endl;

    // std ::cout << str2 << "\n";
    // std ::cout << str2[2] << "\n"; // indexing

    // // input in charcater array

    // // didn't work for sentences(contain whitespace)
    // char strg[11];

    // std ::cout << "enter character array : ";
    // // std :: cin >> string;

    // // cin.getline function
    // std ::cin.getline(strg, 111);

    // // output
    // std ::cout << "output :    " << strg << "\n";

    // // output using for each loop
    // for (char ch : strg)
    // {
    //     std ::cout << ch << " ";
    // }

    // // length using loop
    // int lenght = 0;

    // for (int i = 0; i < strg[i] != '\0'; i++)
    // {
    //     lenght++;
    // }

    // std ::cout << "length of string :  " << lenght << "\n";

    // // --------------------------------------------------------------------------------

    // // strings in cpp (dynammic)

    // std ::string str3 = "Muhammad";
    // std ::cout << str3 << "\n";

    // // concatination
    // std ::cout << str3 + " " + str2 << "\n";

    // std ::cout << (str < str2) << std ::endl;

    // // lenght (in-built method)
    // std ::cout << str3.length() << std ::endl;

    // // input in strings

    // std ::string str4;

    // std ::cout << "enter string :  ";
    // getline(std ::cin, str4);

    // std ::cout << "output :    " << str4 << std ::endl;

    // // loops on strings
    // for (int i = 0; i < str3.length(); i++)
    // {
    //     std ::cout << str3[i] << " ";
    // }

    // for (char ch : str4)
    // {
    //     std ::cout << ch << " ";
    // }
    // std ::cout << "\n\n";

    // // reverse string

    // std ::string str5 = "Radar";

    // for (int i = str5.length(); i >= 0; i--)
    // {
    //     std ::cout << str5[i];
    // }
    // std ::cout << "\n";

    // // using two pointer approach
    // int st = 0, end = str5.length() - 1;

    // while (st < end)
    // {
    //     std ::swap(str5[st], str5[end]);
    //     st++;
    //     end--;
    // }
    // std ::cout << str5;

    // // in-built reverse method
    // std ::string rev_str = str5;
    // reverse(rev_str.begin(), rev_str.end());
    // std ::cout << rev_str << std ::endl;

    // // palindrome

    // bool isPalindrome;
    // if (str5 == rev_str)
    // {
    //     std ::cout << "palindrome!" << std ::endl;
    // }
    // else
    // {
    //     std ::cout << "not palindrome." << std ::endl;
    // }

    std :: string s = "Muhammad Anas Razvi";

    std :: string s2 = "daabcbaabcbc";

    
    std :: vector<char> carr = {'a','a','b','b','b','b','b','b','b','b','b','b','b','b','c','c','c'};
    

    // std :: cout << validPalindrome(s2);

    std :: cout << compress(carr);

    return 0;
}