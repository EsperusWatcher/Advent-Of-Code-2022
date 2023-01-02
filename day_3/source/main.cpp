#include "../include/include.h"

// Puzzle input contains strings representing content of rucksacks
// Each rucksack has two compartments: first half of its content and second
// Each of compartments has one item in common
// each item can be converted into value

// a -> z | 1 -> 26
// A -> Z | 27 -> 52

// The goal is to find the sum of values for common items in these rucksacks

char FindCommonItem(std::string rucksack_contents)
{
    char common;

    for (int i = 0; i < rucksack_contents.length() / 2; i++)
        for (int k = rucksack_contents.length() / 2; k < rucksack_contents.length(); k++)
            if (rucksack_contents[i] == rucksack_contents[k])
            {
                common = rucksack_contents[i];
                break;
            }

    return common;
}

int ConvertItemToValue(char item)
{
    if ((int)item - ASCII_OFFSET < 0)
        return((int)item - ASCII_OFFSET_CAPITAL);
    else
        return ((int)item - ASCII_OFFSET);
}

int main()
{
    std::fstream puzzle_hook;

    puzzle_hook.open("puzzle_input.txt", std::ios::in);

    std::string file_line;

    int total_common_value = 0;
    do
    {
        getline(puzzle_hook, file_line);

        total_common_value += ConvertItemToValue(FindCommonItem(file_line));

    } while (!puzzle_hook.eof());

    std::cout << "Total common value: " << total_common_value << "\n";

    puzzle_hook.close();

    return 0;
}