#include "saveload.h"
#include "player.h"
#include "map.h"

bool SaveLoad::save(const Player& p, const Map& m, int slot) {
    std::ofstream ofs("save_" + std::to_string(slot) + ".txt");
    if (!ofs) return false;

    ofs << "[Player]\n";
    ofs << "hp=" << p.getHp() << "\n";
    ofs << "max_hp=" << p.getMaxHp() << "\n";
    ofs << "atk=" << p.getAtk() << "\n";
    ofs << "def=" << p.getDef() << "\n";
    ofs << "base_atk=" << p.base_atk << "\n";

    ofs << "[Skills]\n";
    for (auto* s : p.skills) {
        ofs << s->name << "," << s->level << "\n";
    }

    ofs << "[Map]\n";
    ofs << "x=" << m.getX() << "\n";
    ofs << "y=" << m.getY() << "\n";
    ofs << "map=\n";

    auto& map = m.getMap();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            ofs << map[i][j] << " ";
        }
        ofs << "\n";
    }

    return true;
}

bool SaveLoad::load(Player& p, Map& m, int slot) {
    std::ifstream ifs("save_" + std::to_string(slot) + ".txt");
    if (!ifs) return false;

    p.clearSkills();

    std::string line;
    int row = 0;
    bool readingMap = false;

    while (std::getline(ifs, line)) {

        if (line == "[Map]") {
            continue;
        }

        if (line == "map=") {
            readingMap = true;
            row = 0;
            continue;
        }

        if (readingMap) {
            std::istringstream iss(line);
            for (int col = 0; col < 12; col++) {
                int v;
                iss >> v;
                m.setMapCell(row, col, v);
            }
            row++;
            if (row >= 5) readingMap = false;
            continue;
        }

        if (line.find("x=") == 0)
            m.setPosition(std::stoi(line.substr(2)), m.getY());

        else if (line.find("y=") == 0)
            m.setPosition(m.getX(), std::stoi(line.substr(2)));

        else if (line.find("max_hp=") == 0)
            p.setMaxHp(std::stoi(line.substr(7)));

        else if (line.find("hp=") == 0)
            p.setHp(std::stoi(line.substr(3)));

        else if (line.find("atk=") == 0)
            p.setAtk(std::stoi(line.substr(4)));

        else if (line.find("def=") == 0)
            p.setDef(std::stoi(line.substr(4)));

        else if (line == "[Skills]") {
            while (std::getline(ifs, line) && line[0] != '[') {
                auto pos = line.find(",");
                p.addSkillByName(
                    line.substr(0, pos),
                    std::stoi(line.substr(pos + 1))
                );
            }
        }
    }
    return true;
}

void SaveLoad::erase(int slot) {
    std::filesystem::remove("save_" + std::to_string(slot) + ".txt");
}