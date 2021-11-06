float modded_sine(long millis, float time_mult)
{
  float freq = TWO_PI/time_mult;
  long millisPerSecond = 1000;
  long freqLenMillis = (long)(freq*millisPerSecond);
  
  long moddedMillis = millis%freqLenMillis;
  float seconds = moddedMillis * 1.0f/millisPerSecond;
  return sin(seconds*time_mult);
}

void setup()
{
}



void draw()
{
  long milliseconds = 9223372854L + millis();
  float timeMult = 1.3;
  float mSin = modded_sine(milliseconds, timeMult);
  float lazySin = sin(timeMult * milliseconds/1000.f);
  
  println("milliseconds: " + milliseconds + " diff = " +(lazySin-mSin) + " ~~lazySin: " + lazySin + " mSin: " +mSin);
  
  ///////render
  background(200);
  float nSin = (mSin+1) * height/2; 
  ellipse(10,nSin,10,10);
  nSin = (lazySin+1) * height/2; 
  ellipse(10,nSin,10,10);
}
