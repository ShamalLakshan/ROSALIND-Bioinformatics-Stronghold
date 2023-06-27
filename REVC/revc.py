strand = input("Input: ")
strand = strand[::-1]
for nucleotide in strand:
    if nucleotide == "A":
        print("T", end="")
    elif nucleotide == "T":
        print("A", end="")
    elif nucleotide == "G":
        print("C", end="")
    elif nucleotide == "C":
        print("G", end="")
