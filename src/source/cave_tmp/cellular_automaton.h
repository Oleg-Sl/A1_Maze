#include "cave.h"
#include "cave_file_manager.h"


namespace s21 {


class CellularAutomaton {
public:
    CellularAutomaton(Cave &cave, size_t birth_limit, size_t death_limit);
    void evolve();
    const Cave &getCave() const;

private:
    size_t birth_limit_{};
    size_t death_limit_{};
    Cave &cave_;

};


}  // namespace s21

