

void drwPlayer(Snake cplay)
{
  gb.display.setColor(cplay.color);
  for(byte i=0;i<VITTESSE_SNAKE;i++)
  {
    for(byte j=0;j<VITTESSE_SNAKE;j++)
    {
      gb.display.drawPixel(cplay.x+i,cplay.y+j);
    }
   }
//  gb.display.fillRect(play.x,play.y,VITTESSE_SNAKE,VITTESSE_SNAKE);
}

void updPlayer(Snake *cplay)
{
  if(cplay->dir == dir_up)
     cplay->y -= VITTESSE_SNAKE;
  else if(cplay->dir == dir_down)
    cplay->y += VITTESSE_SNAKE;
  else if(cplay->dir == dir_left)
    cplay->x -= VITTESSE_SNAKE;
  else if(cplay->dir == dir_right)
    cplay->x += VITTESSE_SNAKE;
    
  if(gb.display.getPixelColor(cplay->x, cplay->y) != WHITE)
  {
      cplay->life = 0;
  }
}


void human(Snake *cplay)
{
  if(gb.buttons.pressed(BTN_UP))
  {
    cplay->dir = dir_up;
  }
  else if(gb.buttons.pressed(BTN_DOWN))
  {
    cplay->dir = dir_down;
  }
  else if(gb.buttons.pressed(BTN_LEFT))
  {
    cplay->dir = dir_left;
  }
  else if(gb.buttons.pressed(BTN_RIGHT))
  {
    cplay->dir = dir_right;
  }
}

void ia(Snake *cplay)
{
  boolean isOk = false;
  uint8_t forceSortie = 0;
  
  if(random(0,40) == 0)
  {
     cplay->dir = allDir[random(0,4)];
  }
  
  do{
    int8_t nextX = cplay->x;
    int8_t nextY = cplay->y;
    if(cplay->dir == dir_up)
       nextY -= VITTESSE_SNAKE;
    else if(cplay->dir == dir_down)
      nextY += VITTESSE_SNAKE;
    else if(cplay->dir == dir_left)
      nextX -= VITTESSE_SNAKE;
    else if(cplay->dir == dir_right)
      nextX += VITTESSE_SNAKE;
     
    
    if(gb.display.getPixelColor(nextX, nextY) == WHITE)
    {
        isOk = true;
    }
    else {
      cplay->dir = allDir[random(0,4)];
    }
  }while(!isOk && forceSortie++<10);
    
}

void movePlayerSlave()
{
   if(gb.buttons.pressed(BTN_RIGHT))
  {
    bt_right = true;
  }
  else if(gb.buttons.pressed(BTN_LEFT))
  {
    bt_left = true;
  }
  if(gb.buttons.pressed(BTN_UP))
  {
    bt_up = true;
  }
  else if(gb.buttons.pressed(BTN_DOWN))
  {
    bt_down = true;
  }
}

void updatePlayer()
{
  updPlayer(&p1);
  updPlayer(&p2);
}


void drawPlayer()
{ 
  drwPlayer(p1);
  drwPlayer(p2);
}
