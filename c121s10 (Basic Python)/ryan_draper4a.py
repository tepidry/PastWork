"""
Author: Ryan Draper
Class: CPSC121 
Assignment Number: 04a
"""
def getPos(ch):
    return (ord(ch) - 97)

def getLetter(pos):
    return (chr(pos + 97));

def vignereIndex(keyLetter, plainTextLetter):
    keyIndex = getPos(keyLetter)
    plainTextIndex = getPos(plainTextLetter)
    newIdx = (plainTextIndex + keyIndex) % 26
    newLetter = getLetter(newIdx)
    return newLetter

def encryptVignere(key, plainText):
    cipherText = ''
    keyLen = len(key)
    plainText = plainText.lower()
    key = key.lower()
    for i in range (len(plainText)):
        ch = plainText[i]
        if not ch.isalpha():
            cipherText = cipherText + ch
        else:
            keyChar = key[i%keyLen]
            cipherText = cipherText + vignereIndex(keyChar, ch)
    return cipherText

def main():
    plainText = input("Input plain text\n")
    key = input("Input a key\n")
    print (encryptVignere(key, plainText))
        

main()
