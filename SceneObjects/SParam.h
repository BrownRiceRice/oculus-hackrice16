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
	float generateGaussian(float mean, float variance, std::mt19937 randomGenerator,
		std::normal_distribution<float> unitNormalDistribution)
	{
		float val;
		while ((val = unitNormalDistribution(randomGenerator) * variance + mean) > max ||
			val < min);

		if (isIntegral)
		{
			return round(val);
		}
		return val;
	}

	// Constructor
	SParam(bool _isIntegral, float _min, float _max)
	{
		isIntegral = _isIntegral;
		min = _min;
		max = _max;
	}

	~SParam() {}
};

#endif // OVR_SParam_h
