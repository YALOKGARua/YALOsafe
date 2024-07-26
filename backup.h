#ifndef BACKUP_H
#define BACKUP_H

#include <string>

class Backup {
public:
    void createBackup(const std::string& filePath);
    void restoreBackup(const std::string& backupPath, const std::string& destinationPath);
};

#endif // BACKUP_H
