#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> usedwords;

bool isSentenceFormed(const string& sentence, map<string, int>& wordCount) {
    if (sentence.empty())
        return true;

    for (auto it = wordCount.begin(); it != wordCount.end(); ++it) {
        string word = it->first;
        int count = it->second;

        if (sentence.substr(0, word.length()) == word) {
            if (count > 0) {
                usedwords.push_back(word);
                it->second--;
                if (isSentenceFormed(sentence.substr(word.length()), wordCount))
                    return true;
                it->second++;
                for(size_t i = 0; i < usedwords.size(); i++){
                    if(word == usedwords[i]){
                        usedwords.erase(usedwords.begin() + i);
                        break;
                    }
                }
            }
        }
    }

    return false;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <dictionary_file> <sentence>" << endl;
        return 1;
    }

    // Load dictionary words and their counts from file
    map<string, int> dictionary;
    map<string, int> ori;
    ifstream inFile(argv[1]);
    string word;
    int count;
    while (inFile >> word >> count) {
        dictionary[word] = count;
        ori[word] = count;
    }
    inFile.close();

    // Get the sentence to check
    string sentence = argv[2];


    // Check if the sentence can be formed
    bool ret = false;
    if (isSentenceFormed(sentence, dictionary)) {
        ret = true;
    } else {
        ret = false;
        cout << "False" << endl;
        return 0;
    }

    // Display the total count and remaining count for each word
    for (const auto& entry : dictionary) {
        int totalCount = ori[entry.first];
        int remainingCount = dictionary[entry.first];
        int used = totalCount - remainingCount;
        if(used > 0){
            cout << entry.first << ": ";
            cout << used << " (" << totalCount << "->" << remainingCount << ")" << endl;
        }
    }

    if(ret){
        cout << "True" << endl;
    }
    for(size_t i = 0; i < usedwords.size(); i++){
        cout << usedwords[i] << " ";
    }
    cout << endl;

    return 0;
}
