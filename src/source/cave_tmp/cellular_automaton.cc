#include "cellular_automaton.h"


namespace s21 {


    CellularAutomaton::CellularAutomaton(Cave &cave, size_t birth_limit, size_t death_limit) : birth_limit_(birth_limit), death_limit_(death_limit), cave_(cave) {
        if (birth_limit > 7 || death_limit > 7) {
            throw std::invalid_argument("Invalid arguments");
        }
    }

    void CellularAutomaton::evolve() {
        Cave current_cave(cave_);
        for (size_t row = 0; row < cave_.getRows(); ++row) {
            for (size_t col = 0; col < cave_.getCols(); ++col) {
                size_t number_alive = current_cave.get_number_living_neighbors(row, col);
                bool isAlive = current_cave.isAlive(row, col);

                if (isAlive && number_alive < death_limit_) {
                    cave_.setAlive(row, col, false);
                } else if (!isAlive && number_alive > birth_limit_) {
                    cave_.setAlive(row, col, true);
                }
            }
        }
    }

    const Cave &CellularAutomaton::getCave() const {
        return cave_;
    }

}  // namespace s21


//int main(int argc, char const *argv[]) {
//    std::string filename = "../../assets/cave_10x10.txt";
//    std::vector<std::vector<bool>> matrix = s21::MatrixFileHandler::load(filename);
//    s21::Cave cave(matrix);
//    s21::Cave cave2(matrix);
//    cave.print();

//    size_t birth_limit = 4;
//    size_t death_limi = 3;
//    s21::CellularAutomaton cell_automat(cave, birth_limit, death_limi);
//    for (size_t i = 0; i < 10; ++i) {
//        cell_automat.evolve();
//    }
//    cave.print();
//    cave2.print();

//    s21::MatrixFileHandler::save(cell_automat.getCave().getGrid(), "test.txt");



//    return 0;
//}
