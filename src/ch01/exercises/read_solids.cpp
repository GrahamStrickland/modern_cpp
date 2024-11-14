#include <cassert>
#include <fstream>
#include <iostream>
#include <math.h>

double cube_volume(double x) { return x * x * x; }

double cube_surface(double x) { return 6.0 * x; }

double pyramid_volume(double b, double h) { return b * b * h / 3.0; }

double pyramid_surface(double b, double h) {
  return b * b + 2.0 * b * sqrt(b * b / 4.0 + h * h);
}

double cylinder_volume(double r, double h) { return M_PI * r * r * h; }

double cylinder_surface(double r, double h) { return 2.0 * M_PI * r * (r + h); }

double sphere_volume(double r) { return 4.0 * M_PI * r * r * r / 3.0; }

double sphere_surface(double r) { return 4.0 * M_PI * r * r; }

int main(int argc, char *argv[]) {
  std::ifstream infile;
  std::string filename{"solids.dat"};

  infile.open(filename);
  if (infile.good()) {
    double x, b, h, r, volume, surface_area, result;

    infile >> x >> volume >> surface_area;
    result = cube_volume(x);
    assert(result == volume);
    result = cube_surface(x);
    assert(result == surface_area);
  } else {
    std::cerr << "Unable to open file " << filename << '\n';
  }

  return EXIT_SUCCESS;
}
