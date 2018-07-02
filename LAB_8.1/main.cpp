#include <iostream>
#include <string>


using namespace std;

void flipString(string &s) {
    if (s.size() < 2) {
        return;
    }
    char first; 
    char last;
    string remaining;
    first = s.at(0);
    last = s.at(s.size() - 1);
    remaining = s.substr(1, s.size()-2);
    flipString(remaining);
    s = last + remaining + first;
}

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}