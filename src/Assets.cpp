#include <fstream>
#include <sstream>
#include <iostream>

#include "Assets.h"

Assets::Assets(): _filename("assets.txt"), _prefix("assets/S001/") {}

Assets::Assets(const std::string& filename): _filename(filename), _prefix("assets/") {}

Assets::~Assets() // hay que eliminar los punteros de los assets
{
    for (auto& pair : _textures) {
        // UnloadTexture(pair.second);
        UnloadTexture(*pair.second);
        delete pair.second;
    }
	for (auto& pair : _sounds) {
		// UnloadSound(pair.second);
		UnloadSound(*pair.second);
		delete pair.second;
	}
}

void Assets::load()
{
	std::ifstream file(_filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open assets file: " << _filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string config_type;
		if (iss >> config_type) {
			if (config_type == "Sound") {
				std::string name;
				std::string path;
				iss >> name >> path;
				path = _prefix + path;
				_sounds[name] = new Sound(LoadSound(path.c_str())); // se crean los assets en heap 
			}
			else if (config_type == "Texture") {
				std::string name;
				std::string path;
				// iss >> name >> path;
                iss >> name;
				path = _prefix + name + ".png";
				_textures[name] = new Texture2D(LoadTexture(path.c_str()));
			}
		}
    }

	file.close();
}