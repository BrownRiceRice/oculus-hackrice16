#ifndef OVR_SceneParams_h
#define OVR_SceneParams_h

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

using namespace OVR;

//-------------------------------------------------------------------------------------
// ***** SceneParams

class SceneParams
{
public:

	// Colors
	float RedMean;
	float RedVariance;
	float BlueMean;
	float BlueVariance;
	float GreenMean;
	float GreenVariance;
	float AlphaMean;
	float AlphaVariance;

	// Dimensions
	float Diameter;
	float Height;
	float Thickness;

	// Miscelleneaous
	float BranchingFactor;

	SceneParams();
	~SceneParams();
};

#endif // OVR_SceneParams_h
