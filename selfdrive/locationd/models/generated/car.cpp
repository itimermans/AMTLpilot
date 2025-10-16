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
void err_fun(double *nom_x, double *delta_x, double *out_3019206191168354398) {
   out_3019206191168354398[0] = delta_x[0] + nom_x[0];
   out_3019206191168354398[1] = delta_x[1] + nom_x[1];
   out_3019206191168354398[2] = delta_x[2] + nom_x[2];
   out_3019206191168354398[3] = delta_x[3] + nom_x[3];
   out_3019206191168354398[4] = delta_x[4] + nom_x[4];
   out_3019206191168354398[5] = delta_x[5] + nom_x[5];
   out_3019206191168354398[6] = delta_x[6] + nom_x[6];
   out_3019206191168354398[7] = delta_x[7] + nom_x[7];
   out_3019206191168354398[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7040565929465379278) {
   out_7040565929465379278[0] = -nom_x[0] + true_x[0];
   out_7040565929465379278[1] = -nom_x[1] + true_x[1];
   out_7040565929465379278[2] = -nom_x[2] + true_x[2];
   out_7040565929465379278[3] = -nom_x[3] + true_x[3];
   out_7040565929465379278[4] = -nom_x[4] + true_x[4];
   out_7040565929465379278[5] = -nom_x[5] + true_x[5];
   out_7040565929465379278[6] = -nom_x[6] + true_x[6];
   out_7040565929465379278[7] = -nom_x[7] + true_x[7];
   out_7040565929465379278[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8434020231350892300) {
   out_8434020231350892300[0] = 1.0;
   out_8434020231350892300[1] = 0.0;
   out_8434020231350892300[2] = 0.0;
   out_8434020231350892300[3] = 0.0;
   out_8434020231350892300[4] = 0.0;
   out_8434020231350892300[5] = 0.0;
   out_8434020231350892300[6] = 0.0;
   out_8434020231350892300[7] = 0.0;
   out_8434020231350892300[8] = 0.0;
   out_8434020231350892300[9] = 0.0;
   out_8434020231350892300[10] = 1.0;
   out_8434020231350892300[11] = 0.0;
   out_8434020231350892300[12] = 0.0;
   out_8434020231350892300[13] = 0.0;
   out_8434020231350892300[14] = 0.0;
   out_8434020231350892300[15] = 0.0;
   out_8434020231350892300[16] = 0.0;
   out_8434020231350892300[17] = 0.0;
   out_8434020231350892300[18] = 0.0;
   out_8434020231350892300[19] = 0.0;
   out_8434020231350892300[20] = 1.0;
   out_8434020231350892300[21] = 0.0;
   out_8434020231350892300[22] = 0.0;
   out_8434020231350892300[23] = 0.0;
   out_8434020231350892300[24] = 0.0;
   out_8434020231350892300[25] = 0.0;
   out_8434020231350892300[26] = 0.0;
   out_8434020231350892300[27] = 0.0;
   out_8434020231350892300[28] = 0.0;
   out_8434020231350892300[29] = 0.0;
   out_8434020231350892300[30] = 1.0;
   out_8434020231350892300[31] = 0.0;
   out_8434020231350892300[32] = 0.0;
   out_8434020231350892300[33] = 0.0;
   out_8434020231350892300[34] = 0.0;
   out_8434020231350892300[35] = 0.0;
   out_8434020231350892300[36] = 0.0;
   out_8434020231350892300[37] = 0.0;
   out_8434020231350892300[38] = 0.0;
   out_8434020231350892300[39] = 0.0;
   out_8434020231350892300[40] = 1.0;
   out_8434020231350892300[41] = 0.0;
   out_8434020231350892300[42] = 0.0;
   out_8434020231350892300[43] = 0.0;
   out_8434020231350892300[44] = 0.0;
   out_8434020231350892300[45] = 0.0;
   out_8434020231350892300[46] = 0.0;
   out_8434020231350892300[47] = 0.0;
   out_8434020231350892300[48] = 0.0;
   out_8434020231350892300[49] = 0.0;
   out_8434020231350892300[50] = 1.0;
   out_8434020231350892300[51] = 0.0;
   out_8434020231350892300[52] = 0.0;
   out_8434020231350892300[53] = 0.0;
   out_8434020231350892300[54] = 0.0;
   out_8434020231350892300[55] = 0.0;
   out_8434020231350892300[56] = 0.0;
   out_8434020231350892300[57] = 0.0;
   out_8434020231350892300[58] = 0.0;
   out_8434020231350892300[59] = 0.0;
   out_8434020231350892300[60] = 1.0;
   out_8434020231350892300[61] = 0.0;
   out_8434020231350892300[62] = 0.0;
   out_8434020231350892300[63] = 0.0;
   out_8434020231350892300[64] = 0.0;
   out_8434020231350892300[65] = 0.0;
   out_8434020231350892300[66] = 0.0;
   out_8434020231350892300[67] = 0.0;
   out_8434020231350892300[68] = 0.0;
   out_8434020231350892300[69] = 0.0;
   out_8434020231350892300[70] = 1.0;
   out_8434020231350892300[71] = 0.0;
   out_8434020231350892300[72] = 0.0;
   out_8434020231350892300[73] = 0.0;
   out_8434020231350892300[74] = 0.0;
   out_8434020231350892300[75] = 0.0;
   out_8434020231350892300[76] = 0.0;
   out_8434020231350892300[77] = 0.0;
   out_8434020231350892300[78] = 0.0;
   out_8434020231350892300[79] = 0.0;
   out_8434020231350892300[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8099859495807403305) {
   out_8099859495807403305[0] = state[0];
   out_8099859495807403305[1] = state[1];
   out_8099859495807403305[2] = state[2];
   out_8099859495807403305[3] = state[3];
   out_8099859495807403305[4] = state[4];
   out_8099859495807403305[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8099859495807403305[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8099859495807403305[7] = state[7];
   out_8099859495807403305[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8611419442479359730) {
   out_8611419442479359730[0] = 1;
   out_8611419442479359730[1] = 0;
   out_8611419442479359730[2] = 0;
   out_8611419442479359730[3] = 0;
   out_8611419442479359730[4] = 0;
   out_8611419442479359730[5] = 0;
   out_8611419442479359730[6] = 0;
   out_8611419442479359730[7] = 0;
   out_8611419442479359730[8] = 0;
   out_8611419442479359730[9] = 0;
   out_8611419442479359730[10] = 1;
   out_8611419442479359730[11] = 0;
   out_8611419442479359730[12] = 0;
   out_8611419442479359730[13] = 0;
   out_8611419442479359730[14] = 0;
   out_8611419442479359730[15] = 0;
   out_8611419442479359730[16] = 0;
   out_8611419442479359730[17] = 0;
   out_8611419442479359730[18] = 0;
   out_8611419442479359730[19] = 0;
   out_8611419442479359730[20] = 1;
   out_8611419442479359730[21] = 0;
   out_8611419442479359730[22] = 0;
   out_8611419442479359730[23] = 0;
   out_8611419442479359730[24] = 0;
   out_8611419442479359730[25] = 0;
   out_8611419442479359730[26] = 0;
   out_8611419442479359730[27] = 0;
   out_8611419442479359730[28] = 0;
   out_8611419442479359730[29] = 0;
   out_8611419442479359730[30] = 1;
   out_8611419442479359730[31] = 0;
   out_8611419442479359730[32] = 0;
   out_8611419442479359730[33] = 0;
   out_8611419442479359730[34] = 0;
   out_8611419442479359730[35] = 0;
   out_8611419442479359730[36] = 0;
   out_8611419442479359730[37] = 0;
   out_8611419442479359730[38] = 0;
   out_8611419442479359730[39] = 0;
   out_8611419442479359730[40] = 1;
   out_8611419442479359730[41] = 0;
   out_8611419442479359730[42] = 0;
   out_8611419442479359730[43] = 0;
   out_8611419442479359730[44] = 0;
   out_8611419442479359730[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8611419442479359730[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8611419442479359730[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8611419442479359730[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8611419442479359730[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8611419442479359730[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8611419442479359730[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8611419442479359730[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8611419442479359730[53] = -9.8000000000000007*dt;
   out_8611419442479359730[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8611419442479359730[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8611419442479359730[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8611419442479359730[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8611419442479359730[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8611419442479359730[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8611419442479359730[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8611419442479359730[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8611419442479359730[62] = 0;
   out_8611419442479359730[63] = 0;
   out_8611419442479359730[64] = 0;
   out_8611419442479359730[65] = 0;
   out_8611419442479359730[66] = 0;
   out_8611419442479359730[67] = 0;
   out_8611419442479359730[68] = 0;
   out_8611419442479359730[69] = 0;
   out_8611419442479359730[70] = 1;
   out_8611419442479359730[71] = 0;
   out_8611419442479359730[72] = 0;
   out_8611419442479359730[73] = 0;
   out_8611419442479359730[74] = 0;
   out_8611419442479359730[75] = 0;
   out_8611419442479359730[76] = 0;
   out_8611419442479359730[77] = 0;
   out_8611419442479359730[78] = 0;
   out_8611419442479359730[79] = 0;
   out_8611419442479359730[80] = 1;
}
void h_25(double *state, double *unused, double *out_8979225577996030938) {
   out_8979225577996030938[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2461360111523505779) {
   out_2461360111523505779[0] = 0;
   out_2461360111523505779[1] = 0;
   out_2461360111523505779[2] = 0;
   out_2461360111523505779[3] = 0;
   out_2461360111523505779[4] = 0;
   out_2461360111523505779[5] = 0;
   out_2461360111523505779[6] = 1;
   out_2461360111523505779[7] = 0;
   out_2461360111523505779[8] = 0;
}
void h_24(double *state, double *unused, double *out_8444334853889446663) {
   out_8444334853889446663[0] = state[4];
   out_8444334853889446663[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8662392791374667205) {
   out_8662392791374667205[0] = 0;
   out_8662392791374667205[1] = 0;
   out_8662392791374667205[2] = 0;
   out_8662392791374667205[3] = 0;
   out_8662392791374667205[4] = 1;
   out_8662392791374667205[5] = 0;
   out_8662392791374667205[6] = 0;
   out_8662392791374667205[7] = 0;
   out_8662392791374667205[8] = 0;
   out_8662392791374667205[9] = 0;
   out_8662392791374667205[10] = 0;
   out_8662392791374667205[11] = 0;
   out_8662392791374667205[12] = 0;
   out_8662392791374667205[13] = 0;
   out_8662392791374667205[14] = 1;
   out_8662392791374667205[15] = 0;
   out_8662392791374667205[16] = 0;
   out_8662392791374667205[17] = 0;
}
void h_30(double *state, double *unused, double *out_5830068967459498328) {
   out_5830068967459498328[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2590699058666745849) {
   out_2590699058666745849[0] = 0;
   out_2590699058666745849[1] = 0;
   out_2590699058666745849[2] = 0;
   out_2590699058666745849[3] = 0;
   out_2590699058666745849[4] = 1;
   out_2590699058666745849[5] = 0;
   out_2590699058666745849[6] = 0;
   out_2590699058666745849[7] = 0;
   out_2590699058666745849[8] = 0;
}
void h_26(double *state, double *unused, double *out_488201731573467765) {
   out_488201731573467765[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6202863430397562003) {
   out_6202863430397562003[0] = 0;
   out_6202863430397562003[1] = 0;
   out_6202863430397562003[2] = 0;
   out_6202863430397562003[3] = 0;
   out_6202863430397562003[4] = 0;
   out_6202863430397562003[5] = 0;
   out_6202863430397562003[6] = 0;
   out_6202863430397562003[7] = 1;
   out_6202863430397562003[8] = 0;
}
void h_27(double *state, double *unused, double *out_8709668350552701868) {
   out_8709668350552701868[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4765462370467170760) {
   out_4765462370467170760[0] = 0;
   out_4765462370467170760[1] = 0;
   out_4765462370467170760[2] = 0;
   out_4765462370467170760[3] = 1;
   out_4765462370467170760[4] = 0;
   out_4765462370467170760[5] = 0;
   out_4765462370467170760[6] = 0;
   out_4765462370467170760[7] = 0;
   out_4765462370467170760[8] = 0;
}
void h_29(double *state, double *unused, double *out_828395699798652683) {
   out_828395699798652683[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2080467714352353665) {
   out_2080467714352353665[0] = 0;
   out_2080467714352353665[1] = 1;
   out_2080467714352353665[2] = 0;
   out_2080467714352353665[3] = 0;
   out_2080467714352353665[4] = 0;
   out_2080467714352353665[5] = 0;
   out_2080467714352353665[6] = 0;
   out_2080467714352353665[7] = 0;
   out_2080467714352353665[8] = 0;
}
void h_28(double *state, double *unused, double *out_3707995082891856223) {
   out_3707995082891856223[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6885519959303299249) {
   out_6885519959303299249[0] = 1;
   out_6885519959303299249[1] = 0;
   out_6885519959303299249[2] = 0;
   out_6885519959303299249[3] = 0;
   out_6885519959303299249[4] = 0;
   out_6885519959303299249[5] = 0;
   out_6885519959303299249[6] = 0;
   out_6885519959303299249[7] = 0;
   out_6885519959303299249[8] = 0;
}
void h_31(double *state, double *unused, double *out_1097952927241981753) {
   out_1097952927241981753[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2430714149646545351) {
   out_2430714149646545351[0] = 0;
   out_2430714149646545351[1] = 0;
   out_2430714149646545351[2] = 0;
   out_2430714149646545351[3] = 0;
   out_2430714149646545351[4] = 0;
   out_2430714149646545351[5] = 0;
   out_2430714149646545351[6] = 0;
   out_2430714149646545351[7] = 0;
   out_2430714149646545351[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3019206191168354398) {
  err_fun(nom_x, delta_x, out_3019206191168354398);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7040565929465379278) {
  inv_err_fun(nom_x, true_x, out_7040565929465379278);
}
void car_H_mod_fun(double *state, double *out_8434020231350892300) {
  H_mod_fun(state, out_8434020231350892300);
}
void car_f_fun(double *state, double dt, double *out_8099859495807403305) {
  f_fun(state,  dt, out_8099859495807403305);
}
void car_F_fun(double *state, double dt, double *out_8611419442479359730) {
  F_fun(state,  dt, out_8611419442479359730);
}
void car_h_25(double *state, double *unused, double *out_8979225577996030938) {
  h_25(state, unused, out_8979225577996030938);
}
void car_H_25(double *state, double *unused, double *out_2461360111523505779) {
  H_25(state, unused, out_2461360111523505779);
}
void car_h_24(double *state, double *unused, double *out_8444334853889446663) {
  h_24(state, unused, out_8444334853889446663);
}
void car_H_24(double *state, double *unused, double *out_8662392791374667205) {
  H_24(state, unused, out_8662392791374667205);
}
void car_h_30(double *state, double *unused, double *out_5830068967459498328) {
  h_30(state, unused, out_5830068967459498328);
}
void car_H_30(double *state, double *unused, double *out_2590699058666745849) {
  H_30(state, unused, out_2590699058666745849);
}
void car_h_26(double *state, double *unused, double *out_488201731573467765) {
  h_26(state, unused, out_488201731573467765);
}
void car_H_26(double *state, double *unused, double *out_6202863430397562003) {
  H_26(state, unused, out_6202863430397562003);
}
void car_h_27(double *state, double *unused, double *out_8709668350552701868) {
  h_27(state, unused, out_8709668350552701868);
}
void car_H_27(double *state, double *unused, double *out_4765462370467170760) {
  H_27(state, unused, out_4765462370467170760);
}
void car_h_29(double *state, double *unused, double *out_828395699798652683) {
  h_29(state, unused, out_828395699798652683);
}
void car_H_29(double *state, double *unused, double *out_2080467714352353665) {
  H_29(state, unused, out_2080467714352353665);
}
void car_h_28(double *state, double *unused, double *out_3707995082891856223) {
  h_28(state, unused, out_3707995082891856223);
}
void car_H_28(double *state, double *unused, double *out_6885519959303299249) {
  H_28(state, unused, out_6885519959303299249);
}
void car_h_31(double *state, double *unused, double *out_1097952927241981753) {
  h_31(state, unused, out_1097952927241981753);
}
void car_H_31(double *state, double *unused, double *out_2430714149646545351) {
  H_31(state, unused, out_2430714149646545351);
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
