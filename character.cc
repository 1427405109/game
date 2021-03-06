#include "character.hpp"
#include <iostream>

Character::Character(int width, int height) : CHARACTER_WIDTH(width), CHARACTER_HEIGHT(height){
	//Initialize the collision box
	mPosX = CHARACTER_WIDTH + TILE_WIDTH;
	mPosY = 0;

	mBox.x = 0;
	mBox.y = 0;
	mBox.w = CHARACTER_WIDTH;
	mBox.h = CHARACTER_HEIGHT;
	mWeapon = mBox;
	isJumping = false;
	isMoving = false;
	isAttacking = false;
	headJump = false;
	//npcStabbed = 0;
	flip = SDL_FLIP_NONE;
	attackingFrame = 0;
	walkingFrame = 0;
	fallingFrame = 3;
	frameRate = 40;

	//Load character texture
	if(!characterTexture.loadFromFile("zerowalk.png")) {
		printf("Failed to load character texture!\n");
	}
	else {

		// Walking.
		spriteClips[0].x = 1;
		spriteClips[0].y = 1;
		spriteClips[0].w = 36;
		spriteClips[0].h = 48;

		spriteClips[1].x = 39;
		spriteClips[1].y = 1;
		spriteClips[1].w = 38;
		spriteClips[1].h = 48;

		spriteClips[2].x = 79;
		spriteClips[2].y = 1;
		spriteClips[2].w = 46;
		spriteClips[2].h = 48;

		spriteClips[3].x = 129;
		spriteClips[3].y = 1;
		spriteClips[3].w = 44;
		spriteClips[3].h = 48;

		spriteClips[4].x = 175;
		spriteClips[4].y = 1;
		spriteClips[4].w = 40;
		spriteClips[4].h = 48;

		spriteClips[5].x = 223;
		spriteClips[5].y = 1;
		spriteClips[5].w = 45;
		spriteClips[5].h = 48;

		spriteClips[6].x = 269;
		spriteClips[6].y = 1;
		spriteClips[6].w = 49;
		spriteClips[6].h = 48;

		spriteClips[7].x = 321;
		spriteClips[7].y = 1;
		spriteClips[7].w = 45;
		spriteClips[7].h = 48;

		spriteClips[8].x = 368;
		spriteClips[8].y = 1;
		spriteClips[8].w = 50;
		spriteClips[8].h = 48;

		spriteClips[9].x = 422;
		spriteClips[9].y = 1;
		spriteClips[9].w = 46;
		spriteClips[9].h = 48;

		spriteClips[10].x = 470;
		spriteClips[10].y = 1;
		spriteClips[10].w = 43;
		spriteClips[10].h = 48;

		spriteClips[11].x = 516;
		spriteClips[11].y = 1;
		spriteClips[11].w = 42;
		spriteClips[11].h = 48;

		spriteClips[12].x = 561;
		spriteClips[12].y = 1;
		spriteClips[12].w = 45;
		spriteClips[12].h = 48;

		spriteClips[13].x = 607;
		spriteClips[13].y = 1;
		spriteClips[13].w = 48;
		spriteClips[13].h = 48;

		spriteClips[14].x = 661;
		spriteClips[14].y = 1;
		spriteClips[14].w = 48;
		spriteClips[14].h = 48;

		spriteClips[15].x = 711;
		spriteClips[15].y = 1;
		spriteClips[15].w = 50;
		spriteClips[15].h = 48;

		// Jumping.
		jumpClips[0].x = 1;
		jumpClips[0].y = 70;
		jumpClips[0].w = 39;
		jumpClips[0].h = 48;
		
		jumpClips[1].x = 46;
		jumpClips[1].y = 66;
		jumpClips[1].w = 44;
		jumpClips[1].h = 56;
		
		jumpClips[2].x = 97;
		jumpClips[2].y = 66;
		jumpClips[2].w = 43;
		jumpClips[2].h = 56;
		
		jumpClips[3].x = 150;
		jumpClips[3].y = 65;
		jumpClips[3].w = 43;
		jumpClips[3].h = 57;
		
		jumpClips[4].x = 200;
		jumpClips[4].y = 65;
		jumpClips[4].w = 43;
		jumpClips[4].h = 56;
		
		jumpClips[5].x = 250;
		jumpClips[5].y = 65;
		jumpClips[5].w = 39;
		jumpClips[5].h = 52;

		fallClips[0].x = 250;
		fallClips[0].y = 65;
		fallClips[0].w = 39;
		fallClips[0].h = 52;

		fallClips[1].x = 295;
		fallClips[1].y = 65;
		fallClips[1].w = 40;
		fallClips[1].h = 55;

		fallClips[2].x = 340;
		fallClips[2].y = 65;
		fallClips[2].w = 36;
		fallClips[2].h = 64;

		fallClips[3].x = 385;
		fallClips[3].y = 56;
		fallClips[3].w = 35;
		fallClips[3].h = 77;

		fallClips[4].x = 430;
		fallClips[4].y = 56;
		fallClips[4].w = 35;
		fallClips[4].h = 79;

		fallClips[5].x = 475;
		fallClips[5].y = 71;
		fallClips[5].w = 40;
		fallClips[5].h = 59;

		attackClips[0].x = 7;
		attackClips[0].y = 173;
		attackClips[0].w = 39;
		attackClips[0].h = 46;

		attackClips[1].x = 52;
		attackClips[1].y = 169;
		attackClips[1].w = 46;
		attackClips[1].h = 50;

		attackClips[2].x = 102;
		attackClips[2].y = 158;
		attackClips[2].w = 49;
		attackClips[2].h = 63;

		attackClips[3].x = 157;
		attackClips[3].y = 158;
		attackClips[3].w = 78;
		attackClips[3].h = 62;

		attackClips[4].x = 242;
		attackClips[4].y = 158;
		attackClips[4].w = 87;
		attackClips[4].h = 60;

		attackClips[5].x = 337;
		attackClips[5].y = 170;
		attackClips[5].w = 91;
		attackClips[5].h = 48;

		attackClips[6].x = 437;
		attackClips[6].y = 169;
		attackClips[6].w = 83;
		attackClips[6].h = 49;

		attackClips[7].x = 527;
		attackClips[7].y = 173;
		attackClips[7].w = 70;
		attackClips[7].h = 45;

		attackClips[8].x = 607;
		attackClips[8].y = 173;
		attackClips[8].w = 59;
		attackClips[8].h = 45;

		attackClips[9].x = 677;
		attackClips[9].y = 172;
		attackClips[9].w = 52;
		attackClips[9].h = 45;

		attackClips[10].x = 737;
		attackClips[10].y = 172;
		attackClips[10].w = 45;
		attackClips[10].h = 45;

		attackClips[11].x = 802;
		attackClips[11].y = 170;
		attackClips[11].w = 49;
		attackClips[11].h = 45;

		secondAttackClips[0].x = 5;
		secondAttackClips[0].y = 228;
		secondAttackClips[0].w = 66;
		secondAttackClips[0].h = 45;

		secondAttackClips[1].x = 80;
		secondAttackClips[1].y = 228;
		secondAttackClips[1].w = 83;
		secondAttackClips[1].h = 45;

		secondAttackClips[2].x = 170;
		secondAttackClips[2].y = 228;
		secondAttackClips[2].w = 103;
		secondAttackClips[2].h = 45;

		secondAttackClips[3].x = 285;
		secondAttackClips[3].y = 228;
		secondAttackClips[3].w = 67;
		secondAttackClips[3].h = 46;

		secondAttackClips[4].x = 360;
		secondAttackClips[4].y = 228;
		secondAttackClips[4].w = 63;
		secondAttackClips[4].h = 46;

		secondAttackClips[5].x = 428;
		secondAttackClips[5].y = 228;
		secondAttackClips[5].w = 53;
		secondAttackClips[5].h = 46;

		secondAttackClips[6].x = 490;
		secondAttackClips[6].y = 228;
		secondAttackClips[6].w = 49;
		secondAttackClips[6].h = 45;

		secondAttackClips[7].x = 560;
		secondAttackClips[7].y = 228;
		secondAttackClips[7].w = 44;
		secondAttackClips[7].h = 46;

		secondAttackClips[8].x = 610;
		secondAttackClips[8].y = 228;
		secondAttackClips[8].w = 41;
		secondAttackClips[8].h = 46;

		secondAttackClips[9].x = 659;
		secondAttackClips[9].y = 228;
		secondAttackClips[9].w = 43;
		secondAttackClips[9].h = 46;

		/*
		for(int i = 0; i < ANIMATION_FRAMES; ++i) {
			spriteClips[i].x = x;
			spriteClips[i].y = y;
			spriteClips[i].w = CHARACTER_WIDTH;
			spriteClips[i].h = CHARACTER_HEIGHT;

			x += CHARACTER_WIDTH + 1;
			if(x >=  SPRITESHEET_WIDTH) {
				x = 0;
				y += CHARACTER_HEIGHT;
			}
		}
		*/
		/*
		if(ATTACKING_FRAMES > 0) {
			x = 0;
			y = 0;
			for(int i =	0; i < ATTACKING_FRAMES; ++i) {
				spriteClips[i].x = x;
				spriteClips[i].y = y;
				spriteClips[i].w = 50;
				spriteClips[i].h = 50;

				x += CHARACTER_WIDTH;
				if(x >= SPRITESHEET_WIDTH) {
					x = 0;
					y += CHARACTER_HEIGHT;
				}
			}
		}
		*/
	}
	currentClip = &spriteClips[0];

	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;

	// Initialize the particles.
	for(int i = 0; i < TOTAL_PARTICLES; ++i) {
		particles[i] = new Particle(mPosX, mPosY, mBox);
	}

}

