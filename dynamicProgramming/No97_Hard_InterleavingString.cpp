//
// Created by Qiang Chen on 11/09/2017.
//
class No97_Hard_InterleavingString{



    /*
     * TLE:暴力解法

    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;

        int i1 = 0, i2 = 0;
        for(int i = 0; i < s3.length(); ++i) {
            if(s3[i] == s1[i1] && s3[i] == s2[i2]) {
                return isInterleave(s1.substr(i1 + 1), s2.substr(i2), s3.substr(i + 1)) || isInterleave(s1.substr(i1), s2.substr(i2 + 1), s3.substr(i + 1));
            } else if(s3[i] == s1[i1]) {
                i1++;
            } else if(s3[i] == s2[i2]) {
                i2++;
            } else {
                return false; // no match char
            }
        }

        return true;
    }
      */
};
