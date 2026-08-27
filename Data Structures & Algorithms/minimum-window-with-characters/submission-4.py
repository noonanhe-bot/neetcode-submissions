class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t:
            return ""
        
        targetCount = {}
        windowCount = {}

        for ch in t:
            targetCount[ch] = targetCount.get(ch, 0) + 1

        have = 0
        need = len(targetCount)

        minIdxs = [-1, -1]
        minLen = float("infinity")

        left = 0
        
        for right in range(len(s)):
            windowCount[s[right]] = windowCount.get(s[right], 0) + 1
            if s[right] in targetCount and windowCount[s[right]] == targetCount[s[right]]:
                have += 1
            while have == need:
                if (right - left + 1)  < minLen:
                    minIdxs = [left, right]
                    minLen = right - left + 1
                windowCount[s[left]] -=1
                if s[left] in targetCount and windowCount[s[left]] < targetCount[s[left]]:
                    have -= 1
                left += 1
        
        left, right = minIdxs
        return s[left : right + 1] if minLen != float("infinity") else ""

            



            