// Copyright 2024 <Mariana Oliveira>
#define CATCH_CONFIG_MAIN  
#include "./catch.hpp"
#include "./rainhas.hpp"

TEST_CASE( "Soluções Inválidas") {
    SECTION( "Teste 1") {
        int result = solve8QueensFromFile("tabuleiros/board1.txt");
        REQUIRE(result == -1);
    }
    SECTION( "Teste 2") {
        int result = solve8QueensFromFile("tabuleiros/board2.txt");
        REQUIRE(result == -1);
    }
    SECTION( "Teste 3") {
        int result = solve8QueensFromFile("tabuleiros/board3.txt");
        REQUIRE(result == -1);
    }
    SECTION( "Teste 4") {
        int result = solve8QueensFromFile("tabuleiros/board4.txt");
        REQUIRE(result == -1);
    }
    SECTION( "Teste 5") {
        int result = solve8QueensFromFile("tabuleiros/board5.txt");
        REQUIRE(result == -1);
    }
    SECTION( "Teste 6") {
        int result = solve8QueensFromFile("tabuleiros/board6.txt");
        REQUIRE(result == -1);
    }
    SECTION( "Teste 7") {
        int result = solve8QueensFromFile("tabuleiros/board7.txt");
        REQUIRE(result == -1);
    }
    SECTION( "Teste 8") {
        int result = solve8QueensFromFile("tabuleiros/board8.txt");
        REQUIRE(result == -1);
    }
}