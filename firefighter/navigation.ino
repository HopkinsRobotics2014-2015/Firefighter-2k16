//Handles the actual navigation, not including position checking

class Vec2f
{
  private:
    float x, y;
  public:
    Vec2f(float _x, float _y){
      x = _x;
      y = _y;
    }
    
    //Gets a copy of the vector
    Vec2f * get(){
      Vec2f * ret = new Vec2f(x,y);
      return ret;
    }
    
    float getX(){
      return x;
    }
    float getY(){
      return y;
    }
    void setX(float _x){
      x = _x;
    }
    void setY(float _y){
      y = _y;
    }
    
    //Adds v to the current vector
    void add(Vec2f v){
      x += v.getX();
      y += v.getY();
    }
    //Sets this = this - v
    void subtract(Vec2f v){
      x -= v.getX();
      y -= v.getY();
    }
    
    //Returns the dot product
    float dot(Vec2f v){
      return x * v.getX() + y * v.getY();
    }
    
    //Getting the magnitude squared is faster since there is no need
    //to take a square root
    float magnitudeSquared(){
      return x * x + y * y;
    }
    
    float magnitude(){
      return sqrt(magnitudeSquared());
    }
    
};
