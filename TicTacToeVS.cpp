//This is my first project! I am currently beginning to learn
// C++, and this was a simple program to learn the basics.
//I created a game of tic-tac-toe against a computer player.

#include <iostream>
#include <ctime>
#include <climits>

//declare all functions
void drawBoard(char* spaces);
void playerMove(char* spaces, char player);
void computerMove(char* spaces, char computer);
bool checkWinner(char* spaces, char player, char computer);
bool checkTie(char* spaces);

int main() {
    char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running) {
        playerMove(spaces, player);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (checkTie(spaces)) {
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (checkTie(spaces)) {
            running = false;
            break;
        }
    }
    return 0;
}

void drawBoard(char* spaces) {
    std::cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << " " << '\n';
    std::cout << "---|---|---\n";
    std::cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << " \n";
    std::cout << "\n";
}

void playerMove(char* spaces, char player) {
    int number;
    while (true) {
        std::cout << "Enter a number to place an X (1-9): ";
        std::cin >> number;

        // Check if input is not a number
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(INT_MAX, '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }

        number--;
        if (number >= 0 && number <= 8 && spaces[number] == ' ') {
            spaces[number] = 'X';
            break;
        }
        else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
}

void computerMove(char* spaces, char computer) {
    int number;
    srand(time(0));

    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char* spaces, char player, char computer) {
    // Possible winning combinations
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (spaces[wins[i][0]] != ' ' &&
            spaces[wins[i][0]] == spaces[wins[i][1]] &&
            spaces[wins[i][1]] == spaces[wins[i][2]]) {
            if (spaces[wins[i][0]] == player) {
                std::cout << "You Win!\n";
            }
            else {
                std::cout << "You Lose :(\n";
            }
            return true;
        }
    }
    return false;
}

bool checkTie(char* spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "It's a tie!";
    return true;
}
