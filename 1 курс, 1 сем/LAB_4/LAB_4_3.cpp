#include <fstream>
#include <string>

using namespace std;

struct Stack {
    char val;
    Stack* last = NULL;
};

Stack* add(char val, Stack* last) {
    Stack* B = (Stack*)malloc(sizeof(Stack));
    B->val = val;
    B->last = last;
    return B;
}

int main() {
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");
    for (int i = 0; i < 10000; i++) {
        Stack* A = NULL;
        string command;
        getline(fin, command);
        if (command.length() == 0) break;
        for (int j = 0; j < command.length() + 1; j++) {
            if (command[j] == '(' || command[j] == '[') {
                A = add(command[j], A);
            }
            else if (command[j] == ')') {
                if (A == NULL || A->val == '[') {
                    fout << "NO\n";
                    break;
                }
                else {
                    A = A->last;
                }
            }
            else if (command[j] == ']') {
                if (A == NULL || A->val == '(') {
                    fout << "NO\n";
                    break;
                }
                else {
                    A = A->last;
                }
            }
            else {
                if (A != NULL)
                    fout << "NO\n";
                else
                    fout << "YES\n";
                break;
            }
        }
    }
    return 0;
}