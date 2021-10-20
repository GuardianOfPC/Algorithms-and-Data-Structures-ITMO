#include <fstream>
using namespace std;

struct Queue {
    long val;
    Queue* last = NULL;
};

Queue* add(long val, Queue* last) {
    Queue* B = (Queue*)malloc(sizeof(Queue));
    B->val = val;
    B->last = last;
    return B;
}

int main() {
    ifstream fin("queue.in");
    ofstream fout("queue.out");
    long m;
    fin >> m;
    char command;
    long val;
    Queue* Last = NULL;
    for (int i = 0; i < m; i++) {
        fin >> command;
        if (command == '+') {
            fin >> val;
            Last = add(val, Last);
        }
        else {
            Queue* First = Last;
            if (First->last != NULL) {
                while (First->last->last != NULL)
                    First = First->last;
                fout << First->last->val << "\n";
                First->last = NULL;
            }
            else {
                fout << First->val << "\n";
                Last = NULL;
            }
        }
    }
}