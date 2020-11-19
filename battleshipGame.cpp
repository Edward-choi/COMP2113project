#include <iostream>
#include <string>
#include "mc1.h"
#include "mc2.h"
#include "mc3.h"
#include "mc4.h"
#include "rps.h"
#include "numberGuess.h"

using namespace std;

struct ships {
    string Carrier[5];
    string Battleship[4];
    string Destroyer[3];
    string Submarine[3];
    string Patrol[2];
} player,cpu;

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
    while (bool error = true) {
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
            continue;
        }
        if ((x1 < 0 || x1 > 9) && (x2 < 0 || x1 > 9)) {
            cout << "Row index must be between 'A' and 'J'!" << '\n';
            continue;
        }
        if ((y1 < 0 || y1 > 9) && (y2 < 0 || y1 > 9)) {
            cout << "Column index must be between 0 and 9!" << '\n';
            continue;
        }
        if (x1 != x2 && y1 != y2) {
            cout << "Boat must be placed horizontally or vertically!" << '\n';
            continue;
        }if ((x2 - x1 + 1 != k) && (y2 - y1 + 1 != k)) {
            cout << "The squares occupied doen't match!" << '\n';
            continue;
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
                continue;
            }
        }
        showBoard(board);
        break;
    }
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
    while (bool e = true) {
        srand(time(0));
        int x = rand() % 10, y = rand() % 10;
        if (rand()%2 == 0) {
            if (y > 6 || y < 1 || x > 10 || x < 1) {
                continue;
            } else {
                for (int i = y; i < y+5; i++) {
                    board[x][i] = "C";
                }
            }
        } else {
            if (x > 6 || x < 1 || y > 10 || y < 1) {
                continue;
            } else {
                for (int i = x; i < x+5; i++) {
                    board[i][y] = "C";
                }
            }
        }
        break;
    }
}

void CPUplaceBattleship(string board[11][11]) {
    while (bool e = true) {
        bool overlap = false;
        int x = rand() % 10, y = rand() % 10;
        if (rand()%2 == 1) {
            if (y > 7 || y < 1 || x > 10 || x < 1) {
                continue;
            } else {
                for (int i = y; i < y+4; i++) {
                    if (board[x][i] != "~") {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = y; i < y+4; i++) {
                        board[x][i] = "B";
                    }
                }
            }
        } else {
            if(x > 7 || x < 1 || y > 10 || y < 1) {
                continue;
            } else {
                for (int i = x; i < x+4; i++) {
                    if (board[i][y] != "~") {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = x; i < x+4; i++) {
                        board[i][y] = "B";
                    }
                }
            }
        }
        break;
    }
}

void CPUplaceSubmaroyer(string board[11][11], string ship) {
    while (bool e = true) {
        bool overlap = false;
        int x = rand() % 10, y = rand() % 10;
        if (rand()%2 == 1) {
            if (y > 8 || y < 1 || x > 10 || x < 1) {
                continue;
            } else {
                for (int i = y; i < y+3; i++) {
                    if (board[x][i] != "~") {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = y; i < y+3; i++) {
                        board[x][i] = ship;
                    }
                }
            }
        } else {
            if(x > 8 || x < 1 || y > 10 || y < 1) {
                continue;
            } else {
                for (int i = x; i < x+3; i++) {
                    if (board[i][y] != "~") {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = x; i < x+3; i++) {
                        board[i][y] = ship;
                    }
                }
            }
        }
        break;
    }
}

void CPUplacePatrol(string board[11][11]) {
    while (bool e = true) {
        bool overlap = false;
        int x = rand() % 10, y = rand() % 10;
        if (rand()%2 == 1) {
            if (y > 9 || y < 1 || x > 10 || x < 1) {
                continue;
            } else {
                for (int i = y; i < y+2; i++) {
                    if (board[x][i] != "~") {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = y; i < y+2; i++) {
                        board[x][i] = "P";
                    }
                }
            }
        } else {
            if(x > 9 || x < 1 || y > 10 || y < 1) {
                continue;
            } else {
                for (int i = x; i < x+2; i++) {
                    if (board[i][y] != "~") {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = x; i < x+2; i++) {
                        board[i][y] = "P";
                    }
                }
            }
        }
        break;
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

void specialSquares(string board[11][11]) {
    int k = 0;
    while (k < 10) {
        int x = (rand() % 10) + 1, y = (rand() % 10) + 1;
        if (board[x][y] == "~") {
            if (k > 5) {
                board[x][y] = "Q";
            } else if (k > 2) {
                board[x][y] = "R";
            } else {
                board[x][y] = "N";
            }
        } else {
            continue;
        }
        k++;
    }
}

void shipLocate(string board[11][11], string Carrier[5], string Battleship[4], string Destroyer[3], string Submarine[3], string Patrol[2]) {
    int c = 0, b = 0, d = 0, s = 0, p = 0;
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            string index = to_string(i-1) + to_string(j-1);
            if (board[i][j] == "C") {
                Carrier[c] = index;
                c++;
            } else if (board[i][j] == "B") {
                Battleship[b] = index;
                b++;
            } else if (board[i][j] == "D") {
                Destroyer[d] = index;
                d++;
            } else if (board[i][j] == "S") {
                Submarine[s] = index;
                s++;
            } else if (board[i][j] == "P") {
                Patrol[p] = index;
                p++;
            }
        }
    }
}

