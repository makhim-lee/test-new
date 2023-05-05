fin = open("lyrics.txt", "r")
lines = fin.readlines()
fin.close()

wordCount = {}

for n, line in enumerate(lines):
    for word in line.strip().split() :
        word = ''.join(char for char in word if char.isalnum())
        #word = word.strip('\'"(),!').lower()
        if word in wordCount.keys() : 
            wordCount[word].append(n)
        else :
            wordCount[word] = [n]
    
for word, index in wordCount.items() :
    print(f"{word} in {index}")    




