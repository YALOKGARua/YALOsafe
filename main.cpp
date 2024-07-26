#include "menu.h"
#include "settings.h"
#include "logger.h"
#include "integrity.h"

int main() {
    // Create a Logger instance
    Logger logger("application.log");
    logger.log("Application started");

    // Create a Settings instance
    Settings settings("config.txt");

    // Create a Menu instance
    Menu menu;
    menu.handleInput();

    // Log application end
    logger.log("Application ended");
    return 0;
}
