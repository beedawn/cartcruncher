#include "Character.h"

Character::Character(Vector2 spawnPosition)
{
    position = spawnPosition;
    texture = LoadTexture("resources/char2.png"); // example
    charSpriteFrame = {0.0f, 0.0f, 32, 32};

    walkSpeed = 2.0f;
    ;
    jumpHeight = 10.0f;
    gravity = 0.0f;
    cooldownTimer = 0;
    cooldownTime = 1.0f;
    inputAllowed = true;
}

void Character::Debug()
{

    DrawText(TextFormat("Ball X: %.2f", position.x), 10, 550, 20, BLACK);
    DrawText(TextFormat("Ball Y: %.2f", position.y), 10, 600, 20, BLACK);
}

void Character::Update()
{
    // input + movement
    // if (IsKeyDown(KEY_RIGHT)) position.x += 2.0f;
    // if (IsKeyDown(KEY_LEFT))  position.x -= 2.0f;
    const int screenWidth = 800;
    const int screenHeight = 800;
    float leftWall = (float)0;
    float rightWall = (float)(screenWidth / 2);
    float topWall = (float)(screenHeight / 2);
    float bottomWall = (float)(screenHeight);
    Vector2 topLeft = {leftWall, topWall};
    Vector2 topRight = {rightWall, topWall};
    Vector2 bottomLeft = {leftWall, bottomWall};
    Vector2 bottomRight = {rightWall, bottomWall};
    Vector2 center = {(float)(screenWidth / 4), (float)(screenHeight / 2) + (screenHeight / 4)};

    // Update
    //----------------------------------------------------------------------------------
    // if (position.y < 800)
    // {
    // 	position.y += gravity;
    // }
  
    if (position.y > bottomWall)
    {
        position.y -= 1;
    }
    if (position.y < topWall)
    {
        position.y += 1;
    }

    if (position.x < leftWall)
    {
        position.x += 1;
    }
    if (cooldownTimer > 0)
    {
        cooldownTimer -= GetFrameTime(); // GetFrameTime() returns seconds passed this frame
        if (cooldownTimer < 0)
            cooldownTimer = 0;
    }
    if (position.x > 390 && IsKeyDown(KEY_SPACE))
    {
        inputAllowed = false;
        cooldownTimer = cooldownTime;
        while (position.x > 360)
        {
            position.x -= 0.5;
        }
    }
    if (cooldownTimer == 0)
    {
        inputAllowed = true;
    }
    if (IsKeyDown(KEY_RIGHT) && position.x < rightWall && inputAllowed)
    {
        if (IsKeyDown(KEY_SPACE))
        {
            MoveRight(jumpHeight); // higher jump if UP held
        }
        ChangeSprite(1);
        MoveRight();
    }
    if (IsKeyDown(KEY_LEFT) && position.x > leftWall && inputAllowed)
    {
        if (IsKeyDown(KEY_SPACE))
        {
            MoveLeft(jumpHeight); // higher jump if UP held
        }
        ChangeSprite(0);
        MoveLeft();
    }
    if (IsKeyDown(KEY_UP) && position.y > topWall && inputAllowed)
    {
        if (IsKeyDown(KEY_SPACE))
        {
            MoveUp(jumpHeight); 
        }
        ChangeSprite(4);
        MoveUp(); 
    }
    if (IsKeyDown(KEY_DOWN) && position.y < bottomWall && inputAllowed)
    {
        if (IsKeyDown(KEY_SPACE))
        {
            MoveDown(jumpHeight);
        }
        ChangeSprite(5);
        MoveDown();
    }
}

void Character::Draw()
{
    DrawTextureRec(texture, charSpriteFrame, position, WHITE);
    // DrawTextureV(texture, position, WHITE);
}

void Character::ChangeSprite(int pos)
{
    charSpriteFrame.x = (pos * 32);
}

void Character::MoveDown()
{
    position.y += walkSpeed;
}

void Character::MoveDown(float speed)
{
    position.y += speed;
}

void Character::MoveUp()
{
    position.y -= walkSpeed;
}
void Character::MoveUp(float speed)
{
    position.y -= speed;
}

void Character::MoveLeft()
{
    position.x -= walkSpeed;
}
void Character::MoveLeft(float speed)
{
    position.x -= speed;
}
void Character::MoveRight()
{
    position.x += walkSpeed;
}

void Character::MoveRight(float speed)
{
    position.x += speed;
}