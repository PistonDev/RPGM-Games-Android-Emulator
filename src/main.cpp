#include <raylib.h>

class Emulator {
public:
	Emulator() {
		InitWindow(800, 600, "RPGM Android Emulator");
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