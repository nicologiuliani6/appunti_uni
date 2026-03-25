#include <iostream>
using namespace std;

int parola(char str[], const int length, const int n, char dest[]) {
    int counter = 1;
    int k = 1; // Start at 1 to store the characters after length
    bool found = false;

    for (int i = 0; i < length; i++) {
        // Count spaces to find the nth word
        if (str[i] == ' ') {
            counter++;
        }

        // When the nth word is found
        if (counter == n) {
            int length_dest = 0;

            // Loop to copy the word into dest
            for (int j = i + 1; j < length; j++) {
                if (str[j] != ' ') {
                    dest[k] = str[j];
                    k++;
                    length_dest++;
                } else {
                    dest[0] = length_dest;  // Store the length of the word at dest[0]
                    found = true;
                    break;
                }
            }

            // If word ends before a space (last word in the string)
            if (!found) {
                dest[0] = length_dest;
            }
            break;
        }
    }

    return (counter >= n) ? 1 : 0; // Return 1 if nth word found, 0 otherwise
}


void print_array(const char A[], const int length){
    for (int i = 1; i <= length; i++) { // Adjusted to print based on actual length
        cout << A[i];
    }
    cout << endl;
}

int main(){
    int length = 10;
    char str[length] = {'a','b','c',' ','d','e','f',' ','g','h'};
    char dest[length];

    int result = parola(str, length, 2, dest);
    if (result == 1) {
        print_array(dest, dest[0]); // Pass dest[0] as the length of the word
    } else {
        cout << "Word not found." << endl;
    }

    return 0;
}

