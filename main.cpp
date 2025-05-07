#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

struct Cell {
    bool isMine = false;
    bool isOpened = false;
    bool isFlagged = false;
    int adjacentMines = 0;
};

// 関数に逐一渡すよりグローバルで管理した方が良い
int height, width, mineCount;
vector<vector<Cell>> board;

const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void enterBoardSetting(){
    cout << "Enter board height(5-50): ";
    cin >> height;
    cout << "Enter board width(5-50): ";
    cin >> width;
    cout << "Enter percentage of mines(10-90): ";
    cin >> mineCount;

    mineCount = height * width * 100 / mineCount;

    board.assign(height, vector<Cell>(width));
}

void printBoard(bool reveal = false) {
    cout << "  ";
    for (int x = 0; x < width; ++x) cout << x % 10;
    cout << '\n';
    for (int y = 0; y < height; y++) {
        cout << y % 10 << " ";
        for (int x = 0; x < width; x++) {
            if (reveal && board[y][x].isMine) cout << "*";
            else if (!board[y][x].isOpened) cout << "#";
            else if (board[y][x].adjacentMines > 0) cout << board[y][x].adjacentMines;
            else cout << " ";
        }
        cout << '\n';
    }
}

bool isInBounds(int y, int x) {
    return y >= 0 && y < height && x >= 0 && x < width;
}

int main(void) {
    enterBoardSetting();
    return 0;
}