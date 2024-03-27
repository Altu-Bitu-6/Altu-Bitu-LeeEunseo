#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool areSimilar(const string& str1, const string& str2) {
    if (str1.length() != str2.length())
        return false;

    // Count occurrences of each character in str1 and str2
    vector<int> count1(26, 0), count2(26, 0);
    for (char c : str1)
        count1[c - 'A']++;
    for (char c : str2)
        count2[c - 'A']++;

    // Check if the counts of characters match
    return count1 == count2;
}

bool isOneCharDifferent(const string& str1, const string& str2) {
    if (str1.length() != str2.length())
        return false;

    int diffCnt = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i])
            diffCnt++;
        if (diffCnt > 1)
            return false;
    }
    return diffCnt == 1;
}

bool isOneCharMissing(const string& longer, const string& shorter) {
    if (longer.length() != shorter.length() + 1)
        return false;

    size_t i = 0, j = 0;
    while (i < shorter.length() && j < longer.length()) {
        if (shorter[i] != longer[j]) {
            if (i != j)
                return false;
            j++;
        } else {
            i++;
            j++;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; ++i)
        cin >> words[i];

    int similar = 0;
    for (int i = 1; i < N; ++i) {
        if (areSimilar(words[0], words[i]) || isOneCharDifferent(words[0], words[i]) || isOneCharMissing(words[0], words[i]))
            similar++;
    }

    cout << similar << endl;

    return 0;
}
