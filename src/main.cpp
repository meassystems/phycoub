/*
 * main.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: root
 */

#include <iostream>
#include <string>

#include "ElectronsInElasticCoub.h"
#include "NOCoub.h"
#include "ArCoub.h"

using namespace phycoub;

int main()
{
	/*
	try {
		ElectronsInElasticCoub electronsInElasticCoub;
		while(true){
			electronsInElasticCoub.phyCoub();
			std::cout << electronsInElasticCoub.electrons_[0].coordinate_.x_ << " ; " << electronsInElasticCoub.electrons_[0].coordinate_.y_ << " ; " << electronsInElasticCoub.electrons_[0].coordinate_.z_;
			std::cout << "	-	" <<electronsInElasticCoub.electrons_[1].coordinate_.x_ << " ; " << electronsInElasticCoub.electrons_[1].coordinate_.y_ << " ; " << electronsInElasticCoub.electrons_[1].coordinate_.z_ << std::endl;
		}
	} catch (char const * str) {
		std::cout << str;
	}

	try {
			NOCoub NOPhyCoub;
			while(true){
				NOPhyCoub.phyCoub();
				std::cout << NOPhyCoub.azot_[0].coordinate_.x_ << " ; " << NOPhyCoub.azot_[0].coordinate_.y_ << " ; " << NOPhyCoub.azot_[0].coordinate_.z_;
				std::cout << "	-	" <<NOPhyCoub.azot_[1].coordinate_.x_ << " ; " << NOPhyCoub.azot_[1].coordinate_.y_ << " ; " << NOPhyCoub.azot_[1].coordinate_.z_ << std::endl;
			}
		} catch (char const * str) {
			std::cout << str;
		}
*/
	try {
		ArCoub ArCoub;
		while(true){
			ArCoub.phyCoub();
			std::cout << ArCoub.argon_[0].coordinate_.x_ << " ; " << ArCoub.argon_[0].coordinate_.y_ << " ; " << ArCoub.argon_[0].coordinate_.z_;
			std::cout << "	-	" <<ArCoub.argon_[1].coordinate_.x_ << " ; " << ArCoub.argon_[1].coordinate_.y_ << " ; " << ArCoub.argon_[1].coordinate_.z_ << std::endl;
		}
	} catch (char const * str) {
		std::cout << str;
	}

	return 0;
}
