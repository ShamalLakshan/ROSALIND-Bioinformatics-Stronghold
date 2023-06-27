def main():
    strand = input("Input: ")
    
    A = 0 
    C = 0 
    G = 0 
    T = 0

    for nucleotide in strand:
        if nucleotide == "A":
            A = A + 1
        elif nucleotide == "C":
            C = C + 1
        elif nucleotide == "G":
            G = G + 1
        elif nucleotide == "T":
            T = T + 1
        else:
            break

    print(A, C, G, T)

main()