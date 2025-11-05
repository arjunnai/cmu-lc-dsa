class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        freqDict = {}
        for char in magazine:
            if char in freqDict:
                freqDict[char]+=1
            else:
                freqDict[char] = 1
        

        for char in ransomNote:
            if char in freqDict and freqDict[char]>0:
                freqDict[char]-=1
            else:
                return False

        return True
        