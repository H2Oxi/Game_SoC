
#include "code_def.h"
#include "role.h"

extern uint32_t LCD_finish;
uint16_t down_height; 

void Role_Ini(void)
{
	LCD_finish=0;
	Role1_Message->AttackerHeight=RoleAttackerHeight;
	Role1_Message->AttackerP=RoleAttackerP;
	Role1_Message->AttackerWidth=RoleAttackerWidth;
	Role1_Message->Height=RoleHeight;
	Role1_Message->Width=RoleWidth;
	Role2_Message->AttackerHeight=RoleAttackerHeight;
	Role2_Message->AttackerP=RoleAttackerP;
	Role2_Message->AttackerWidth=RoleAttackerWidth;
	Role2_Message->Height=RoleHeight;
	Role2_Message->Width=RoleWidth;
	Role1_State->HP=72;
	Role1_State->Action=STAND;
	Role1_State->ActionRank=1;
	Role1_State->HurtCount=0;
	Role1_State->PositionX=20;
	Role1_State->PositionY=200;
	Role1_State->Head=LEFT;
	Role2_State->Head=RIGHT;
	Role2_State->HP=72;
	Role2_State->Action=STAND;
	Role2_State->ActionRank=1;
	Role2_State->HurtCount=0;
	Role2_State->PositionX=120;
	Role2_State->PositionY=200;
	Role1_State->AttackRank=1;
	Role2_State->AttackRank=1;
	Map_State->BlockRank1=1;
	Map_State->BlockRank2=1;
	Map_State->BlockRank3=1;
	Map_State->DamageBlock1=ZERO;
	Map_State->DamageBlock2=ZERO;
	Map_State->DamageBlock3=ZERO;	
	Map_State->Height=20;
	Block_move->Block1step=1;
	Block_move->Block2step=1;
	Block_move->Block3step=1;
	Map_State->DamageBlock1Y=220;
	Map_State->DamageBlock2Y=220;
	Map_State->DamageBlock3Y=220;
	Map_State->BlockRank4=1;
	Map_State->BlockRank5=1;
	Map_State->BlockRank6=1;	
	Map_State->DamageBlock4=ZERO;
	Map_State->DamageBlock5=ZERO;
	Map_State->DamageBlock6=ZERO;		
	Block_move->Block4step=1;
	Block_move->Block5step=1;
	Block_move->Block6step=1;
}

void LeftAttacking1(void)
{
	switch(Role1_State->AttackRank)
	{
		case 1:{
		switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+Role1_Message->AttackerP,10);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);DrawLCD(Role1_State->PositionX-24,Role1_State->PositionY+Role1_Message->AttackerP,8);Role1_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+Role1_Message->AttackerP,10);
			if(((Role1_State->PositionX-Role1_Message->AttackerWidth)<=Role2_State->PositionX+Role2_Message->Width)&&((Role1_State->PositionX-Role1_Message->AttackerWidth)>=Role2_State->PositionX))
		{
			Role2_State->HP=Role2_State->HP-1;Role2_State->HurtCount=Role2_State->HurtCount+1;
		}
		if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}
		Role1_State->ActionRank=1;Role1_State->AttackRank=Role1_State->AttackRank+1;
		}break;
	}
}break;
		case 2:{
		switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);
		DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+12+Role1_Message->AttackerP,10);DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+24+Role1_Message->AttackerP,10);
			DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+Role1_Message->AttackerP,10);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);
		DrawLCD(Role1_State->PositionX-24,Role1_State->PositionY+12+Role1_Message->AttackerP,8);DrawLCD(Role1_State->PositionX-24,Role1_State->PositionY+24+Role1_Message->AttackerP,8);
		DrawLCD(Role1_State->PositionX-24,Role1_State->PositionY+Role1_Message->AttackerP,8);Role1_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);
			DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+12+Role1_Message->AttackerP,10);DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+24+Role1_Message->AttackerP,10);
			DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+Role1_Message->AttackerP,10);
			if(((Role1_State->PositionX-Role1_Message->AttackerWidth)<=Role2_State->PositionX+Role2_Message->Width)&&((Role1_State->PositionX-Role1_Message->AttackerWidth)>=Role2_State->PositionX))
		{
			Role2_State->HP=Role2_State->HP-3;Role2_State->HurtCount=Role2_State->HurtCount+1;
		}
		if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}
		Role1_State->ActionRank=1;Role1_State->AttackRank=Role1_State->AttackRank+1;
		}break;
	}
}break;
		case 3:{
		switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,13);DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+Role1_Message->AttackerP,10);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);
		DrawLCD(Role1_State->PositionX-36,Role1_State->PositionY+Role1_Message->AttackerP,14);
		DrawLCD(Role1_State->PositionX-24,Role1_State->PositionY+Role1_Message->AttackerP,8);Role1_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,13);
			DrawLCD(Role1_State->PositionX-36,Role1_State->PositionY+Role1_Message->AttackerP,14);DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+Role1_Message->AttackerP,10);
			if(((Role1_State->PositionX-Role1_Message->AttackerWidth)<=Role2_State->PositionX+Role2_Message->Width)&&((Role1_State->PositionX-Role1_Message->AttackerWidth)>=Role2_State->PositionX))
		{
			Role2_State->HP=Role2_State->HP-5;Role2_State->HurtCount=Role2_State->HurtCount+1;
		}
		if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}
		Role1_State->ActionRank=1;Role1_State->AttackRank=Role1_State->AttackRank+1;
		}break;
	}
}break;
		case 4:{
		switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,13);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);DrawLCD(Role1_State->PositionX-13,Role1_State->PositionY+Role1_Message->AttackerP,10);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,13);
		DrawLCD(Role1_State->PositionX-50,Role1_State->PositionY+Role1_Message->AttackerP,20);
		Role1_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);
			DrawLCD(Role1_State->PositionX-50,Role1_State->PositionY+Role1_Message->AttackerP,20);
			if(((Role1_State->PositionX-Role1_Message->AttackerWidth)<=Role2_State->PositionX+Role2_Message->Width)&&((Role1_State->PositionX-Role1_Message->AttackerWidth)>=Role2_State->PositionX))
		{
			Role2_State->HP=Role2_State->HP-10;Role2_State->HurtCount=Role2_State->HurtCount+1;
		}
		if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}
		Role1_State->ActionRank=1;Role1_State->AttackRank=1;
		}break;
	}
}break;
	}
}

