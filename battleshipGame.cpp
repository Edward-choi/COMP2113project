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

void showBoard(string **board) {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void place_Boats(string **board, string x, int k) {
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

void initializePlayer(string **board) {
    
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

void CPUplaceCarrier(string **board) {
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

void CPUplaceBattleship(string **board) {
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

void CPUplaceSubmaroyer(string **board, string ship) {
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

void CPUplacePatrol(string **board) {
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

void initializeCPU(string **realboard, string **outputboard) {
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

void specialSquares(string **board) {
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

void shipLocate(string **board, string Carrier[5], string Battleship[4], string Destroyer[3], string Submarine[3], string Patrol[2]) {
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

string showShip(string Carrier[5], string Battleship[4], string Destroyer[3], string Submarine[3], string Patrol[2]) {
    int k = rand() % 5, i = rand(), xc;
    char x, y;
    string location = "";
    if (k == 0) {
        i = i % 5;
        xc = int(Carrier[i][0]);
        x = char(xc+17);
        y = Carrier[i][1];
        location.append(1, x);
        location.append(1, y);
    } else if (k == 1) {
        i = i % 4;
        xc = int(Battleship[i][0]);
        x = char(xc+17);
        y = Battleship[i][1];
        location.append(1, x);
        location.append(1, y);
    } else if (k == 2) {
        i = i % 3;
        xc = int(Destroyer[i][0]);
        x = char(xc+17);
        y = Destroyer[i][1];
        location.append(1, x);
        location.append(1, y);
    } else if (k == 3) {
        i = i % 3;
        xc = int(Submarine[i][0]);
        x = char(xc+17);
        y = Submarine[i][1];
        location.append(1, x);
        location.append(1, y);
    } else {
        i = i % 2;
        xc = int(Patrol[i][0]);
        x = char(xc+17);
        y = Patrol[i][1];
        location.append(1, x);
        location.append(1, y);
    }
    return location;
}

void shipExplode(string **board, string Carrier[5], string Battleship[4], string Destroyer[3], string Submarine[3], string Patrol[2]) {
    int x, y, k;
    k = rand() % 5;
    if (k == 0) {
        for (int i = 0; i < 5; i++) {
            x = int(Carrier[i][0]) - 47;
            y = int(Carrier[i][1]) - 47;
            board[x][y] = "o";
        }
    } else if (k == 1) {
        for (int i = 0; i < 4; i++) {
            x = int(Battleship[i][0]) - 47;
            y = int(Battleship[i][1]) - 47;
            board[x][y] = "o";
        }
    } else if (k == 2) {
        for (int i = 0; i < 3; i++) {
            x = int(Destroyer[i][0]) - 47;
            y = int(Destroyer[i][1]) - 47;
            board[x][y] = "o";
        }
    } else if (k == 3) {
        for (int i = 0; i < 3; i++) {
            x = int(Submarine[i][0]) - 47;
            y = int(Submarine[i][1]) - 47;
            board[x][y] = "o";
        }
    } else {
        for (int i = 0; i < 2; i++) {
            x = int(Patrol[i][0]) - 47;
            y = int(Patrol[i][1]) - 47;
            board[x][y] = "o";
        }
    }
}

void cpuAttack(string **board) {
    int x = rand() % 10 + 1, y = rand() % 10 + 1;
    string index;
    if (board[x][y] == "o" || board[x][y] == "X") {
        cpuAttack(board);
    } else {
        cout << "Player 2's turn to attack!" << '\n';
        char xcoor = char(x+64), ycoor = char(y+47);
        index.append(1, xcoor);
        index.append(1, ycoor);
        cout << "Player 2 attacked " << index << "!" << '\n';
        if (board[x][y] == "~") {
            cout << "Player 2 missed!" << '\n';
            board[x][y] = "X";
            showBoard(board);
        } else {
            cout << "Player 2 hit your ship!" << '\n';
            board[x][y] = "o";
            showBoard(board);
        }
    }
}

void playerAttack(string **realboard, string **output, string **playerBoard, int &k, string C[5], string B[4], string D[3], string S[3], string P[2], string pC[5], string pB[4], string pD[3], string pS[3], string pP[2]) {
    cout << "Your turn to attck!" << '\n';
    while (true) {
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
        if (output[x][y] != "~") {
            cout << "That square has already been hit. Try again" << '\n';
            continue;
        } else {
            if (realboard[x][y] == "~") {
                cout << "You missed" << '\n';
                output[x][y] = "X";
                showBoard(output);
            } else if (realboard[x][y] == "N") {
                output[x][y] = "!";
                if (NumberGuess() == 0) {
                    cout << "One of your opponent's ships exploded and sunk itself" << '\n';
                    shipExplode(output, C, B, D, S, P);
                } else {
                    cout << "One of your ships exploded and sunk itself" << '\n';
                    shipExplode(playerBoard, pC, pB, pD, pS, pP);
                }
                
            } else if (realboard[x][y] == "R") {
                output[x][y] = "!";
                if (RPS() == 0) {
                    continue;
                } else {
                    cpuAttack(playerBoard);
                }
            } else if (realboard[x][y] == "Q") {
                output[x][y] = "!";
                if (k == 1) {
                    int mc = MC1();
                    if (mc == 0) {
                        cout << "One of your opponent's ship is at " << showShip(C, B, D, S, P) << '\n';
                    }
                    k++;
                } else if (k == 2) {
                    int mc = MC2();
                    if (mc == 0) {
                        cout << "One of your opponent's ship is at " << showShip(C, B, D, S, P) << '\n';
                    }
                    k++;
                } else if (k == 3) {
                    int mc = MC3();
                    if (mc == 0) {
                        cout << "One of your opponent's ship is at " << showShip(C, B, D, S, P) << '\n';
                    }
                    k++;
                } else if (k == 4) {
                    int mc = MC4();
                    if (mc == 0) {
                        cout << "One of your opponent's ship is at " << showShip(C, B, D, S, P) << '\n';
                    }
                    k++;
                }
            } else {
                cout << "You hit your opponent's ship!" << '\n';
                output[x][y] = "o";
                showBoard(output);
            }
        }
        break;
    }
}

bool carrierLost(string **board, string Carrier[5]) {
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

bool battleshipLost(string **board, string Battleship[4]) {
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

bool destroyerLost(string **board, string Destroyer[3]) {
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

bool patrolLost(string **board, string Patrol[2]) {
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

bool noShips(string **board, string Carrier[5], string Battleship[4], string Destroyer[3], string Submarine[3], string Patrol[2]) {
    if (carrierLost(board, Carrier) && battleshipLost(board, Battleship) && destroyerLost(board, Destroyer) && destroyerLost(board, Submarine) && patrolLost(board, Patrol)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int size = 11;
    string** playerBoard = new string* [size];
    string** cpuRealBoard = new string* [size];
    string** cpuoutputBoard = new string* [size];
    for (int i = 0; i < size; i++) {
        playerBoard[i] = new string[size];
        cpuRealBoard[i] = new string[size];
        cpuoutputBoard[i] = new string[size];
    }
    bool end = true;
    int q = 1;
    string * winner = new string;
    cout << "----------Place Your Ships----------" << '\n';
    initializePlayer(playerBoard);
    initializeCPU(cpuRealBoard, cpuoutputBoard);
    specialSquares(cpuRealBoard);
    showBoard(cpuRealBoard);
    shipLocate(playerBoard, player.Carrier, player.Battleship, player.Destroyer, player.Submarine, player.Patrol);
    shipLocate(cpuRealBoard, cpu.Carrier, cpu.Battleship, cpu.Destroyer, cpu.Submarine, cpu.Patrol);
    cout << "----------Attack your Opponent----------" << '\n';
    int k = rand() % 10;
    if (k % 2 == 1) {
        cout << "Player 1 (You) attack first" << '\n';
    } else {
        cout << "Player 2 (Your Opponent) attack first" << '\n';
    }
    while (end) {
        if (k % 2 == 1) {
            playerAttack(cpuRealBoard, cpuoutputBoard, playerBoard, q, cpu.Carrier, cpu.Battleship, cpu.Destroyer, cpu.Submarine, cpu.Patrol, player.Carrier, player.Battleship, player.Destroyer, player.Submarine, player.Patrol);
            if (noShips(cpuoutputBoard, cpu.Carrier, cpu.Battleship, cpu.Destroyer, cpu.Submarine, cpu.Patrol)) {
                *winner = "Player 1";
                end = false;
            } else {
                k++;
            }
        } else {
            cpuAttack(playerBoard);
            if (noShips(playerBoard, player.Carrier, player.Battleship, player.Destroyer, player.Submarine, player.Patrol)) {
                *winner = "Player 2";
                end = false;
            } else {
                k++;
            }
        }
    }
    cout << "The winner is......" << '\n' << '\n';
    cout << *winner << "!!!";
    for (int i = 0; i < size; i++) {
        delete[] playerBoard[i];
        delete[] cpuRealBoard[i];
        delete[] cpuoutputBoard[i];
    }
    delete[] playerBoard;
    delete[] cpuRealBoard;
    delete[] cpuoutputBoard;
    delete winner;
    winner = 0;
    return 0;
}
