#include <sstream>
#include <iostream>
#include <unordered_map>
#include <tuple>

#include "config.h"

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

#define LOSS 0
#define DRAW 3
#define WIN 6

#define ENEMY_ROCK 'A'
#define ENEMY_PAPER 'B'
#define ENEMY_SCISSORS 'C'

#define PLAYER_ROCK 'X'
#define PLAYER_PAPER 'Y'
#define PLAYER_SCISSORS 'Z'

int calculateScore(char enemyChoice, char response) {
    // sorry not sorry
    return enemyChoice == ENEMY_ROCK ? 
        (response == PLAYER_ROCK ? DRAW :
         response == PLAYER_PAPER ? WIN : LOSS /*rock beats scissors*/) :

        (enemyChoice == ENEMY_PAPER ?
            (response == PLAYER_ROCK ? LOSS :
             response == PLAYER_PAPER ? DRAW : WIN /*paper loses to scissors*/) :

            // enemy scissors bb
            (response == PLAYER_ROCK ? WIN :
             response == PLAYER_PAPER ? LOSS : DRAW /*scissors vs scissors is draw*/));
}

// This doesn't even work but the below comment is true so here it is,
// now a testament to my ability to waste time or something
//
// It took me WAY too long to format this like this lol
/*const std::unordered_map<std::tuple<char, char>, int> scoreMap = {
    { { ENEMY_ROCK    , PLAYER_ROCK       },  DRAW },
    { { ENEMY_ROCK    , PLAYER_PAPER      },  WIN  },
    { { ENEMY_ROCK    , PLAYER_SCISSORS   },  LOSS },

    { { ENEMY_PAPER   , PLAYER_ROCK       },  LOSS },
    { { ENEMY_PAPER   , PLAYER_PAPER      },  DRAW },
    { { ENEMY_PAPER   , PLAYER_SCISSORS   },  WIN  },

    { { ENEMY_SCISSORS, PLAYER_ROCK       },  WIN  },
    { { ENEMY_SCISSORS, PLAYER_PAPER      },  LOSS },
    { { ENEMY_SCISSORS, PLAYER_SCISSORS   },  DRAW },
};*/

int answerPartOne(const std::string& input) {
    std::stringstream ss(input);

    int score = 0;

    for (std::string line; std::getline(ss, line); ) {
        score += (line[2] == PLAYER_ROCK ? ROCK : (line[2] == PLAYER_PAPER ? PAPER : SCISSORS));
        score += calculateScore(line[0], line[2]);
    }

    return score;
}

enum class Choice {
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

int scoreAfterResponseForDesiredOutcome(char enemyChoice, char desiredOutcome) {
    bool lose = desiredOutcome == 'X';
    bool draw = desiredOutcome == 'Y';
    // bool win = desiredOutcome == 'Z';

    Choice choice =
        // ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary ternary
        // you probably didn't read that but if you did does it still feel like a real word?
        enemyChoice == ENEMY_ROCK ?
            (lose ? Choice::Scissors :
            (draw ? Choice::Rock : Choice::Paper /* to win */)) :

            (enemyChoice == ENEMY_PAPER ? 
                (lose ? Choice::Rock :
                (draw ? Choice::Paper : Choice::Scissors /* to win */)) :

                // ENEMY_SCISSORS bb
                    (lose ? Choice::Paper :
                    (draw ? Choice::Scissors : Choice::Rock)));

    return ((int)choice + (lose ? 0 : (draw ? 3 : 6)));
}

int answerPartTwo(const std::string& input) {
    std::stringstream ss(input);

    int score = 0;

    for (std::string line; std::getline(ss, line); ) {
        char enemyChoice = line[0];
        char desiredOutcome = line[2];

        score += scoreAfterResponseForDesiredOutcome(enemyChoice, desiredOutcome);
    }

    return score;
}

int main() {
    std::cout << "Example part 1 answer: " << answerPartOne(DAY_TWO_EXAMPLE_INPUT) << "\n";
    std::cout << "Example part 2 answer: " << answerPartTwo(DAY_TWO_EXAMPLE_INPUT) << "\n";

    std::cout << "Part 1 answer: " << answerPartOne(DAY_TWO_INPUT) << "\n";
    std::cout << "Part 2 answer: " << answerPartTwo(DAY_TWO_INPUT) << "\n";
}
