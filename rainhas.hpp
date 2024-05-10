#ifndef RAINHAS_HPP
#define RAINHAS_HPP

#include <string>
#include <vector>

bool isValidInput(const std::string& board_str);
bool isAttacking(const std::vector<std::string>& board, int row1, int col1, int row2, int col2);
void saveAttacks(const std::vector<std::string>& board, const std::string& filename);
bool isSafe(const std::vector<std::string>& board, int row, int col);
bool solveQueens(std::vector<std::string>& board, int row);
int solve8Queens(const std::string& board_str);
int solve8QueensFromFile(const std::string& filename);

#endif // RAINHAS_HPP

 