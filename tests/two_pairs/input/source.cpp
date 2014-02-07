#include<string>
#include<cstring>
#include<iostream>
#include<fstream>

using namespace std;

string help=
"\n"
"   This program can be used to verify if the parenthesis in a file are balanced.\n"
"\n"
"   Usage:\n"
"\n"
"      paracheck [options]\n"
"\n"
"   where options are:\n"
"\n"
"      -p <characters>\n"
"          Specify the string that contains pairs of characters considered to be\n"
"          matching parenthesis. The default set of parenthesis is '(){}[]'.\n"
"\n"
"      -f <File>\n"
"          Specify the file to be checked. This option is required. To read from\n"
"          stdin, invoke this command with '-f /dev/stdin'.\n"
"\n"
"      -h\n"
"      --help\n"
"          Print this help.\n"
"\n"
"   Example:\n"
"\n"
"          paracheck -p '(){}()[]<>' -f data.txt\n"
"\n"
"";

string usage_error=
"\n"
"  Error: invalid usage; for help, execute:\n"
"\n"
"          paracheck -h\n"
"\n";

int main(int argc, const char * argv[]){
    string parentheses="(){}[]";
    string filename;
    for(int i=1;i<argc;i++){
        if (!strcmp(argv[i],"-h")||!strcmp(argv[i],"--help")){
            cout<<help;
            return 0;
        } else
        if (!strcmp(argv[i],"-p")){
            if (i+1>=argc){ 
                cerr<<usage_error;
                return 1;
            }
            parentheses=argv[i+1];
            i++;
        } else
        if (!strcmp(argv[i],"-f")){
            if (i+1>=argc){ 
                cerr<<usage_error;
                return 1;
            }
            filename=argv[i+1];
            i++;
        }
    }
    if (filename.empty()){
        cerr<<"\nError: the input file must be specified. For help, execute\n\n"
              "    paracheck -h\n\n";
        return 2;
    }
    ifstream input(filename.c_str());
    if (!input){
        cerr<<"Error: cannot open the file: "<<filename<<endl;
        return 3;
    }
    string stack;
    stack.reserve(1024);
    int line=1,col=1;
    while(input.good()){
        char c=input.get();
        //cout<<c;
        size_t k=parentheses.find(c);
        if(k==string::npos){
            if (c=='\n'){
                line++;
                col=1;
            } else {
                col++;
            } 
        } else {
            if (k%2==0){
                stack.append(1,c);
            } else {
                int l=stack.length()-1;
                if (l>=0 && stack[l]==parentheses[k-1]){
                    stack.erase(l,1);
                } else {
                    cout<<"file "<<filename<<", line "<<line<<", column "<<col<<": ";
                    if (l>=0){
                        k=parentheses.find(stack[l]);
                        cout<<"expected "<<parentheses[k+1];
                        cout<<" but found "<<c;
                        cout<<" after "<<stack<<endl;
                    } else {
                        cout<<" found unmatched "<<c<<endl;
                    }
                    return 4;
                }
            }
        }
    }
    if (input.eof()){
        return 0;
    } else {
        cerr<<"Unexpected error."<<endl;
        return 5;
    }
}
