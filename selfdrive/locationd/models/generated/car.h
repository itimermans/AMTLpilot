#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_3019206191168354398);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7040565929465379278);
void car_H_mod_fun(double *state, double *out_8434020231350892300);
void car_f_fun(double *state, double dt, double *out_8099859495807403305);
void car_F_fun(double *state, double dt, double *out_8611419442479359730);
void car_h_25(double *state, double *unused, double *out_8979225577996030938);
void car_H_25(double *state, double *unused, double *out_2461360111523505779);
void car_h_24(double *state, double *unused, double *out_8444334853889446663);
void car_H_24(double *state, double *unused, double *out_8662392791374667205);
void car_h_30(double *state, double *unused, double *out_5830068967459498328);
void car_H_30(double *state, double *unused, double *out_2590699058666745849);
void car_h_26(double *state, double *unused, double *out_488201731573467765);
void car_H_26(double *state, double *unused, double *out_6202863430397562003);
void car_h_27(double *state, double *unused, double *out_8709668350552701868);
void car_H_27(double *state, double *unused, double *out_4765462370467170760);
void car_h_29(double *state, double *unused, double *out_828395699798652683);
void car_H_29(double *state, double *unused, double *out_2080467714352353665);
void car_h_28(double *state, double *unused, double *out_3707995082891856223);
void car_H_28(double *state, double *unused, double *out_6885519959303299249);
void car_h_31(double *state, double *unused, double *out_1097952927241981753);
void car_H_31(double *state, double *unused, double *out_2430714149646545351);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}