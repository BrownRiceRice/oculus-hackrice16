#include "RockObject.h"

using namespace ParamWorld;

// Forcing it to be on the ground.
RockObject::RockObject(int depth, OVR::Color color, Vector2f a, Vector2f b, Vector2f c) : _depth(depth), _color1(color) {
	ModelX = *new Model();
	Init(depth, Vector3f(a.x, 0, a.y), Vector3f(b.x, 0, b.y), Vector3f(c.x, 0, c.y));
	_color2 = Color((unsigned char)std::min(color.R + SHADE, 255), (unsigned char)std::min(color.G + SHADE, 255), (unsigned char) std::min(color.B + SHADE, 255), (unsigned char) 255);
	_color3 = Color((unsigned char)std::max(color.R - SHADE, 0), (unsigned char)std::max(color.G - SHADE, 0), (unsigned char)std::max(color.B - SHADE, 0), (unsigned char) 255);
}

void RockObject::Init(int depth, Vector3f a, Vector3f b, Vector3f c) {
	// Select a point slightly off the triangle.
	Vector3f finalPt = sampleInTri(a, b, c);
	finalPt.y = (finalPt.y > 0) ? finalPt.y : 0;
	// Add the tetra to the rock.
	int best = rand() % 3;
	Color _color;
	switch (best) {
	case 0:
		_color = _color1;
		break;
	case 1:
		_color = _color2;
		break;
	case 2: 
		_color = _color3;
		break;
	}
	ModelX->AddTetra(_color, finalPt, a, b, c);

	if (depth == 0) {
		return;
	}
	else {
		Init(depth - 1, finalPt, a, b);
		Init(depth - 1, finalPt, b, c);
		Init(depth - 1, finalPt, c, a);
	}
}

Vector3f RockObject::sampleInTri(Vector3f a, Vector3f b, Vector3f c) {
	float u, v;
	do {
		u = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		v = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	} while (u + v > 1);
	Vector3f p =  ((b - a) * u + (c - a) * v) + a;
	float w = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	Vector3f n = (b - a).Cross((c - a));
	float area = n.Length() / 2;

	n.Normalize();

	return p + (n * (sqrt(area) * w));
}