void RightAttacking1(void)
{
	switch(Role1_State->AttackRank)
	{
		case 1:{
		switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,10);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,9);Role1_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,10);
			if(((Role1_State->PositionX+Role1_Message->Width+Role1_Message->AttackerWidth)>=Role2_State->PositionX)&&((Role1_State->PositionX+Role1_Message->Width+Role1_Message->AttackerWidth)<=Role2_State->PositionX+Role2_Message->Width))
		{
			Role2_State->HP=Role2_State->HP-1;Role2_State->HurtCount=Role2_State->HurtCount+1;
		}
		if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}
		Role1_State->ActionRank=1;Role1_State->AttackRank=Role1_State->AttackRank+1;
		}break;
	}
}break;
		case 2:{
		switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);
		DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+12+Role1_Message->AttackerP,10);DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+24+Role1_Message->AttackerP,10);
			DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,10);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);
		DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+12+Role1_Message->AttackerP,9);DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+24+Role1_Message->AttackerP,9);
		DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,9);Role1_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);
			DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+12+Role1_Message->AttackerP,10);DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+24+Role1_Message->AttackerP,10);
			DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,10);
			if(((Role1_State->PositionX+Role1_Message->Width+Role1_Message->AttackerWidth)>=Role2_State->PositionX)&&((Role1_State->PositionX+Role1_Message->Width+Role1_Message->AttackerWidth)<=Role2_State->PositionX+Role2_Message->Width))
		{
			Role2_State->HP=Role2_State->HP-3;Role2_State->HurtCount=Role2_State->HurtCount+1;
		}
		if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}
		Role1_State->ActionRank=1;Role1_State->AttackRank=Role1_State->AttackRank+1;
		}break;
	}
}break;
		case 3:{
		switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,13);DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,10);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);
		DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,14);
		DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,9);Role1_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,13);
			DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,14);DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,10);
			if(((Role1_State->PositionX+Role1_Message->Width+Role1_Message->AttackerWidth)>=Role2_State->PositionX)&&((Role1_State->PositionX+Role1_Message->Width+Role1_Message->AttackerWidth)<=Role2_State->PositionX+Role2_Message->Width))
		{
			Role2_State->HP=Role2_State->HP-5;Role2_State->HurtCount=Role2_State->HurtCount+1;
		}
		if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}
		Role1_State->ActionRank=1;Role1_State->AttackRank=Role1_State->AttackRank+1;
		}break;
	}
}break;
		case 4:{
		switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,13);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,10);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,13);
		DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,20);
		Role1_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);
			DrawLCD(Role1_State->PositionX+Role1_Message->Width,Role1_State->PositionY+Role1_Message->AttackerP,20);
			if(((Role1_State->PositionX+Role1_Message->Width+Role1_Message->AttackerWidth)>=Role2_State->PositionX)&&((Role1_State->PositionX+Role1_Message->Width+Role1_Message->AttackerWidth)<=Role2_State->PositionX+Role2_Message->Width))
		{
			Role2_State->HP=Role2_State->HP-10;Role2_State->HurtCount=Role2_State->HurtCount+1;
		}
		if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}
		Role1_State->ActionRank=1;Role1_State->AttackRank=1;
		}break;
	}
}break;
	}
}


void LeftMoving1(void)
{
	switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,4);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{Role1_State->PositionX=Role1_State->PositionX-2;DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,4);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 4:{Role1_State->PositionX=Role1_State->PositionX-1;DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=0;}break;
		case 0:{
					if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}Role1_State->ActionRank=1;
		
		}break;
	}
}

void RightMoving1(void)
{
	switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,5);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{Role1_State->PositionX=Role1_State->PositionX+2;DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,5);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 4:{Role1_State->PositionX=Role1_State->PositionX+1;DrawLCD(Role1_State->PositionX,Role1_State->PositionY,3);
		Role1_State->ActionRank=0;}break;
		case 0:{
					if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}Role1_State->ActionRank=1;
		
		}break;
	}
}

void Standing1(void)
{
		switch(Role1_State->ActionRank)
	{
		
		case 1:{if(Role1_State->Head==RIGHT){DrawLCD(Role1_State->PositionX,Role1_State->PositionY,5);}
		if(Role1_State->Head==LEFT){DrawLCD(Role1_State->PositionX,Role1_State->PositionY,4);}
		Role1_State->ActionRank=0;}break;
		
		case 0:{if(Role1_State->Head==RIGHT){DrawLCD(Role1_State->PositionX,Role1_State->PositionY,5);}
		if(Role1_State->Head==LEFT){DrawLCD(Role1_State->PositionX,Role1_State->PositionY,4);}

		}break;
	}
	
}

void Hurting1(void)
{
	switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,0);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,0);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,1);Role1_State->ActionRank=0;}break;
		case 0:{
					if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}Role1_State->ActionRank=1;
		
		}break;
	}
	
	
}
//2//
void LeftAttacking2(void)
{
	switch(Role2_State->AttackRank)
	{
		case 1:{
		switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+Role2_Message->AttackerP,10);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);DrawLCD(Role2_State->PositionX-24,Role2_State->PositionY+Role2_Message->AttackerP,8);Role2_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+Role2_Message->AttackerP,10);
			if(((Role2_State->PositionX-Role2_Message->AttackerWidth)<=Role1_State->PositionX+Role1_Message->Width)&&((Role2_State->PositionX-Role2_Message->AttackerWidth)>=Role1_State->PositionX))
		{
			Role1_State->HP=Role1_State->HP-1;Role1_State->HurtCount=Role1_State->HurtCount+1;
		}
		if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}
		Role2_State->ActionRank=1;Role2_State->AttackRank=Role2_State->AttackRank+1;
		}break;
	}
}break;
		case 2:{
		switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);
		DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+12+Role2_Message->AttackerP,10);DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+24+Role2_Message->AttackerP,10);
			DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+Role2_Message->AttackerP,10);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);
		DrawLCD(Role2_State->PositionX-24,Role2_State->PositionY+12+Role2_Message->AttackerP,8);DrawLCD(Role2_State->PositionX-24,Role2_State->PositionY+24+Role2_Message->AttackerP,8);
		DrawLCD(Role2_State->PositionX-24,Role2_State->PositionY+Role2_Message->AttackerP,8);Role2_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);
			DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+12+Role2_Message->AttackerP,10);DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+24+Role2_Message->AttackerP,10);
			DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+Role2_Message->AttackerP,10);
			if(((Role2_State->PositionX-Role2_Message->AttackerWidth)<=Role1_State->PositionX+Role1_Message->Width)&&((Role2_State->PositionX-Role2_Message->AttackerWidth)>=Role1_State->PositionX))
		{
			Role1_State->HP=Role1_State->HP-3;Role1_State->HurtCount=Role1_State->HurtCount+1;
		}
		if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}
		Role2_State->ActionRank=1;Role2_State->AttackRank=Role2_State->AttackRank+1;
		}break;
	}
}break;
		case 3:{
		switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,13);DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+Role2_Message->AttackerP,10);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);
		DrawLCD(Role2_State->PositionX-36,Role2_State->PositionY+Role2_Message->AttackerP,14);
		DrawLCD(Role2_State->PositionX-24,Role2_State->PositionY+Role2_Message->AttackerP,8);Role2_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,13);
			DrawLCD(Role2_State->PositionX-36,Role2_State->PositionY+Role2_Message->AttackerP,14);DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+Role2_Message->AttackerP,10);
			if(((Role2_State->PositionX-Role2_Message->AttackerWidth)<=Role1_State->PositionX+Role1_Message->Width)&&((Role2_State->PositionX-Role2_Message->AttackerWidth)>=Role1_State->PositionX))
		{
			Role1_State->HP=Role1_State->HP-5;Role1_State->HurtCount=Role1_State->HurtCount+1;
		}
		if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}
		Role2_State->ActionRank=1;Role2_State->AttackRank=Role2_State->AttackRank+1;
		}break;
	}
}break;
		case 4:{
		switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,13);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);DrawLCD(Role2_State->PositionX-13,Role2_State->PositionY+Role2_Message->AttackerP,10);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,13);
		DrawLCD(Role2_State->PositionX-50,Role2_State->PositionY+Role2_Message->AttackerP,20);
		Role2_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);
			DrawLCD(Role2_State->PositionX-50,Role2_State->PositionY+Role2_Message->AttackerP,20);
			if(((Role2_State->PositionX-Role2_Message->AttackerWidth)<=Role1_State->PositionX+Role1_Message->Width)&&((Role2_State->PositionX-Role2_Message->AttackerWidth)>=Role1_State->PositionX))
		{
			Role1_State->HP=Role1_State->HP-16;Role1_State->HurtCount=Role1_State->HurtCount+1;
		}
		if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}
		Role2_State->ActionRank=1;Role2_State->AttackRank=1;
		}break;
	}
}break;
	}
}

