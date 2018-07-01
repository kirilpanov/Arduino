int piezoPin = 8; // Connect + of the piezo speaker to D9 and connect its next wire to Gnd

int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
// mid C C# D D# E F F# G G# A

void setup()
{
   for (int i = 0; i < numTones; i++)
   {
      tone(piezoPin, tones[i]);
      delay(500);
   }
   noTone(piezoPin);
}
void loop()
{
} // Reset to play the scale again
