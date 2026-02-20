class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        # Optimized solution
        # String is immutable on Python
        # Every concatnation cost in loop
        # cost extra to deep copy and add to the string
        vowel = {'a', 'e', 'i', 'o', 'u'}
        add = "ma"
        words = sentence.split()
        n = len(words)

        i = 0
        ret_list = []
        for i, word in enumerate(words):
            ret_string ="" 
            if word[0].lower() in vowel:
                ret_string += word+add
            else:
                ret_string += word[1:]+word[0]+add
            ret_string += (i+1)*'a'
            ret_list.append(ret_string)
        return ' '.join(ret_list)
