#include "extractor.hpp"

namespace Extractor {

	zip* Extractor::archive = nullptr;

	void Extractor::InitExtract(const std::string& zippath) {
		archive = zip_open(zippath.c_str(), 0, NULL);

		if (!archive) {
			std::cerr << "Failed to open the zip file." << std::endl;
			return;
		}
	}

	void Extractor::ReciteArchive() {
		int no_of_files = zip_get_num_entries(archive, 0);

		for (int i = 0; i < no_of_files; i++) {
			struct zip_stat fileInfo;
			zip_stat_init(&fileInfo);

			if (zip_stat_index(archive, i, 0, &fileInfo) == 0) {
				std::cout << i << " : " << fileInfo.name << std::endl;
			}
		}
	}

	zip* Extractor::GetArchive() { return archive; }
}