void RightAttacking2(void)
{
	switch(Role2_State->AttackRank)
	{
		case 1:{
		switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,10);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,9);Role2_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,10);
			if(((Role2_State->PositionX+Role2_Message->Width+Role2_Message->AttackerWidth)>=Role1_State->PositionX)&&((Role2_State->PositionX+Role2_Message->Width+Role2_Message->AttackerWidth)<=Role1_State->PositionX+Role1_Message->Width))
		{
			Role1_State->HP=Role1_State->HP-1;Role1_State->HurtCount=Role1_State->HurtCount+1;
		}
		if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}
		Role2_State->ActionRank=1;Role2_State->AttackRank=Role2_State->AttackRank+1;
		}break;
	}
}break;
		case 2:{
		switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);
		DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+12+Role2_Message->AttackerP,10);DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+24+Role2_Message->AttackerP,10);
			DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,10);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);
		DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+12+Role2_Message->AttackerP,9);DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+24+Role2_Message->AttackerP,9);
		DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,9);Role2_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);
			DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+12+Role2_Message->AttackerP,10);DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+24+Role2_Message->AttackerP,10);
			DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,10);
			if(((Role2_State->PositionX+Role2_Message->Width+Role2_Message->AttackerWidth)>=Role1_State->PositionX)&&((Role2_State->PositionX+Role2_Message->Width+Role2_Message->AttackerWidth)<=Role1_State->PositionX+Role1_Message->Width))
		{
			Role1_State->HP=Role1_State->HP-3;Role1_State->HurtCount=Role1_State->HurtCount+1;
		}
		if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}
		Role2_State->ActionRank=1;Role2_State->AttackRank=Role2_State->AttackRank+1;
		}break;
	}
}break;
		case 3:{
		switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,13);DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,10);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);
		DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,15);
		DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,9);Role2_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,13);
			DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,15);DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,10);
			if(((Role2_State->PositionX+Role2_Message->Width+Role2_Message->AttackerWidth)>=Role1_State->PositionX)&&((Role2_State->PositionX+Role2_Message->Width+Role2_Message->AttackerWidth)<=Role1_State->PositionX+Role1_Message->Width))
		{
			Role1_State->HP=Role1_State->HP-5;Role1_State->HurtCount=Role1_State->HurtCount+1;
		}
		if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}
		Role2_State->ActionRank=1;Role2_State->AttackRank=Role2_State->AttackRank+1;
		}break;
	}
}break;
		case 4:{
		switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,13);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,10);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,13);
		DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,20);
		Role2_State->ActionRank=0;}break;
		case 0:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);
			DrawLCD(Role2_State->PositionX+Role2_Message->Width,Role2_State->PositionY+Role2_Message->AttackerP,20);
			if(((Role2_State->PositionX+Role2_Message->Width+Role2_Message->AttackerWidth)>=Role1_State->PositionX)&&((Role2_State->PositionX+Role2_Message->Width+Role2_Message->AttackerWidth)<=Role1_State->PositionX+Role1_Message->Width))
		{
			Role1_State->HP=Role1_State->HP-16;Role1_State->HurtCount=Role1_State->HurtCount+1;
		}
		if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}
		Role2_State->ActionRank=1;Role2_State->AttackRank=1;
		}break;
	}
}break;
	}
}

void LeftMoving2(void)
{
	switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,4);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{Role2_State->PositionX=Role2_State->PositionX-4;DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,4);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 4:{Role2_State->PositionX=Role2_State->PositionX-2;DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=0;}break;
		case 0:{
		if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}			
			Role2_State->ActionRank=1;
		
		}break;
	}
}

void RightMoving2(void)
{
	switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,5);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{Role2_State->PositionX=Role2_State->PositionX+4;DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,5);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 4:{Role2_State->PositionX=Role2_State->PositionX+2;DrawLCD(Role2_State->PositionX,Role2_State->PositionY,3);
		Role2_State->ActionRank=0;}break;
		case 0:{
			if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}		
			Role2_State->ActionRank=1;
		
		}break;
	}
}

void Standing2(void)
{
		switch(Role2_State->ActionRank)
	{
		
		case 1:{if(Role2_State->Head==RIGHT){DrawLCD(Role2_State->PositionX,Role2_State->PositionY,5);}
		if(Role2_State->Head==LEFT){DrawLCD(Role2_State->PositionX,Role2_State->PositionY,4);}
		Role2_State->ActionRank=0;}break;
		
		case 0:{if(Role2_State->Head==RIGHT){DrawLCD(Role2_State->PositionX,Role2_State->PositionY,5);}
		if(Role2_State->Head==LEFT){DrawLCD(Role2_State->PositionX,Role2_State->PositionY,4);}

		}break;
	}
	
}

void Hurting2(void)
{
	switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,0);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,0);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,1);Role2_State->ActionRank=0;}break;
		case 0:{
			if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}		
			Role2_State->ActionRank=1;
		
		}break;
	}
	
	
}

