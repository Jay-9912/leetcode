class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res={}
        for s in strs:
            tmp=[0 for i in range(26)]
            for i in range(len(s)):
                tmp[ord(s[i])-ord('a')]+=1
            if tuple(tmp) not in res.keys():
                res[tuple(tmp)]=[];
            res[tuple(tmp)].append(s)
        return list(res.values())
