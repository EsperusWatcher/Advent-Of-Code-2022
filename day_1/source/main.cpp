#include "../include/include.h"

void SortArray (int array[MAX_TOP])
{
    // Bubble sort
    for (int i = 0; i < MAX_TOP - 1; i++)
        for (int j = 0; j < MAX_TOP - i - 1; j++)
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
}

int main()
{
    std::fstream puzzle_hook;
    puzzle_hook.open("puzzle_input.txt", std::ios::in);

    std::string file_line;

    int current_elf_calories = 0;
    int max_elf_calories[MAX_TOP];

    for (int i = 0; i < MAX_TOP; i++)
        max_elf_calories[i] = 0;

    do
    {
        getline(puzzle_hook, file_line);

        if (file_line.length() == 0)
        {
            for (int i = 0; i < MAX_TOP; i++)
            {
                if (current_elf_calories > max_elf_calories[i])
                {
                    max_elf_calories[i] = current_elf_calories;
                    SortArray(max_elf_calories);
                    break;
                }
            }

            current_elf_calories = 0;
        }
        else
        {
            current_elf_calories += stoi(file_line);
        }

    } while (!puzzle_hook.eof());

    long int top_three_elf_calories_total = 0;

    for (int i = 0; i < MAX_TOP; i++)
        top_three_elf_calories_total += max_elf_calories[i];

    std::cout << "Top 3 calories total: " << top_three_elf_calories_total << "\n"; 

    puzzle_hook.close();

    return 0;
}