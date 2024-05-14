// Copyright 2024 <Mariana Oliveira>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm> 

/**
 * @brief Verifica se a entrada fornecida representa um tabuleiro válido de 8 rainhas.
 * 
 * @param board_str A string que representa o tabuleiro.
 * @return true se o tabuleiro é válido, false caso contrário.
 */
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
/**
 * @brief Verifica se duas rainhas estão atacando uma à outra.
 * 
 * @param board O tabuleiro de xadrez.
 * @param row1 A linha da primeira rainha.
 * @param col1 A coluna da primeira rainha.
 * @param row2 A linha da segunda rainha.
 * @param col2 A coluna da segunda rainha.
 * @return true se as rainhas estão atacando uma à outra, false caso contrário.
 */
bool isAttacking(const std::vector<std::string>& board, size_t row1, size_t col1, size_t row2, size_t col2) {
    return row1 == row2 || col1 == col2 || std::abs(static_cast<int>(row1) - static_cast<int>(row2)) == std::abs(static_cast<int>(col1) - static_cast<int>(col2));
}
/**
 * @brief Salva os movimentos de ataque das rainhas em um arquivo.
 * 
 * @param board O tabuleiro de xadrez.
 * @param filename O nome do arquivo onde os movimentos de ataque serão salvos.
 */
void saveAttacks(const std::vector<std::string>& board, const std::string& filename) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) return;
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == '1') {
                for (size_t k = j + 1; k < board[i].size(); ++k) {
                    if (board[i][k] == '1') {
                        outfile << i << "," << j << " " << i << "," << k << "\n";
                        outfile << i << "," << k << " " << i << "," << j << "\n";
                    }
                }
                for (size_t k = i + 1; k < board.size(); ++k) {
                    if (board[k][j] == '1') {
                        outfile << i << "," << j << " " << k << "," << j << "\n";
                        outfile << k << "," << j << " " << i << "," << j << "\n";
                    }
                }
                for (size_t k = i + 1; k < board.size(); ++k) {
                    int col_diff = static_cast<int>(k) - static_cast<int>(i);
                    if (j + col_diff < board[i].size() && board[k][j + col_diff] == '1') {
                        outfile << i << "," << j << " " << k << "," << j + col_diff << "\n";
                        outfile << k << "," << j + col_diff << " " << i << "," << j << "\n";
                    }
                    if (static_cast<int>(j) - col_diff >= 0 && board[k][j - col_diff] == '1') {
                        outfile << i << "," << j << " " << k << "," << j - col_diff << "\n";
                        outfile << k << "," << j - col_diff << " " << i << "," << j << "\n";
                    }
                }
            }
        }
    }
    outfile.close();
}
/**
 * @brief Verifica se é seguro colocar uma rainha em uma determinada posição.
 * 
 * @param board O tabuleiro de xadrez.
 * @param row A linha onde a rainha será colocada.
 * @param col A coluna onde a rainha será colocada.
 * @return true se for seguro colocar a rainha nessa posição, false caso contrário.
 */
bool isSafe(const std::vector<std::string>& board, int row, int col) {
    for (int i = 0; i < 8; ++i) {
        if (i != col && board[row][i] == '1') {
            return false;
        }
    }
    for (int i = 0; i < 8; ++i) {
        if (i != row && board[i][col] == '1') {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (i != row && j != col && board[i][j] == '1') {
            return false;
        }
    }
    for (int i = row, j = col; i < 8 && j >= 0; ++i, --j) {
        if (i != row && j != col && board[i][j] == '1') {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < 8; --i, ++j) {
        if (i != row && j != col && board[i][j] == '1') {
            return false;
        }
    }
    for (int i = row, j = col; i < 8 && j < 8; ++i, ++j) {
        if (i != row && j != col && board[i][j] == '1') {
            return false;
        }
    }
    return true;
}
/**
 * @brief Resolve o problema das 8 rainhas.
 * 
 * @param board O tabuleiro de xadrez.
 * @param row A linha atual.
 * @return true se uma solução foi encontrada, false caso contrário.
 */
bool solveQueens(std::vector<std::string>& board, size_t row) {
    if (row >= board.size()) return true;
    bool queen_placed = false;
    for (size_t col = 0; col < board[row].size(); ++col) {
        if (isSafe(board, static_cast<int>(row), static_cast<int>(col))) {
            board[row][col] = '1';
            if (solveQueens(board, row + 1)) return true;
            board[row][col] = '0';
            queen_placed = true;
        }
    }
    if (!queen_placed) return false;

    return false;
}
/**
 * @brief Resolve o problema das 8 rainhas a partir de uma string representando o tabuleiro.
 * 
 * @param board_str A string representando o tabuleiro.
 * @param filename O nome do arquivo onde os movimentos de ataque serão salvos.
 * @return 0 se nenhuma solução foi encontrada, 1 se uma solução foi encontrada, -1 se houve um erro.
 */
int solve8Queens(const std::string& board_str, const std::string& filename) {
    if (!isValidInput(board_str)) return -1;
    std::vector<std::string> board;
    std::istringstream iss(board_str);
    std::string row;
    while (std::getline(iss, row)) {
        board.push_back(row);
    }
    if (!solveQueens(board, 0)) {
        saveAttacks(board, filename);
        return 0;
    } else {
        return 1;
    }
}
/**
 * @brief Resolve o problema das 8 rainhas a partir de um arquivo.
 * 
 * @param filename O nome do arquivo contendo o tabuleiro.
 * @return 0 se nenhuma solução foi encontrada, 1 se uma solução foi encontrada, -1 se houve um erro ao abrir o arquivo.
 */
int solve8QueensFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        return -1;
    }
    std::string board_str;
    std::string line;
    while (std::getline(infile, line)) {
        board_str += line + "\n";
    }
    infile.close();
    return solve8Queens(board_str, "ataques.txt"); 
}