void Attacking(uint8_t id)
{
	if(id==1)
	{
		if(Role1_State->Head==LEFT)
		{
			Role1_State->Action=LATTACK;Role1_State->ActionRank=1;
		}
		if(Role1_State->Head==RIGHT)
		{
			Role1_State->Action=RATTACK;Role1_State->ActionRank=1;
		}
	}
		if(id==2)
	{
		if(Role2_State->Head==LEFT)
		{
			Role2_State->Action=LATTACK;Role2_State->ActionRank=1;
		}
				if(Role2_State->Head==RIGHT)
		{
			Role2_State->Action=RATTACK;Role2_State->ActionRank=1;
		}
		
	}
}

void RoleMovingRight(uint8_t id)
{
	if(id==1)
	{
		Role1_State->Action=RMOVE;Role1_State->ActionRank=1;Role1_State->Head=RIGHT;
	}
		if(id==2)
	{
		Role2_State->Action=RMOVE;Role2_State->ActionRank=1;Role2_State->Head=RIGHT;
	}
	
	
}

void RoleMovingLeft(uint8_t id)
{
	if(id==1)
	{
		Role1_State->Action=LMOVE;Role1_State->ActionRank=1;Role1_State->Head=LEFT;
	}
		if(id==2)
	{
		Role2_State->Action=LMOVE;Role2_State->ActionRank=1;Role2_State->Head=LEFT;
	}
	
	
}

void RoleSquat(uint8_t id)
{
		if(id==1)
	{
		Role1_State->Action=SQUAT;Role1_State->ActionRank=1;
	}
		if(id==2)
	{
		Role2_State->Action=SQUAT;Role2_State->ActionRank=1;
	}

}

void RoleJumping(uint8_t id)
{
			if(id==1)
	{
		Role1_State->Action=JUMP;Role1_State->ActionRank=1;
	}
		if(id==2)
	{
		Role2_State->Action=JUMP;Role2_State->ActionRank=1;
	}

	
}

