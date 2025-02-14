#include <bits/stdc++.h>
using namespace std;

// Function to determine column order based on keyword
vector<int> getColumnOrder(const string &keyword) {
    vector<pair<char, int>> indexed_keyword;
    for (int i = 0; i < keyword.size(); i++) {
        indexed_keyword.emplace_back(keyword[i], i);
    }
    sort(indexed_keyword.begin(), indexed_keyword.end());

    vector<int> order(keyword.size());
    for (int i = 0; i < keyword.size(); i++) {
        order[indexed_keyword[i].second] = i;
    }
    return order;
}

// Function to reverse columnar transposition
string reverseTransposition(const string &ciphertext, const string &keyword) {
    int rows = (ciphertext.size() + keyword.size() - 1) / keyword.size();
    vector<string> columns(keyword.size());
    vector<int> columnOrder = getColumnOrder(keyword);

    // Determine column lengths
    vector<int> colLength(keyword.size(), rows);
    int extra = rows * keyword.size() - ciphertext.size();
    for (int i = keyword.size() - 1; extra > 0; i--, extra--) {
        colLength[columnOrder[i]]--; // Reduce length for last few columns
    }

    // Fill columns with ciphertext
    int index = 0;
    for (int i = 0; i < keyword.size(); i++) {
        int col = columnOrder[i];
        columns[col] = ciphertext.substr(index, colLength[col]);
        index += colLength[col];
    }

    // Read the table row-wise
    string original;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyword.size(); j++) {
            if (i < columns[j].size()) {
                original += columns[j][i];
            }
        }
    }

    return original;
}

// Function to decrypt ADFGVX pairs using the given 6x6 matrix
string decryptSubstitution(const string &pairs, const vector<vector<char>> &polybiusSquare) {
    string adfgvx = "ADFGVX";
    unordered_map<char, int> indexMap;
    for (int i = 0; i < 6; i++) {
        indexMap[adfgvx[i]] = i;
    }

    string plaintext;
    for (size_t i = 0; i < pairs.size(); i += 2) {
        int row = indexMap[pairs[i]];
        int col = indexMap[pairs[i + 1]];
        plaintext += polybiusSquare[row][col];
    }
    return plaintext;
}

int main() {
    // Input 6×6 Polybius Square
    vector<vector<char>> polybiusSquare(6, vector<char>(6));
    for (int i = 0; i < 6; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 6; j++) {
            polybiusSquare[i][j] = row[j];
        }
    }

    // Read keyword and ciphertext
    string keyword, ciphertext;
    cin >> keyword >> ciphertext;

    // Reverse the columnar transposition
    string reorderedPairs = reverseTransposition(ciphertext, keyword);

    // Reverse the ADFGVX substitution
    string plaintext = decryptSubstitution(reorderedPairs, polybiusSquare);

    // Output the final decrypted message
    cout << plaintext << endl;

    return 0;
}

