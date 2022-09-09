/*
CCI-1.6
String Compression: Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).
*/

#include <string>
#include <iostream>
using namespace std;
#include <cstdlib>
int debug = 0;

string compress_string(string inp_str) {
    int i =0;
    int count = 1;
    string compressed_string;
    if(debug) cout << "input str is " << inp_str << "\n";
    while(i < inp_str.length()) {
        if(inp_str[i] == inp_str[i+1]) {
            i++;count++; continue;
        }
    compressed_string += inp_str[i];
    i++;
    char ch = count + '0';
    compressed_string += ch;
    count = 1;
    if(debug) cout << "compressed string till here is :- ---" << compressed_string << "--\n";
    }
    return compressed_string;
}

int main(int argc,char *argv[]) {
    
    if(argc>1) debug = atoi(argv[1]);
    cout << "debug value is " << debug << "\n";
    int run_program = 1;
    while(run_program) {
        cout << "Please enter input string\n";
        string inp_str;
        getline(cin,inp_str);
        if(debug) cout << "Input string is ---" << inp_str << "---";
        string compressed_str = compress_string(inp_str);
        if(compressed_str.length() >= inp_str.length()) 
            cout << "Original string more performant => " << inp_str << "\n\n";
        else
            cout << "Compressed string is => " << compressed_str << "\n\n";
        cout << "Please enter 1 to enter another input string and 0 to terminate program.\n\n";
        cin >> run_program;
        getchar();
    }
    cout << "Exiting Program\n";

}