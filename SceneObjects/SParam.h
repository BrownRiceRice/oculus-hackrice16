#ifndef OVR_SParam_h
#define OVR_SParam_h

#include "SceneParams.h"

#include <algorithm>
#include <math.h>
#include <random>

using namespace OVR;

//-------------------------------------------------------------------------------------
// ***** SParam

class SParam
{
public:

	bool isIntegral;
	float min;
	float max;
	std::mt19937 randomGenerator;

	// Generates a uniform valid value
	float generateUniform(float randNum)
	{
		if (isIntegral)
		{
			return round(randNum * (max - min) + min);
		}
		return randNum * (max - min) + min;
	}

	// Generates a gaussian valid value
	float generateGaussian(float mean, float variance,
		std::normal_distribution<float> unitNormalDistribution)
	{
		std::normal_distribution<float> dist(0.0f, 1.0f);
		//WriteLog("Mean: %f, Variance: %f", mean, variance);
		float val;
		//while (((val = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * (max - min) * variance/2 + min)) > max || val < min);

		while ((val = unitNormalDistribution(randomGenerator) * (max - min) / 2 * variance + mean) > max ||
			val < min);

		//WriteLog("Val: %f", val);
		if (isIntegral)
		{
			return round(val);
		}

		return val;
	}

	// Constructor
	SParam(bool _isIntegral, float _min, float _max) : randomGenerator()
	{
		randomGenerator.seed(((unsigned int)time(NULL)));
		isIntegral = _isIntegral;
		min = _min;
		max = _max;
	}

	~SParam() {}
};

#endif // OVR_SParam_h
