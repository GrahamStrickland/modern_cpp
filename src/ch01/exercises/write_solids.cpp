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
  std::ofstream outfile;
  std::string filename{"solids.dat"};

  outfile.open(filename);
  if (outfile.good()) {
    double x{3.14};
    double b{2.0};
    double h{3.0};
    double r{2.78};

    outfile << x << ' ' << cube_volume(x) << ' ' << cube_surface(x) << '\n'
            << b << ' ' << h << ' ' << pyramid_volume(b, h) << ' '
            << pyramid_surface(b, h) << '\n'
            << r << ' ' << h << ' ' << cylinder_volume(r, h) << ' '
            << cylinder_surface(r, h) << '\n'
            << r << ' ' << sphere_volume(r) << ' ' << sphere_surface(r) << '\n';
  } else {
    std::cerr << "Unable to open file " << filename << '\n';
  }

  return EXIT_SUCCESS;
}
