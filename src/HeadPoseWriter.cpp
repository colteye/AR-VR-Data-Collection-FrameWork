#include "HeadPoseWriter.h"
#include <sstream>

void HeadPoseWriter::WriteHeader()
{
	header = "posX,posY,posZ\n";
	WriteToDataFile(header);
}

bool HeadPoseWriter::InitializeDataProvider()
{
	vr::EVRInitError eError = vr::VRInitError_None;
	headset = vr::VR_Init(&eError, vr::VRApplication_Background);

	// Check if vr runtime is installed and HMD is there.
	if (vr::VR_IsHmdPresent() && vr::VR_IsRuntimeInstalled()) return true;
	else return false;
}

void HeadPoseWriter::WriteData()
{
	vr::HmdMatrix34_t pose = GetPose();

	// Position in space of headset.
	float position[3] = { pose.m[0][3], pose.m[1][3], pose.m[2][3] };
	//float rotation[3];

	std::ostringstream data;
	data << position[0] << ',' << position[1] << ',' << position[2] << '\n';
	WriteToDataFile(data.str());
}

vr::HmdMatrix34_t HeadPoseWriter::GetPose()
{
	headset->GetDeviceToAbsoluteTrackingPose(vr::TrackingUniverseOrigin::TrackingUniverseStanding, 0, trackedDevicePoseArray, unTrackedDevicePoseArrayCount);
	return trackedDevicePoseArray[0].mDeviceToAbsoluteTracking;
}
