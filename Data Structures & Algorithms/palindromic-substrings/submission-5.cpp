class Solution {
public:
    int countSubstrings(string s) {
        //walk with two pointers
        int count = 0;
        for (int center = 0; center < s.size(); center++){
            int front = center;
            int back = center;
            while(front >=0 && back < s.size() && s[front] == s[back]) {
                count++;
                front--;
                back++;
            }
            front = center;
            back = center+1;
            while(front >=0 && back < s.size() && s[front] == s[back]) {
                count++;
                front--;
                back++;
            }
        }
        return count;
    }
};
