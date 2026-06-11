#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {
    const int W = 40, H = 20, P = 7;
    int bx = W/2, by = H/2, dx = 1, dy = -1;
    int px = W/2 - P/2;
    int score = 0;

    // Gra zaczyna sie od razu

    while (true) {
        system("cls");
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (y==0 || y==H-1 || x==0 || x==W-1) cout << '#';
                else if (x==bx && y==by) cout << 'O';
                else if (y==H-2 && x>=px && x<px+P) cout << '=';
                else cout << ' ';
            }
            cout << '\n';
        }

        cout << "Punkty: " << score << "\n";

        if (_kbhit()) {
            char c = _getch();
            if (c=='a' || c=='A') if (px>1) px--;
            if (c=='d' || c=='D') if (px+P < W-1) px++;
            if (c=='q' || c=='Q') break;
        }

        int nbx = bx + dx, nby = by + dy;
        if (nbx <= 1 || nbx >= W-2) dx = -dx;
        if (nby <= 1) dy = -dy;
        if (nby == H-2 && nbx >= px && nbx < px+P) { dy = -dy; score++; }

        bx += dx; by += dy;
        if (by >= H-1) {
            system("cls");
            cout << "Koniec gry. Wynik: " << score << "\n";
            cout << "Nacisnij dowolny klawisz, aby wyjsc...";
            _getch();
            break;
        }

        Sleep(80);
    }

    return 0;
}

