void CornerShrink()
{
  for(int j=0;j<4;j++){
for(int i=0;i<9;i++) {CubeOutline(0,0,0,i,1,1); LedShow();}

for(int i=0;i<9;i++) {CubeOutline(i,0,0,8-i,1,1); LedShow();}
for(int i=0;i<9;i++) {CubeOutline(8-i,0,0,i,1,1); LedShow();} //Back Left Down

for(int i=0;i<9;i++) {CubeOutline(0,i,i,8-i,1,1); LedShow();}
for(int i=0;i<9;i++) {CubeOutline(0,8-i,8-i,i,1,1); LedShow();} //Front Right Up

for(int i=0;i<9;i++) {CubeOutline(i,i,0   ,8-i,1,1); LedShow();}
for(int i=0;i<9;i++) {CubeOutline(8-i,8-i,0   ,i,1,1); LedShow();} //Front Left Down

for(int i=0;i<9;i++) {CubeOutline(i,0,i,    8-i,1,1); LedShow();}
for(int i=0;i<9;i++) {CubeOutline(8-i,0,8-i,    i,1,1); LedShow();} //Back Left Up


for(int i=0;i<9;i++) {CubeOutline(0,0,i,    8-i,1,1); LedShow();}
for(int i=0;i<9;i++) {CubeOutline(0,0,8-i,    i,1,1); LedShow();} //Back Right Up

for(int i=0;i<9;i++) {CubeOutline(0,i,0,    8-i,1,1); LedShow();}
for(int i=0;i<9;i++) {CubeOutline(0,8-i,0,    i,1,1); LedShow();} //Front Right Down

for(int i=0;i<9;i++) {CubeOutline(i,i,i,    8-i,1,1); LedShow();}
for(int i=0;i<9;i++) {CubeOutline(8-i,8-i,8-i,    i,1,1); LedShow();} //Front Left Up

for(int i=0;i<9;i++) {CubeOutline(0,0,0,8-i,1,1); LedShow();}
  }
  
  for(int i=0;i<4;i++) {CubeOutline(i,i,i,0,1,1); LedShow();}

for(int i=0;i<18;i++){
  CubeOutline(4,4,4,0,1,1); LedShow();
  CubeOutline(3,3,3,2,0,1); LedShow();
  CubeOutline(2,2,2,4,0,1); LedShow();
  CubeOutline(1,1,1,6,0,1); LedShow();
  CubeOutline(0,0,0,8,0,1); LedShow();

  CubeOutline(4,4,4,0,0,0); LedShow();
  CubeOutline(3,3,3,2,0,0); LedShow();
  CubeOutline(2,2,2,4,0,0); LedShow();
  CubeOutline(1,1,1,6,0,0); LedShow();
  CubeOutline(0,0,0,8,0,0); LedShow();
}


}
