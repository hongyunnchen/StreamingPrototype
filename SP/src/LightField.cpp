#include "LightField.hpp"
#include <iostream>

namespace SP {

	LightField::LightField() {

		// test images
		//const std::string kFilePath{ pathBase + "crown_" + std::to_string(index) + ".ppm" };

		for (size_t i = 0; i < numOfSubLFs; ++i) {
			subLFs.push_back(SubLightField(i, this->pathBase));
		}
	}

	LightField::SubLightField::SubLightField(size_t index) {

		if (numOfImgs > 0) {
			images.resize(numOfImgs);
		}

	}


	// for testing
	LightField::SubLightField::SubLightField(size_t index, const std::string & basePath) {

		std::cerr << "LOAD LF\n";

		for (size_t i = 0; i < numOfImgs; ++i) {
			//const std::string kFilePath{ basePath + "LF_crown_" + std::to_string(2 * index + i) + ".ppm" };
			const std::string kFilePath{ basePath + "LF_crown_" + std::to_string(index) + ".ppm" };
			images.push_back(ImageConfig(2 * index + i, kFilePath));
		}

		std::cerr << "LF FIN\n";

	}

	ImageConfig::ImageBuffer LightField::getSubLightFieldImages(size_t index) {

		ImageConfig::ImageBuffer buffer;

		for (size_t i = 0; i < subLFs[index].images.size(); ++i) {

			ImageConfig::ImageBuffer& imgBufferRef= subLFs[index].images[i].getImageData();
			buffer.insert(buffer.end(), imgBufferRef.begin(), imgBufferRef.end());

		}
		

		return buffer;
	}

	ImageConfig::ImageBuffer LightField::getSubLightFieldImageWithIndex(size_t subLFIdx, size_t imgIdx) {
		return subLFs[subLFIdx].images[imgIdx].getImageData();
	}

	size_t LightField::getTotalSize() const {
		return subLFs.size();
	}

	size_t LightField::getSubLightFieldSize(size_t subLFIdx) const {
		return subLFs[subLFIdx].images.size();
	}

	ImageConfig::ImageBuffer LightField::getAll() {

		ImageConfig::ImageBuffer buffer;


		for (size_t i = 0; i < subLFs.size(); ++i) {			// 3

			for (size_t j = 0; j < subLFs[i].images.size(); ++j) {		// 2

				ImageConfig::ImageBuffer& imgBufferRef = subLFs[i].images[j].getImageData();
				buffer.insert(buffer.end(), imgBufferRef.begin(), imgBufferRef.end());
				buffer.insert(buffer.end(), imgBufferRef.begin(), imgBufferRef.end());

			}


		}

	


		return buffer;
	}


	// test


	

}
