#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;
const int PADDLE_WIDTH = 7;

void clearScreen() {
    system("cls");
}

bool isKeyPressed(int vk) {
    return (GetAsyncKeyState(vk) & 0x8000) != 0;
}

void drawBox(int ballX, int ballY, int paddleX, int score) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
                cout << '#';
            } else if (x == ballX && y == ballY) {
                cout << 'O';
            } else if (y == HEIGHT - 2 && x >= paddleX && x < paddleX + PADDLE_WIDTH) {
                cout << '=';
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    cout << "Punkty: " << score << "\n";
    cout << "Sterowanie: A - lewo, D - prawo, Q - wyjscie do menu\n";
}

void showMenu() {
    clearScreen();
    cout << "========================\n";
    cout << "      PONG ENHANCED     \n";
    cout << "========================\n";
    cout << "1. Rozpocznij gre\n";
    cout << "2. Informacje o autorze\n";
    cout << "3. Jak grac\n";
    cout << "4. Wyjscie\n";
    cout << "Wybierz opcje (1-4): ";
}

void showAuthor() {
    clearScreen();
    cout << "========================\n";
    cout << "       O autorze       \n";
    cout << "========================\n";
    cout << "Autor: Twoj szkolny projekt\n";
    cout << "Opis: Prosta gra w stylu Pong, gdzie gracz kontroluje jedna paletke.\n";
    cout << "Nacisnij dowolny klawisz, aby wrocic do menu...\n";
    _getch();
}

void showHowToPlay() {
    clearScreen();
    cout << "========================\n";
    cout << "       Jak grac         \n";
    cout << "========================\n";
    cout << "1. Poruszaj paletka w lewo i prawo za pomoca klawiszy A i D.\n";
    cout << "2. Pilka bedzie odbijac sie od gornej i bocznych scian.\n";
    cout << "3. Twoim celem jest odbijac pilke paletka znajdujaca sie na dolnej scianie.\n";
    cout << "4. Za kazde odbicie pilki przez paletke otrzymujesz 1 punkt.\n";
    cout << "5. Jesli pilka opuści pole na dole, gra sie konczy.\n";
    cout << "Nacisnij dowolny klawisz, aby wrocic do menu...\n";
    _getch();
}

void playGame() {
    int ballX = WIDTH / 2;
    int ballY = HEIGHT / 2;
    int ballDirX = 1;
    int ballDirY = -1;
    int paddleX = WIDTH / 2 - PADDLE_WIDTH / 2;
    int score = 0;
    bool gameOver = false;

    while (!gameOver) {
        clearScreen();
        drawBox(ballX, ballY, paddleX, score);

        if (isKeyPressed('A')) {
            if (paddleX > 1) {
                paddleX--;
            }
        }
        if (isKeyPressed('D')) {
            if (paddleX + PADDLE_WIDTH < WIDTH - 1) {
                paddleX++;
            }
        }
        if (isKeyPressed('Q')) {
            break;
        }

        int nextBallX = ballX + ballDirX;
        int nextBallY = ballY + ballDirY;

        if (nextBallX == 0 || nextBallX == WIDTH - 1) {
            ballDirX = -ballDirX;
            nextBallX = ballX + ballDirX;
        }

        if (nextBallY == 0) {
            ballDirY = -ballDirY;
            nextBallY = ballY + ballDirY;
        }

        if (nextBallY == HEIGHT - 2) {
            if (nextBallX >= paddleX && nextBallX < paddleX + PADDLE_WIDTH) {
                ballDirY = -ballDirY;
                score++;
                nextBallY = ballY + ballDirY;
            }
        }

        ballX = nextBallX;
        ballY = nextBallY;

        if (ballY >= HEIGHT - 1) {
            gameOver = true;
        }

        Sleep(60);
    }

    clearScreen();
    cout << "========================\n";
    cout << "       GAME OVER       \n";
    cout << "========================\n";
    cout << "Twoj wynik: " << score << " punktow\n";
    cout << "Nacisnij dowolny klawisz, aby wrocic do menu...\n";
    _getch();
}

int main() {
    while (true) {
        showMenu();
        char choice = _getch();

        if (choice == '1') {
            playGame();
        } else if (choice == '2') {
            showAuthor();
        } else if (choice == '3') {
            showHowToPlay();
        } else if (choice == '4') {
            clearScreen();
            cout << "Do zobaczenia!\n";
            break;
        }
    }

    return 0;
}
