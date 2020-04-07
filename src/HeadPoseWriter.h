#ifndef HEADPOSEWRITER_H_   /* Include guard */
#define HEADPOSEWRITER_H_
#pragma once

#include "DataWriter.h"
#include <openvr.h>
#pragma comment (lib, "openvr_api.lib")

class HeadPoseWriter : public DataWriter
{
public:
	void WriteData();

protected:
	void WriteHeader();
	bool InitializeDataProvider();

private:
	vr::IVRSystem* headset;
	uint32_t unTrackedDevicePoseArrayCount = vr::k_unMaxTrackedDeviceCount;
	vr::TrackedDevicePose_t trackedDevicePoseArray[vr::k_unMaxTrackedDeviceCount];
	vr::HmdMatrix34_t GetPose();
};

#endif // HEADPOSEWRITER_H_
