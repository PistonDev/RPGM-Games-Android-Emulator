#include <zip.h>
#include <string>
#include <iostream>

namespace Extractor {

	class Extractor {
	private:
		static zip* archive;

	public:
		static void InitExtract(const std::string& zippath);
		static void ReciteArchive();
		static zip* GetArchive();

		~Extractor() { zip_close(archive); }
	};
}