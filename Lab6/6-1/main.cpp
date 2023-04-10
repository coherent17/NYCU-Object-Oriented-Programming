#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>


using namespace std;

const vector<string> split(const string &str, const char &delimiter) {
    vector<string> result;
    stringstream ss(str);
    string tok;

    while (std::getline(ss, tok, delimiter)) {
        result.push_back(tok);
    }
    return result;
}

int main(int argc, char* argv[]){

    string is,os;

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    
    int NumOfWord=0;
    int NumOfSentence=0;
    int longest_sentence_length = 0;
    int Llength=0;

    vector<string> LongestWords;

    char c;

    int last_word = 0;
    while(fin.get(c)){
        NumOfWord++;
        while(fin.get(c)){
            if(c == ' ') break;

            if(c == '.'){
                fin.get(c);
                if(c == ' '){
                    int sentence_length = NumOfWord - last_word;
                    last_word = NumOfWord;
                    longest_sentence_length = longest_sentence_length > sentence_length ? longest_sentence_length : sentence_length; 
                    NumOfSentence++;
                    break;
                }

            }
        }
    }

    NumOfSentence++;
    fin.close();

    fout<<"The number of words is "<< NumOfWord<<endl;
    fout<<"The number of sentence is "<<NumOfSentence<<endl;
    fout<<"The longest sentence has a length of: " << longest_sentence_length << endl;



    ifstream fin2(argv[1]);
    while(fin2.get(c)){
        int count = 1;
        while(fin2.get(c)){
            if(isalpha(c)){
                count++;
            }
            else{
                Llength = Llength > count? Llength : count;
                count = 0;
                break;
            }
        }
    }    


    fout<<"The longest word has a length of "<<Llength<<endl;
    fout<<"The Longest word is ";
    fin2.close();
    


    ifstream fin3(argv[1]);
    
    string str;
    while(getline(fin3, str)){
        vector<string> ret = split(str, ' ');
        for(int i = 0; i < ret.size(); i++){
            if(ret[i].size() == Llength){
                fout << ret[i] << " ";
            }
            else if(ret[i].size() == Llength + 1){
                for(int j = 0; j < ret[i].length()-1; j++){
                    fout << ret[i][j];
                }
                fout << " ";
            }
            // else if(ret[i].size() == Llength + 1 && ret[i][ret[i].length() - 1] == '.'){
            //     for(int j = 0; j < ret[i].length()-2; j++){
            //         fout << ret[j];
            //     }
            //     fout << " ";
            // }
        }
    }
    fin3.close();


    
    
    fout<<endl;


    fout.close();
    return 0;
}
