boolean matrix[8][8];
int row=0;
int column=0; 
void setup() {

Serial.begin(9600);

clearMatrix();
//initial position
matrix[5][0]=1;
row=5;

}

void loop() {

  delay(1000);
  clearMatrix();
  column++;
  row--;
  matrix[row][column]=1;
  

}
void clearMatrix(){

  for(int i=0;i<8;i++){

  for(int j=0,j<8,j++){
    matrix[i][j]=0;
  }
}
}

