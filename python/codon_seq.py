START = "AUG"
STOP = ["UAA", "UAG", "UGA"]


def seq_to_codon(seq: str) -> str:
    seq = seq.upper()  # FOR GENERALISATION
    starts_at = seq.find(START)
    new_seq = seq[starts_at:]
    remove_how_many = len(new_seq) % 3
    if remove_how_many == 0:
        pass
    else:
        new_seq = new_seq[:-remove_how_many]  # Remove extra from the end
    splitting_into_3 = []
    # Make sets of 3
    for i in range(0, len(new_seq), 3):
        splitting_into_3.append(new_seq[i:i+3])
    for i in range(len(splitting_into_3)):
        if splitting_into_3[i] == STOP[0] or splitting_into_3[i] == STOP[1] or splitting_into_3[i] == STOP[2]:
            list_to_end_at = i
            break
    splitting_into_3 = splitting_into_3[:list_to_end_at+1]

    return " ".join(splitting_into_3)


CONVERTOR = {"UUU": "F", "UUC": "F", "AUG": "M", "UAU": "Y", "UAC": "Y", "UAA": "Ochre", "UAG": "Amber", "CAU": "H",
             "CAC": "H", "CAA": "Q", "CAG": "Q", "AAU": "N", "AAC": "N", "AAA": "K", "AAG": "K", "GAU": "D", "GAC": "D",
             "GAA": "E", "GAG": "E", "UGU": "C", "UGC": "C", "UGG": "W", "AGU": "S", "AGC": "S", "AGA": "R", "AGG": "R",
             "GGG": "G", "GGA": "G", "GGC": "G", "GGU": "G", "CGU": "R", "CGC": "R", "CGA": "R", "CGG": "R", "GCG": "A",
             "GCC": "A", "GCA": "A", "GCU": "A", "ACU": "T", "ACC": "T", "ACA": "T", "ACG": "T", "CCU": "P", "CCC": "P",
             "CCA": "P", "CCG": "P", "UCU": "S", "UCC": "S", "UCA": "S", "UCG": "S", "GUU": "V", "GUC": "V", "GUA": "V",
             "GUG": "V", "AUU": "I", "AUC": "I", "AUA": "I", "UUA": "L", "UUG": "L", "CUU": "L", "CUC": "L", "CUA": "L",
             "CUG": "L", "UGA": "Opal"}


def codon_to_protein(codon: str) -> None:
    for i in codon.split():
        print(CONVERTOR[i], end=" ")
    print()


def main():
    nucleic = input("Enter nucleic sequence: ")
    codon = seq_to_codon(nucleic)
    print(codon)
    codon_to_protein(codon)


if __name__ == "__main__":
    main()
