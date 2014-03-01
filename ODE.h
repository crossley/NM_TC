#pragma once
/****************************************************************************************************/
/*									ODE function of the system										*/
/****************************************************************************************************/
#include "Cortical_Column.h"
#include "Thalamic_Column.h"
/****************************************************************************************************/
/*									parameters for integration of SRK4								*/
/****************************************************************************************************/
// vectors needed for stochastic RK
extern const vector<double> B1 = {0,
								  0.626708569400000081728308032325,
								  1.7296310295000001389098542858846,
		 	 	 	 	 	 	  1.2703689705000000831347506391467};
extern const vector<double> B2 = {0,
								  0.78000033203198970710445792065002,
								  1.28727807507536762265942797967,
								  0.44477273249350995909523476257164};
/****************************************************************************************************/
/*										 		end													*/
/****************************************************************************************************/


/****************************************************************************************************/
/*											ODE function											*/
/****************************************************************************************************/
// function that evaluates ODE using stochastic Runge Kutta
void ODE(Cortical_Column& C, Thalamic_Column& T) {
	// first calculating every jth RK moment
	// has to be in order, 1th moment first
	for (auto i=1; i<=4; ++i) {
		C.set_RK(i);
		T.set_RK(i);
	}

	// Adding all moments up
		C.add_RK();
		T.add_RK();
}
/****************************************************************************************************/
/*										 		end													*/
/****************************************************************************************************/