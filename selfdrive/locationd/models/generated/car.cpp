#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3712298530660200368) {
   out_3712298530660200368[0] = delta_x[0] + nom_x[0];
   out_3712298530660200368[1] = delta_x[1] + nom_x[1];
   out_3712298530660200368[2] = delta_x[2] + nom_x[2];
   out_3712298530660200368[3] = delta_x[3] + nom_x[3];
   out_3712298530660200368[4] = delta_x[4] + nom_x[4];
   out_3712298530660200368[5] = delta_x[5] + nom_x[5];
   out_3712298530660200368[6] = delta_x[6] + nom_x[6];
   out_3712298530660200368[7] = delta_x[7] + nom_x[7];
   out_3712298530660200368[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1585390793410116901) {
   out_1585390793410116901[0] = -nom_x[0] + true_x[0];
   out_1585390793410116901[1] = -nom_x[1] + true_x[1];
   out_1585390793410116901[2] = -nom_x[2] + true_x[2];
   out_1585390793410116901[3] = -nom_x[3] + true_x[3];
   out_1585390793410116901[4] = -nom_x[4] + true_x[4];
   out_1585390793410116901[5] = -nom_x[5] + true_x[5];
   out_1585390793410116901[6] = -nom_x[6] + true_x[6];
   out_1585390793410116901[7] = -nom_x[7] + true_x[7];
   out_1585390793410116901[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7492711310731175134) {
   out_7492711310731175134[0] = 1.0;
   out_7492711310731175134[1] = 0.0;
   out_7492711310731175134[2] = 0.0;
   out_7492711310731175134[3] = 0.0;
   out_7492711310731175134[4] = 0.0;
   out_7492711310731175134[5] = 0.0;
   out_7492711310731175134[6] = 0.0;
   out_7492711310731175134[7] = 0.0;
   out_7492711310731175134[8] = 0.0;
   out_7492711310731175134[9] = 0.0;
   out_7492711310731175134[10] = 1.0;
   out_7492711310731175134[11] = 0.0;
   out_7492711310731175134[12] = 0.0;
   out_7492711310731175134[13] = 0.0;
   out_7492711310731175134[14] = 0.0;
   out_7492711310731175134[15] = 0.0;
   out_7492711310731175134[16] = 0.0;
   out_7492711310731175134[17] = 0.0;
   out_7492711310731175134[18] = 0.0;
   out_7492711310731175134[19] = 0.0;
   out_7492711310731175134[20] = 1.0;
   out_7492711310731175134[21] = 0.0;
   out_7492711310731175134[22] = 0.0;
   out_7492711310731175134[23] = 0.0;
   out_7492711310731175134[24] = 0.0;
   out_7492711310731175134[25] = 0.0;
   out_7492711310731175134[26] = 0.0;
   out_7492711310731175134[27] = 0.0;
   out_7492711310731175134[28] = 0.0;
   out_7492711310731175134[29] = 0.0;
   out_7492711310731175134[30] = 1.0;
   out_7492711310731175134[31] = 0.0;
   out_7492711310731175134[32] = 0.0;
   out_7492711310731175134[33] = 0.0;
   out_7492711310731175134[34] = 0.0;
   out_7492711310731175134[35] = 0.0;
   out_7492711310731175134[36] = 0.0;
   out_7492711310731175134[37] = 0.0;
   out_7492711310731175134[38] = 0.0;
   out_7492711310731175134[39] = 0.0;
   out_7492711310731175134[40] = 1.0;
   out_7492711310731175134[41] = 0.0;
   out_7492711310731175134[42] = 0.0;
   out_7492711310731175134[43] = 0.0;
   out_7492711310731175134[44] = 0.0;
   out_7492711310731175134[45] = 0.0;
   out_7492711310731175134[46] = 0.0;
   out_7492711310731175134[47] = 0.0;
   out_7492711310731175134[48] = 0.0;
   out_7492711310731175134[49] = 0.0;
   out_7492711310731175134[50] = 1.0;
   out_7492711310731175134[51] = 0.0;
   out_7492711310731175134[52] = 0.0;
   out_7492711310731175134[53] = 0.0;
   out_7492711310731175134[54] = 0.0;
   out_7492711310731175134[55] = 0.0;
   out_7492711310731175134[56] = 0.0;
   out_7492711310731175134[57] = 0.0;
   out_7492711310731175134[58] = 0.0;
   out_7492711310731175134[59] = 0.0;
   out_7492711310731175134[60] = 1.0;
   out_7492711310731175134[61] = 0.0;
   out_7492711310731175134[62] = 0.0;
   out_7492711310731175134[63] = 0.0;
   out_7492711310731175134[64] = 0.0;
   out_7492711310731175134[65] = 0.0;
   out_7492711310731175134[66] = 0.0;
   out_7492711310731175134[67] = 0.0;
   out_7492711310731175134[68] = 0.0;
   out_7492711310731175134[69] = 0.0;
   out_7492711310731175134[70] = 1.0;
   out_7492711310731175134[71] = 0.0;
   out_7492711310731175134[72] = 0.0;
   out_7492711310731175134[73] = 0.0;
   out_7492711310731175134[74] = 0.0;
   out_7492711310731175134[75] = 0.0;
   out_7492711310731175134[76] = 0.0;
   out_7492711310731175134[77] = 0.0;
   out_7492711310731175134[78] = 0.0;
   out_7492711310731175134[79] = 0.0;
   out_7492711310731175134[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1912712957534596757) {
   out_1912712957534596757[0] = state[0];
   out_1912712957534596757[1] = state[1];
   out_1912712957534596757[2] = state[2];
   out_1912712957534596757[3] = state[3];
   out_1912712957534596757[4] = state[4];
   out_1912712957534596757[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1912712957534596757[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1912712957534596757[7] = state[7];
   out_1912712957534596757[8] = state[8];
}
void F_fun(double *state, double dt, double *out_6070284381192909234) {
   out_6070284381192909234[0] = 1;
   out_6070284381192909234[1] = 0;
   out_6070284381192909234[2] = 0;
   out_6070284381192909234[3] = 0;
   out_6070284381192909234[4] = 0;
   out_6070284381192909234[5] = 0;
   out_6070284381192909234[6] = 0;
   out_6070284381192909234[7] = 0;
   out_6070284381192909234[8] = 0;
   out_6070284381192909234[9] = 0;
   out_6070284381192909234[10] = 1;
   out_6070284381192909234[11] = 0;
   out_6070284381192909234[12] = 0;
   out_6070284381192909234[13] = 0;
   out_6070284381192909234[14] = 0;
   out_6070284381192909234[15] = 0;
   out_6070284381192909234[16] = 0;
   out_6070284381192909234[17] = 0;
   out_6070284381192909234[18] = 0;
   out_6070284381192909234[19] = 0;
   out_6070284381192909234[20] = 1;
   out_6070284381192909234[21] = 0;
   out_6070284381192909234[22] = 0;
   out_6070284381192909234[23] = 0;
   out_6070284381192909234[24] = 0;
   out_6070284381192909234[25] = 0;
   out_6070284381192909234[26] = 0;
   out_6070284381192909234[27] = 0;
   out_6070284381192909234[28] = 0;
   out_6070284381192909234[29] = 0;
   out_6070284381192909234[30] = 1;
   out_6070284381192909234[31] = 0;
   out_6070284381192909234[32] = 0;
   out_6070284381192909234[33] = 0;
   out_6070284381192909234[34] = 0;
   out_6070284381192909234[35] = 0;
   out_6070284381192909234[36] = 0;
   out_6070284381192909234[37] = 0;
   out_6070284381192909234[38] = 0;
   out_6070284381192909234[39] = 0;
   out_6070284381192909234[40] = 1;
   out_6070284381192909234[41] = 0;
   out_6070284381192909234[42] = 0;
   out_6070284381192909234[43] = 0;
   out_6070284381192909234[44] = 0;
   out_6070284381192909234[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_6070284381192909234[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_6070284381192909234[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6070284381192909234[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6070284381192909234[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_6070284381192909234[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_6070284381192909234[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_6070284381192909234[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_6070284381192909234[53] = -9.8000000000000007*dt;
   out_6070284381192909234[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6070284381192909234[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6070284381192909234[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6070284381192909234[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6070284381192909234[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6070284381192909234[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6070284381192909234[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6070284381192909234[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6070284381192909234[62] = 0;
   out_6070284381192909234[63] = 0;
   out_6070284381192909234[64] = 0;
   out_6070284381192909234[65] = 0;
   out_6070284381192909234[66] = 0;
   out_6070284381192909234[67] = 0;
   out_6070284381192909234[68] = 0;
   out_6070284381192909234[69] = 0;
   out_6070284381192909234[70] = 1;
   out_6070284381192909234[71] = 0;
   out_6070284381192909234[72] = 0;
   out_6070284381192909234[73] = 0;
   out_6070284381192909234[74] = 0;
   out_6070284381192909234[75] = 0;
   out_6070284381192909234[76] = 0;
   out_6070284381192909234[77] = 0;
   out_6070284381192909234[78] = 0;
   out_6070284381192909234[79] = 0;
   out_6070284381192909234[80] = 1;
}
void h_25(double *state, double *unused, double *out_163645903678262497) {
   out_163645903678262497[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6159201920050507373) {
   out_6159201920050507373[0] = 0;
   out_6159201920050507373[1] = 0;
   out_6159201920050507373[2] = 0;
   out_6159201920050507373[3] = 0;
   out_6159201920050507373[4] = 0;
   out_6159201920050507373[5] = 0;
   out_6159201920050507373[6] = 1;
   out_6159201920050507373[7] = 0;
   out_6159201920050507373[8] = 0;
}
void h_24(double *state, double *unused, double *out_1223586909973532045) {
   out_1223586909973532045[0] = state[4];
   out_1223586909973532045[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3986552321045007807) {
   out_3986552321045007807[0] = 0;
   out_3986552321045007807[1] = 0;
   out_3986552321045007807[2] = 0;
   out_3986552321045007807[3] = 0;
   out_3986552321045007807[4] = 1;
   out_3986552321045007807[5] = 0;
   out_3986552321045007807[6] = 0;
   out_3986552321045007807[7] = 0;
   out_3986552321045007807[8] = 0;
   out_3986552321045007807[9] = 0;
   out_3986552321045007807[10] = 0;
   out_3986552321045007807[11] = 0;
   out_3986552321045007807[12] = 0;
   out_3986552321045007807[13] = 0;
   out_3986552321045007807[14] = 1;
   out_3986552321045007807[15] = 0;
   out_3986552321045007807[16] = 0;
   out_3986552321045007807[17] = 0;
}
void h_30(double *state, double *unused, double *out_438839965962768386) {
   out_438839965962768386[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8677534878557756000) {
   out_8677534878557756000[0] = 0;
   out_8677534878557756000[1] = 0;
   out_8677534878557756000[2] = 0;
   out_8677534878557756000[3] = 0;
   out_8677534878557756000[4] = 1;
   out_8677534878557756000[5] = 0;
   out_8677534878557756000[6] = 0;
   out_8677534878557756000[7] = 0;
   out_8677534878557756000[8] = 0;
}
void h_26(double *state, double *unused, double *out_3043245286771466037) {
   out_3043245286771466037[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2417698601176451149) {
   out_2417698601176451149[0] = 0;
   out_2417698601176451149[1] = 0;
   out_2417698601176451149[2] = 0;
   out_2417698601176451149[3] = 0;
   out_2417698601176451149[4] = 0;
   out_2417698601176451149[5] = 0;
   out_2417698601176451149[6] = 0;
   out_2417698601176451149[7] = 1;
   out_2417698601176451149[8] = 0;
}
void h_27(double *state, double *unused, double *out_991195736529219316) {
   out_991195736529219316[0] = state[3];
}
void H_27(double *state, double *unused, double *out_543257721877525736) {
   out_543257721877525736[0] = 0;
   out_543257721877525736[1] = 0;
   out_543257721877525736[2] = 0;
   out_543257721877525736[3] = 1;
   out_543257721877525736[4] = 0;
   out_543257721877525736[5] = 0;
   out_543257721877525736[6] = 0;
   out_543257721877525736[7] = 0;
   out_543257721877525736[8] = 0;
}
void h_29(double *state, double *unused, double *out_1042155850639245903) {
   out_1042155850639245903[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2141736934237291359) {
   out_2141736934237291359[0] = 0;
   out_2141736934237291359[1] = 1;
   out_2141736934237291359[2] = 0;
   out_2141736934237291359[3] = 0;
   out_2141736934237291359[4] = 0;
   out_2141736934237291359[5] = 0;
   out_2141736934237291359[6] = 0;
   out_2141736934237291359[7] = 0;
   out_2141736934237291359[8] = 0;
}
void h_28(double *state, double *unused, double *out_6869481224087934404) {
   out_6869481224087934404[0] = state[0];
}
void H_28(double *state, double *unused, double *out_4105367205802617610) {
   out_4105367205802617610[0] = 1;
   out_4105367205802617610[1] = 0;
   out_4105367205802617610[2] = 0;
   out_4105367205802617610[3] = 0;
   out_4105367205802617610[4] = 0;
   out_4105367205802617610[5] = 0;
   out_4105367205802617610[6] = 0;
   out_4105367205802617610[7] = 0;
   out_4105367205802617610[8] = 0;
}
void h_31(double *state, double *unused, double *out_3473803624575759853) {
   out_3473803624575759853[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1791490498943099673) {
   out_1791490498943099673[0] = 0;
   out_1791490498943099673[1] = 0;
   out_1791490498943099673[2] = 0;
   out_1791490498943099673[3] = 0;
   out_1791490498943099673[4] = 0;
   out_1791490498943099673[5] = 0;
   out_1791490498943099673[6] = 0;
   out_1791490498943099673[7] = 0;
   out_1791490498943099673[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_3712298530660200368) {
  err_fun(nom_x, delta_x, out_3712298530660200368);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1585390793410116901) {
  inv_err_fun(nom_x, true_x, out_1585390793410116901);
}
void car_H_mod_fun(double *state, double *out_7492711310731175134) {
  H_mod_fun(state, out_7492711310731175134);
}
void car_f_fun(double *state, double dt, double *out_1912712957534596757) {
  f_fun(state,  dt, out_1912712957534596757);
}
void car_F_fun(double *state, double dt, double *out_6070284381192909234) {
  F_fun(state,  dt, out_6070284381192909234);
}
void car_h_25(double *state, double *unused, double *out_163645903678262497) {
  h_25(state, unused, out_163645903678262497);
}
void car_H_25(double *state, double *unused, double *out_6159201920050507373) {
  H_25(state, unused, out_6159201920050507373);
}
void car_h_24(double *state, double *unused, double *out_1223586909973532045) {
  h_24(state, unused, out_1223586909973532045);
}
void car_H_24(double *state, double *unused, double *out_3986552321045007807) {
  H_24(state, unused, out_3986552321045007807);
}
void car_h_30(double *state, double *unused, double *out_438839965962768386) {
  h_30(state, unused, out_438839965962768386);
}
void car_H_30(double *state, double *unused, double *out_8677534878557756000) {
  H_30(state, unused, out_8677534878557756000);
}
void car_h_26(double *state, double *unused, double *out_3043245286771466037) {
  h_26(state, unused, out_3043245286771466037);
}
void car_H_26(double *state, double *unused, double *out_2417698601176451149) {
  H_26(state, unused, out_2417698601176451149);
}
void car_h_27(double *state, double *unused, double *out_991195736529219316) {
  h_27(state, unused, out_991195736529219316);
}
void car_H_27(double *state, double *unused, double *out_543257721877525736) {
  H_27(state, unused, out_543257721877525736);
}
void car_h_29(double *state, double *unused, double *out_1042155850639245903) {
  h_29(state, unused, out_1042155850639245903);
}
void car_H_29(double *state, double *unused, double *out_2141736934237291359) {
  H_29(state, unused, out_2141736934237291359);
}
void car_h_28(double *state, double *unused, double *out_6869481224087934404) {
  h_28(state, unused, out_6869481224087934404);
}
void car_H_28(double *state, double *unused, double *out_4105367205802617610) {
  H_28(state, unused, out_4105367205802617610);
}
void car_h_31(double *state, double *unused, double *out_3473803624575759853) {
  h_31(state, unused, out_3473803624575759853);
}
void car_H_31(double *state, double *unused, double *out_1791490498943099673) {
  H_31(state, unused, out_1791490498943099673);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
