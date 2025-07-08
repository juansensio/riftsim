#include "SceneDecks.h"
#include "../GameEngine.h"

SceneDecks::SceneDecks(GameEngine& game_engine)
	: Scene(game_engine) 
	, _card(nullptr)
	{}

SceneDecks::~SceneDecks() {}

void SceneDecks::init()
{
	_card = Card(_entity_manager.addEntity(EntityType::CARD));  
	_card.init();
}

void SceneDecks::update()
{
	_entity_manager.update();
}

void SceneDecks::render()
{
	for (auto& entity : _entity_manager.getEntities()) {
		if (entity->has<CSprite>()) {
			const auto& sprite = entity->get<CSprite>();
			DrawTexturePro(
				*sprite.texture, 
				sprite.source_rect, 
				Rectangle{
					(GetScreenWidth() - sprite.width) / 2.0f,
					(GetScreenHeight() - sprite.height) / 2.0f,
					sprite.width,
					sprite.height
				},
				Vector2{0, 0},
				0, 
				sprite.color
			);
		}
	}
}

// void SceneMenu::doAction(const Action& action)
// {
// }