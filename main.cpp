#include "menu.h"
#include "settings.h"
#include "logger.h"
#include "integrity.h"

int main() {
    Logger logger("application.log");
    logger.log("Application started");

    Settings settings("config.txt");

    Menu menu;
    menu.handleInput();

    logger.log("Application ended");
    return 0;
}
