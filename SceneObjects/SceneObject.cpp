

#include "SceneObject.h"
#include "SceneParams.h"
#include <iostream>


SceneObject::SceneObject(SceneParams params):
    BodyPos(7.7f, 1.76f - 0.15f, -1.0f),
	Params(params)
{
}

SceneObject::~SceneObject()
{
}

