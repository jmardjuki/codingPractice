class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        #appends
        vowel = {'a', 'e', 'i', 'o', 'u'}
        add = "ma"
        words = sentence.split()
        n = len(words)

        i = 0
        ret_string = ""
        for word in words:
            if word[0].lower() in vowel:
                ret_string += word+add
            else:
                ret_string += word[1:]+word[0]+add
            ret_string += (i+1)*'a'
            if i < n-1:
                ret_string += " " 
            i+=1
        return ret_string
