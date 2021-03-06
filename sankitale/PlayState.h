#pragma once

#include "GameState.h"

class PlayState : public GameState
{
public:
	void enter(void);
	void exit(void);

	void pause(void);
	void resume(void);

	bool frameStarted(GameManager* game, const Ogre::FrameEvent& evt);
	bool frameEnded(GameManager* game, const Ogre::FrameEvent& evt);

	bool mouseMoved(GameManager* game, const OIS::MouseEvent &e);
	bool mousePressed(GameManager* game, const OIS::MouseEvent &e, OIS::MouseButtonID id);
	bool mouseReleased(GameManager* game, const OIS::MouseEvent &e, OIS::MouseButtonID id);

	bool keyPressed(GameManager* game, const OIS::KeyEvent &e);
	bool keyReleased(GameManager* game, const OIS::KeyEvent &e);

	static PlayState* getInstance() { return &mPlayState; }

	bool beInRange(Ogre::Vector3 me, Ogre::Vector3 other);
	void setAnimState(Ogre::AnimationState* anim) { mAnimationState = anim; }
private:

	void _setLights(void);
	void _drawGroundPlane(void);
	void _drawGridPlane(void);


	static PlayState mPlayState;
	Ogre::Vector3 mCharacterDirection;
	Ogre::Root *mRoot;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager* mSceneMgr;
	Ogre::Camera* mCamera;

	Ogre::Light *mLightP, *mLightD, *mLightS;

	Ogre::SceneNode* mCharacterRoot;
	Ogre::SceneNode* mCharacterYaw;
	Ogre::SceneNode* mSavePointRoot;
	Ogre::SceneNode* mCameraHolder;
	Ogre::SceneNode* mCameraYaw;
	Ogre::SceneNode* mCameraPitch;
	Ogre::SceneNode* mGroundNode;;
	Ogre::SceneNode* mBrickNode;
	Ogre::SceneNode* mBrickNode2;
	Ogre::SceneNode* mPortalNode;
	Ogre::SceneNode* mDoorNode;

	Ogre::Entity* mCharacterEntity;
	Ogre::Entity* mSavePointEntity;
	Ogre::Entity* mDoorEntity;
	Ogre::AnimationState* mAnimationState;
	short mAnimationOperation;
	enum{WALK,IDLE};

	Ogre::Overlay*           mInformationOverlay;

	bool mContinue;
};