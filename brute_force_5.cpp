#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static bool Substitute(string input, string key1, string key2, string& output)
{
    output = "";
    
    for (char current : input) {
        if (current == ' ' || current == '.') {
            output += current;
        } else {
            bool sub = false;
            for (size_t j = 0; j < key1.size(); ++j) {
                if (key1[j] == current) {
                    output += key2[j];
                    sub = true;
                    break;
                }
            }
            if (!sub)
                return false;
        }
    }
    return true;
}

void brute_force_5(string ciphertext, string keyLetters, string keyReplaceWith)
{
    sort(keyLetters.begin(), keyLetters.end());

    do {
        string decryptedText;
        if (Substitute(ciphertext, keyLetters, keyReplaceWith, decryptedText)) {
            cout << "Decrypted message using key: " << keyLetters << " -> " << decryptedText << endl;
        }
    } while (next_permutation(keyLetters.begin(), keyLetters.end()));
}

int main()
{
    string Input = "htff erf tfhftff";
    string keyLetters = "htfer";
    string keyReplaceWith = "eftrh";

    brute_force_5(Input, keyLetters, keyReplaceWith);

    return 0;
}
