#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"


TEST_CASE( "Numeros romanos - algarismos �nicos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("I") == 1 );
    
    REQUIRE( romanos_para_decimal("V") == 5 );

    
}

 