void Character::renderParticles(SDL_Rect &camera, bool toggleParticles) {
	if(toggleParticles) {
		// Go through particles.
		for(int i = 0; i < TOTAL_PARTICLES; ++i) {

			if(particles[i] != NULL) {
				if(particles[i]->isDead()) {
					delete particles[i];
					//if(camera.x > 0 && camera.x < LEVEL_WIDTH - camera.w) {
					//std::cout << "hit " << mPosX << std::endl;
					//particles[i] = new Particle((SCREEN_WIDTH / 2) - (CHARACTER_WIDTH / 2), mPosY - camera.y);
					//}
					//else 
					particles[i] = new Particle(mPosX - camera.x, mPosY - camera.y, mBox);
				}
			}
			else {
				particles[i] = new Particle(mPosX - camera.x, mPosY - camera.y, mBox);
			}
		}

		// Show particles.
		for(int i = 0; i < TOTAL_PARTICLES; ++i) {
			particles[i]->render();
		}
	}
	else {
		// Delete and replace dead particles.
		for(int i = 0; i < TOTAL_PARTICLES; ++i) {
			delete particles[i];
			particles[i] = NULL;
		}
	}
}

void Character::handleEvent(SDL_Event &e) {
	//If a key was pressed

	if(e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		//Adjust the velocity
		switch(e.key.keysym.sym) {
			case SDLK_SPACE: 
				//if(!isJumping) {
				mVelY = 0; 
				mVelY -= CHARACTER_VELY; 
				//}
				break;
			case SDLK_w: 
				mVelY -= CHARACTER_VELY;
				break;
			case SDLK_s: 
				mVelY += CHARACTER_VELY;
				break;
			//case SDLK_DOWN: mVelY += CHARACTER_VELY; break;
			case SDLK_a: 
				mVelX -= CHARACTER_VELX; 
				break;
			case SDLK_d: 
				mVelX +=  CHARACTER_VELX; 
				break;
			default:
				break;
			case SDLK_f:
				if(attackingFrame >= 8 && attackingFrame < ATTACKING_FRAMES) {
					secondAttack = true;
				}
				else if(secondAttack == false) isAttacking = true;
				break;
		}
	}
	//If a key was released
	else if(e.type == SDL_KEYUP && e.key.repeat == 0) {
		//Adjust the velocity
		switch(e.key.keysym.sym) {
			case SDLK_w: mVelY += CHARACTER_VELY; break;
			case SDLK_s: mVelY -= CHARACTER_VELY; break;
			//case SDLK_DOWN: mVelY -= CHARACTER_VELY; break;
			case SDLK_a: mVelX += CHARACTER_VELX; break; 
			case SDLK_d: mVelX -= CHARACTER_VELX; break; 
			default: break;
		}
	}
}

