#ifndef PARAMWORLD_TreeObject_h
#define PARAMWORLD_TreeObject_h
#include "OculusWorldDemo.h"
#include "Kernel/OVR_Color.h"
#include <vector>

namespace ParamWorld {
	class TreeObject {
	public:
		std::vector<Ptr<Model>> Models;

		TreeObject(Vector3f root, int depth, float height, float width, float scale, float angle, OVR::Color leafColor, OVR::Color trunkColor);

	private:
		int _depth;
		float _height, _width, _scale, _splitAngle;
		OVR::Color _leafColor, _trunkColor;

		void initModels(Vector3f root, Vector3f dims, int depth, Quatf angleFromY);
	};
}

#endif
