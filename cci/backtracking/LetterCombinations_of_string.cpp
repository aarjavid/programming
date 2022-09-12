/*LeetCode -  Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/
#include <iostream>
using namespace std;
#include <vector>
int debug = 0;

void backtrack(int i, string curstr,vector<string>& data,int* digits_int,int digit_size,vector<string>& oup) {
        if(curstr.length() == digit_size ) {
            oup.push_back(curstr);
            return;
        }

        for(auto ch : data[digits_int[i]]) {
            backtrack(i+1,curstr+ch,data,digits_int,digit_size,oup);
        }

    }

vector<string> letterCombinations(string digits) {
    int string_size = digits.size();
    cout << digits << "\n";
    int digits_int[string_size];
    vector<string> oup;
    vector<string> data;
    data.push_back(""); //0
    data.push_back(""); //1 
    data.push_back("abc"); //2
    data.push_back("def"); //3
    data.push_back("ghi"); //4
    data.push_back("jkl"); //5
    data.push_back("mno"); //6
    data.push_back("pqrs"); //7
    data.push_back("tuv"); //8
    data.push_back("wxyz"); //9

    for(int i=0;i<data.size();i++) {
        cout << data[i] << "\n";
    }

    for(int i=0;i<string_size;i++) {
        digits_int[i] = digits[i] - '0';
        cout << digits_int[i] << "\n";
    }


    
    backtrack(0,"",data,digits_int,string_size,oup);
    cout<<"\n\nOUTPUT is:-\n\n";
    for(auto str : oup) cout << str<<"\n";
    return oup;
}

int main(int argc,char* argv[]) {

    if(argc<2) exit;
    string input = argv[1];

    
    letterCombinations(input);

   

}