Character::~Character() {
	// Delete particles.
	for(int i = 0; i < TOTAL_PARTICLES; ++i) {
		delete particles[i];
	}
}

void Character::move(Tile *tiles[], std::vector<Npc *> &npcVector, float timeStep) {

	int tileTouched, npcTouched;

	//Move the character left or right
	mPosX += mVelX * timeStep;

	//If the character went too far to the left or right or touched a wall
	if((mPosX < 0) || (mPosX + CHARACTER_WIDTH > LEVEL_WIDTH)) {
		//move back
		if(mPosX < 0) {
			mPosX = 0;
		}
		else {
			mPosX = LEVEL_WIDTH - CHARACTER_WIDTH;
		}
	}
	mBox.x = mPosX;
	mWeapon.x = mPosX;
	tileTouched = touchesWall(mBox, tiles);
	/*
	if(tileTouched > -1 && tiles[tileTouched]->diagonalTile && mPosX > tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].x) {
		mPosX = tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].x + tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].w;
	}
	*/
	if(tileTouched > -1 && tiles[tileTouched]->diagonalTile && mPosY > tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y) {
		mPosY = tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y + tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].h;
		mPosX = tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].x - tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].w;
	}
	else if(tileTouched > -1 && mPosX < tiles[tileTouched]->getBox().x) {
		if(tiles[tileTouched]->topHalf) mPosX = tiles[tileTouched]->getCollisionBox().x - CHARACTER_WIDTH;
		else if(tiles[tileTouched]->diagonalTile && !(mPosY > tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y)) {
			//std::cout << "hit!" << std::endl;
			mPosY = tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y - CHARACTER_HEIGHT;
		}
		else mPosX = tiles[tileTouched]->getBox().x - CHARACTER_WIDTH;
	}
	else if(tileTouched > -1 && mVelX < 0) {
		if(tiles[tileTouched]->topHalf) mPosX = tiles[tileTouched]->getCollisionBox().x + TILE_WIDTH;
		else if(tiles[tileTouched]->diagonalTile && mPosY < tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y) {
			std::cout << tiles[tileTouched]->pixelTouched << std::endl;
			//std::cout << "hit!" << std::endl;
			mPosY = tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y - tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].h;
		}
		else if(tiles[tileTouched]->diagonalTile && mPosY > tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y) {
			mPosY = tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y + tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].h;
			mPosX = tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].x - tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].w;
		}
		else mPosX = tiles[tileTouched]->getBox().x + TILE_WIDTH;
	}

	if(isAttacking && flip == SDL_FLIP_NONE) mWeapon.x = mPosX + 50;
	else if(isAttacking && flip == SDL_FLIP_HORIZONTAL) mWeapon.x = mPosX - 50;
	npcTouched = touchesNpc(mWeapon, npcVector);
	// Handle weapon.
	if(npcTouched > -1 && isAttacking && flip == SDL_FLIP_NONE && (attackingFrame >= 4 && attackingFrame <= 7)) {
		npcVector[npcTouched]->wasStabbed = true;
		npcVector[npcTouched]->setVelocityX(15 * 60);
		npcVector[npcTouched]->wasAttackedTimer.start();
	}
	else if(npcTouched > -1 && isAttacking && flip == SDL_FLIP_HORIZONTAL && (attackingFrame >= 4 && attackingFrame <= 7)) {
		npcVector[npcTouched]->wasStabbed = true;
		npcVector[npcTouched]->setVelocityX(-15 * 60);
		npcVector[npcTouched]->wasAttackedTimer.start();
	}

	// Handle character.
	npcTouched = touchesNpc(mBox, npcVector);
	if(npcTouched > -1 && mVelX > 0) {
		mPosX = npcVector[npcTouched]->getPosX() - CHARACTER_WIDTH;
		/*
		if(isAttacking) {
			npcVector[npcTouched]->wasStabbed = true;
			npcVector[npcTouched]->setVelocityX(15 * 60);
			npcVector[npcTouched]->wasAttackedTimer.start();
		}
		*/
	}
	if(npcTouched > -1 && mVelX < 0) {
		mPosX = npcVector[npcTouched]->getPosX() + npcVector[npcTouched]->NPC_WIDTH;
		/*
		if(isAttacking) {
			npcVector[npcTouched]->wasStabbed = true;
			npcVector[npcTouched]->setVelocityX(-15 * 60);
			npcVector[npcTouched]->wasAttackedTimer.start();
		}
		*/
	}
	mBox.x = mPosX;

	// Gravity.
	if(mVelY < 900) {
		mVelY += 3600 * timeStep;
	}
	else if(mVelY > 900) {
		mVelY = 900;
	}
	//Move the character up or down
	mPosY += mVelY * timeStep;

	//If the character went too far up or down or touched a wall
	if((mPosY < 0) || (mPosY + CHARACTER_HEIGHT > LEVEL_HEIGHT)) {
		if(mPosY < 0) mPosY = 0;
		else {
			mVelY = 0;
			mPosY = LEVEL_HEIGHT - CHARACTER_HEIGHT;
			isJumping = false;
		}
	} 
	mBox.y = mPosY;
	mWeapon.y = mPosY;
	tileTouched = touchesWall(mBox, tiles);
	tileTap = touchesTap(mBox, tiles);
	if(tileTouched > -1 && tiles[tileTouched]->diagonalTile && mPosY > tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y) {
		// Do nothing, seriously...
	}
	else if(tileTouched > -1 && mPosY < tiles[tileTouched]->getBox().y) {
		mVelY = 0;
		if(tiles[tileTouched]->topHalf) mPosY = tiles[tileTouched]->getCollisionBox().y - CHARACTER_HEIGHT;
		else if(tiles[tileTouched]->diagonalTile) {
			//std::cout << "hit!" << std::endl;
			mPosY = tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y - CHARACTER_HEIGHT;
		}
		else mPosY = tiles[tileTouched]->getBox().y - CHARACTER_HEIGHT;
		isJumping = false;
	}
	/*
	if(tileTouched > -1 && tiles[tileTouched]->diagonalTile && mPosY > tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y) {
		mPosY = tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y + tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].h;
	}
	*/
	else if((tileTouched > -1 && mPosY > tiles[tileTouched]->getBox().y)) {
		if(tiles[tileTouched]->topHalf) mPosY = tiles[tileTouched]->getCollisionBox().y + tiles[tileTouched]->getCollisionBox().h;
		/*
		else if(tiles[tileTouched]->diagonalTile) {
			//std::cout << "hit!" << std::endl;
			mPosY = tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].y + tiles[tileTouched]->getPixelBox()[tiles[tileTouched]->pixelTouched].h;
		}
		*/
		else mPosY = tiles[tileTouched]->getBox().y + TILE_HEIGHT;
	}
	npcTouched = touchesNpc(mBox, npcVector);
	if(npcTouched > -1 && mVelY > 0) {
		if(!isAttacking) {
			mPosY = npcVector[npcTouched]->getPosY() - CHARACTER_HEIGHT;
		}
		// Hack for now, don't want to decrease frame rate cap.
		if(mVelY > 60) {
			headJump = true;
		}
		isJumping = false;
		npcVector[npcTouched]->wasJumped = true;
	}
	if(npcTouched > -1 && mVelY < 0) {
		if(!isAttacking) mPosY = npcVector[npcTouched]->getPosY() + npcVector[npcTouched]->NPC_HEIGHT;
	}
	mBox.y = mPosY;
}

