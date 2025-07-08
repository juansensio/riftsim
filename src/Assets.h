#pragma once

#include <map>
#include <string>
#include "raylib.h"

class Assets
{
	std::string 						_filename;
	std::string 						_prefix;
	std::map<std::string, Sound*> 		_sounds; // guardo punteros para evitar copiar assets durante la carga y acelerar el proceso de busqueda en el map
	std::map<std::string, Texture2D*> 	_textures;

public:
	Assets();
	Assets(const std::string& filename);
	~Assets();

	void load();

	const Sound& getSound(const std::string& name) const { return *_sounds.at(name); } // devuelvo referencia para evitar dereferencias constantes (así solo se hace una vez) y no se puede modificar el asset
	const Texture2D& getTexture(const std::string& name) const { return *_textures.at(name); }
	const Texture2D* getTexturePtr(const std::string& name) const { return _textures.at(name); }
};