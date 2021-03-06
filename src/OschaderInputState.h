#pragma once

#include "InputResolver.h"

static const int AUDIO_TEXTURE = 0;
static const int CAMERA_TEXTURE = 1;
static const int KICK = 2;
static const int EQ_TEXTURE = 3;
static const int VOLUME = 4;

struct InputState {
	ci::gl::TextureRef audioTexture;
	ci::gl::TextureRef cameraTexture;
	float volume;
	float kick;
	std::function<ci::gl::TextureRef(int)> eqTexture;
};

class OschaderInputResolver : public input::InputResolver {
public:
	virtual void update(InputState state);
	virtual int parseInputType(std::string type);
	virtual bool isTexture(int inputType);
	virtual bool isFloat(int inputType);
	virtual float getFloat(int inputType);
	virtual ci::gl::TextureRef getTexture(int inputType, float mod);

private:
	InputState mState;
};