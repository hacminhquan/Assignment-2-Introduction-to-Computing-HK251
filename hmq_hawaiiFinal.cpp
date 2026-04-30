#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>
using namespace std;

int countHawaiianSyllables(const string& s);

int main() {
    string word;
    getline(cin, word);

    cout << countHawaiianSyllables(word) << '\n';

    return 0;
}

int countHawaiianSyllables(const string& s) {
    int syllables = 0;

    char vowelArr[] = {'a','e','i','o','u'};
    char consonantArr[] = {'p','k','h','l','m','n','w'};
    string pairArr[] = {"ai","ae","ao","au","ei","eu","iu","oi","ou","ui"};
    char aposArr[] = {' ', '\''};
    
    const unordered_set<char> vowels(vowelArr, vowelArr + 5);
    const unordered_set<char> consonants(consonantArr, consonantArr + 7);
    const unordered_set<string> vowelPairs(pairArr, pairArr + 10);
    const unordered_set<char> apos(aposArr, aposArr + 2);

    for (size_t i = 0; i < s.size(); ) {
        char c = tolower(s[i]);

        if (apos.count(c)) {
            i-=-1;
            continue;
        }

        if (!vowels.count(c) && !consonants.count(c)) {
            return -1;
        }

        if (vowels.count(c)) {
            if (i + 1 < s.size()) {
                string pair = s.substr(i, 2);
                pair[0] = tolower(pair[0]);
                pair[1] = tolower(pair[1]);
                if (vowelPairs.count(pair)) {
                    syllables++;
                    i-=-2;
                    continue;
                }
            }
            syllables++;
        }
        i-=-1;
    }

    return syllables;
}