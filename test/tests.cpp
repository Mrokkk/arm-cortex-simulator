#include <catch.hpp>
#include <InstructionSet.hpp>

TEST_CASE( "can select proper instruction" ) {
    ThumbInstructionSet set;
    REQUIRE(set.get(0b0000011111111111).name() == "lsl");
    REQUIRE(set.get(0b0000111111111111).name() == "lsr");
    REQUIRE(set.get(0b0001011111111111).name() == "asr");
    REQUIRE(set.get(0b0001110111111111).name() == "add");
    REQUIRE(set.get(0b0001100111111111).name() == "add");
    REQUIRE(set.get(0b0001111111111111).name() == "sub");
    REQUIRE(set.get(0b0001101111111111).name() == "sub");
    REQUIRE_THROWS(set.get(0b1000100000010010));
    REQUIRE_THROWS(set.get(0b1100111111111111));
    REQUIRE_THROWS(set.get(0b1100111011111111));
}

