#include <iostream>
#include <string>
using namespace std;

void printPattern(int N) {
    int middle = N / 2; 
    
    for (int i = 0; i < N; i++) {
        if (i < middle) { 
            cout << string(i, ' '); 
            cout << "\\";
            cout << string(N - 2 - 2 * i, ' '); 
            cout << "/" << endl;
        } else if (i == middle) { 
            cout << string(i, ' '); 
            cout << "X" << endl;
        } else { 
            int j = N - i - 1; 
            cout << string(j, ' '); 
            cout << "/";
            cout << string(N - 2 - 2 * j, ' '); 
            cout << "\\" << endl;
        }
    }
}

int main() {
    int N;
    cin >> N; 
    printPattern(N);
    return 0;
}
