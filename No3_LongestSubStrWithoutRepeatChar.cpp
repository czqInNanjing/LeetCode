//
// Created by Qiang Chen on 02/08/2017.
//
//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//          Given "abcabcbb", the answer is "abc", which the length is 3.
//
//          Given "bbbbb", the answer is "b", with the length of 1.
//
//          Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
#import "string"
#import "map"
using namespace std;
class No3_LongestSubStrWithoutRepeatChar {




public:
    // 这道题的本质是维护一个窗口，窗口内部不存在重复的字符，出现重复的字符的时候，就向右移动，移动新遇到的字符在这个窗口内部的重复字符的下一个位置
    /*
     * the basic idea is, keep a hashmap which stores the characters in string as keys and their positions as values,
     * and keep two pointers which define the max substring. move the right pointer to scan through the string ,
     * and meanwhile update the hashmap. If the character is already in the hashmap,
     * then move the left pointer to the right of the same character last found.
     * Note that the two pointers can only move forward.
     */
    int lengthOfLongestSubstring(string s) {
        int maxNum = 1;
        map<char, int> charMap;
        int tempNoRepeatMax = 0;
        for (int i = 0; i < s.size(); ++i) {

            if (charMap.find(s[i]) == charMap.end()) {
                charMap[s[i]] = i;

            } else {
                int lastNum = charMap[s[i]];
                if (lastNum >= tempNoRepeatMax) {

                    int tempMax = i - tempNoRepeatMax;
                    maxNum = maxNum > tempMax ? maxNum : tempMax;
                    tempNoRepeatMax = lastNum + 1;
                }
                charMap[s[i]] = i;


            }



        }


        if(tempNoRepeatMax == 0) {
            return charMap.size();
        }
        int maxUntilFinal = charMap[s[s.size() - 1]] - tempNoRepeatMax + 1;
        return maxNum > maxUntilFinal ? maxNum : maxUntilFinal;



    }







 // wrong answer think too easy, simply empty the set is wrong ,
    // some remain object may be still useful, so it is necessary to keep the order of the object inserted

//public:
//    int lengthOfLongestSubstring(string s) {
//        if (s.size() == 0)
//            return 0;
//
//        int maxNum = 1;
//        set<char> charSet;
//
//        for(auto &c : s) {
//            if (charSet.find(c) != charSet.end()) {
//                maxNum = maxNum > charSet.size() ? maxNum : charSet.size();
//                charSet.clear();
//            }
//
//            charSet.insert(c);
//
//        }
//
//        return maxNum > charSet.size() ? maxNum : charSet.size();
//    }
};
