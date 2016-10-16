#ifndef OVR_SceneObject_h
#define OVR_SceneObject_h

#include "Kernel/OVR_Types.h"
#include "Kernel/OVR_Allocator.h"
#include "Kernel/OVR_RefCount.h"
#include "Kernel/OVR_System.h"
#include "Kernel/OVR_Nullptr.h"
#include "Kernel/OVR_Timer.h"
#include "Kernel/OVR_SysFile.h"
#include "Extras/OVR_Math.h"

#include <vector>
#include <string>

#include "SceneParams.h"

using namespace OVR;


//-------------------------------------------------------------------------------------
// ***** SceneObject

class SceneObject
{
public:
	Vector3f BodyPos;
	SceneParams Params;

	SceneObject(SceneParams params);
	~SceneObject();
};

#endif // OVR_SceneObject_h
