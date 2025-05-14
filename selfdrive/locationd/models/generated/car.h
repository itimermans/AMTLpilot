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
void car_err_fun(double *nom_x, double *delta_x, double *out_3712298530660200368);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1585390793410116901);
void car_H_mod_fun(double *state, double *out_7492711310731175134);
void car_f_fun(double *state, double dt, double *out_1912712957534596757);
void car_F_fun(double *state, double dt, double *out_6070284381192909234);
void car_h_25(double *state, double *unused, double *out_163645903678262497);
void car_H_25(double *state, double *unused, double *out_6159201920050507373);
void car_h_24(double *state, double *unused, double *out_1223586909973532045);
void car_H_24(double *state, double *unused, double *out_3986552321045007807);
void car_h_30(double *state, double *unused, double *out_438839965962768386);
void car_H_30(double *state, double *unused, double *out_8677534878557756000);
void car_h_26(double *state, double *unused, double *out_3043245286771466037);
void car_H_26(double *state, double *unused, double *out_2417698601176451149);
void car_h_27(double *state, double *unused, double *out_991195736529219316);
void car_H_27(double *state, double *unused, double *out_543257721877525736);
void car_h_29(double *state, double *unused, double *out_1042155850639245903);
void car_H_29(double *state, double *unused, double *out_2141736934237291359);
void car_h_28(double *state, double *unused, double *out_6869481224087934404);
void car_H_28(double *state, double *unused, double *out_4105367205802617610);
void car_h_31(double *state, double *unused, double *out_3473803624575759853);
void car_H_31(double *state, double *unused, double *out_1791490498943099673);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}