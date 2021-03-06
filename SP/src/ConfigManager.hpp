#ifndef _SP_CONFIGMANAGER_HPP_
#define _SP_CONFIGMANAGER_HPP_

#include "Common.hpp"

#include <vector>

#include "SyncBuffer.hpp"
#include "Encoder/Encoder.hpp"
#include "LightField.hpp"

namespace SP {

	class ConfigManager {


	public:
		ConfigManager(SyncBuffer<ImageConfig>& buffer, LightField& imgLF);

		CameraConfig getCamera();

		void setScreen(uint32_t w, uint32_t h);
		ScreenConfig getScreen();

		void setModuleID(uint32_t mID);

		void setPositionDelta(float dx, float dy, float dz);

		//const ImageConfig& getImageRef(size_t index);

		ImageConfig getImage();
		ImageConfig getImageCache();


		// LF indexing
		size_t getIndexOfSubLightField(float dx) const;


		// Light Field
		size_t getSubLightFieldSize(size_t subLFIdx) const;
		ImageConfig::ImageBuffer getSubLightFieldImageWithIndex(size_t subLFIdx, size_t imgIdx);

		bool getSubLightFieldRefreshState(std::size_t subLFIdx) const;
		void setSubLightFieldRefreshState(std::size_t subLFIdx, bool state);

		// Encoder
		Encoder* getEncoder();

		~ConfigManager();

		// tmp
		//void loadImages();

	private:

		uint32_t moduleID = 0;

		CameraConfig cameraCfg;
		ScreenConfig screenCfg;

		// could be used as a cache, but we disable it right now
		//std::vector<ImageConfig> images;

		// cache for current image
		SyncBuffer<ImageConfig>::DataPointer imagePtr{ new ImageConfig };

		// timer linit, wait no longer than this
		const int kTimeLimit = 10;

		SyncBuffer<ImageConfig>& bufferRef;

		LightField& imageLightFieldRef;

		Encoder* encoder;


	};



}












#endif









