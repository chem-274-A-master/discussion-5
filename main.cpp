#include <vector>

class Molecule
{
    protected:
      int num_atoms_;

      // Coordinates are stored "flattened" as a single array
      std::vector<double> coords_;

    public:
      Molecule()
        : num_atoms_(0)
      {}

      Molecule(std::vector<double> coords)
        : coords_(coords)
      {
        num_atoms_ = coords.size() / 3;
      }

      const std::vector<double> & get_coords(void) const { return coords_; }

      void set_coords(std::vector<double> coords)
      {
        coords_ = coords;
      }
};



int main() {
  return 0;
}