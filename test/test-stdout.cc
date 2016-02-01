#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <Log.hh>

int
test_log ()
{
    using namespace Abdillah::Ellog;
    Log logger ("basic");
    logger.log (Log::TAG_WARN, "Hello world!");

    return 0;
}

TEST_CASE ("Logger return 0", "[retval]") {
    REQUIRE (test_log() == 0);
}
