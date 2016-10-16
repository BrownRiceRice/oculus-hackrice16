#ifndef PARAMWORLD_RockObject_H
#define PARAMWORLD_RockObject_H

#include "OculusWorldDemo.h"

namespace ParamWorld {
	class RockObject {
	public:
		Ptr<Model> ModelX;

		// Forcing it to be on the ground.
		RockObject(int depth, OVR::Color color, Vector2f a, Vector2f b, Vector2f c);

	private:
		int _depth;
		OVR::Color _color;

		void Init(int depth, Vector3f a, Vector3f b, Vector3f c);

		Vector3f sampleInTri(Vector3f a, Vector3f b, Vector3f c);
	};
}
#endif

