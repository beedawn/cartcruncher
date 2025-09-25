/*******************************************************************************************
 *
 *   raylib [core] example - input keys
 *
 *   Example complexity rating: [★☆☆☆] 1/4
 *
 *   Example originally created with raylib 1.0, last time updated with raylib 1.0
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2014-2025 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "raylib.h"
#include <cmath>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys");
	//(float)(screenWidth/2)
	float leftWall = (float)0;
	float rightWall = (float)(screenWidth / 2);
	float topWall = (float)(screenHeight / 2);
	float bottomWall = (float)(screenHeight);
	Vector2 topLeft = {leftWall, topWall};
	Vector2 topRight = {rightWall, topWall};
	Vector2 bottomLeft = {leftWall, bottomWall};
	Vector2 bottomRight = {rightWall, bottomWall};
	Vector2 center = {(float)(screenWidth / 4), (float)(screenHeight / 2) + (screenHeight / 4)};
	Vector2 ballPosition = topLeft;

	SetTargetFPS(60); // Set our game to run at 60 frames-per-second
					  //--------------------------------------------------------------------------------------
	Color ballColor = MAROON;
	int ballSize = 20;
	float gravity = 0.0f;
	float jumpHeight = 10.0f;
	float walkSpeed = 2.0f;
	bool inputAllowed = true;
	float cooldownTimer = 0;
	float cooldownTime = 1.0f;
	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{

		// Update
		//----------------------------------------------------------------------------------
		if (ballPosition.y < 800)
		{
			ballPosition.y += gravity;
		}
		if (ballPosition.y > 800)
		{
			ballPosition.y -= 1;
		}
		if (ballPosition.y > 800)
		{
			ballPosition.y -= 1;
		}
		if(ballPosition.y<400)
		{
			ballPosition.y += 1;
		}

		if(ballPosition.x<0)
		{
			ballPosition.x += 1;
		}
		 if(cooldownTimer > 0) {
        cooldownTimer -= GetFrameTime(); // GetFrameTime() returns seconds passed this frame
        if(cooldownTimer < 0) cooldownTimer = 0;
    }
		if(ballPosition.x>390 && IsKeyDown(KEY_SPACE))
		{
			inputAllowed = false;
			cooldownTimer = cooldownTime;
			while(ballPosition.x>360){
			ballPosition.x -= 0.5;
			}
			
		} 
		    if(cooldownTimer == 0) {
        inputAllowed = true;
    }
		if (IsKeyDown(KEY_RIGHT) && ballPosition.x < rightWall && inputAllowed)
		{
				if (IsKeyDown(KEY_SPACE))
			{
				ballPosition.x += jumpHeight; // higher jump if UP held
			}
			else
			{
				ballPosition.x += walkSpeed; // normal jump
			}
			ballPosition.x += walkSpeed;
		}
		if (IsKeyDown(KEY_LEFT) && ballPosition.x > leftWall && inputAllowed)
		{
				if (IsKeyDown(KEY_SPACE))
			{
				ballPosition.x -= jumpHeight; // higher jump if UP held
			}
			else
			{
				ballPosition.x -= walkSpeed; // normal jump
			}
			ballPosition.x -= walkSpeed;
		}
		if (IsKeyDown(KEY_UP) && ballPosition.y > topWall && inputAllowed)
		{
				if (IsKeyDown(KEY_SPACE))
			{
				ballPosition.y -= jumpHeight; // higher jump if UP held
			}
			else
			{
				ballPosition.y -= walkSpeed; // normal jump
			}
			 
		}
		if (IsKeyDown(KEY_DOWN) && ballPosition.y < bottomWall && inputAllowed)
		{
				if (IsKeyDown(KEY_SPACE))
			{
				ballPosition.y += jumpHeight; // higher jump if UP held
			}
			else
			{
				ballPosition.y += walkSpeed; // normal jump
			}
			
		}

		// if (IsKeyPressed(KEY_A) && ballPosition.y == bottomWall && (ballPosition.y + 10.0f) > topWall)
		// {

		// 	if (IsKeyDown(KEY_UP))
		// 	{
		// 		ballPosition.y -= jumpHeight+100; // higher jump if UP held
		// 	}
		// 	else
		// 	{
		// 		ballPosition.y -= jumpHeight; // normal jump
		// 	}

		// }

		float t = GetTime(); // seconds since program start
		Color flickerColor = (fmod(t, 0.5f) < 0.25f) ? GREEN : BLUE;
		int flickerSize = (fmod(t, 0.5f) < 0.25f) ? 10 : 15;

		if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) ||
			IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
		{
			ballColor = flickerColor;
			ballSize = flickerSize;
		}
		else
		{
			ballColor = MAROON; // default when idle
			ballSize = 20;
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("move the ball with arrow keys", 10, 500, 20, BLACK);
		DrawText(TextFormat("Ball X: %.2f", ballPosition.x), 10, 550, 20, BLACK);
		DrawText(TextFormat("Ball Y: %.2f", ballPosition.y), 10, 600, 20, BLACK);
		// ballColor = MAROON;

		DrawCircleV(ballPosition, ballSize, ballColor);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow(); // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

bool inBounds(Vector2 ballPosition)
{
	return false;
}