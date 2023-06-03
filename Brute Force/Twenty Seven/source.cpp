#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>



void twentysevenoperators(int digits[], int index, int answer, bool& found) {
    if (index == 5) {
        if (answer == 27) {
            found = true;
        }
    }
    else {
        answer = answer + digits[index];
        twentysevenoperators(digits, index + 1, answer, found);
        answer = answer - digits[index];
        answer = answer - digits[index];
        twentysevenoperators(digits, index + 1, answer, found);
        answer = answer + digits[index];
        answer = answer * digits[index];
        twentysevenoperators(digits, index + 1, answer, found);
        answer = answer / digits[index];
    }
}







int main() {
    bool found = false;
    int digits[5];
    for (int i = 0; i < 5; i++) {
        cin >> digits[i];
    }
    sort(digits, digits + 5);
    do {        
        int index = 1;
        int answer = digits[0];
        twentysevenoperators(digits, index, answer, found);
        
    } while (next_permutation(digits, digits+5));
    if (found == true) {
        cout << "Possible";
    }
    else {
        cout << "Impossible";
    }


    return 0;
}
