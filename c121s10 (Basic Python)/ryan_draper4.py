"""
Author: Ryan Draper
Class: CPSC121 
Assignment Number: 04
"""


import random
def removeChar(string,idx):
    return string[:idx] + string[idx+1:]

def keyGen():
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    sizeAlpha = len(alpha)
    key = ''
    for i in range(sizeAlpha):
        ch = random.randrange(0, len(alpha))
        key = key + alpha[ch]
        alpha = removeChar(alpha,ch)
    return key

def sub1Encrypt(plainText,key):
    alph = 'abcdefghijklmnopqrstuvwxyxz'
    plainText = plainText.lower()

    cipherText = ''
    for ch in plainText:
        idx = alph.find(ch)
        cipherText = cipherText + key[idx]

    return cipherText

def sub1Decrypt(cipherText, key)
    decipherText = ''
    for ch in cipherText:
        
    
def main():
    plainText = input("Input a string\n")
    key = keyGen();
    print ('key = : ', key)
    cipherText = sub1Encrypt(plainText, key)
    print('Cipher Text : ',cipherText)
    decipherText = sub1Decrypt(cipherText, key)
    print('Decipher Text : ',decipherText)
    
    

main()
    
