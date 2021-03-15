#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int keywordCheck(char *buffer)
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};

    for(int i = 0; i < 32; i++) 
    {
        if(strcmp(keywords[i], buffer) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char** argv)
{
    ifstream fin(argv[1]);

    char buffer[15];

    char c;
    char operators[] = "+-*/%=";

    int j = 0;

    while(!fin.eof()){
   		c = fin.get();
   		
		for(int i = 0; i < 6; ++i){
   			if(c == operators[i])
   				cout << c << " is operator\n";
   		}
   		
   		if(isalnum(c)){
   			buffer[j++] = c;
   		}
   		else if((c == ' ' || c == '\n') && (j != 0)){
   				buffer[j] = '\0';
   				j = 0;
   				   				
   				if(keywordCheck(buffer) == 1)
   					cout << buffer << " is keyword\n";
   				else
   					cout << buffer << " is identifier\n";
   		}
   		
	}

    fin.close();
    return 0;
}