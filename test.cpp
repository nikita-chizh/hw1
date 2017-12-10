#define BOOST_TEST_MODULE TestMain
#include <spdlog/spdlog.h>
#include <boost/test/unit_test.hpp>
#include "lib.h"

BOOST_AUTO_TEST_SUITE( test_suite )

    BOOST_AUTO_TEST_CASE( test_version )
    {
        auto console = spdlog::stdout_logger_st("console");
        console->info("test version()");

        BOOST_CHECK( version() > 0 );
    }

BOOST_AUTO_TEST_SUITE_END()