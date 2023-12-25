#ifndef __MAZE_SOURCE_ADAPTER_ADAPTER_H__
#define __MAZE_SOURCE_ADAPTER_ADAPTER_H__

#include <string>
#include <vector>

#include "cell.h"
#include "point2d.h"
#include "../model/cave/cellularautomaton.h"
#include "../model/cave/cavegenerator.h"
#include "../model/cave/cavefilemanager.h"


namespace s21 {

class Adapter {
 public:
    Adapter(CellularAutomaton& cellular_automaton);

    std::vector<std::vector<Cell>> generateMaze(const int M, const int N) const;
    std::vector<Point2D> solutionMaze(std::vector<std::vector<Cell>> maze, Point2D start, Point2D end) const;
    std::vector<std::vector<Cell>> loadMazeFromFile(std::string filename) const;
    void saveMazeFile(const std::vector<std::vector<Cell>>& maze, const std::string& filename) const;

    const std::vector<std::vector<bool>>& getCaveGrid() const {
        return cellular_automaton_.getCave().getGrid();
    }
    
    bool loadCaveFromFile(const std::string& filename) const {
        try {
            cellular_automaton_.getCave().setGrid(MatrixFileHandler::load(filename));
        } catch (const std::invalid_argument& e) {
            std::cout << e.what();
            return false;
        }

        return true;
    }

    void saveCaveToFile(const std::string& filename) const {
        MatrixFileHandler::save(getCaveGrid(), filename);
    }

    bool evolveCave(size_t birth_limit, size_t death_limit) {
        return cellular_automaton_.evolve(birth_limit, death_limit);
    }

    void generateCave(size_t rows, size_t cols, int probability_birth) {
        cellular_automaton_.getCave().setGrid(GridCaveGenerator().generateGrid(rows, cols, probability_birth));
    }



private:
    CellularAutomaton& cellular_automaton_;

};

}  // namespace s21

#endif  // __MAZE_SOURCE_ADAPTER_ADAPTER_H__