#include <cstdlib>
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
  double x{3.14};
  double b{2.0};
  double h{3.0};
  double r{2.78};

  std::cout << "Volume of a cube of width/height/depth " << x << ": "
            << cube_volume(x) << ", surface area: " << cube_surface(x)
            << "\nVolume of a right rectangular pyramid with equal base width "
               "and length "
            << b << " and height " << h << ": " << pyramid_volume(b, h)
            << ", surface area: " << pyramid_surface(b, h)
            << "\nVolume of a right cylinder "
            << " of radius " << r << " and height " << h << ": "
            << cylinder_volume(r, h)
            << ", surface area: " << cylinder_surface(r, h)
            << "\nVolume of a sphere of radius " << r << ": "
            << sphere_volume(r) << ", surface area: " << sphere_surface(r)
            << '\n';

  return EXIT_SUCCESS;
}
