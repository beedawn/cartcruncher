
#include "raylib.h"

class Character
{
public:
    Character(Vector2 spawnPosition);
    void Update();
    void Draw();
    void Debug();
    

private:
    Texture2D texture;
    Vector2 position;
    Rectangle charSpriteFrame;

    float walkSpeed;
    float jumpHeight;
    float gravity;
    float cooldownTimer;
    float cooldownTime;
    bool inputAllowed;
    void ChangeSprite(int pos);

void MoveDown();

void MoveDown(float speed);

void MoveUp();
void MoveUp(float speed);

void MoveLeft();
void MoveLeft(float speed);
void MoveRight();

void MoveRight(float speed);

};
