#include "../include/include.h"

// Rock-Paper-Scissors game
// A - rock (1 point)
// B - paper (2 points)
// C - scissors (3 points)

// Round results:
// win - 6 points
// lose - 0 points
// draw - 3 points

// Desired round result:
// X - you must lose
// Y - must be a draw
// Z - you must win

// Very Ugly
// A - Your opponent move
// B - desired round result
int RockPaperScissorsRound(int A, int B)
{
    int round_score = 0;

    switch (A)
    {
        case ROCK:
            switch (B)
            {
                case LOSE:
                    round_score = SCISSORS + LOSE;
                    break;

                case DRAW:
                    round_score = ROCK + DRAW;
                    break;

                case WIN:
                    round_score = PAPER + WIN;
                    break;

                default:
                    break;
            }   

            break;

        case PAPER:
            switch (B)
            {
                case LOSE:
                    round_score = ROCK + LOSE;
                    break;

                case DRAW:
                    round_score = PAPER + DRAW;
                    break;

                case WIN:
                    round_score = SCISSORS + WIN;
                    break;

                default:
                    break;
            }

            break;

        case SCISSORS:
            switch (B)
            {
                case LOSE:
                    round_score = PAPER + LOSE;
                    break;
                
                case DRAW:
                    round_score = SCISSORS + DRAW;
                    break;

                case WIN:
                    round_score = ROCK + WIN;
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
    puzzle_data_map['B'] = PAPER;
    puzzle_data_map['C'] = SCISSORS;

    puzzle_data_map['X'] = LOSE;
    puzzle_data_map['Y'] = DRAW;
    puzzle_data_map['Z'] = WIN;


    do
    {
        getline(puzzle_hook, file_line);

        // Format is always "A B"
        total_score += RockPaperScissorsRound(puzzle_data_map[file_line[0]], puzzle_data_map[file_line[2]]);

    } while (!puzzle_hook.eof());
    
    std::cout << "Total score: " << total_score << "\n";

    return 0;
}