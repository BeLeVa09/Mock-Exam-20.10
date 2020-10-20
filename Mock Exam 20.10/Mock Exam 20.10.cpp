#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <vector>
#include <algorithm>

void login();
void drawLock(char lock[3][3]);
void menu();
void Task1();
void Task2();
void Task3();
void drawBoard(char board[10][10]);
void Task4();

int main()
{
    srand(time(NULL));
    login();
}

void login() {
    char lock[3][3];
    char correctCombination[5]{ '1', '4', '5', '2', '3' };
    int failCounter{ 0 };

    do {
        int currentX{ 0 };
        int currentY{ 0 };
        int correct{ 0 };
        int counter{ 0 };
        char combination[5]{ '1', '-', '-', '-', '-' };

        // Initializing the grid
        for (int i{ 0 }; i < 3; ++i) {
            for (int j{ 0 }; j < 3; ++j) {
                lock[i][j] = i * 3 + j + 49; // i*3 to get the values 456 and 789 in correct positions since all numbers are values of j
            } // + 49 since this is a char array and I need ascii values of numbers to be put in
        }
        lock[currentY][currentX] = '*'; // Starting position

        system("cls");

        std::cout << "Move with WASD, you have three tries\n";

        drawLock(lock);
        std::cout << "\n\t [" << combination[0] << "][" << combination[1] << "][" << combination[2] << "][" << combination[3] << "][" << combination[4] << "]\n";

        do {
            char input = _getch();
            system("cls");

            lock[currentY][currentX] = currentY * 3 + currentX + 49;
            if (toupper(input) == 'S' && currentY != 2) {
                currentY += 1;
            }
            else if (toupper(input) == 'W' && currentY != 0) {
                currentY -= 1;
            }
            else if (toupper(input) == 'A' && currentX != 0) {
                currentX -= 1;
            }
            else if (toupper(input) == 'D' && currentX != 2) {
                currentX += 1;
            }

            ++counter;
            combination[counter] = lock[currentY][currentX];
            lock[currentY][currentX] = '*';
            drawLock(lock);

            std::cout << "\n\t [" << combination[0] << "][" << combination[1] << "][" << combination[2] << "][" << combination[3] << "][" << combination[4] << "]\n";

        } while (counter < 4);

        for (int i{ 0 }; i < 5; ++i) {
            if (combination[i] == correctCombination[i]) {
                ++correct;
            }
        }
        if (correct == 5) {
            menu();
            failCounter = 3;
        }
        else {
            ++failCounter;
        }
    } while (failCounter < 3);
}

void drawLock(char lock[3][3]) {

    std::cout << "\n\t      ";
    for (int i{ 0 }; i < 3; ++i) {
        for (int j{ 0 }; j < 3; ++j) {

            std::cout << lock[i][j] << ' ';
            
            if (j == 2 && i != 2) {
                std::cout << "\n\t      ";
            }
        }
    }
}

void menu() {
    bool validInput{ 0 };
    bool ifState{ 0 };

    do {
        system("cls");
        std::cout << "Welcome, what task do you want to see?\n";
        std::cout << "\t1. Task 1\n";
        std::cout << "\t2. Task 2\n";
        std::cout << "\t3. Task 3\n";
        std::cout << "\t4. Task 4\n";
        std::cout << "\t5. Quit\n";

        char input = _getch();

        switch (input) {
        case '1':
            Task1();
            break;

        case '2':
            Task2();
            break;

        case '3':
            Task3();
            break;

        case '4':
            Task4();
            break;

        case '5':
            validInput = true;
            break;

        default:

            do {
                std::cout << "\nWrong input ... Do you want to try again? (y/n)\n";
                char choice = _getch();
                if (toupper(choice) == 'Y') {
                    ifState = true;
                }
                else if (toupper(choice) == 'N') {
                    validInput = true;
                    ifState = true;
                }
            } while (!ifState);
                break;
        }
    } while (!validInput);
}

void Task1() {
    int ones{ 0 };
    int twos{ 0 };
    int threes{ 0 };
    int fours{ 0 };
    int fives{ 0 };
    int sixes{ 0 };

    for (int i{ 0 }; i < 2000; ++i) {
        int number{ rand() % 6 + 1 };
        if (number == 1) {
            ++ones;
        }
        else if (number == 2) {
            ++twos;
        }
        else if (number == 3) {
            ++threes;
        }
        else if (number == 4) {
            ++fours;
        }
        else if (number == 5) {
            ++fives;
        }
        else if (number == 6) {
            ++sixes;
        }
    }

    system("cls");
    std::cout << "Rolling 2000 dice...\n";
    
    for (int i{ 0 }; i < 3; ++i) {
        Sleep(1000);
        std::cout << "   .";
    }
    Sleep(1000);
    std::cout << "\nAmounts rolled:\n";
    std::cout << " 1. " << ones << "times\n";
    Sleep(250);
    std::cout << " 2. " << twos << "times\n";
    Sleep(250);
    std::cout << " 3. " << threes << "times\n";
    Sleep(250);
    std::cout << " 4. " << fours << "times\n";
    Sleep(250);
    std::cout << " 5. " << fives << "times\n";
    Sleep(250);
    std::cout << " 6. " << sixes << "times\n";

    system("pause");
}