void playerAttack(string realboard[11][11], string output[11][11]) {
    cout << "Your turn to attck!" << '\n';
    while (bool e = true) {
        showBoard(output);
        cout << "Enter the square you'd like to attack: ";
        string index;
        cin >> index;
        int x = int(index[0]) - 64;
        int y = int(index[1]) - 47;
        if (index.length() != 2) {
            cout << "Incorrect index format!" << '\n';
            continue;
        }
        if (x < 1 || x > 10) {
            cout << "Row index must be between 'A' and 'J'!" << '\n';
            continue;
        }
        if (y < 1 || y > 10) {
            cout << "Column index must be between 0 and 9!" << '\n';
            continue;
        }
        if (output[x][y] == "X" || output[x][y] == "o") {
            cout << "That square has already been hit. Try again" << '\n';
            continue;
        } else {
            if (realboard[x][y] == "~") {
                cout << "You missed" << '\n';
                output[x][y] = "X";
                showBoard(output);
            } else if (realboard[x][y] == "N") {
                cout << "Number Guess";
            } else if (realboard[x][y] == "R") {
                cout << "RPS";
            } else if (realboard[x][y] == "Q") {
                cout << "MCQ";
            } else {
                cout << "You hit your opponent's ship!" << '\n';
                output[x][y] = "o";
                showBoard(output);
            }
        }
        break;
    }
}

void cpuAttack(string board[11][11]) {
    int x = rand() % 10 + 1, y = rand() % 10 + 1;
    string index;
    if (board[x][y] == "o" || board[x][y] == "X") {
        cpuAttack(board);
    } else {
        cout << "Opponent's turn to attack!" << '\n';
        char xcoor = char(x+64), ycoor = char(y+47);
        index.append(1, xcoor);
        index.append(1, ycoor);
        cout << "Your opponent attacked " << index << "!" << '\n';
        if (board[x][y] == "~") {
            cout << "Your opponent missed!" << '\n';
            board[x][y] = "X";
            showBoard(board);
        } else {
            cout << "Your ship was hit!" << '\n';
            board[x][y] = "o";
            showBoard(board);
        }
    }
}

bool carrierLost(string board[11][11], string Carrier[5]) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        int x = (Carrier[i][0] - '0');
        int y = (Carrier[i][1] - '0');
        if (board[x+1][y+1] == "o") {
            count++; 
        }
    }
    if (count == 5) {
        return true;
    } else {
        return false;
    }
}

bool battleshipLost(string board[11][11], string Battleship[4]) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int x = (Battleship[i][0] - '0');
        int y = (Battleship[i][1] - '0');
        if (board[x+1][y+1] == "o") {
            count++; 
        }
    }
    if (count == 4) {
        return true;
    } else {
        return false;
    }
}

bool destroyerLost(string board[11][11], string Destroyer[3]) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        int x = (Destroyer[i][0] - '0');
        int y = (Destroyer[i][1] - '0');
        if (board[x+1][y+1] == "o") {
            count++; 
        }
    }
    if (count == 3) {
        return true;
    } else {
        return false;
    }
}

bool patrolLost(string board[11][11], string Patrol[2]) {
    int count = 0;
    for (int i = 0; i < 2; i++) {
        int x = (Patrol[i][0] - '0');
        int y = (Patrol[i][1] - '0');
        if (board[x+1][y+1] == "o") {
            count++; 
        }
    }
    if (count == 2) {
        return true;
    } else {
        return false;
    }
}

bool noShips(string board[11][11], string Carrier[5], string Battleship[4], string Destroyer[3], string Submarine[3], string Patrol[2]) {
    if (carrierLost(board, Carrier) && battleshipLost(board, Battleship) && destroyerLost(board, Destroyer) && destroyerLost(board, Submarine) && patrolLost(board, Patrol)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string playerBoard[11][11];
    string cpuRealBoard[11][11];
    string cpuoutputBoard[11][11];
    string location[17];
    bool end = true;
    bool winner;
    cout << "----------Place Your Ships----------" << '\n';
    initializePlayer(playerBoard);
    initializeCPU(cpuRealBoard, cpuoutputBoard);
    specialSquares(cpuRealBoard);
    showBoard(cpuRealBoard);
    shipLocate(playerBoard, player.Carrier, player.Battleship, player.Destroyer, player.Submarine, player.Patrol);
    shipLocate(cpuRealBoard, cpu.Carrier, cpu.Battleship, cpu.Destroyer, cpu.Submarine, cpu.Patrol);
    cout << "----------Attack Phase----------" << '\n';
    int k = rand() % 10;
    while (end) {
        if (k % 2 == 0) {
            playerAttack(cpuRealBoard, cpuoutputBoard);
            if (noShips(cpuoutputBoard, cpu.Carrier, cpu.Battleship, cpu.Destroyer, cpu.Submarine, cpu.Patrol)) {
                end = false;
                winner = true;
            } else {
                k++;
            }
        } else {
            cpuAttack(playerBoard);
            if (noShips(playerBoard, player.Carrier, player.Battleship, player.Destroyer, player.Submarine, player.Patrol)) {
                end = false;
                winner = false;
            } else {
                k++;
            }
        }
    }
    if (winner) {
        cout << "You have sunk all you opponent's ships. YOU WIN!!!";
    } else {
        cout << "Your opponent has sunk all your ships. You Lose";
    }
    return 0;
}
