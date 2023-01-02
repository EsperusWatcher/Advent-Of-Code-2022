#include "../include/include.h"

int main()
{
    std::fstream puzzle_hook;
    puzzle_hook.open("puzzle_input.txt", std::ios::in);

    std::string file_line;

    int current_elf_calories = 0;
    int max_elf_calories = 0;

    do
    {
        getline(puzzle_hook, file_line);

        if (file_line.length() == 0)
        {
            if (current_elf_calories > max_elf_calories)
                max_elf_calories = current_elf_calories;

            current_elf_calories = 0;
        }
        else
        {
            current_elf_calories += stoi(file_line);
        }

    } while (!puzzle_hook.eof());

    std::cout << "Max calories: " << max_elf_calories << "\n";

    puzzle_hook.close();

    return 0;
}