#include "detect.hpp"
#include "../system/extractor.hpp"

#include <string>
#include <iostream>

using zint = zip_int64_t;

namespace RPGM {

	Engine DetectEngine(zip* archive) {
		zint no_of_files = zip_get_num_entries(archive, 0);

		for (zint i = 0; i < no_of_files; i++) {
			struct zip_stat fileInfo;

			zip_stat_init(&fileInfo);

			if (zip_stat_index(archive, i, 0, &fileInfo) == 0) {
				const std::string& fname = fileInfo.name;

				if (fname.find("www/") != std::string::npos) {
					return Engine::MV;
				}

				if (fname.find("js/") != std::string::npos) {
					return Engine::MZ;
				}

				if (fname.find("RGSS102E.dll") != std::string::npos) {
					return Engine::XP;
				}

				if (fname.find("RGSS202E.dll") != std::string::npos) {
					return Engine::VX;
				}

				if (fname.find("RGSS301.dll") != std::string::npos) {
					return Engine::VX_ACE;
				}
			}

		}

		return Engine::UNKNOWN;
	}

}