void Task2() {
    system("cls");

    struct HealthBar {
        int number{ 0 };
        char name{ ' ' };
        int value{ 0 };
    };

    std::vector <HealthBar> list(11);

    std::cout << "No\tName\tValue\tHealth Bar\n";
    std::cout << "-----------------------------------------------\n";

    for (int i{ 0 }; i < 10; ++i) {
        list[i].number = i;
        list[i].name = i + 65;
        list[i].value = rand() % 20 + 1;

        std::cout << list[i].number << "\t" << list[i].name << "\t" << list[i].value << "\t";

        for (int j{ 0 }; j < list[i].value; ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    system("pause");

    // Sorting values
    for (int i{ 0 }; i < 10; ++i) {
        for (int j{ 0 }; j < 10; ++j) {
            if (list[j].value < list[j + 1].value) {
                std::swap(list[j], list[j + 1]);
            }
        }
    }

    system("cls");

    std::cout << "No\tName\tValue\tHealth Bar\n";
    std::cout << "-----------------------------------------------\n";

    for (int i{ 0 }; i < 10; ++i) {

        std::cout << list[i].number << "\t" << list[i].name << "\t" << list[i].value << "\t";

        for (int j{ 0 }; j < list[i].value; ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    system("pause");
}

void Task3() {
    int currentX{ 1 };
    int currentY{ 1 };
    bool quit{ 0 };

    system("cls");

    char board[10][10]{
        {'+', '#', '#', '#', '#', '#', '#', '#', '#', '+'},
        {'|', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '|'},
        {'|', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '|'},
        {'|', ' ', '#', '#', ' ', ' ', ' ', '#', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '|'},
        {'#', '#', '#', ' ', '#', '#', ' ', '#', '#', '#'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', '#', '#', '#', ' ', '#', '#', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'+', '#', '#', '#', '#', '#', '#', '#', '#', '+'},
    };
    board[1][1] = 'E';
    drawBoard(board);
    std::cout << "Press 'E' to exit\n";

    do {
        char input = _getch();
        board[currentY][currentX] = ' ';
        if (toupper(input) == 'W') {
            if (board[currentY - 1][currentX] != '#') {
                --currentY;
            }
        }
        else if (toupper(input) == 'S') {
            if (board[currentY + 1][currentX] != '#') {
                ++currentY;
            }
        }
        else if (toupper(input) == 'A') {
            if (board[currentY][currentX - 1] != '#' && board[currentY][currentX - 1] != '|') {
                --currentX;
            }
        }
        else if (toupper(input) == 'D') {
            if (board[currentY][currentX + 1] != '#' && board[currentY][currentX + 1] != '|') {
                ++currentX;
            }
        }
        else if (toupper(input) == 'E') {
            quit = true;
        }
        board[currentY][currentX] = 'E';
        system("cls");
        drawBoard(board);
        std::cout << "Press 'E' to exit\n";
    } while (!quit);
}

void drawBoard(char board[10][10]) {
    for (int i{ 0 }; i < 10; ++i) {
        for (int j{ 0 }; j < 10; ++j) {
            std::cout << board[i][j] << ' ';
            if (j == 9) {
                std::cout << '\n';
            }
        }
    }
}

void Task4() {
    int currentX{ 1 };
    int currentY{ 1 };
    int points{ 0 };
    bool quit{ 0 };

    system("cls");

    char board[10][10]{
        {'+', '#', '#', '#', '#', '#', '#', '#', '#', '+'},
        {'|', ' ', '.', '.', '.', '#', '.', '.', '.', '|'},
        {'|', '.', '#', '#', '.', '#', '.', '#', '.', '|'},
        {'|', '.', '#', '#', '.', '.', '.', '#', '.', '|'},
        {'|', '.', '.', '.', '.', '#', '.', '.', '.', '|'},
        {'#', '#', '#', '.', '#', '#', '.', '#', '#', '#'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'|', '.', '#', '#', '#', '.', '#', '#', '.', '|'},
        {'|', '.', '.', '.', '.', '.', '.', '.', '.', '|'},
        {'+', '#', '#', '#', '#', '#', '#', '#', '#', '+'},
    };
    board[1][1] = 'E';
    drawBoard(board);
    std::cout << "Score: " << points;
    std::cout << "Press 'E' to exit\n";

    do {
        int randomX = rand() % 10;
        int randomY = rand() % 10;
        if (board[randomY][randomX] == ' ') {
            board[randomY][randomX] = '.';
        }

        char input = _getch();
        board[currentY][currentX] = ' ';
        if (toupper(input) == 'W') {
            if (board[currentY - 1][currentX] != '#') {
                --currentY;
            }
        }
        else if (toupper(input) == 'S') {
            if (board[currentY + 1][currentX] != '#') {
                ++currentY;
            }
        }
        else if (toupper(input) == 'A') {
            if (board[currentY][currentX - 1] != '#' && board[currentY][currentX - 1] != '|') {
                --currentX;
            }
        }
        else if (toupper(input) == 'D') {
            if (board[currentY][currentX + 1] != '#' && board[currentY][currentX + 1] != '|') {
                ++currentX;
            }
        }
        else if (toupper(input) == 'E') {
            quit = true;
        }

        if (board[currentY][currentX] == '.') {
            points += 5;
        }

        board[currentY][currentX] = 'E';
        
        system("cls");
        drawBoard(board);
        std::cout << "Score: " << points << '\n';
        std::cout << "Press 'E' to exit\n";
    } while (!quit);

    std::cout << "You got " << points << " points!\n";
    system("pause");
}