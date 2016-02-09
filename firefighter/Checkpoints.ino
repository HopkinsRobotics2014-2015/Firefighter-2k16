
checkpoint[] checkpoints;

void setup () {
  checkpoints = new checkpoint[17];
  checkpoints[0] = new checkpoint (23, 42);
  checkpoints[1] = new checkpoint (23, 114);
  checkpoints[2] = new checkpoint (23, 166);
  checkpoints[3] = new checkpoint (23, 221);
  checkpoints[4] = new checkpoint (97, 23);
  checkpoints[5] = new checkpoint (97, 114);
  checkpoints[6] = new checkpoint (97, 175);
  checkpoints[7] = new checkpoint (97, 221);
  checkpoints[8] = new checkpoint (143, 73);
  checkpoints[9] = new checkpoint (143, 114);
  checkpoints[10] = new checkpoint (150, 175);//(150,17);
  checkpoints[11] = new checkpoint (150, 221);//(150,22);
  checkpoints[12] = new checkpoint (169, 23);//(169,23);
  checkpoints[13] = new checkpoint (169, 73);//(169,73);
  checkpoints[14] = new checkpoint (220, 23);//(220,23);
  checkpoints[15] = new checkpoint (220, 114);//(220,11);
  checkpoints[16] = new checkpoint (220, 222);//(220,22);
  background(255);
  size(800, 600);
  visualize();
}
class checkpoint {
  float x;
  float y;
  ArrayList<checkpoint> neighbors;
  checkpoint(float _x, float _y) { 
    x = _x;
    y = _y;
    neighbors = new ArrayList <checkpoint> ();
  }
}

//Map One Dog 1



void link(int a, int b) {
  checkpoints[a-1].neighbors.add(checkpoints[b-1]);
  checkpoints[b-1].neighbors.add(checkpoints[a-1]);
}

void visualize() {
  for (checkpoint cp : checkpoints) {
    ellipse(map(cp.x, 0, 244, 40, 760), map(cp.y, 0, 244, 40, 560), 20, 20);
    for (checkpoint neighbor : cp.neighbors) {
      line(map(cp.x, 0, 244, 40, 760), map(cp.y, 0, 244, 40, 560), map(neighbor.x, 0, 244, 40, 760), map(neighbor.y, 0, 244, 40, 560));
    }
  }
}
//checkpoint 1 hard way example
//THis is assuming i have the checkpoints be values and not variables
//checkpoints.get(1).neighbors.add(checkpoint.get(2));
//checkpoint 1 slightly better way using variables for checkpoints
//ex. checkpoint 1 = new checkpoint (23,42)
// Checkpoint 1 
//1.neighbors.add(2);

//Even easier way will be used in this program
//Use the link function so that you only have to say link(1,2)

//No Walls or Dog code

link(1,2);
 link(2,6);
 link(3,4);
 link(4,8);
 link(5,13);
 link(5,6);
 link(6,7);
 link(6,10);
 link(7,8);
 link(7,11);
 link(8,12);
 link(9,10);
 link(9,14);
 link(10,16);
 link(11,12);
 link(12,17);
 link(13,14);
 link(13,15);
 link(15,16);
 link(16,17);
 */

//Map One Dog 1

void setNeighbors(int map) {
  
  for (checkpoint cp : checkpoints){
    cp.neighbors.clear();
  }
  
  switch (map) {
  // Map One Dog 1
  case 3:
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 6);
    link(6, 7);
    link(6, 10);
    link(7, 8);
    link(7, 11);
    link(9, 10);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  // Map Two Dog 1
  case 4:
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 6);
    link(6, 7);
    link(6, 10);
    link(7, 8);
    link(8, 12);
    link(9, 10);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  case 5:
    // Map 3 dog 1
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 6);
    link(6, 7);
    link(6, 10);
    link(7, 8);
    link(7, 11);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 14);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  //Map One Dog 2
  case 6:
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 13);
    link(5, 6);
    link(6, 7);
    link(6, 10);
    link(7, 8);
    link(7, 11);
    link(9, 10);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 15);
    link(16, 17);
    break;
  case 7:
  //Map Two Dog 2

  link(1, 2);
  link(2, 6);
  link(3, 4);
  link(4, 8);
  link(5, 13);
  link(5, 6);
  link(6, 7);
  link(6, 10);
  link(7, 8);
  link(8, 12);
  link(9, 10);
  link(9, 14);
  link(10, 16);
  link(11, 12);
  link(12, 17);
  link(13, 15);
  link(16, 17);
  break;
  case 8: // Map 3 dog 2
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 13);
    link(5, 6);
    link(6, 7);
    link(6, 10);
    link(7, 8);
    link(7, 11);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 14);
    link(13, 15);
    link(16, 17);
    break;
  //Map One Dog 3
  case 9:
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 13);
    link(5, 6);
    link(6, 7);
    link(7, 8);
    link(7, 11);
    link(9, 10);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  case 10:
    // Map 2 Dog 3
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 13);
    link(5, 6);
    link(6, 7);
    link(7, 8);
    link(8, 12);
    link(9, 10);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  case 11:
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 13);
    link(5, 6);
    link(6, 7);
    link(7, 8);
    link(7, 11);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 14);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  }
}

void draw(){
  background(255);
  visualize();
}

void keyPressed(){
  if (1 <= key - '0' && key - '0' <= 9) setNeighbors(key - '0' + 2);
}


