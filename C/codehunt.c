#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

const char *HASH_PART1() { return "8b5b9db0c13db24256c829aa364aa90c6d2eba318b9232a4ab9313b954d3555f"; } // hash("three")

void cos2mphu5tae6(const char *str, char *output_buffer) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)str, strlen(str), hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output_buffer + (i * 2), "%02x", hash[i]);
    }
    output_buffer[64] = 0;
}

const char *HASH_PART2() { return "47c215b5f70eb9c9b4bcb2c027007d6cf38a899f40d1d1da6922e49308b15b69"; } // hash("eye")

void Frost()
{
    printf("There were _____ in the meadow by the brook\n");
    printf("Gathering up windrows, piling cocks of hay,\n");
    printf("With an ___ always lifted toward the west\n");
    printf("Where an irregular ___-bordered cloud\n");
    printf("Darkly advanced with a perpetual dagger\n");
    printf("Flickering across its bosom. Suddenly\n");
    printf("One helper, thrusting pitchfork in the ground,\n");
    printf("Marched himself off the field and home. One stayed.\n");
    printf("The town-bred farmer failed to understand.\n");
}
const char *HASH_PART3() { return "27756f050e14a1cb1c1ee867f0eace9ea4d9fcb81b8bee089469f1ebd5fd7b17"; } // hash("sun")
const char *FULL_HASH() { return "04b904b5a7639cddd7723d745711f881bb164feef5b9afc68fa1ba5d7321a077"; } // hash("three-eye-sun")

int main(int argc, char *argv[]) {
    // Define mutable buffers for each part
    char part1[65], part2[65], part3[65], full_hash[65];

    // Copy constant parts into mutable buffers
    strcpy(part1, HASH_PART1());
    strcpy(part2, HASH_PART2());
    strcpy(part3, HASH_PART3());
    strcpy(full_hash, FULL_HASH());

    printf("Initiating system...\n");
    printf("Log: D3H3-INIT | Fragment verification in progress...\n");
    printf("System code 34B | AUTH-START...\n");

    // Display the poem with underlined blanks for missing words
    Frost();
    
    printf("Hint: Think of fullness, a resting place, and blooms.\n");

    if (argc != 2) {
        printf("Error: Invalid input length. System code 33X.\n");
        printf("Hint: There are multiple parts to complete the whole.\n");
        return 1;
    }

    const char *input_part = argv[1];
    char hash_output[65];
    cos2mphu5tae6(input_part, hash_output);

    if (strcmp(hash_output, part1) == 0) {
        printf("Partial match: Number revealed !!\n");
        printf("Noise log: A9F2-R3Q | Integrity check at 28%%...\n");
        return 0;
    } else if (strcmp(hash_output, part2) == 0) {
        printf("Intermediate structure confirmed. Vision Active.\n");
        printf("System warning: E47W3 | Cottage verification at 72%%.\n");
        return 0;
    } else if (strcmp(hash_output, part3) == 0) {
        printf("Partial match: Sun's out.\n");
        printf("Note log: T6B3-ALT | Blossoming checks pass.\n");
        return 0;
    } else if (strcmp(hash_output, full_hash) == 0) {
        printf("Success: The Code restored.\n");
        return 0;
    } else {
        printf("No match found. System warning: code 405-INVALID.\n");
        printf("Hint: Think of a number, a blind man, and the warmth of the Sun.\n");
        printf("Log: Interference high. Recheck structure for any missing parts.\n");
        return 1;
    }
}
