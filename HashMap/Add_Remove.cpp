#include <iostream>
#include <tr1/unordered_map>

using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::tr1::unordered_map<char, int> m;
        
        //Add characters magazine on map "m"
        for(auto& c: magazine) m[c]+=1;
        
        //Substract characters ransomNote on map "m"
        //If magazine is not included on ransomNote returns False
        for(auto& c: ransomNote) {
            --m[c];
            if(m[c]<0) return false;
        }
        
        return true;
    }
};

int main(){
	Solution sol;
	string ransomNote = "aa";
	string magazine = "aab";
	if(sol.canConstruct(ransomNote, magazine)) cout << "True";
	else cout << "False";
}
