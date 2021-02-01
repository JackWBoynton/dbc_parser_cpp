#include <catch2/catch.hpp>
#include "defines.hpp"
#include "dbc.hpp"

TEST_CASE("Testing dbc file loading", "[fileio]") {
	auto parser = std::unique_ptr<libdbc::DbcParser>(new libdbc::DbcParser());

	SECTION("Loading a non dbc file should throw an error", "[error]") {
		REQUIRE_THROWS_AS(parser->parse_file(TEXT_FILE), libdbc::validity_error);
	}

	// Undecided on the type of error yet. Need to think about this.
	// SECTION("Loading a dbc with bad headers throws an error", "[error]") {
	// 	REQUIRE_THROWS_AS(parser->parse_file(MISSING_VERSION_DBC_FILE), libdbc::header_error);
	// }

	SECTION("Loading a single simple dbc file", "[dbc]") {
		std::vector<libdbc::Message> messages;

		parser->parse_file(SIMPLE_DBC_FILE);

		REQUIRE(parser->get_version() == "1.0.0");
	}

}