void RoleHPshowing(void)
{
	DrawLCD(2,2,16);
	DrawLCD(2,24,17);
	if(Role1_State->HP>=1)
	DrawLCD(18,4,18);
	if(Role1_State->HP>=2)
	DrawLCD(24,4,18);
	if(Role1_State->HP>=3)
	DrawLCD(30,4,18);
	if(Role1_State->HP>=4)
	DrawLCD(36,4,18);	
	if(Role1_State->HP>=5)
	DrawLCD(42,4,18);	
	if(Role1_State->HP>=6)
	DrawLCD(48,4,18);	
	if(Role1_State->HP>=7)
	DrawLCD(54,4,18);	
	if(Role1_State->HP>=8)
	DrawLCD(60,4,18);	
	if(Role1_State->HP>=9)
	DrawLCD(66,4,18);	
	if(Role1_State->HP>=10)
	DrawLCD(72,4,18);	
	if(Role1_State->HP>=11)
	DrawLCD(78,4,18);
	if(Role1_State->HP>=12)
	DrawLCD(84,4,18);
	if(Role1_State->HP>=13)
	DrawLCD(90,4,18);
	if(Role1_State->HP>=14)
	DrawLCD(96,4,18);	
	if(Role1_State->HP>=15)
	DrawLCD(102,4,18);	
	if(Role1_State->HP>=16)
	DrawLCD(108,4,18);	
	if(Role1_State->HP>=17)
	DrawLCD(114,4,18);	
	if(Role1_State->HP>=18)
	DrawLCD(120,4,18);	
	if(Role1_State->HP>=19)
	DrawLCD(126,4,18);	
	if(Role1_State->HP>=20)
	DrawLCD(132,4,18);
	if(Role1_State->HP>=21)
	DrawLCD(138,4,18);
	if(Role1_State->HP>=22)
	DrawLCD(144,4,18);
	if(Role1_State->HP>=23)
	DrawLCD(150,4,18);
	if(Role1_State->HP>=24)
	DrawLCD(156,4,18);	
	if(Role1_State->HP>=25)
	DrawLCD(162,4,18);	
	if(Role1_State->HP>=26)
	DrawLCD(168,4,18);	
	if(Role1_State->HP>=27)
	DrawLCD(174,4,18);	
	if(Role1_State->HP>=28)
	DrawLCD(180,4,18);	
	if(Role1_State->HP>=29)
	DrawLCD(186,4,18);	
	if(Role1_State->HP>=30)
	DrawLCD(192,4,18);	
	if(Role1_State->HP>=31)
	DrawLCD(198,4,18);
	if(Role1_State->HP>=32)
	DrawLCD(204,4,18);
	if(Role1_State->HP>=33)
	DrawLCD(210,4,18);
	if(Role1_State->HP>=34)
	DrawLCD(216,4,18);	
	if(Role1_State->HP>=35)
	DrawLCD(222,4,18);	
	if(Role1_State->HP>=36)
	DrawLCD(8,12,18);	
	if(Role1_State->HP>=37)
	DrawLCD(14,12,18);	
	if(Role1_State->HP>=38)
	DrawLCD(20,12,18);	
	if(Role1_State->HP>=39)
	DrawLCD(26,12,18);	
	if(Role1_State->HP>=40)
	DrawLCD(32,12,18);
	if(Role1_State->HP>=41)
	DrawLCD(38,12,18);
	if(Role1_State->HP>=42)
	DrawLCD(44,12,18);
	if(Role1_State->HP>=43)
	DrawLCD(50,12,18);
	if(Role1_State->HP>=44)
	DrawLCD(56,12,18);	
	if(Role1_State->HP>=45)
	DrawLCD(62,12,18);	
	if(Role1_State->HP>=46)
	DrawLCD(68,12,18);	
	if(Role1_State->HP>=47)
	DrawLCD(74,12,18);	
	if(Role1_State->HP>=48)
	DrawLCD(80,12,18);	
	if(Role1_State->HP>=49)
	DrawLCD(86,12,18);	
	if(Role1_State->HP>=50)
	DrawLCD(92,12,18);	
	if(Role1_State->HP>=51)
	DrawLCD(98,12,18);
	if(Role1_State->HP>=52)
	DrawLCD(104,12,18);
	if(Role1_State->HP>=53)
	DrawLCD(110,12,18);
	if(Role1_State->HP>=54)
	DrawLCD(116,12,18);	
	if(Role1_State->HP>=55)
	DrawLCD(122,12,18);	
	if(Role1_State->HP>=56)
	DrawLCD(128,12,18);	
	if(Role1_State->HP>=57)
	DrawLCD(134,12,18);	
	if(Role1_State->HP>=58)
	DrawLCD(140,12,18);	
	if(Role1_State->HP>=59)
	DrawLCD(146,12,18);	
	if(Role1_State->HP>=60)
	DrawLCD(152,12,18);
	if(Role1_State->HP>=61)
	DrawLCD(158,12,18);
	if(Role1_State->HP>=62)
	DrawLCD(164,12,18);
	if(Role1_State->HP>=63)
	DrawLCD(170,12,18);
	if(Role1_State->HP>=64)
	DrawLCD(176,12,18);	
	if(Role1_State->HP>=65)
	DrawLCD(182,12,18);	
	if(Role1_State->HP>=66)
	DrawLCD(188,12,18);	
	if(Role1_State->HP>=67)
	DrawLCD(194,12,18);	
	if(Role1_State->HP>=68)
	DrawLCD(200,12,18);	
	if(Role1_State->HP>=69)
	DrawLCD(206,12,18);	
	if(Role1_State->HP>=70)
	DrawLCD(212,12,18);	
	if(Role1_State->HP>=71)
	DrawLCD(218,12,18);
	if(Role1_State->HP>=72)
	DrawLCD(224,12,18);
	if(Role2_State->HP>=1)
	DrawLCD(18,24,18);
	if(Role2_State->HP>=2)
	DrawLCD(24,24,18);
	if(Role2_State->HP>=3)
	DrawLCD(30,24,18);
	if(Role2_State->HP>=4)
	DrawLCD(36,24,18);	
	if(Role2_State->HP>=5)
	DrawLCD(42,24,18);	
	if(Role2_State->HP>=6)
	DrawLCD(48,24,18);	
	if(Role2_State->HP>=7)
	DrawLCD(54,24,18);	
	if(Role2_State->HP>=8)
	DrawLCD(60,24,18);	
	if(Role2_State->HP>=9)
	DrawLCD(66,24,18);	
	if(Role2_State->HP>=10)
	DrawLCD(72,24,18);	
	if(Role2_State->HP>=11)
	DrawLCD(78,24,18);
	if(Role2_State->HP>=32)
	DrawLCD(84,24,18);
	if(Role2_State->HP>=13)
	DrawLCD(90,24,18);
	if(Role2_State->HP>=14)
	DrawLCD(96,24,18);	
	if(Role2_State->HP>=15)
	DrawLCD(102,24,18);	
	if(Role2_State->HP>=16)
	DrawLCD(108,24,18);	
	if(Role2_State->HP>=17)
	DrawLCD(114,24,18);	
	if(Role2_State->HP>=18)
	DrawLCD(120,24,18);	
	if(Role2_State->HP>=19)
	DrawLCD(126,24,18);	
	if(Role2_State->HP>=20)
	DrawLCD(132,24,18);
	if(Role2_State->HP>=21)
	DrawLCD(138,24,18);
	if(Role2_State->HP>=22)
	DrawLCD(144,24,18);
	if(Role2_State->HP>=23)
	DrawLCD(150,24,18);
	if(Role2_State->HP>=24)
	DrawLCD(156,24,18);	
	if(Role2_State->HP>=25)
	DrawLCD(162,24,18);	
	if(Role2_State->HP>=26)
	DrawLCD(168,24,18);	
	if(Role2_State->HP>=27)
	DrawLCD(174,24,18);	
	if(Role2_State->HP>=28)
	DrawLCD(180,24,18);	
	if(Role2_State->HP>=29)
	DrawLCD(186,24,18);	
	if(Role2_State->HP>=30)
	DrawLCD(192,24,18);	
	if(Role2_State->HP>=31)
	DrawLCD(198,24,18);
	if(Role2_State->HP>=32)
	DrawLCD(204,24,18);
	if(Role2_State->HP>=33)
	DrawLCD(210,24,18);
	if(Role2_State->HP>=34)
	DrawLCD(216,24,18);	
	if(Role2_State->HP>=35)
	DrawLCD(222,24,18);	
	if(Role2_State->HP>=36)
	DrawLCD(8,32,18);	
	if(Role2_State->HP>=37)
	DrawLCD(14,32,18);	
	if(Role2_State->HP>=38)
	DrawLCD(20,32,18);	
	if(Role2_State->HP>=39)
	DrawLCD(26,32,18);	
	if(Role2_State->HP>=40)
	DrawLCD(32,32,18);
	if(Role2_State->HP>=41)
	DrawLCD(38,32,18);
	if(Role2_State->HP>=42)
	DrawLCD(44,32,18);
	if(Role2_State->HP>=43)
	DrawLCD(50,32,18);
	if(Role2_State->HP>=44)
	DrawLCD(56,32,18);	
	if(Role2_State->HP>=45)
	DrawLCD(62,32,18);	
	if(Role2_State->HP>=46)
	DrawLCD(68,32,18);	
	if(Role2_State->HP>=47)
	DrawLCD(74,32,18);	
	if(Role2_State->HP>=48)
	DrawLCD(80,32,18);	
	if(Role2_State->HP>=49)
	DrawLCD(86,32,18);	
	if(Role2_State->HP>=50)
	DrawLCD(92,32,18);	
	if(Role2_State->HP>=51)
	DrawLCD(98,32,18);
	if(Role2_State->HP>=52)
	DrawLCD(104,32,18);
	if(Role2_State->HP>=53)
	DrawLCD(110,32,18);
	if(Role2_State->HP>=54)
	DrawLCD(116,32,18);	
	if(Role2_State->HP>=55)
	DrawLCD(122,32,18);	
	if(Role2_State->HP>=56)
	DrawLCD(128,32,18);	
	if(Role2_State->HP>=57)
	DrawLCD(134,32,18);	
	if(Role2_State->HP>=58)
	DrawLCD(140,32,18);	
	if(Role2_State->HP>=59)
	DrawLCD(146,32,18);	
	if(Role2_State->HP>=60)
	DrawLCD(152,32,18);
	if(Role2_State->HP>=61)
	DrawLCD(158,32,18);
	if(Role2_State->HP>=62)
	DrawLCD(164,32,18);
	if(Role2_State->HP>=63)
	DrawLCD(170,32,18);
	if(Role2_State->HP>=64)
	DrawLCD(176,32,18);	
	if(Role2_State->HP>=65)
	DrawLCD(182,32,18);	
	if(Role2_State->HP>=66)
	DrawLCD(188,32,18);	
	if(Role2_State->HP>=67)
	DrawLCD(194,32,18);	
	if(Role2_State->HP>=68)
	DrawLCD(200,32,18);	
	if(Role2_State->HP>=69)
	DrawLCD(206,32,18);	
	if(Role2_State->HP>=70)
	DrawLCD(212,32,18);	
	if(Role2_State->HP>=71)
	DrawLCD(218,32,18);
	if(Role2_State->HP>=72)
	DrawLCD(224,32,18);

}

