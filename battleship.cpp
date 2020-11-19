#include <iostream>
#include <string>
using namespace std;

struct ships {
    string Carrier[5];
    string Battleship[4];
    string Destroyer[3];
    string Submarine[3];
    string Patrol[2];
} cpu;

void showBoard(string board[11][11]) {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void place_Boats(string board[11][11], string x, int k) {
    cout << "From which square to which square? ";
    string start;
    string end;
    string empty = "~";
    int count = 0;
    cin >> start >> end;
    int x1 = int(start[0]) - 65;
    int y1 = int(start[1]) - 48;
    int x2 = int(end[0]) - 65;
    int y2 = int(end[1]) - 48;
    if (start.length() != 2 || end.length() != 2) {
        cout << "Incorrect index format!" << '\n';
        place_Boats(board, x, k);
    }
    if ((x1 < 0 || x1 > 9) && (x2 < 0 || x1 > 9)) {
        cout << "Row index must be between 'A' and 'J'!" << '\n';
        place_Boats(board, x, k);
    }
    if ((y1 < 0 || y1 > 9) && (y2 < 0 || y1 > 9)) {
        cout << "Column index must be between 0 and 9!" << '\n';
        place_Boats(board, x, k);
    }
    if (x1 != x2 && y1 != y2) {
        cout << "Boat must be placed horizontally or vertically!" << '\n';
        place_Boats(board, x, k);
    } else if ((x2 - x1 + 1 != k) && (y2 - y1 + 1 != k)) {
        cout << "The squares occupied doen't match!" << '\n';
        place_Boats(board, x, k);
    } else {
        for (int i = x1; i < x2+1; i++) {
            for (int j = y1; j < y2+1; j++) {
                if (empty.compare(board[i+1][j+1]) == 0) {
                    count++;
                }
            }
        }
        if (count == k) {
            for (int i = x1; i < x2+1; i++) {
                for (int j = y1; j < y2+1; j++) {
                    board[i+1][j+1] = x;
                }
            }
        } else {
            cout << "Ships cannot overlap each other!" << '\n';
            place_Boats(board, x, k);
        }

    }
    showBoard(board);
}

void initializePlayer(string board[11][11]) {
    
    board[0][0] = '/';
    for (int i = 1; i < 11; i++) {
        board[i][0] = char(64+i);
        board[0][i] = to_string(i-1);       
        for (int j = 1; j < 11; j++) {
            board[i][j] = "~";
        }
    }
    
    showBoard(board);
    cout << "Place your Carrier (5 squares)" << '\n';
    place_Boats(board, "C", 5);
    cout << "Place your Battleship (4 squares)" << '\n';
    place_Boats(board, "B", 4);
    cout << "Place your Destroyer (3 squares)" << '\n';
    place_Boats(board, "D", 3);
    cout << "Place your Submarine (3 squares)" << '\n';
    place_Boats(board, "S", 3);
    cout << "Place your Patrol Boat (2 squares)" << '\n';
    place_Boats(board, "P", 2);
}

void CPUplaceCarrier(string board[11][11]) {
    int x = rand() % 10;
    int y = rand() % 10;
    if (rand()%2 == 0) {
        if (y > 5 || y < 0 || x > 9 || x < 0) {
            CPUplaceCarrier(board);
        } else {
            for (int i = y; i < y+5; i++) {
                board[x][i] = "C";
            }
        }
    } else {
        if (x > 5 || x < 0 || y > 9 || y < 0) {
            CPUplaceCarrier(board);
        } else {
            for (int i = x; i < x+5; i++) {
                board[i][y] = "C";
            }
        }
    }
}

void CPUplaceBattleship(string board[11][11]) {
    bool overlap = false;
    int x = rand() % 10;    
    int y = rand() % 10;
    if (rand()%2 == 1) {
        if (y > 6 || y < 0 || x > 9 || x < 0) {
            CPUplaceBattleship(board);
        } else {
            for (int i = y; i < y+4; i++) {
                if (board[x][i] != "~") {
                    overlap = true;
                }
            }
            if (overlap) {
                CPUplaceBattleship(board);
            } else {
                for (int i = y; i < y+4; i++) {
                    board[x][i] = "B";
                }
            }
        }
    } else {
        if(x>6 || x<0 || y>9 || y<0) {
            CPUplaceBattleship(board);
        } else {
            for (int i = x; i < x+4; i++) {
                if (board[i][y] != "~") {
                    overlap = true;
                }
            }
            if (overlap) {
                CPUplaceBattleship(board);
            } else {
                for (int i = x; i < x+4; i++) {
                    board[i][y] = "B";
                }
            }
        }
    }
}

void CPUplaceSubmaroyer(string board[11][11], string ship) {
    bool overlap = false;
    int x = rand() % 10;    
    int y = rand() % 10;
    if (rand()%2 == 1) {
        if (y > 7 || y < 0 || x > 9 || x < 0) {
            CPUplaceSubmaroyer(board, ship);
        } else {
            for (int i = y; i < y+3; i++) {
                if (board[x][i] != "~") {
                    overlap = true;
                }
            }
            if (overlap) {
                CPUplaceSubmaroyer(board, ship);
            } else {
                for (int i = y; i < y+3; i++) {
                    board[x][i] = ship;
                }
            }
        }
    } else {
        if(x>7 || x<0 || y>9 || y<0) {
            CPUplaceSubmaroyer(board, ship);
        } else {
            for (int i = x; i < x+3; i++) {
                if (board[i][y] != "~") {
                    overlap = true;
                }
            }
            if (overlap) {
                CPUplaceSubmaroyer(board, ship);
            } else {
                for (int i = x; i < x+3; i++) {
                    board[i][y] = ship;
                }
            }
        }
    }
}

void CPUplacePatrol(string board[11][11]) {
    bool overlap = false;
    int x = rand() % 10;    
    int y = rand() % 10;
    if (rand()%2 == 1) {
        if (y > 8 || y < 0 || x > 9 || x < 0) {
            CPUplacePatrol(board);
        } else {
            for (int i = y; i < y+2; i++) {
                if (board[x][i] != "~") {
                    overlap = true;
                }
            }
            if (overlap) {
                CPUplacePatrol(board);
            } else {
                for (int i = y; i < y+2; i++) {
                    board[x][i] = "P";
                }
            }
        }
    } else {
        if(x>8 || x<0 || y>9 || y<0) {
            CPUplacePatrol(board);
        } else {
            for (int i = x; i < x+2; i++) {
                if (board[i][y] != "~") {
                    overlap = true;
                }
            }
            if (overlap) {
                CPUplacePatrol(board);
            } else {
                for (int i = x; i < x+2; i++) {
                    board[i][y] = "P";
                }
            }
        }
    }
}

void initializeCPU(string realboard[11][11], string outputboard[11][11]) {
    realboard[0][0] = '/';
    for (int i = 1; i < 11; i++) {
        realboard[i][0] = char(64+i);
        realboard[0][i] = to_string(i-1);       
        for (int j = 1; j < 11; j++) {
            realboard[i][j] = "~";
        }
    }
    CPUplaceCarrier(realboard);
    CPUplaceBattleship(realboard);
    CPUplaceSubmaroyer(realboard, "D");
    CPUplaceSubmaroyer(realboard, "S");
    CPUplacePatrol(realboard);
    
    outputboard[0][0] = '/';
    for (int i = 1; i < 11; i++) {
        outputboard[i][0] = char(64+i);
        outputboard[0][i] = to_string(i-1);       
        for (int j = 1; j < 11; j++) {
            outputboard[i][j] = "~";
        }
    }
}

int main() {
    string playerBoard[11][11];
    string cpuRealBoard[11][11];
    string cpuoutputBoard[11][11];
    string location[17];
    initializePlayer(playerBoard);
    initializeCPU(cpuRealBoard, cpuoutputBoard);
}

