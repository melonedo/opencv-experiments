#include <Eigen/dense>
#include <iostream>

using namespace Eigen;
using namespace std;

int main() {
  Vector3d t{1, 0, 3};
  Matrix3d A;
  A << 1, 0, 3, 4, 5, 6, 7, 8, 9;
  Matrix3d I = Matrix3d::Identity();
  Matrix4d T;
  T.topLeftCorner(3, 3) = A;
  T.topRightCorner(3, 1) = t;
  T.bottomLeftCorner(1, 3) = RowVector3d::Zero();
  T.bottomRightCorner(1, 1) << 1;
  Matrix3d B = A.transpose();

  cout << "t:\n" << t << endl;
  cout << "A:\n" << A << endl;
  cout << "I:\n" << I << endl;
  cout << "T:\n" << T << endl;
  cout << "B:\n" << B << endl;
  cout << endl;

  t(1) = 2;
  A(0, 1) = 2;
  cout << "t:\n" << t << endl;
  cout << "A:\n" << A << endl;
  cout << endl;

  RowVector3d row = A.row(1);
  Vector3d col = A.col(1);
  Matrix2d block = T.block<2, 2>(1, 1);
  cout << "row:\n" << row << endl;
  cout << "col:\n" << col << endl;
  cout << "block:\n" << block << endl;
  cout << endl;

  Vector3d t2{1, 1, 1};
  cout << "A+I:\n" << A + I << endl;
  cout << "t+t2:\n" << t + t2 << endl;
  cout << "A*t:\n" << A * t << endl;
  cout << "t¡¤t2:\n" << t.dot(t2) << endl;
  cout << "A.*I:\n" << A.array() * I.array() << endl;
  cout << "t.homogeneous():\n" << t.homogeneous() << endl;
  cout << "t.hnormalized():\n" << t.hnormalized() << endl;
  cout << endl;

  cout << "A.sum() = " << A.sum() << endl;
  Eigen::Index x, y;
  cout << "A.min() = " << A.minCoeff(&x, &y);
  cout << ", index = (" << x << ", " << y << ")\n";
  cout << "Columnwise minimum:\n" << A.colwise().minCoeff() << endl;
  cout << "L1(t) = " << t.lpNorm<1>() << ", L2(t) = " << t.lpNorm<2>() << endl;
  cout << "Number of elements greater 1 in A: " << (A.array() > 1).count() << endl;
  cout << endl;

  return 0;
}
