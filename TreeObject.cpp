#include "TreeObject.h"

using namespace ParamWorld;

TreeObject::TreeObject(Vector3f root, int depth, float height, float width, 
	    float scale, float angle, OVR::Color leafColor, 
	    OVR::Color trunkColor): 
	_depth(depth),
	_height(height),
	_width(width),
	_scale(scale),
	_splitAngle(angle),
	_leafColor(leafColor),
	_trunkColor(trunkColor)
{	
	initModels(root, Vector3f(height, width, width), depth, Quatf());
}

void TreeObject::initModels(Vector3f root, Vector3f dims, int depth, Quatf angleFromY) {
	if (depth == 0) {
		Model *level0 = new Model();
		// Add one cube, the leaf color. Dimensions should be all the width, I guess.
		level0->AddBox(_leafColor, root + angleFromY.Rotate(Vector3f(0, dims.y, 0)), Vector3f(dims.y * 2, dims.y * 2, dims.y * 2));
		Models.push_back(level0);
	}
	else {
		Quatf left = Quatf(angleFromY.Rotate(Vector3f(0, 0, 1)), _splitAngle) * angleFromY;
		Model *levelX = new Model();
		levelX->AddBox(_trunkColor, root + angleFromY.Rotate(Vector3f(0, dims.y, 0)), dims);
		Models.push_back(levelX);
		initModels(root + angleFromY.Rotate(Vector3f(0, 1, 0)), dims, depth - 1, left);
	}
}
