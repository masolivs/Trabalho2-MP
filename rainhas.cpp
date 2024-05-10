// Copyright 2024 <Mariana Oliveira>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 

bool isValidInput(const std::string& board_str) {
    std::vector<std::string> rows;
    std::string row;
    std::istringstream iss(board_str);
    while (std::getline(iss, row)) {
        if (row.size() != 8) return false;
        rows.push_back(row);
    }
    if (rows.size() != 8) return false;

    int queens_count = 0;
    for (const auto& r : rows) {
        queens_count += std::count(r.begin(), r.end(), '1');
    }
    if (queens_count != 8) return false;

    return true;
}
bool isAttacking(const std::vector<std::string>& board, size_t row1, size_t col1, size_t row2, size_t col2) {
    return row1 == row2 || col1 == col2 || std::abs(static_cast<int>(row1) - static_cast<int>(row2)) == std::abs(static_cast<int>(col1) - static_cast<int>(col2));
}
void saveAttacks(const std::vector<std::string>& board, const std::string& filename) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) return;
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == '1') {
                for (size_t k = i + 1; k < board.size(); ++k) {
                    for (size_t l = 0; l < board[k].size(); ++l) {
                        if (board[k][l] == '1' && isAttacking(board, i, j, k, l)) {
                            outfile << i << "," << j << " " << k << "," << l << "\n";
                        }
                    }
                }
            }
        }
    }
    outfile.close();
}
bool isSafe(const std::vector<std::string>& board, int row, int col) {
    for (size_t i = 0; i < static_cast<size_t>(row); ++i) {
        if (board[i][col] == '1') return false;
        if (col - (row - static_cast<int>(i)) >= 0 && board[i][col - (row - static_cast<int>(i))] == '1') return false;
        if (col + (row - static_cast<int>(i)) < board.size() && board[i][col + (row - static_cast<int>(i))] == '1') return false;
    }
    return true;
}
bool solveQueens(std::vector<std::string>& board, size_t row) {
    if (row >= board.size()) return true;
    for (size_t col = 0; col < board[row].size(); ++col) {
        if (isSafe(board, static_cast<int>(row), static_cast<int>(col))) {
            board[row][col] = '1';
            if (solveQueens(board, row + 1)) return true;
            board[row][col] = '0';
        }
    }
    return false;
}
int solve8Queens(const std::string& board_str) {
    if (!isValidInput(board_str)) return -1;

    std::vector<std::string> board;
    std::istringstream iss(board_str);
    std::string row;
    while (std::getline(iss, row)) {
        board.push_back(row);
    }
    if (!solveQueens(board, 0)) {
        saveAttacks(board, "ataques.txt");
        return 0;
    } else {
        return 1;
    }
}
int solve8QueensFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        return -1; // Retorna -1 se não conseguir abrir o arquivo
    }
    std::string board_str;
    std::string line;
    while (std::getline(infile, line)) {
        board_str += line + "\n";
    }
    infile.close();
    return solve8Queens(board_str);
}