
-----------------------------------------------------------   
  
Processing Tutorial 教學  
  https://weshare.hk/kwankung/articles/4764814  
  
Processing 基本教學 1小時快速入門  
  http://140.129.118.16/~richwang/100-1-Courses/Processing%20Tutorial%20(cht).pdf  
  
-----------------------------------------------------------   
  
事半功倍...  
first try Processing 劃畫 ,  
then try Arduino ,  
a piece of cake !!!  
  
1小時快速入門  
  
Processing Tutorial 教學  
  
  
demo - Processing Sine Wave simulate Lissajous Curve 20200608  
video :  
  https://youtu.be/X0e1K6sGsDU  
source code :  
  https://www.openprocessing.org/sketch/913656#  
  
  
demo - DrawCircles  
  https://openprocessing.org/sketch/1244458  
  
  
  
Processing Arduino relationship...  
  https://www.arduino.cc/education/visualization-with-arduino-and-processing  
With Processing, you can create stunning visual and interactive experiences. You can use Arduino serial data and send it to Processing using a serial library (in Processing). This allows you to use the data from all sorts of sensors !  
  
  
  
Processing 基本教學 1小時快速入門  
  http://140.129.118.16/~richwang/100-1-Courses/Processing%20Tutorial%20(cht).pdf  
  
  
請copy至PDE執行環境,  
並按下Run按鈕來執行看看!!  
  
  
  
void setup() {  
    size(200, 200);  
    noStroke();  
    background(255);  
    fill(0, 102, 153, 204);  
    smooth();  
    noLoop();  
}  
void draw() {  
    circles(40, 80);  
    circles(90, 70);  
}  
void circles(int x, int y) {  
    ellipse(x, y, 50, 50);  
    ellipse(x+20, y+20, 60, 60);  
}  
  
  
-----------------------------------------------------------   
end of file
