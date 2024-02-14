#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <fstream>
#include <filesystem>


namespace Global {
    std::string read_from_file(const std::string& file_path);
    void update_task_id(const std::string& file_path, int current_id);
    int task_id(const std::string& id_line);
    int get_next_task_id();
}
#endif // GLOBAL_H
