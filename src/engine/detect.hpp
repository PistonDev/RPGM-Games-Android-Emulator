#include <zip.h>

namespace RPGM {

	enum class Engine {
		UNKNOWN = -1,

		MV		= 0,
		MZ		= 1,
			
		VX		= 2,
		VX_ACE	= 3,

		XP		= 4
	};

	Engine DetectEngine(zip* archive);

}