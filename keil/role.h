#define RoleHeight 72
#define RoleWidth  39
#define RoleAttackerP 31
#define RoleAttackerHeight 7
#define RoleAttackerWidth 24

#define LEFT 0
#define RIGHT 1

//rolestate ACTION
#define RATTACK 2
#define LATTACK  1
#define STAND 0
#define HURTING 3
#define LMOVE	4
#define RMOVE	5
#define JUMP	6
#define FLOUTING	7 
#define SQUAT 8
#define SHOOT 9
#define SUPERSHOOT 10
#define DOWN 11

//MAP Define
#define MAP_HEIGHT 20
#define ZERO 0
#define FIRE 3
#define ICE 1
#define WATER 2
//attack define
#define FIREWIDTH 20
#define FIREHEIGHT 20
#define ICEWIDTH 20
#define ICEHEIGHT 20



typedef struct{
    volatile uint8_t HP;
    volatile uint8_t PositionX;
	  volatile uint16_t PositionY;
    volatile uint8_t Action;
		volatile uint8_t ActionRank;
	  volatile uint8_t HurtCount;
	  volatile uint8_t Head;
	  volatile uint8_t AttackRank;		
}role_state;
//RAMDATA-----------------------------
//0X20000000-0X2000FFFF
#define ROLE_BASE 0X20000110
#define Role1_State ((role_state *)ROLE_BASE )
#define Role2_State ((role_state *)0x2000011A )

typedef struct{
    volatile uint8_t Height;
    volatile uint8_t Width;
	  volatile uint8_t AttackerP;
    volatile uint8_t AttackerHeight;
	  volatile uint8_t AttackerWidth;

}role_message;
#define ROLE_MESSAGE_BASE 0X20000124
#define Role1_Message ((role_message *)ROLE_MESSAGE_BASE )
#define Role2_Message ((role_message *)0X2000012B )

typedef struct{
    volatile uint8_t Height;
    volatile uint8_t DamageBlock1;
	  volatile uint8_t DamageBlock2;
    volatile uint8_t DamageBlock3;
		volatile uint8_t BlockRank1;
	  volatile uint8_t BlockRank2;
	  volatile uint8_t BlockRank3;
    volatile uint8_t DamageBlock1X;
	  volatile uint8_t DamageBlock2X;
    volatile uint8_t DamageBlock3X;	
    volatile uint16_t DamageBlock1Y;
	  volatile uint16_t DamageBlock2Y;
    volatile uint16_t DamageBlock3Y;
    volatile uint8_t DamageBlock1Head;
	  volatile uint8_t DamageBlock2Head;
    volatile uint8_t DamageBlock3Head;
    volatile uint8_t DamageBlock4;
	  volatile uint8_t DamageBlock5;
    volatile uint8_t DamageBlock6;
		volatile uint8_t BlockRank4;
	  volatile uint8_t BlockRank5;
	  volatile uint8_t BlockRank6;
    volatile uint8_t DamageBlock4X;
	  volatile uint8_t DamageBlock5X;
    volatile uint8_t DamageBlock6X;	
    volatile uint16_t DamageBlock4Y;
	  volatile uint16_t DamageBlock5Y;
    volatile uint16_t DamageBlock6Y;
    volatile uint8_t DamageBlock4Head;
	  volatile uint8_t DamageBlock5Head;
    volatile uint8_t DamageBlock6Head;
}map_state;
#define MAP_STATE_BASE 0X20000140
#define Map_State ((map_state *)MAP_STATE_BASE )


typedef struct{
    volatile uint8_t Block1step;
    volatile uint8_t Block2step;
	  volatile uint8_t Block3step;
    volatile uint8_t Block4step;
    volatile uint8_t Block5step;
	  volatile uint8_t Block6step;
}block_move;
#define BLOCK_MOVE_BASE 0X20000180
#define Block_move ((block_move *)BLOCK_MOVE_BASE )

void Role_Ini(void);
void LeftAttacking1(void);
void RightAttacking1(void);
void LeftMoving1(void);
void RightMoving1(void);
void Standing1(void);
void Hurting1(void);
void LeftAttacking2(void);
void RightAttacking2(void);
void LeftMoving2(void);
void RightMoving2(void);
void Standing2(void);
void Hurting2(void);
void Attacking(uint8_t id);
void RoleMovingRight(uint8_t id);
void RoleMovingLeft(uint8_t id);
void RoleSquat(uint8_t id);
void RoleJumping(uint8_t id);
void RoleHPshowing(void);
void Shooting1(void);
void Fire(void);
void MapDraw(void);
void Ice(void);
void Damage_define(void);
void Jumping1(void);
void Floating1(void);
void Down1(void);
void Squating1(void);
void Cure_define1(void);
void Shooting2(void);
void Jumping2(void);
void Floating2(void);
void Down2(void);
void Squating2(void);
void Cure_define2(void);
void IceGo(void);

