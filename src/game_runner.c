#include "game_runner.h"

int main(int argc, char* argv[]) {
    playGame();
    return 0;
}

void playGame() {
    Game* aGame = newGame();

    add(aGame, "Chet");
    add(aGame, "Pat");
    add(aGame, "Sue");

    do {
        roll(aGame, nextInt(5) + 1);

        if (nextInt(9) == 7) {
            notWinner = wrongAnswer(aGame);
        } else {
            notWinner = wasCorrectlyAnswered(aGame);
        }
    } while (notWinner);

}