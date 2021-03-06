#ifndef _SP_CAMERA_HPP_
#define _SP_CAMERA_HPP_

#include "SceneObject.hpp"

#include "math/mathutils.h"

namespace SP {



	class Camera : public SceneObject {
	public:
		Camera() = default;
		virtual ~Camera() = default;
	};


	class PerspectiveCamera : public Camera {
	public:
		// camera position, camera look at, up vector
		PerspectiveCamera(RadeonRays::float3 const& eye, RadeonRays::float3 const& at, RadeonRays::float3 const& up);

		void setFocusDistance(float distance);
		float getFocusDistance() const;

		void setAperture(float aperture);
		float getAperture() const;

		void setSensorSize(RadeonRays::float2 const& size);
		RadeonRays::float2 getSensorSize() const;

		void setFocalLength(float length);
		float getFocalLength() const;

		void setDepthRange(RadeonRays::float2 const& range);
		RadeonRays::float2 getDepthRange() const;

		RadeonRays::float3 getForwardVector() const;
		RadeonRays::float3 getRightVector() const;
		RadeonRays::float3 getUpVector() const;
		RadeonRays::float3 getPosition() const;
		float getAspectRatio() const;


		// trans

		void rotate(float angle);

	private:


		// Camera coordinate
		RadeonRays::float3 forwardVec;
		RadeonRays::float3 rightVec;
		RadeonRays::float3 upVec;
		RadeonRays::float3 position;

		// Image plane width & hight in scene units
		RadeonRays::float2 dim;


		// Near and far Z
		RadeonRays::float2 zcap;

		float focalLength;
		float aspect;
		float focusDistance;
		float aperture;

	};


}




#endif


