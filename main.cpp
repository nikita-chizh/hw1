#include "lib.h"
#include <spdlog/spdlog.h>

int main(int argc, char* argv[]){
    auto logger = spdlog::stdout_logger_mt("console");
    logger -> info("version {}", version());
    return 0;
}
