/*
CCI - 1.5
One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.
EXAMPLE
pale, ple -> true pales, pale -> true pale, bale -> true pale, bake -> false
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int calcStrDistance(string inp_str1,string inp_str2) {
    int first_diff_char = 0;
    int i = 0;
    int j = 0;
    int len = inp_str1.length();

    while(i < len){
        if(inp_str1[i] == inp_str2[j] ) {
            i++;
            j++;
        }
        else{
            if(first_diff_char == 1) { return 0;}
            first_diff_char = 1;
            i++;
            if(inp_str1.length() == inp_str2.length()) j++;
        }
    }
    return 1;
}

int checkStrDistance(string inp_str1,string inp_str2) {
    int len1 = inp_str1.length();
    int len2 = inp_str2.length();
    if(abs(len1 - len2) > 1) { return 0;}  
    int ret_val;
    if(len1 > len2) 
        ret_val = calcStrDistance(inp_str1,inp_str2);
    else if(len2 > len1) 
        ret_val = calcStrDistance(inp_str2,inp_str1);
    else 
        ret_val = calcStrDistance(inp_str1,inp_str2);
    return ret_val;
}

int main(int argc,char *argv[]) {

    int debug = 0;
    if(argc > 1) {debug = atoi(argv[1]);}
    if(debug) printf("Debug mode is on\n");
    int run_var = 1;
    string inp_str1;
    string inp_str2;
    while(run_var) {
        cout << "Enter 1st string\n";
        getline(cin,inp_str1);
        if(debug)
            cout <<"1st string is:---"<<inp_str1<<"---\n";
        cout << "Enter 2nd string\n";
        getline(cin,inp_str2);
        int ret_val = checkStrDistance(inp_str1,inp_str2);
        if(ret_val)
            {printf("PASS . Input strings are at distance of 1/0.\n");}
        else 
            {printf("FAIL . Input strings are at more than distance of 1.\n");}
        cout << "\n\nPlease enter 1 to continue and 0 to exit program\n" ;
        cin >> run_var;
        getchar();

    }

    printf("Exiting program\n");


}