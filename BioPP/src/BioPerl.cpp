
#include "BioPerl.hpp"

namespace Bio
{
    template <typename T1, typename T2>
    constexpr inline auto Max(T1 a, T2 b) noexcept
    {
        return (a > b) ? a : b;
    }

    template <typename T1, typename T2, typename... Types>
    constexpr inline auto Max(T1 a, T2 b, Types... args) noexcept 
    {
        return Max(a, Max(b, args...));
    }

    template <typename T1, typename T2>
    constexpr inline auto Min(T1 a, T2 b) noexcept
    {
        return ((a < b) ? a : b);
    }

    template <typename T1, typename T2, typename... Types>
    constexpr inline auto Min(T1 a, T2 b, Types... args) noexcept
    {
        return Min(a, Min(b, args...));
    }
} // namespace Bio

// Source: https://en.wikipedia.org/wiki/Wagner%E2%80%93Fischer_algorithm

int main()
{
    char* seq = "SVLQDRSMPHQEILAADEVLQESEMRQQDMISHDE";
    char* txt = "EIQADEVRL";

    std::size_t l1 = strlen(seq) + 1;
    std::size_t l2 = strlen(txt) + 1;

    int **distanceMatrix = (int **) malloc(sizeof(int *) * l2);
    
    for (auto i = 0u; i < l2; i++) {
        distanceMatrix[i] = (int * ) malloc(sizeof(int) * l1);
    }

    {   /** Initialize the matrix */
        for (auto i = 0u; i < l1; i++) {
            // distanceMatrix[0][i] = i;
            distanceMatrix[0][i] = 0;
        }

        for (auto i = 0u; i < l2; i++) {
            distanceMatrix[i][0] = i;
        }
    }   /** End matrix initialization */

    for (auto i = 1u; i < l2; i++) {
        for (auto j = 1u; j < l1; j++) {
            if (seq[j-1] == txt[i-1]) {
                distanceMatrix[i][j] = distanceMatrix[i-1][j-1];
            } else {
                distanceMatrix[i][j] = Bio::Min(distanceMatrix[i-1][j] + 1, distanceMatrix[i][j-1] + 1, distanceMatrix[i-1][j-1] + 1);
            }
        }
    }

    for (auto i = 0u; i < l1; i++) {
        printf("%2d ", i);
    }

    printf("\n");

    for (auto i = 0u; i < l2; i++) {
        for (auto j = 0u; j < l1; j++) {
            printf("%2d ", distanceMatrix[i][j]);
        }

        printf("\n");
    }

    int score = l1;
    int position = 0;

    for (auto i = 1u; i < l1; i++) {
        if (distanceMatrix[l2-1][i] < score) {
            score = distanceMatrix[l2-1][i];
            position = i;
        }
    }

    printf("Edit Distance: %d\n", score);
    printf("Position: %d\n", position);

    char* match = (char *) malloc(sizeof(char) * l2);
    
    char* offsetString = &seq[position-l2+1];

    strncpy(match, offsetString, l2 - 1);

    printf("Original: %s\n", txt);
    printf("Match:    %s\n", match);

    return EXIT_SUCCESS;
}
