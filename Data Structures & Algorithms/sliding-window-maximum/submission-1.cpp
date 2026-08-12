
#include <algorithm>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(); // so we don't have to keep making this call
        vector<int> result(n - k + 1); //we know our result set size before hand
        deque<int> window;

        int left = 0;
        int right = 0;

        // while the right pointer hasn't gone past our last index
        while (right < n) {
            // while our queue isn't empty & the next number is greather than the last
            while (!window.empty() && nums[window.back()] < nums[right]) {
                window.pop_back(); // get rid of previous max's smaller than this new one
            }
            window.push_back(right); // put new index on the queue

            if (left > window.front()) { // if our left pointer is now past the oldest max
                window.pop_front();
            }

            if ((right + 1) >= k) { // if we've passed enough numbers to constitute a window
                result[left] = nums[window.front()]; //next index in result vector is the index at front of queue
                left++; //increment front pointer
            }
            right++; 
        }
        return result;
    }
};