void Character::setCamera(SDL_Rect &camera) {
	//Center the camera over the character
	camera.x = (mPosX + CHARACTER_WIDTH / 2) - SCREEN_WIDTH / 2;
	camera.y = (mPosY + CHARACTER_HEIGHT / 2) - SCREEN_HEIGHT / 2;

	//Keep the camera in bounds
	if(camera.x < 0) {
		camera.x = 0;
	}
	if(camera.y < 0) {
		camera.y = 0;
	}
	if(camera.x > LEVEL_WIDTH - camera.w) {
		camera.x = LEVEL_WIDTH - camera.w;
	}
	if(camera.y > LEVEL_HEIGHT - camera.h) {
		camera.y = LEVEL_HEIGHT - camera.h;
	}
}

void Character::render(SDL_Rect &camera, bool toggleParticles, float scale, float heightScale) {
	//Show the character
	if(isAttacking) {
		// Stop walking timer.
		walkingTimer.stop();
		firstWalk = false;

		// Begin attack timer.
		if(!attackingTimer.isStarted()) attackingTimer.start();
		currentClip = &attackClips[attackingFrame];
		attackingFrame = (attackingTimer.getTicks() / 40) % ATTACKING_FRAMES;
		if(attackingFrame > 0) firstAttack = true;
		if((attackingFrame % ATTACKING_FRAMES == 0 && firstAttack == true) || secondAttack == true) {
			firstAttack = false;
			attackingTimer.stop();
			attackingFrame = 0;
			isAttacking = false;
			currentClip = &spriteClips[0];
		}
	}
	else if(secondAttack) {
		// Stop walking timer.
		walkingTimer.stop();
		firstWalk = false;

		// Begin attack timer.
		if(!attackingTimer.isStarted()) attackingTimer.start();
		currentClip = &secondAttackClips[attackingFrame];
		attackingFrame = (attackingTimer.getTicks() / 400) % SECOND_ATTACKING_FRAMES;
		if(attackingFrame > 0) firstAttack = true;
		if(attackingFrame % SECOND_ATTACKING_FRAMES == 0 && firstAttack == true) {
			firstAttack = false;
			attackingTimer.stop();
			attackingFrame = 0;
			secondAttack = false;
			currentClip = &spriteClips[0];
		}
	}
	else if(mVelY < 0) {
		walkingTimer.stop();
		firstWalk = false;
		if(mVelY < 0 && mVelY >= -100) currentClip = &jumpClips[5];
		else if(mVelY < -100 && mVelY >= -200) currentClip = &jumpClips[4];
		else if(mVelY < -200 && mVelY >= -300) currentClip = &jumpClips[3];
		else if(mVelY < -300 && mVelY >= -600) currentClip = &jumpClips[2];
		else if(mVelY < -600 && mVelY >= -800) currentClip = &jumpClips[1];
		else if(mVelY < -800 && mVelY >= -900) currentClip = &jumpClips[0];
		else currentClip = &jumpClips[1];
	}
	else if(mVelY > 60) {
		walkingTimer.stop();
		firstWalk = false;
		if(tileTap == true) {
			currentClip = &fallClips[5];
			tileTap = false;
		}
		else if(mVelY > 60 && mVelY <= 100) currentClip = &fallClips[0];
		else if(mVelY > 100 && mVelY <= 200) currentClip = &fallClips[1];
		else if(mVelY > 200 && mVelY <= 400) currentClip = &fallClips[2];
		else if(mVelY > 400 && mVelY <= 600) currentClip = &fallClips[3];
		else if(mVelY > 600) {
			if(!fallingTimer.isStarted()) fallingTimer.start();
			fallingFrame = ((fallingTimer.getTicks() / frameRate) + 3) % 5;
			if(((fallingTimer.getTicks() / frameRate) + 3) % 5 == 0) {
				fallingTimer.start();
				fallingFrame = ((fallingTimer.getTicks() / frameRate) + 3) % 5;
			}
			currentClip = &fallClips[fallingFrame];
		}
	}
	else {
		fallingTimer.stop();
		// Really complicated implementation...

		if(getVelocityX() > 0 || getVelocityX() < 0) {
			if(getVelocityX() > 0) flip = SDL_FLIP_NONE;
			else if(getVelocityX() < 0) flip = SDL_FLIP_HORIZONTAL;

			if(!walkingTimer.isStarted()) walkingTimer.start();
			if(walkingFrame % ANIMATION_FRAMES == 0 && firstWalk == true) {
				walkingTimer.start();
				walkingFrame = ((walkingTimer.getTicks() / frameRate) + 2) % ANIMATION_FRAMES;
			}
			currentClip = &spriteClips[walkingFrame];
			if(firstWalk == true) {
				walkingFrame = ((walkingTimer.getTicks() / frameRate) + 2) % ANIMATION_FRAMES;
			}
			else if(firstWalk == false) walkingFrame = (walkingTimer.getTicks() / frameRate) % ANIMATION_FRAMES;
			if((walkingTimer.getTicks() / frameRate) == ANIMATION_FRAMES) firstWalk = true;
		}
		else {
			walkingFrame = 0;
			walkingTimer.stop();
			firstWalk = false;
			currentClip = &spriteClips[0];
		}
	}
	dstrect.w = (int) (currentClip->w * scale);
	dstrect.h = (int) (currentClip->h * heightScale);
	if(flip == SDL_FLIP_NONE) dstrect.x = (int)(mBox.x - camera.x - dstrect.w + CHARACTER_WIDTH);
	else dstrect.x = (int) (mBox.x - camera.x);
	dstrect.y = (int) (mBox.y - camera.y);

	if(isAttacking || secondAttack) { 
		if(flip == SDL_FLIP_HORIZONTAL) {
			if(secondAttack) dstrect.x = (int)(mBox.x - camera.x - dstrect.w + CHARACTER_WIDTH);
			else dstrect.x = (int)(mBox.x - camera.x - dstrect.w + CHARACTER_WIDTH);
		}
		else {
			if(secondAttack) dstrect.x = mBox.x - camera.x;
			else dstrect.x = mBox.x - camera.x;
		}
		dstrect.y = mBox.y - camera.y;
		dstrect.h = mBox.h;
	}

	if(flip == SDL_FLIP_NONE) {
		// To adjust for clipping size.
		characterTexture.render(0, 0, currentClip, dstrect, 0, NULL, flip);
	}
	else {
		characterTexture.render(0, 0, currentClip, dstrect, 0, NULL, flip);
	}

	// Show particles on top of character.
	renderParticles(camera, toggleParticles);
}
