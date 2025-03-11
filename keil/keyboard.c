#include <stdint.h>
#include "code_def.h"
#include "role.h"

extern uint8_t ready_time_en ;
extern uint16_t ready_time;
extern uint8_t show_gameover;
extern uint16_t show_time;
extern uint8_t show_mode;
extern uint32_t LCD_finish;
extern uint8_t hurt2_time;
extern uint8_t hurt1_time;
extern uint8_t ready_time2_en ;
extern uint16_t ready_time2;
extern uint32_t game_time;


void LCD_FINISH(void)
{
	LCD_finish=1;
	
}


void TIMER(void)//100ms
{
	MapDraw();game_time=game_time+1;
	USER->LED=(0x0001<<(game_time%5))|0x1;
	if(Role1_State->HP>100)
		Role1_State->HP=0;
	if(Role2_State->HP>100)
		Role2_State->HP=0;
	//movement//
	if(show_mode==1)
	{
		if(ready_time_en)
		{
			ready_time=ready_time+1;
			
		}else{
			ready_time=0;
		}
		if(ready_time2_en)
		{
			ready_time2=ready_time2+1;
			
		}else{
			ready_time2=0;
		}
	switch(Role1_State->Action)
	{
		case STAND:Standing1();break;
		case LATTACK:{LeftAttacking1();}break;
		case RATTACK:{RightAttacking1();}break;
		case LMOVE:{LeftMoving1();}break;
		case RMOVE:{RightMoving1();}break;
		case JUMP:{Jumping1();}break;
		case HURTING:{Hurting1();}break;
		case SHOOT:{Shooting1();}break;
		case FLOUTING:{Floating1();}break;
		case DOWN:{Down1();}break;
		case SQUAT:{Squating1();}break;
		default:break;
			
	}
		switch(Map_State->DamageBlock1)
	{
		case ZERO:break;
		case FIRE:{Fire();}break;
		case ICE :{Ice();}break;
		default:break;
			
	}
		switch(Map_State->DamageBlock3)
	{
		case ZERO:break;
		case FIRE:{FireGo();}break;
		case ICE :{Ice();}break;
		default:break;
			
	}
		switch(Map_State->DamageBlock4)
	{
		case ZERO:break;
		case FIRE:{Fire();}break;
		case ICE :{Ice();}break;
		default:break;
			
	}	
		switch(Map_State->DamageBlock6)
	{
		case ZERO:break;
		case FIRE:break;
		case ICE :{IceGo();}break;
		default:break;
			
	}
		switch(Role2_State->Action)
	{
		case STAND:Standing2();break;
		case LATTACK:{LeftAttacking2();}break;
		case RATTACK:{RightAttacking2();}break;
		case LMOVE:{LeftMoving2();}break;
		case RMOVE:{RightMoving2();}break;
		case JUMP:{Jumping2();}break;
		case HURTING:{Hurting2();}break;
		case SHOOT:{Shooting2();}break;
		case FLOUTING:{Floating2();}break;
		case DOWN:{Down2();}break;
		case SQUAT:{Squating2();}break;
		default:break;
			
	}
	if(Role1_State->HurtCount)
	{
		hurt1_time=hurt1_time+1;
		if(hurt1_time>=20)
		{	hurt1_time=0;Role1_State->HurtCount=0;}
		if(Role1_State->HurtCount>=2)
		{
			Role1_State->Action=HURTING;Role1_State->ActionRank=1;
		}
	}
		if(Role2_State->HurtCount)
	{
		hurt2_time=hurt2_time+1;
		if(hurt2_time>=20)
		{	hurt2_time=0;Role2_State->HurtCount=0;}
		if(Role2_State->HurtCount>=2)
		{
			Role2_State->Action=HURTING;Role2_State->ActionRank=1;
		}
	}
	Damage_define();
	RoleHPshowing();
	if((Role1_State->HP==0)||(Role2_State->HP==0))
	{
		show_gameover=1;show_mode=0;
		
	}
		
}
	else {if(show_mode==0)
	{
		if(show_gameover==0){
		DrawLCD(150,280,22);
		DrawLCD((show_time%12)*18,120,14);

		if(show_time==0)
		{
			MusicPlay(3);
		}
		show_time=show_time+1;
		if(show_time==200)
		{show_time=0;show_mode=1;}
	}
		if(show_gameover==1)
		{
		if(show_time==0)
		{
		
			MusicPlay(0);
		}
		 DrawLCD(100,160,21);
			
		}
	
	
	}}

}

