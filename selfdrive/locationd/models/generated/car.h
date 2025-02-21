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
void car_err_fun(double *nom_x, double *delta_x, double *out_5572462111588697519);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8262163926405569783);
void car_H_mod_fun(double *state, double *out_960347356571562607);
void car_f_fun(double *state, double dt, double *out_7749261609135615100);
void car_F_fun(double *state, double dt, double *out_6122738597067565141);
void car_h_25(double *state, double *unused, double *out_7161928783281413043);
void car_H_25(double *state, double *unused, double *out_1676209568443863587);
void car_h_24(double *state, double *unused, double *out_217317979340475636);
void car_H_24(double *state, double *unused, double *out_3848859167449363153);
void car_h_30(double *state, double *unused, double *out_574100856805117880);
void car_H_30(double *state, double *unused, double *out_6203905898571471785);
void car_h_26(double *state, double *unused, double *out_2030304464003579771);
void car_H_26(double *state, double *unused, double *out_5417712887317919811);
void car_h_27(double *state, double *unused, double *out_6558612898604935526);
void car_H_27(double *state, double *unused, double *out_3980311827387528568);
void car_h_29(double *state, double *unused, double *out_3610886908249450565);
void car_H_29(double *state, double *unused, double *out_5693674554257079601);
void car_h_28(double *state, double *unused, double *out_7502122751506597961);
void car_H_28(double *state, double *unused, double *out_3730044282691753350);
void car_h_31(double *state, double *unused, double *out_7647365762174116223);
void car_H_31(double *state, double *unused, double *out_6043920989551271287);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}