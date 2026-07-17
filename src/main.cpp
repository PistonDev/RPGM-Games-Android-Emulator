#include <raylib.h>

#include "system/extractor.hpp"
#include "engine/detect.hpp"

namespace xtr = Extractor;
namespace rpg = RPGM;

class Emulator {
private:
	rpg::Engine trg_engine;

public:
	Emulator() {
		InitWindow(800, 600, "RPGM Android Emulator");

		xtr::Extractor::InitExtract(R"(C:\Users\pisto\Downloads\Parallel Relief EN 1.7.zip)");

		trg_engine = rpg::DetectEngine(xtr::Extractor::GetArchive());
		std::cout << static_cast<int>(trg_engine) << std::endl;
	}

	void Update() {
	}

	void Draw() {

	}

	~Emulator() {
		CloseWindow();
	}
};

int main() {

	Emulator emulator;

	while (!WindowShouldClose()) {
		emulator.Update();

		BeginDrawing();
		ClearBackground(BLACK);

		emulator.Draw();

		EndDrawing();
	}

	return 0;
}