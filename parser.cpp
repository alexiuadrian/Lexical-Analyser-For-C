#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    ifstream f(argv[1]);

    char buffer[100];

    char c;
    int nr = -1;
    while(f >> c)
    {
        buffer[++nr] = c;
    }

    for (int i = 0; i <= nr; i++)
    {
        cout << buffer[i];
    }

    f.close();
    return 0;
}