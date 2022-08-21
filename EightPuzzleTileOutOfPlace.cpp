#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>


/*Eight Puzzle Tile of Out of place counting.
 *Using 2D Vector(Dynamic Array) input initial state of Eight Puzzle & generate states after sliding.
 *Compare those generated state with goal stata for tile out of place value
 */

void printState (const std::vector<std::vector<int>>& input)
{
    std::cout << "8 Puzzle state: \n";
    for (const auto& row : input)
    {
        for (const auto& s : row)
            std::cout << s << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::vector<int>> generateState (const std::vector<std::vector<int>>& input,
                                             int initialRow,
                                             int initialCol,
                                             int destRow,
                                             int destCol)
{
    std::vector<std::vector<int>> result = input;

    std::swap (result[initialRow][initialCol], result[destRow][destCol]);

    return result;
}

int findTileOutOfPlace (const std::vector<std::vector<int>>& input,
                        const std::vector<std::vector<int>>& comparator)
{
    int result{0};
    for (std::size_t i = 0; i < input.size (); i++)
    {
        for (std::size_t j = 0; j < input[i].size (); j++)
        {
            if (input[i][j] != comparator[i][j] && input[i][j] != 0)
                result += 1;
        }
    }

    return result;
}

int main ()
{
    std::vector<std::vector<int>> initialState = {{2, 8, 3}, {1, 6, 4}, {7, 0, 5}}; // Given 8-puzzle
    const std::vector<std::vector<int>> goalState = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};

    const std::vector<std::vector<int>> state1 =
    generateState (initialState, 2, 1, 2, 0);
    const std::vector<std::vector<int>> state2 =
    generateState (initialState, 2, 1, 1, 1);
    const std::vector<std::vector<int>> state3 =
    generateState (initialState, 2, 1, 2, 2);
    // printState (state1);
    // printState (state2);
    // printState (state3);

    std::cout << "Tile out of place for state1: " << findTileOutOfPlace (state1, goalState)
              << "\n";
    std::cout << "Tile out of place for state2: " << findTileOutOfPlace (state2, goalState)
              << "\n";
    std::cout << "Tile out of place for state3: " << findTileOutOfPlace (state3, goalState)
              << "\n";
    return EXIT_SUCCESS;
}