void KEY0(void)
{
	Role1_State->Head=LEFT;
if(Role1_State->Action==STAND)
RoleMovingLeft(1);
  if(Role1_State->Action==FLOUTING)
	{
		Role1_State->Action=LMOVE;
		Role1_State->ActionRank=1;
	}
}

void KEY1(void)
{
	if(Role1_State->Action==STAND)
RoleSquat(1);

}

void KEY2(void)
{
	Role1_State->Head=RIGHT;
		if(Role1_State->Action==STAND)
	RoleMovingRight(1);
		  if(Role1_State->Action==FLOUTING)
	{
		Role1_State->Action=RMOVE;
		Role1_State->ActionRank=1;
	}
}

void KEY3(void)
{
		if(Role1_State->Action==STAND)
Attacking(1);
		  if(Role1_State->Action==FLOUTING)
	{
		if(Role1_State->Head==LEFT)
		Role1_State->Action=LATTACK;
		else
			Role1_State->Action=RATTACK;
		
		Role1_State->ActionRank=1;
	}
		if(ready_time<=4)
	{
		Block_move->Block3step=5;
		
	}
  else	if(ready_time<=8)
	{
		Block_move->Block3step=10;
		
	}
	else	if(ready_time<=12)
	{
		Block_move->Block3step=20;
		
	}
	if(ready_time_en){
	Map_State->BlockRank3=1;Map_State->DamageBlock3=FIRE;Map_State->DamageBlock3Head=Role1_State->Head;
	}
	ready_time_en=0;
}
void KEY4(void)
{ 
  //show_mode=~show_mode;
  //show_gameover=0;
}

void KEY5(void)
{
	if(Role1_State->Action==STAND)
RoleJumping(1);
  if(Role1_State->Action==FLOUTING)
	{
		Role1_State->Action=JUMP;
		Role1_State->ActionRank=1;
	}
}

void KEY6(void)
{
	ready_time_en=1;
}

void KEY7(void)
{
	if(ready_time<=4)
	{
		Block_move->Block1step=5;
		
	}
  else	if(ready_time<=8)
	{
		Block_move->Block1step=10;
		
	}
	else	if(ready_time<=12)
	{
		Block_move->Block1step=20;
		
	}
	if(ready_time_en){
	Role1_State->Action=SHOOT;Role1_State->ActionRank=1;
	}
	ready_time_en=0;
	
}
void KEY8(void)
{
	if(ready_time2<=4)
	{
		Block_move->Block4step=5;
		
	}
  else	if(ready_time2<=8)
	{
		Block_move->Block4step=10;
		
	}
	else	if(ready_time2<=12)
	{
		Block_move->Block4step=20;
		
	}
	if(ready_time2_en){
	Role2_State->Action=SHOOT;Role2_State->ActionRank=1;
	}
	ready_time2_en=0;
	
}

void KEY9(void)
{
	
		ready_time2_en=1;
}

void KEY10(void)
{
	if(Role2_State->Action==STAND)
RoleJumping(2);
  if(Role2_State->Action==FLOUTING)
	{
		Role2_State->Action=JUMP;
		Role2_State->ActionRank=1;
	}
}

void KEY11(void)
{

}
void KEY12(void)
{
	if(Role2_State->Action==STAND)
Attacking(2);
		  if(Role2_State->Action==FLOUTING)
	{
		if(Role2_State->Head==LEFT)
		Role2_State->Action=LATTACK;
		else
			Role2_State->Action=RATTACK;
		
		Role2_State->ActionRank=1;
	}
		if(ready_time2<=4)
	{
		Block_move->Block6step=5;
		
	}
  else	if(ready_time2<=8)
	{
		Block_move->Block6step=10;
		
	}
	else	if(ready_time2<=12)
	{
		Block_move->Block6step=20;
		
	}
	if(ready_time2_en){
	Map_State->BlockRank3=1;Map_State->DamageBlock6=ICE;Map_State->DamageBlock6Head=Role2_State->Head;
	}
	ready_time2_en=0;
}

void KEY13(void)
{
		Role2_State->Head=RIGHT;
		if(Role2_State->Action==STAND)
	RoleMovingRight(2);
		  if(Role2_State->Action==FLOUTING)
	{
		Role2_State->Action=RMOVE;
		Role2_State->ActionRank=1;
	}
}

void KEY14(void)
{
	if(Role2_State->Action==STAND)
RoleSquat(2);
}

void KEY15(void)
{
	Role2_State->Head=LEFT;
if(Role2_State->Action==STAND)
RoleMovingLeft(2);
  if(Role2_State->Action==FLOUTING)
	{
		Role2_State->Action=LMOVE;
		Role2_State->ActionRank=1;
	}
}