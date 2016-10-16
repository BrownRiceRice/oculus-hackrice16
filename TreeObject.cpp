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
	_trunkColor(trunkColor), 
	ModelX(new Model())
{	
	initModels(root, Vector3f(width, height, width), depth, Quatf(0, 0, 0, 1));
}

void TreeObject::initModels(Vector3f root, Vector3f dims, int depth, Quatf angleFromY) {
	if (depth == 0) {
		// Add one cube, the leaf color. Dimensions should be all the width, I guess.
		ModelX->AddBox(_leafColor, root + angleFromY.Rotate(Vector3f(0, dims.x, 0)), Vector3f(dims.y * 2, dims.x * 2, dims.y * 2), angleFromY);
		//WriteLog("Hit base case: new leaf at %f, %f, %f", root.x, root.y, root.z);
	}
	else {
		Vector3f newZ = angleFromY.Rotate(Vector3f(0, 0, 1));
		Vector3f newY = angleFromY.Rotate(Vector3f(0, 1, 0));
		//Quatf left = Quatf((Quatf(newZ, _splitAngle) * angleFromY) , 0); // MATH_FLOAT_PI / 2);
		ModelX->AddBox(_trunkColor, root + angleFromY.Rotate(Vector3f(0, dims.y / 2, 0)), dims, angleFromY);
		Quatf left = Quatf(newZ, _splitAngle) * Quatf(newY, MATH_FLOAT_PI/2) * angleFromY;
		Quatf right = Quatf(newZ, -_splitAngle) * Quatf(newY, -MATH_FLOAT_PI/2) * angleFromY;
		Vector3f newRoot = root + angleFromY.Rotate(Vector3f(0, dims.y, 0));
		initModels(newRoot, dims * _scale, depth - 1, left);
		initModels(newRoot, dims * _scale, depth - 1, right);
	}
}
