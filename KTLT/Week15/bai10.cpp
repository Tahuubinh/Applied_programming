#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
#define fr(i,x,y) for(int i = x; i <= y; ++i)
using ll = long long;
using ull = unsigned long long;

int n, q;
string inputs;
vector<string> sentences, querries;
vector<vector<string>> words, words_in_querry;
map<pair<string, int>, int> freqs;
vector<int> maxfs;
map<string, int> df;

vector<string> stringSplit(string s){
    vector<string> ans;
    stringstream ss(s);
    while(ss.good()){
        string substr;
        getline(ss, substr, ',');
        ans.push_back(substr);
    }

    return ans;
}

int frequencyOfWordInSentence(string word, int i){
    if (freqs.find({word, i}) != freqs.end()){
        return freqs[{word, i}];
    }
    int cnt = 0;
    for (string s: words[i]){
        if (word == s){
            ++cnt;
        }
    }
    freqs[{word, i}] = cnt;
    return cnt;
}

void findMaxf(){
    for (auto a: words){
        map<string, int> m;
        int max_f = 0;
        for (string s: a){
            ++m[s];
            max_f = max(m[s], max_f);
        }
        maxfs.push_back(max_f);
    }
}

int countSenContainsWord(string word){
    if (df.find(word) != df.end()){
        return df[word];
    }
    int cnt = 0;
    for (vector<string> sen: words){
        for (string s: sen){
            if (s == word){
                ++cnt;
                break;
            }
        }
    }
    df[word] = cnt;
    return cnt;
}

double getScoreWord(string t, int d){
    // if (find(words[d].begin(), words[d].end(), t) == words[d].end()){
    //     return 0;
    // }
    if (frequencyOfWordInSentence(t,d) == 0){
        return 0;
    }
    double tf = 0.5 + 0.5 * frequencyOfWordInSentence(t,d) / maxfs[d];
    double idf = log2(1.0 * n / countSenContainsWord(t));
    return tf * idf;
}

double getScoreQuery(int querry, int d){
    double score = 0;
    for (string word: words_in_querry[querry]){
        if (find(words[d].begin(), words[d].end(), word) 
        != words[d].end()){
            score += getScoreWord(word, d);
        }
    }
    return score;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    fr(i,1,n){
        cin >> inputs;
        sentences.push_back(inputs);
        words.push_back(stringSplit(inputs));
    }
    words.resize(n);
    cin >> q;
    fr(i, 1, q){
        cin >> inputs;
        querries.push_back(inputs);
        words_in_querry.push_back(stringSplit(inputs));
    }
    words_in_querry.resize(q);
    findMaxf();
    fr(i, 0, q - 1){
        double maxtemp = getScoreQuery(i, 0);
        int ans = 0;
        fr (j, 1, n - 1){
            double score = getScoreQuery(i, j);
            if (score > maxtemp){
                maxtemp = score;
                ans = j;
            }
        }
        cout << ans + 1 << endl;
    }
    
    return 0;
}
