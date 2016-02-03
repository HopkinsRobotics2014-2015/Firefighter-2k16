

void Move(p3vecf pie)
{
  float rotation = atan(pie.y/pie.x);
  rotation += currentOrientation.angle;
  rotate(rotation);
  float distance = pie.x*pie.x + pie.y*pie.y;
  distance = sqrt(distance);
  drive(distance);
  rotation = -(currentorientation.angle-pie.angle);
  rotate(rotation);
}

move (0,100,-90);
move (0,74,-90);
move (0,72,0);
//firefight
rotate (180);
move (0,74,90);
move (0,72,-90);
move (0,107,-90);
move (0,74,0);
//firefight
rotate (180);
move (0,74,90);
move (0,46,-90);
move (0,53,0);
//firefight
move (0,70,90);
move (0,198,90);
move (0,51,90);
move (0,50,0);
//firefight
rotate (180);
move (0,50,90);
move (0,72,90);
