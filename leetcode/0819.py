import collections
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        pr2 = ""
        paragraph = paragraph.lower()
        for ch in paragraph:
            if (ord(ch)>=ord('a') and ord(ch)<=ord('z')) or ch==' ':
                pr2 += ch
            else:
                pr2 += ' '
        pr2 = pr2.lower().split()
        counter = collections.Counter(pr2)
        mc = counter.most_common()
        for word,cnt in mc:
            if word not in banned:
                return word