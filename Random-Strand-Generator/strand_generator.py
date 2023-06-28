from random import choice
count = int(input("Count: "))
nucleotides = ["A", "C", "G", "T"]
strand = ""
for _ in range(count):
    new_nucleotide = choice(nucleotides)
    strand = strand + new_nucleotide
print(strand)

'''
for _ in range(count):
    print(random.choice["A", "C", "G", "T"], end = "")
'''