# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        maxPath = [root.val]

        def depthFirstSearch(root):
            if not root:
                return 0

            leftMax = depthFirstSearch(root.left)
            rightMax = depthFirstSearch(root.right)

            leftMax = max(leftMax, 0)
            rightMax = max(rightMax, 0)

            maxPath[0] = max(maxPath[0], root.val + leftMax + rightMax)

            return root.val + max(leftMax, rightMax)

        depthFirstSearch(root)
        return maxPath[0]

