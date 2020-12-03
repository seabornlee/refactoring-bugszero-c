#include "game_runner.h"

int main(int argc, char* argv[]) {
    Game* aGame = newGame();
    playGame(aGame);
    destroyGame(aGame);
    return 0;
}

void playGame(Game *aGame) {
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