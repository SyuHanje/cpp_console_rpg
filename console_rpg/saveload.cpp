#include "saveload.h"

bool SaveLoad::save(const Player& p, const Map& m, int slot) {
    std::ofstream ofs("save_" + std::to_string(slot) + ".txt");
    if (!ofs) return false;

    ofs << "[Player]\n";
    ofs << "hp=" << p.getHp() << "\n";
    ofs << "max_hp=" << p.getMaxHp() << "\n";
    ofs << "atk=" << p.getAtk() << "\n";
    ofs << "def=" << p.getDef() << "\n";

    return true;
}

bool SaveLoad::load(Player& p, Map& m, int slot) {
    std::ifstream ifs("save_" + std::to_string(slot) + ".txt");
    if (!ifs) return false;

    std::string line;
    while (std::getline(ifs, line)) {

        if (line.find("hp=") == 0) {
            p.setHp(std::stoi(line.substr(3)));
        }

        else if (line.find("atk=") == 0) {
            p.setAtk(std::stoi(line.substr(4)));
        }
    }

    return true;
}