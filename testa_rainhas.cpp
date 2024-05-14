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
    SECTION( "Teste 9") {
        int result = solve8QueensFromFile("tabuleiros/board9.txt");
        REQUIRE(result == -1);
    }
    SECTION( "Teste 10") {
        int result = solve8QueensFromFile("tabuleiros/board10.txt");
        REQUIRE(result == -1);
    }
    SECTION( "Teste 20") {
        int result = solve8QueensFromFile("tabuleiros/board20.txt");
        REQUIRE(result == -1);
    }
}
TEST_CASE( "Soluções Válidas - É solução do problema") {
    SECTION( "Teste 11") {
        int result = solve8QueensFromFile("tabuleiros/board11.txt");
        REQUIRE(result == 1);
    }
    SECTION( "Teste 12") {
        int result = solve8QueensFromFile("tabuleiros/board12.txt");
        REQUIRE(result == 1);
    }
    SECTION( "Teste 13") {
        int result = solve8QueensFromFile("tabuleiros/board13.txt");
        REQUIRE(result == 1);
    }
    SECTION( "Teste 14") {
        int result = solve8QueensFromFile("tabuleiros/board14.txt");
        REQUIRE(result == 1);
    }
    SECTION( "Teste 15") {
        int result = solve8QueensFromFile("tabuleiros/board15.txt");
        REQUIRE(result == 1);
    }
    SECTION( "Teste 19") {
        int result = solve8QueensFromFile("tabuleiros/board19.txt");
        REQUIRE(result == 1);
    }
}
TEST_CASE( "Soluções Válidas - Não é solução do problema") {
    SECTION( "Teste 21") {
        int result = solve8QueensFromFile("tabuleiros/board21.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 22") {
        int result = solve8QueensFromFile("tabuleiros/board22.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 23") {
        int result = solve8QueensFromFile("tabuleiros/board23.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 24") {
        int result = solve8QueensFromFile("tabuleiros/board24.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 25") {
        int result = solve8QueensFromFile("tabuleiros/board25.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 26") {
        int result = solve8QueensFromFile("tabuleiros/board26.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 27") {
        int result = solve8QueensFromFile("tabuleiros/board27.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 28") {
        int result = solve8QueensFromFile("tabuleiros/board28.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 29") {
        int result = solve8QueensFromFile("tabuleiros/board29.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 30") {
        int result = solve8QueensFromFile("tabuleiros/board30.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 16") {
        int result = solve8QueensFromFile("tabuleiros/board16.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 17") {
        int result = solve8QueensFromFile("tabuleiros/board17.txt");
        REQUIRE(result == 0);
    }
    SECTION( "Teste 18") {
        int result = solve8QueensFromFile("tabuleiros/board18.txt");
        REQUIRE(result == 0);
    }
}