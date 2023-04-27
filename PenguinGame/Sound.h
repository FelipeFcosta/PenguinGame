#pragma once
#ifndef SOUND_H
#define SOUND_H

#include <string>
#include "Component.h"
#include "GameObject.h"
#include <SDL_mixer.h>

class Sound : public Component
{
public:
    Sound(GameObject& associated);
    Sound(GameObject& associated, std::string file);
    ~Sound();
    void Play(int times = 1);
    void Stop();
    void Open(std::string file);
    bool IsOpen();
    bool IsPlaying();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
private:
    Mix_Chunk* chunk;
    int channel;
};

#endif // SOUND_H