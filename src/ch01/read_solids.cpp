#include <cassert>
#include <cstdlib>
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
    double x, b, h, r, volume, surface_area;

    infile >> x >> volume >> surface_area;
    assert(fabs(volume - cube_volume(x)) <= 1E-3);
    assert(fabs(surface_area - cube_surface(x)) <= 1E-3);

    infile >> b >> h >> volume >> surface_area;
    assert(fabs(volume - pyramid_volume(b, h)) <= 1E-3);
    assert(fabs(surface_area - pyramid_surface(b, h)) <= 1E-3);

    infile >> r >> h >> volume >> surface_area;
    assert(fabs(volume - cylinder_volume(r, h)) <= 1E-3);
    assert(fabs(surface_area - cylinder_surface(r, h)) <= 1E-3);

    infile >> r >> volume >> surface_area;
    assert(fabs(volume - sphere_volume(r)) <= 1E-3);
    assert(fabs(surface_area - sphere_surface(r)) <= 1E-3);
  } else {
    std::cerr << "Unable to open file " << filename << '\n';
  }

  return EXIT_SUCCESS;
}
