
#include "BioPerl.hpp"


void ConvertNucleotidesToCodons(char *argv[]) {
    FILE* inputFile = fopen(argv[1], "r");

    char input = fgetc(inputFile);

    /** Skip the first line of FASTA files, which are generally just metadata
     *  that we do not need to worry about right now.
     *
     */
    if (input == '>') {
        while (input != '\n') {
            input = fgetc(inputFile);
        }
    }

    while (input != EOF) {
        input = fgetc(inputFile);

        if (input == ADENINE) {
            input = fgetc(inputFile);

            if (input == ADENINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("K");
                } else if (input == CYTOSINE) {
                    printf("N");
                } else if (input == GUANINE) {
                    printf("K");
                } else if (input == THYMINE) {
                    printf("N");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == CYTOSINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("T");
                } else if (input == CYTOSINE) {
                    printf("T");
                } else if (input == GUANINE) {
                    printf("T");
                } else if (input == THYMINE) {
                    printf("T");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == GUANINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("R");
                } else if (input == CYTOSINE) {
                    printf("S");
                } else if (input == GUANINE) {
                    printf("R");
                } else if (input == THYMINE) {
                    printf("S");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == THYMINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("I");
                } else if (input == CYTOSINE) {
                    printf("I");
                } else if (input == GUANINE) {
                    printf("M");
                } else if (input == THYMINE) {
                    printf("I");
                } else {
                    // TODO: Handle this case
                }
            } else {
                // TODO: Handle this case
            }
        } else if (input == CYTOSINE) {
            input = fgetc(inputFile);

            if (input == ADENINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("Q");
                } else if (input == CYTOSINE) {
                    printf("H");
                } else if (input == GUANINE) {
                    printf("Q");
                } else if (input == THYMINE) {
                    printf("H");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == CYTOSINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("P");
                } else if (input == CYTOSINE) {
                    printf("P");
                } else if (input == GUANINE) {
                    printf("P");
                } else if (input == THYMINE) {
                    printf("P");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == GUANINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("R");
                } else if (input == CYTOSINE) {
                    printf("R");
                } else if (input == GUANINE) {
                    printf("R");
                } else if (input == THYMINE) {
                    printf("R");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == THYMINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("L");
                } else if (input == CYTOSINE) {
                    printf("L");
                } else if (input == GUANINE) {
                    printf("L");
                } else if (input == THYMINE) {
                    printf("L");
                } else {
                    // TODO: Handle this case
                }
            } else {
                // TODO: Handle this case
            }
        } else if (input == GUANINE) {
            input = fgetc(inputFile);

            if (input == ADENINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("E");
                } else if (input == CYTOSINE) {
                    printf("D");
                } else if (input == GUANINE) {
                    printf("E");
                } else if (input == THYMINE) {
                    printf("D");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == CYTOSINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("A");
                } else if (input == CYTOSINE) {
                    printf("A");
                } else if (input == GUANINE) {
                    printf("A");
                } else if (input == THYMINE) {
                    printf("A");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == GUANINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("G");
                } else if (input == CYTOSINE) {
                    printf("G");
                } else if (input == GUANINE) {
                    printf("G");
                } else if (input == THYMINE) {
                    printf("G");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == THYMINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("V");
                } else if (input == CYTOSINE) {
                    printf("V");
                } else if (input == GUANINE) {
                    printf("V");
                } else if (input == THYMINE) {
                    printf("V");
                } else {
                    // TODO: Handle this case
                }
            } else {
                // TODO: Handle this case
            }
        } else if (input == THYMINE) {
            input = fgetc(inputFile);

            if (input == ADENINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("_");
                } else if (input == CYTOSINE) {
                    printf("Y");
                } else if (input == GUANINE) {
                    printf("_");
                } else if (input == THYMINE) {
                    printf("Y");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == CYTOSINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("S");
                } else if (input == CYTOSINE) {
                    printf("S");
                } else if (input == GUANINE) {
                    printf("S");
                } else if (input == THYMINE) {
                    printf("S");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == GUANINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("_");
                } else if (input == CYTOSINE) {
                    printf("C");
                } else if (input == GUANINE) {
                    printf("W");
                } else if (input == THYMINE) {
                    printf("C");
                } else {
                    // TODO: Handle this case
                }
            } else if (input == THYMINE) {
                input = fgetc(inputFile);

                if (input == ADENINE) {
                    printf("L");
                } else if (input == CYTOSINE) {
                    printf("F");
                } else if (input == GUANINE) {
                    printf("L");
                } else if (input == THYMINE) {
                    printf("F");
                } else {
                    // TODO: Handle this case
                }
            } else {
                // TODO: Handle this case
            }
        } else {
            // TODO: Handle this case
        }

        //printf("%c", input);
    }

    printf("\n");

    fclose(inputFile);
}
