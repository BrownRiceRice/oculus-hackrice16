#ifndef PARAMWORLD_RockObject_H
#define PARAMWORLD_RockObject_H

#include "OculusWorldDemo.h"
#include <math.h>
#include <algorithm>

#define SHADE 20

namespace ParamWorld {
	class RockObject {
	public:
		Ptr<Model> ModelX;

		// Forcing it to be on the ground.
		RockObject(int depth, OVR::Color color, Vector2f a, Vector2f b, Vector2f c, float heightMult);

	private:
		int _depth;
		float _heightMult;
		OVR::Color _color1, _color2, _color3;

		void Init(int depth, Vector3f a, Vector3f b, Vector3f c);

		Vector3f sampleInTri(Vector3f a, Vector3f b, Vector3f c);
	};
}
#endif

