#ifndef PARAMWORLD_SCENEOBJECT_H
#define PARAMWORLD_SCENEOBJECT_H

#include "OculusWorldDemo.h"

namespace ParamWorld {
	class SceneObject {
	public:
		float *params;
		Vector3f rootPosition;

		SceneObject(float *params, Vector3f rootPos) : params(params), rootPosition(rootPos) {}

	};
};



#endif