/*
 * HighSpeedModificationVerle.cpp
 *
 *  Created on: Oct 20, 2016
 *      Author: root
 */

#include <HighSpeedModificationVerle.h>
#include <algorithm>
#include <thread>
#include <functional>
#include "Vector.h"
#include "FeelField.h"

namespace phycoub {

HighSpeedModificationVerle::HighSpeedModificationVerle() {}
HighSpeedModificationVerle::~HighSpeedModificationVerle() {}

void phyCalculateThread(FeelField* feelField, int start, int end);

void HighSpeedModificationVerle::phyCalculate(FeelField* feelField) {

	int numCPU =  std::thread::hardware_concurrency() - 2;
	if(numCPU < 2 || (int)feelField->particles_.size() < numCPU * 100) {
		Vector* interworking = new Vector[feelField->particles_.size()];
		int iterator = 0;

		for_each(feelField->particles_.begin(), feelField->particles_.end(), [&](const Particle* particle) {
			interworking[iterator] = feelField->createField_->getFieldInMark(particle->coordinate_);
			++iterator;
		}
		);

		iterator = 0;
		Vector bufInterworking;
		for_each(feelField->particles_.begin(), feelField->particles_.end(), [&](Particle* particle) {
			bufInterworking = feelField->interworkingFunction_->psyForce(interworking[iterator], *particle);
			particle->speed_ += (bufInterworking + particle->interworking_) * (*feelField->dt_ / (particle->m_ * 2));
			particle->move(*feelField->dt_);

			particle->interworking_ = bufInterworking;

			++iterator;
		}
		);

		delete[] interworking;
	}
	else {
		int sizeBlockOfThread = feelField->particles_.size() / numCPU;
		std::thread* threads[numCPU];

		int start = 0, stop = start + sizeBlockOfThread;
		for(int i = 0; i < numCPU - 1; ++i) {
			threads[i] = new std::thread(phyCalculateThread, feelField, start, stop);
			start = stop;
			stop = start + i * sizeBlockOfThread;
		}
		threads[numCPU - 1] = new std::thread(phyCalculateThread, feelField, start, feelField->particles_.size());

		for(int i = 0; i < numCPU; ++i) {
			if(threads[i]->joinable()) {
				threads[i]->join();
			}
		}
		for(int i = 0; i < numCPU; ++i) {
			delete threads[i];

		}
		//delete[] threads;
	}
}

// Функция потока, для распаралеливания процесса моделировани/
void phyCalculateThread(FeelField* feelField, int start, int end) {
	Vector* interworking = new Vector[end - start];

	for(int i = start; i < end; ++i) {
		interworking[i] = feelField->createField_->getFieldInMark(feelField->particles_[i]->coordinate_);
	}

	Vector bufInterworking;
	for(int i = start; i < end; ++i) {
		bufInterworking = feelField->interworkingFunction_->psyForce(interworking[i], *feelField->particles_[i]);
		feelField->particles_[i]->speed_ += (bufInterworking + feelField->particles_[i]->interworking_) * (*feelField->dt_ / (feelField->particles_[i]->m_ * 2));
		feelField->particles_[i]->move(*feelField->dt_);
		feelField->particles_[i]->interworking_ = bufInterworking;
	}

	delete[] interworking;
}
//

} /* namespace phycoub */
