#include "../include/include.h"

// Puzzle input contains strings representing content of rucksacks
// Each rucksack has two compartments: first half of its content and second
// Each of compartments has one item in common
// each item can be converted into value

// a -> z | 1 -> 26
// A -> Z | 27 -> 52

// The goal is to find the sum of values for common items in these rucksacks
// in sets of three

char FindCommonItem(std::string rucksack_1, std::string rucksack_2, std::string rucksack_3)
{
    char common;
    bool commonFound = false;

    for (int i = 0; i < rucksack_1.length() && !commonFound; i++)
        for (int k = 0; k < rucksack_2.length() && !commonFound; k++)
        {
            if (rucksack_1[i] == rucksack_2[k])
                for (int j = 0; j < rucksack_3.length(); j++)
                {
                    if (rucksack_2[k] == rucksack_3[j])
                    {
                        common = rucksack_3[j];
                        commonFound = true;
                        break;
                    }
                }
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

    std::string rucksack_1;
    std::string rucksack_2;
    std::string rucksack_3;

    int total_common_value = 0;
    do
    {
        getline(puzzle_hook, rucksack_1);
        getline(puzzle_hook, rucksack_2);
        getline(puzzle_hook, rucksack_3);

        total_common_value += ConvertItemToValue(FindCommonItem(rucksack_1, rucksack_2, rucksack_3));

    } while (!puzzle_hook.eof());

    std::cout << "Total common value: " << total_common_value << "\n";

    puzzle_hook.close();

    return 0;
}