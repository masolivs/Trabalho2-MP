// Copyright 2024 <Mariana Oliveira>
#define CATCH_CONFIG_MAIN  
#include "./catch.hpp"
#include "./rainhas.hpp"

TEST_CASE( "Soluções Inválidas") {
    SECTION( "Teste 1") {
        int result = solve8QueensFromFile("tabuleiros/board1.txt");
        REQUIRE(result == -1);
    }
}