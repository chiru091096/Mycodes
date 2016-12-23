#Python program to censor the given word

def censor(text,word):
    length=len(text)
    star=""
    
    for i in range(len(word)):
        star+='*'
        
    text1=""
    i=0
    word1=""
    
    while text[i]!=' ' and i<length:
        word1+=text[i]   #get first word
        i+=1  
        
    i+=1        #point to beginning of next word
    
    while True :
        if word1==word:
            text1+=star
        else:
            text1+=word1
            
        if i>=length:
            break
    
        text1+=' '   # after above if condition so that extra space is not added to text1
        word1=""
        
        while i<length and text[i]!=' ':
            word1+=text[i]
            i+=1
        i+=1    
    return text1
