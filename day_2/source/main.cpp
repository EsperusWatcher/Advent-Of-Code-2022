#include "../include/include.h"

// Rock-Paper-Scissors game
// A, X - rock (1 point)
// B, Y - paper (2 points)
// C, Z - scissors (3 points)

// Round results:
// win - 6 points
// lose - 0 points
// draw - 3 points

// Very Ugly
int RockPaperScissorsRound(int A, int B)
{
    int round_score = 0;

    switch (A)
    {
        case ROCK:
            switch (B)
            {
                case ROCK:
                    round_score = ROCK + DRAW;
                    break;

                case PAPER:
                    round_score = PAPER + WIN;
                    break;

                case SCISSORS:
                    round_score = SCISSORS + LOSE;
                    break;

                default:
                    break;
            }   

            break;

        case PAPER:
            switch (B)
            {
                case ROCK:
                    round_score = ROCK + LOSE;
                    break;

                case PAPER:
                    round_score = PAPER + DRAW;
                    break;

                case SCISSORS:
                    round_score = SCISSORS + WIN;
                    break;

                default:
                    break;
            }

            break;

        case SCISSORS:
            switch (B)
            {
                case ROCK:
                    round_score = ROCK + WIN;
                    break;
                
                case PAPER:
                    round_score = PAPER + LOSE;
                    break;

                case SCISSORS:
                    round_score = SCISSORS + DRAW;
                    break;

                default:
                    break;
            }

            break;

        default:
            break;
    }

    return round_score;
}

int main()
{
    std::fstream puzzle_hook;
    puzzle_hook.open("puzzle_input.txt", std::ios::in);

    std::string file_line;

    int total_score = 0;

    std::map <char, int> puzzle_data_map;

    puzzle_data_map['A'] = ROCK;
    puzzle_data_map['X'] = ROCK;

    puzzle_data_map['B'] = PAPER;
    puzzle_data_map['Y'] = PAPER;

    puzzle_data_map['C'] = SCISSORS;
    puzzle_data_map['Z'] = SCISSORS;

    do
    {
        getline(puzzle_hook, file_line);

        // Format is always "A B"
        total_score += RockPaperScissorsRound(puzzle_data_map[file_line[0]], puzzle_data_map[file_line[2]]);

    } while (!puzzle_hook.eof());
    
    std::cout << "Total score: " << total_score << "\n";

    return 0;
}