void Shooting1(void)
{
	switch(Role1_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 4:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 5:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 6:{DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);Role1_State->ActionRank=0;}break;
		case 0:{
			DrawLCD(Role1_State->PositionX,Role1_State->PositionY,2);
			if(Map_State->DamageBlock1==ZERO){Map_State->DamageBlock1=FIRE;Map_State->DamageBlock1Head=Role1_State->Head;Map_State->BlockRank1=1;
		Map_State->DamageBlock1X=Role1_State->PositionX+Role1_Message->AttackerWidth;Map_State->DamageBlock1Y=Role1_State->PositionY;}
			else if(Map_State->DamageBlock2==ZERO){Map_State->DamageBlock2=FIRE;Map_State->DamageBlock2Head=Role2_State->Head;Map_State->BlockRank2=1;
		Map_State->DamageBlock1X=Role1_State->PositionX+Role1_Message->AttackerWidth;Map_State->DamageBlock1Y=Role1_State->PositionY;}
					if(Role1_State->PositionY==200)
		{Role1_State->Action=STAND;}
		else
		{
			Role1_State->Action=FLOUTING;
		}Role1_State->ActionRank=1;
		}break;
	
}
}

void Damage_define(void)
{
	if(Map_State->DamageBlock1!=ZERO)
	{
	if((Map_State->DamageBlock1X>Role1_State->PositionX)&&(Map_State->DamageBlock1X<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock1Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP-16;
}
		if((Map_State->DamageBlock1X>Role2_State->PositionX)&&(Map_State->DamageBlock1X<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock1Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP-16;
}
}
		if(Map_State->DamageBlock2!=ZERO)
	{
	if((Map_State->DamageBlock2X>Role1_State->PositionX)&&(Map_State->DamageBlock2X<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock2Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP-3;
}
		if((Map_State->DamageBlock2X>Role2_State->PositionX)&&(Map_State->DamageBlock2X<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock2Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP-3;
}
}
		if(Map_State->DamageBlock3!=ZERO)
	{
	if((Map_State->DamageBlock3X>Role1_State->PositionX)&&(Map_State->DamageBlock3X<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock3Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP-3;
}
		if((Map_State->DamageBlock3X>Role2_State->PositionX)&&(Map_State->DamageBlock3X<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock3Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP-3;
}
}
	if(Map_State->DamageBlock4!=ZERO)
	{
	if((Map_State->DamageBlock4X>Role1_State->PositionX)&&(Map_State->DamageBlock4X<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock4Y>(Role1_State->PositionY)))
{
	Role1_State->HurtCount=2;
}
		if((Map_State->DamageBlock4X>Role2_State->PositionX)&&(Map_State->DamageBlock4X<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock4Y>(Role2_State->PositionY)))
{
	Role2_State->HurtCount=2;
}
}
		if(Map_State->DamageBlock5!=ZERO)
	{
	if((Map_State->DamageBlock5X>Role1_State->PositionX)&&(Map_State->DamageBlock5X<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock5Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP-2;
}
		if((Map_State->DamageBlock5X>Role2_State->PositionX)&&(Map_State->DamageBlock5X<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock5Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP-2;
}
}
		if(Map_State->DamageBlock6!=ZERO)
	{
	if((Map_State->DamageBlock6X>Role1_State->PositionX)&&(Map_State->DamageBlock6X<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock6Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP-2;
}
		if((Map_State->DamageBlock6X>Role2_State->PositionX)&&(Map_State->DamageBlock6X<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock6Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP-2;
}
}
}


void Fire(void)
{
	if((Map_State->DamageBlock1X+12)<320)
	{
		switch(Map_State->BlockRank1)
	{
		
		case 1:{Map_State->DamageBlock1Y=Role1_State->PositionY-100 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 2:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 3:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 4:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		
		case 5:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 6:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 7:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 8:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 9:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 10:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 11:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=(Map_State->BlockRank1)+1;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 12:{Map_State->DamageBlock1Y=Map_State->DamageBlock1Y+10 ;if(Map_State->DamageBlock1Head==LEFT){Map_State->DamageBlock1X=Map_State->DamageBlock1X-Block_move->Block1step;}
		else if(Map_State->DamageBlock1Head==RIGHT){Map_State->DamageBlock1X=Map_State->DamageBlock1X+Block_move->Block1step;}
		Map_State->BlockRank1=0;DrawLCD(Map_State->DamageBlock1X,Map_State->DamageBlock1Y,14);}break;
		case 0:{Map_State->DamageBlock1=ZERO;Map_State->BlockRank1=1;
			
		}break;
	
}}else
	{
		Map_State->DamageBlock1=ZERO;Map_State->BlockRank1=0;
	}

}

void FireGo(void)
{
	if((Map_State->DamageBlock3X+12)<320)
	{
		switch(Map_State->BlockRank3)
	{
		
		case 1:{Map_State->DamageBlock3Y=Role1_State->PositionY+30;if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Role1_State->PositionX;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Role1_State->PositionX+Role1_Message->Width;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 2:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 3:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 4:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 5:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 6:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 7:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 8:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 9:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 10:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 11:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=(Map_State->BlockRank3)+1;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 12:{if(Map_State->DamageBlock3Head==LEFT){Map_State->DamageBlock3X=Map_State->DamageBlock3X-Block_move->Block3step;}
		else if(Map_State->DamageBlock3Head==RIGHT){Map_State->DamageBlock3X=Map_State->DamageBlock3X+Block_move->Block3step;}
		Map_State->BlockRank3=0;DrawLCD(Map_State->DamageBlock3X,Map_State->DamageBlock3Y,14);}break;
		case 0:{Map_State->DamageBlock3=ZERO;Map_State->BlockRank3=1;
			
		}break;
	
}}else
	{
		Map_State->DamageBlock3=ZERO;Map_State->BlockRank3=0;
	}

	
	
}

void IceGo(void)
{
	if((Map_State->DamageBlock6X+12)<320)
	{
		switch(Map_State->BlockRank6)
	{
		
		case 1:{Map_State->DamageBlock6Y=Role2_State->PositionY+30;if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Role2_State->PositionX;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Role2_State->PositionX+Role2_Message->Width;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 2:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 3:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 4:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 5:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 6:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 7:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 8:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 9:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 10:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 11:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=(Map_State->BlockRank6)+1;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 12:{if(Map_State->DamageBlock6Head==LEFT){Map_State->DamageBlock6X=Map_State->DamageBlock6X-Block_move->Block6step;}
		else if(Map_State->DamageBlock6Head==RIGHT){Map_State->DamageBlock6X=Map_State->DamageBlock6X+Block_move->Block6step;}
		Map_State->BlockRank6=0;DrawLCD(Map_State->DamageBlock6X,Map_State->DamageBlock6Y,15);}break;
		case 0:{Map_State->DamageBlock6=ZERO;Map_State->BlockRank6=1;
			
		}break;
	
}}else
	{
		Map_State->DamageBlock6=ZERO;Map_State->BlockRank6=0;
	}

	
	
}

void MapDraw(void)
{
	for(int i=0;i<=318;i=i+2)
	{
		DrawLCD(0,i,19);
		
	}
	
}


void Jumping1(void)
{

		switch(Role1_State->ActionRank)
	{
		
		case 1:{if(Role1_State->Head==LEFT)
			  DrawLCD(Role1_State->PositionX,Role1_State->PositionY,12);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,13);
		Role1_State->PositionY=Role1_State->PositionY-6;
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{
			if(Role1_State->Head==LEFT)
			  DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{
			if(Role1_State->Head==LEFT)
			  DrawLCD(Role1_State->PositionX,Role1_State->PositionY,12);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,13);
		Role1_State->PositionY=Role1_State->PositionY-6;
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 4:{
			if(Role1_State->Head==LEFT)
			  DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=0;}break;
		case 0:{
			Role1_State->Action=FLOUTING;Role1_State->ActionRank=1;
		
		}break;
	}
	
	
}

void Floating1(void)
{
		switch(Role1_State->ActionRank)
	{
		
		case 1:{
						if(Role1_State->Head==LEFT)
			  DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{
					if(Role1_State->Head==LEFT)
			  DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{
					if(Role1_State->Head==LEFT)
			  DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 4:{
					if(Role1_State->Head==LEFT)
			  DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 5:{
					if(Role1_State->Head==LEFT)
			  DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=0;}break;
		case 0:{Role1_State->Action=DOWN;Role1_State->ActionRank=1;}break;
		default:break;
		
	}
}

void Down1(void)
{
			switch(Role1_State->ActionRank)
	{
		case 1:{down_height=200-Role1_State->PositionY;
			Role1_State->PositionY=Role1_State->PositionY+down_height/4;
			if(Role1_State->Head==LEFT)
			DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{
					Role1_State->PositionY=Role1_State->PositionY+down_height/4;
			if(Role1_State->Head==LEFT)
			DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{
					Role1_State->PositionY=Role1_State->PositionY+down_height/4;
			if(Role1_State->Head==LEFT)
			DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 4:{
					Role1_State->PositionY=Role1_State->PositionY+down_height/4;
			if(Role1_State->Head==LEFT)
			DrawLCD(Role1_State->PositionX,Role1_State->PositionY,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY,7);
		Role1_State->ActionRank=0;}break;

		case 0:{Role1_State->Action=STAND;Role1_State->ActionRank=1;}break;
		default:break;
	}
}

void Squating1(void)
{
	Cure_define1();
		switch(Role1_State->ActionRank)
	{
		
		case 1:{if(Role1_State->Head==LEFT)
			DrawLCD(Role1_State->PositionX,Role1_State->PositionY+7,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY+7,7);
		DrawLCD(Role1_State->PositionX-5,Role1_State->PositionY-5,20);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 2:{
			if(Role1_State->Head==LEFT)
			DrawLCD(Role1_State->PositionX,Role1_State->PositionY+7,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY+7,7);
		DrawLCD(Role1_State->PositionX-5,Role1_State->PositionY-5,20);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 3:{
			if(Role1_State->Head==LEFT)
			DrawLCD(Role1_State->PositionX,Role1_State->PositionY+7,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY+7,7);
		DrawLCD(Role1_State->PositionX-5,Role1_State->PositionY-5,20);
		Role1_State->ActionRank=(Role1_State->ActionRank)+1;}break;
		case 4:{
			if(Role1_State->Head==LEFT)
			DrawLCD(Role1_State->PositionX,Role1_State->PositionY+7,6);
			else
				DrawLCD(Role1_State->PositionX,Role1_State->PositionY+7,7);
		DrawLCD(Role1_State->PositionX-5,Role1_State->PositionY-5,20);
		Role1_State->ActionRank=0;}break;
		case 0:{
					
		Role1_State->Action=STAND;
		Role1_State->ActionRank=1;
		
		}break;
	}
	
}

void Cure_define1(void)
{
	
	if(Map_State->DamageBlock1!=ZERO)
	{
	if(((Map_State->DamageBlock1X+10)>Role1_State->PositionX)&&((Map_State->DamageBlock1X-10)<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock1Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP+3;
}

}
	if(Map_State->DamageBlock2!=ZERO)
	{
	if(((Map_State->DamageBlock2X+10)>Role1_State->PositionX)&&((Map_State->DamageBlock2X-10)<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock2Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP+3;
}

}
	if(Map_State->DamageBlock3!=ZERO)
	{
	if(((Map_State->DamageBlock3X+10)>Role1_State->PositionX)&&((Map_State->DamageBlock3X-10)<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock3Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP+3;
}

}	
	if(Map_State->DamageBlock4!=ZERO)
	{
	if(((Map_State->DamageBlock4X+10)>Role1_State->PositionX)&&((Map_State->DamageBlock4X-10)<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock4Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP+3;
}

}
	if(Map_State->DamageBlock5!=ZERO)
	{
	if(((Map_State->DamageBlock5X+10)>Role1_State->PositionX)&&((Map_State->DamageBlock5X-10)<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock5Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP+3;
}

}
	if(Map_State->DamageBlock6!=ZERO)
	{
	if(((Map_State->DamageBlock6X+10)>Role1_State->PositionX)&&((Map_State->DamageBlock6X-10)<(Role1_State->PositionX+Role1_Message->Width))&&(Map_State->DamageBlock6Y>(Role1_State->PositionY)))
{
	Role1_State->HP=Role1_State->HP+3;
}

}
}

void Cure_define2(void)
{
	
	if(Map_State->DamageBlock1!=ZERO)
	{
	if(((Map_State->DamageBlock1X+10)>Role2_State->PositionX)&&((Map_State->DamageBlock1X-10)<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock1Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP+5;
}

}
	if(Map_State->DamageBlock2!=ZERO)
	{
	if(((Map_State->DamageBlock2X+10)>Role2_State->PositionX)&&((Map_State->DamageBlock2X-10)<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock2Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP+5;
}

}
	if(Map_State->DamageBlock3!=ZERO)
	{
	if(((Map_State->DamageBlock3X+10)>Role2_State->PositionX)&&((Map_State->DamageBlock3X-10)<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock3Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP+5;
}

}	
	if(Map_State->DamageBlock4!=ZERO)
	{
	if(((Map_State->DamageBlock4X+10)>Role2_State->PositionX)&&((Map_State->DamageBlock4X-10)<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock4Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP+5;
}

}
	if(Map_State->DamageBlock5!=ZERO)
	{
	if(((Map_State->DamageBlock5X+10)>Role2_State->PositionX)&&((Map_State->DamageBlock5X-10)<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock5Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP+5;
}

}
	if(Map_State->DamageBlock6!=ZERO)
	{
	if(((Map_State->DamageBlock6X+10)>Role2_State->PositionX)&&((Map_State->DamageBlock6X-10)<(Role2_State->PositionX+Role2_Message->Width))&&(Map_State->DamageBlock6Y>(Role2_State->PositionY)))
{
	Role2_State->HP=Role2_State->HP+5;
}

}
}

void Shooting2(void)
{
	switch(Role2_State->ActionRank)
	{
		
		case 1:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 4:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 5:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 6:{DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);Role2_State->ActionRank=0;}break;
		case 0:{
			DrawLCD(Role2_State->PositionX,Role2_State->PositionY,2);
			if(Map_State->DamageBlock4==ZERO){Map_State->DamageBlock4=ICE;Map_State->DamageBlock4Head=Role2_State->Head;Map_State->BlockRank4=1;
		Map_State->DamageBlock4X=Role2_State->PositionX+Role2_Message->AttackerWidth;Map_State->DamageBlock4Y=Role2_State->PositionY;}
			else if(Map_State->DamageBlock5==ZERO){Map_State->DamageBlock5=ICE;Map_State->DamageBlock5Head=Role2_State->Head;Map_State->BlockRank5=1;
		Map_State->DamageBlock4X=Role2_State->PositionX+Role2_Message->AttackerWidth;Map_State->DamageBlock4Y=Role2_State->PositionY;}
					if(Role2_State->PositionY==200)
		{Role2_State->Action=STAND;}
		else
		{
			Role2_State->Action=FLOUTING;
		}Role2_State->ActionRank=1;
		}break;
	
}
}

void Ice(void)
{
	if((Map_State->DamageBlock4X+12)<320)
	{
		switch(Map_State->BlockRank4)
	{
		
		case 1:{Map_State->DamageBlock4Y=Role1_State->PositionY-100 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 2:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 3:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 4:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		
		case 5:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 6:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 7:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 8:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 9:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 10:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 11:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=(Map_State->BlockRank4)+1;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 12:{Map_State->DamageBlock4Y=Map_State->DamageBlock4Y+10 ;if(Map_State->DamageBlock4Head==LEFT){Map_State->DamageBlock4X=Map_State->DamageBlock4X-Block_move->Block4step;}
		else if(Map_State->DamageBlock4Head==RIGHT){Map_State->DamageBlock4X=Map_State->DamageBlock4X+Block_move->Block4step;}
		Map_State->BlockRank4=0;DrawLCD(Map_State->DamageBlock4X,Map_State->DamageBlock4Y,15);}break;
		case 0:{Map_State->DamageBlock4=ZERO;Map_State->BlockRank4=1;
			
		}break;
	
}}else
	{
		Map_State->DamageBlock4=ZERO;Map_State->BlockRank4=0;
	}

}

void Jumping2(void)
{

		switch(Role2_State->ActionRank)
	{
		
		case 1:{if(Role2_State->Head==LEFT)
			  DrawLCD(Role2_State->PositionX,Role2_State->PositionY,12);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,13);
		Role2_State->PositionY=Role2_State->PositionY-3;
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{
			if(Role2_State->Head==LEFT)
			  DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{
			if(Role2_State->Head==LEFT)
			  DrawLCD(Role2_State->PositionX,Role2_State->PositionY,12);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,13);
		Role2_State->PositionY=Role2_State->PositionY-3;
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 4:{
			if(Role2_State->Head==LEFT)
			  DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=0;}break;
		case 0:{
			Role2_State->Action=FLOUTING;Role2_State->ActionRank=1;
		
		}break;
	}
	
	
}

void Floating2(void)
{
		switch(Role2_State->ActionRank)
	{
		
		case 1:{
						if(Role2_State->Head==LEFT)
			  DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{
					if(Role2_State->Head==LEFT)
			  DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{
					if(Role2_State->Head==LEFT)
			  DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 4:{
					if(Role2_State->Head==LEFT)
			  DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 5:{
					if(Role2_State->Head==LEFT)
			  DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=0;}break;
		case 0:{Role2_State->Action=DOWN;Role2_State->ActionRank=1;}break;
		default:break;
		
	}
}

void Down2(void)
{
			switch(Role2_State->ActionRank)
	{
		case 1:{down_height=200-Role2_State->PositionY;
			Role2_State->PositionY=Role2_State->PositionY+down_height/4;
			if(Role2_State->Head==LEFT)
			DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{
					Role2_State->PositionY=Role2_State->PositionY+down_height/4;
			if(Role2_State->Head==LEFT)
			DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{
					Role2_State->PositionY=Role2_State->PositionY+down_height/4;
			if(Role2_State->Head==LEFT)
			DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 4:{
					Role2_State->PositionY=Role2_State->PositionY+down_height/4;
			if(Role2_State->Head==LEFT)
			DrawLCD(Role2_State->PositionX,Role2_State->PositionY,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY,7);
		Role2_State->ActionRank=0;}break;

		case 0:{Role2_State->Action=STAND;Role2_State->ActionRank=1;}break;
		default:break;
	}
}

void Squating2(void)
{
	Cure_define2();
		switch(Role2_State->ActionRank)
	{
		
		case 1:{if(Role2_State->Head==LEFT)
			DrawLCD(Role2_State->PositionX,Role2_State->PositionY+7,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY+7,7);
		DrawLCD(Role2_State->PositionX-5,Role2_State->PositionY-5,20);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 2:{
			if(Role2_State->Head==LEFT)
			DrawLCD(Role2_State->PositionX,Role2_State->PositionY+7,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY+7,7);
		DrawLCD(Role2_State->PositionX-5,Role2_State->PositionY-5,20);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 3:{
			if(Role2_State->Head==LEFT)
			DrawLCD(Role2_State->PositionX,Role2_State->PositionY+7,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY+7,7);
		DrawLCD(Role2_State->PositionX-5,Role2_State->PositionY-5,20);
		Role2_State->ActionRank=(Role2_State->ActionRank)+1;}break;
		case 4:{
			if(Role2_State->Head==LEFT)
			DrawLCD(Role2_State->PositionX,Role2_State->PositionY+7,6);
			else
				DrawLCD(Role2_State->PositionX,Role2_State->PositionY+7,7);
		DrawLCD(Role2_State->PositionX-5,Role2_State->PositionY-5,20);
		Role2_State->ActionRank=0;}break;
		case 0:{
					
		Role2_State->Action=STAND;
		Role2_State->ActionRank=1;
		
		}break;
	}
	
}
