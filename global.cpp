#include "global.h"

std::string Global::read_from_file(const std::string& file_path)
{
    std::ifstream file(file_path, std::fstream::in);
    if (!file.is_open()) {
        std::exit(1);
    }
    std::string line;
    while(std::getline(file, line)) {
        if(line.find("{")) {
            break;
        }
    }
    file.close();
    return line;

}

void Global::update_task_id(const std::string& file_path, int current_id)
{
    // updating task_id and rewriting into file
    std::ofstream file (file_path, std::fstream::out | std::fstream::trunc);
    if(!file.is_open()) {
        std::exit(1);
    }
    ++current_id;
    file << "task_id_cntr = "<< ' ' << '"'<< current_id << '"';
    file.close();
}

int Global::task_id(const std::string& id_line)
{
    // parsing task_id from file
    int sub = id_line.find('"');
    std::string task_id_with_par = id_line.substr(sub + 1);

    std::string task_id {};
    for (const auto& it : task_id_with_par) {
        if (it == '"') {
            break;
        }
        task_id += it;
    }
    // converting to integer
    return std::stoi(task_id);
}

int Global::get_next_task_id()
{
    // reading from file
    std::string file_path = std::filesystem::absolute("task_id.txt");
    int curr_task_id = Global::task_id(Global::read_from_file(file_path));

    // updating task_id and return previous id
    Global::update_task_id(file_path,curr_task_id);
    return curr_task_id;
}





