
/*
back light are a 2*4 led grid
0000
0000

0100
0010

0110
0110

1111
1111

1101
1011

1001
1001

0000
0000
*/
uint8_t backLightEffectPulseGrid[7][2] = {
  {0,0},
  {4,2},
  {6,6},
  {15,15},
  {13,11},
  {9,9},
  {0,0}
  };

void backLightEffectPulse(int pulseSpeed, Color color)
{
  int now = (gb.frameCount / pulseSpeed) % 7;
  for(uint8_t i=0;i< 4; i++){
    

    if((backLightEffectPulseGrid[now][0] >> i & 1) == 1){
      //gb.display.drawPixel(0, i, color);
      gb.lights.drawPixel(0, i, color); 
    }
    if((backLightEffectPulseGrid[now][1] >> i & 1) == 1){
      //gb.display.drawPixel(1, i, color);
      gb.lights.drawPixel(1, i, color); 
    }    

    uint8_t y2 = backLightEffectPulseGrid[i][1];
  }
}

void backLightEffectSonar()
{
  
}

