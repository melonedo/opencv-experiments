// code segments from
// https://eigen.tuxfamily.org/dox/group__DenseMatrixManipulation__chapter.html

#include <Eigen/dense>
#include <iostream>

using namespace Eigen;

int main() {
  Matrix3d A;
  A << 1, 0, 3, 4, 5, 6, 7, 8, 9;
  std::cout << "A\n" << A << std::endl;
  Vector3d row2 = A.row(1);
  std::cout << "Second row " << row2 << std::endl;
  auto col2 = A.col(1);
  std::cout << "Second column\n" << col2 << std::endl;
  Matrix2d B = A.block<2, 2>(1, 1);
  std::cout << "Block\n" << B << std::endl;

  std::cout << std::endl;

  Matrix3d C;
  Matrix2d D;
  D << 1, 2, 3, 4;
  C.block<2, 2>(0, 0) << D;
  Vector2d e{5, 6};
  C.block<2, 1>(0, 2) << e;
  C.block<1, 2>(2, 0) << 0, 0;
  C.block<1, 1>(2, 2) << 0;
  std::cout << "T\n" << C << std::endl;

  std::cout << std::endl;

  Matrix2cf R = MatrixXcf::Random(2, 2);
  std::cout << "R\n" << R << std::endl;
  std::cout << "R^T\n" << R.transpose() << std::endl;
  std::cout << "conj(R)\n" << R.conjugate() << std::endl;
  std::cout << "adj(R)\n" << R.adjoint() << std::endl;

  std::cout << std::endl;

  Matrix2i F;
  F << 1, 2, 3, 4;
  std::cout << "A\n" << F << std::endl;
  Matrix2i G = F.transpose();
  std::cout << "B\n" << G << std::endl;

  std::cout << std::endl;

  Matrix2d a;
  a << 1, 2, 3, 4;
  MatrixXd b(2, 2);
  b << 2, 3, 1, 4;
  std::cout << "a + b =\n" << a + b << std::endl;
  std::cout << "a - b =\n" << a - b << std::endl;
  std::cout << "Doing a += b;" << std::endl;
  a += b;
  std::cout << "Now a =\n" << a << std::endl;
  Vector3d v(1, 2, 3);
  Vector3d w(1, 0, 0);
  std::cout << "-v + w - v =\n" << -v + w - v << std::endl;

  std::cout << std::endl;

  Matrix2d mat;
  mat << 1, 2, 3, 4;
  Vector2d u(-1, 1), v2(2, 0);
  std::cout << "Here is mat*mat:\n" << mat * mat << std::endl;
  std::cout << "Here is mat*u:\n" << mat * u << std::endl;
  std::cout << "Here is u^T*mat:\n" << u.transpose() * mat << std::endl;
  std::cout << "Here is u^T*v:\n" << u.transpose() * v2 << std::endl;
  std::cout << "Here is u*v^T:\n" << u * v2.transpose() << std::endl;
  std::cout << "Let's multiply mat by itself" << std::endl;
  mat = mat * mat;
  std::cout << "Now mat is mat:\n" << mat << std::endl;

  std::cout << std::endl;

  Vector3d v3(1, 2, 3);
  Vector3d w3(0, 1, 2);

  std::cout << "Dot product: " << v3.dot(w3) << std::endl;
  double dp = v3.adjoint() * w3;
  std::cout << "Dot product via a matrix product: " << dp << std::endl;
  std::cout << "Cross product:\n" << v3.cross(w3) << std::endl;

  std::cout << std::endl;

  std::cout << "Here is mat.sum():       " << mat.sum() << std::endl;
  std::cout << "Here is mat.prod():      " << mat.prod() << std::endl;
  std::cout << "Here is mat.mean():      " << mat.mean() << std::endl;
  std::cout << "Here is mat.minCoeff():  " << mat.minCoeff() << std::endl;
  std::cout << "Here is mat.maxCoeff():  " << mat.maxCoeff() << std::endl;
  std::cout << "Here is mat.trace():     " << mat.trace() << std::endl;

  std::cout << std::endl;

  Matrix3f m = Matrix3f::Random();
  std::ptrdiff_t i, j;
  float minOfM = m.minCoeff(&i, &j);
  std::cout << "Here is the matrix m:\n" << m << std::endl;
  std::cout << "Its minimum coefficient (" << minOfM << ") is at position ("
            << i << "," << j << ")\n\n";

  RowVector4i v4 = RowVector4i::Random();
  int maxOfV = v4.maxCoeff(&i);
  std::cout << "Here is the vector v: " << v4 << std::endl;
  std::cout << "Its maximum coefficient (" << maxOfV << ") is at position " << i
            << std::endl;

  VectorXf v5(2);
  MatrixXf m5(2, 2), n5(2, 2);

  v5 << -1, 2;

  m5 << 1, -2, -3, 4;

  std::cout << "v.squaredNorm() = " << v5.squaredNorm() << std::endl;
  std::cout << "v.norm() = " << v5.norm() << std::endl;
  std::cout << "v.lpNorm<1>() = " << v5.lpNorm<1>() << std::endl;
  std::cout << "v.lpNorm<Infinity>() = " << v5.lpNorm<Infinity>() << std::endl;

  std::cout << std::endl;
  std::cout << "m.squaredNorm() = " << m5.squaredNorm() << std::endl;
  std::cout << "m.norm() = " << m5.norm() << std::endl;
  std::cout << "m.lpNorm<1>() = " << m5.lpNorm<1>() << std::endl;
  std::cout << "m.lpNorm<Infinity>() = " << m5.lpNorm<Infinity>() << std::endl;

  return 0;
}
